#include "Koopas.h"

CKoopas::CKoopas(float x, float y, int koopasType) :CGameObject(x, y)
{
	this->koopasType = koopasType;
	ay = KOOPAS_GRAVITY;

	isHeld = false;
	isShaking = false;
	isOnPlatform = false;
	isUpSide = false;

	defend_start = 0;
	detector = NULL;
	if (koopasType != PARA_KOOPAS)
	{
		SetState(KOOPAS_STATE_WALKING);
		if (koopasType == RED_KOOPA)
		{
			detector = new CDetector(x - KOOPAS_SET_DETECTOR_X, y);
			CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
			scene->AddObject(detector, ADD_OBJECT_BACK);
		}
	}
	else
	{
		SetState(KOOPAS_STATE_FLYING);
	}

	isActive = false;
	initial_x_coordinate = x;
	initial_y_coordinate = y;
	initial_state = state;
}

void CKoopas::resetKoopasState()
{
	x = initial_x_coordinate;
	y = initial_y_coordinate;
	SetState(initial_state);

	isShaking = false;
	isOnPlatform = false;
	isHeld = false;
	isUpSide = false;
	defend_start = 0;

	if (koopasType == RED_KOOPA)
	{
		detector->SetPosition(x - KOOPAS_SET_DETECTOR_X, y);
	}
}

void CKoopas::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == KOOPAS_STATE_WALKING || state == KOOPAS_STATE_FLYING)
	{
		l = x - KOOPAS_BBOX_WIDTH / 2;
		t = y - KOOPAS_BBOX_HEIGHT / 2.1f;
		r = l + KOOPAS_BBOX_WIDTH;
		b = t + KOOPAS_BBOX_HEIGHT;
	}
	else
	{
		l = x - KOOPAS_SHELL_BBOX_WIDTH / 2;
		t = y - KOOPAS_SHELL_BBOX_HEIGHT / 2;
		r = l + KOOPAS_SHELL_BBOX_WIDTH;
		b = t + KOOPAS_SHELL_BBOX_HEIGHT;
	}
}

void CKoopas::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if ((abs(initial_x_coordinate - mario->GetX()) >= DISTANCE_SET_ACTIVE && abs(x - mario->GetX()) >= DISTANCE_SET_ACTIVE) ||
		(abs(initial_x_coordinate - mario->GetX()) >= DISTANCE_SET_ACTIVE && y > OUT_OF_MAP_Y))
	{
		isActive = false;
		resetKoopasState();
		return;
	}
	else if (!isActive)
	{
		isActive = true;
	}

	if (!checkObjectInCamera(this)) return;

	vy += ay * dt;

	if (koopasType == RED_KOOPA)
	{
		detector->SetX(x - KOOPAS_SET_DETECTOR_X + ((abs(vx) + vx) / (2 * abs(vx))) * 2 * KOOPAS_SET_DETECTOR_X);

		if (state == KOOPAS_STATE_WALKING && isOnPlatform)
		{
			if (detector->GetY() > y) {

				vx = -vx;
				detector->SetY(y - DETECTOR_DEFLECT_HIGH);
			}
		}
	}

	if (state == KOOPAS_STATE_FLYING && isOnPlatform)
	{
		vy = -KOOPAS_JUMP_DEFLECT_SPEED;
	}

	if (GetTickCount64() - defend_start > KOOPAS_COMEBACK_START && !isShaking && defend_start > 0)
	{
		isShaking = true;
		SetState(KOOPAS_STATE_SHAKING);
	}

	DebugOut(L"%d\n", isUpSide);

	if (defend_start > 0)	// Koopas starts hiding in the shell
	{
		if (GetTickCount64() - defend_start <= KOOPAS_DEFEND_TIMEOUT)	// Koopas still hides in the shell
		{
			if (!mario->GetIsHolding() && isHeld)
			{
				mario->StartKicking();
				SetState(KOOPAS_STATE_ROLLING);
				isHeld = false;
				//DebugOut(L">>> Drop koopa shell >>> \n");
			}
		}

		else	// Koopas comes out of the shell
		{
			if (mario->GetIsHolding())
			{
				mario->SetIsHolding(false);
				mario->SetLevelLower();
				mario->StartUntouchable();
			}

			isShaking = false;
			SetState(KOOPAS_STATE_WALKING);
			if (isUpSide)
				isUpSide = false;
			y -= 10.0f;

			if (koopasType == RED_KOOPA)
				detector->SetY(y - 10.0f);

			defend_start = 0;
			if (isHeld)
				isHeld = false;
		}
	}

	if (mario->GetIsHolding() && isHeld)
	{
		x = mario->GetX() + mario->GetNX() * (MARIO_BIG_BBOX_WIDTH - 3);
		y = mario->GetY();

		vx = mario->GetVX();
		vy = mario->GetVY();
	}

	if (vy != 0)
	{
		isOnPlatform = false;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CKoopas*>(e->obj)) return;

	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}

	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = -vx;
	}

	if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
	else if (dynamic_cast<CMysBox*>(e->obj))
		OnCollisionWithMysbox(e);
	else if (dynamic_cast<CPlatform*>(e->obj))
		OnCollisionWithPlatform(e);
	else if (dynamic_cast<CBrick*>(e->obj))
		OnCollisionWithBrick(e);
	else if (dynamic_cast<CMario*>(e->obj))
		OnCollisionWithPlayer(e);
}

void CKoopas::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (state == KOOPAS_STATE_ROLLING)
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			mario->AddScore(goomba->GetX(), goomba->GetY(), 100);
			goomba->SetState(GOOMBA_STATE_DIE_UPSIDE_DOWN);
		}
	}
}

void CKoopas::OnCollisionWithBrick(LPCOLLISIONEVENT e)
{
	CBrick* brick = dynamic_cast<CBrick*>(e->obj);
	if (state == KOOPAS_STATE_ROLLING)
	{
		if (e->ny == 0)
		{
			brick->SetState(BRICK_STATE_DELETE);
		}
	}
}

void CKoopas::OnCollisionWithPlatform(LPCOLLISIONEVENT e)
{
	if (e->ny < 0)
	{
		isOnPlatform = true;
	}
}

void CKoopas::OnCollisionWithPlayer(LPCOLLISIONEVENT e)
{
	CMario* mario = dynamic_cast<CMario*>(e->obj);

	if (e->ny <= 0)
	{
		if (state != KOOPAS_STATE_HIDING && state != KOOPAS_STATE_SHAKING)
			mario->SetLevelLower();
	}
}

void CKoopas::OnCollisionWithMysbox(LPCOLLISIONEVENT e)
{
	if (state != KOOPAS_STATE_ROLLING) return;

	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMysBox* mysbox = dynamic_cast<CMysBox*>(e->obj);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	//jump and hit the sides of the box
	if (e->nx != 0)
	{
		if (mysbox->GetState() == MYSBOX_STATE_CARRY_ITEMS)
		{
			mysbox->SetState(MYSBOX_STATE_EMPTY);
			int itemType = mysbox->GetItemType();
			CGameObject* item = NULL;
			switch (itemType)
			{
			case COIN:
				item = new CCoin(mysbox->GetX(), mysbox->GetY(), HIDDEN_COIN_TYPE);
				scene->AddObject(item);
				mario->SetCoinNum(mario->GetCoinNum() + 1);
				break;
			case ITEMS:
				if (mario->GetLevel() == MARIO_LEVEL_SMALL)
				{
					item = new CMushroom(mysbox->GetX(), mysbox->GetY(), mysbox->GetMushroomType());
					scene->AddObject(item, mysbox->GetIndex());
				}
				else
				{
					item = new CLeaf(mysbox->GetX(), mysbox->GetY());
					scene->AddObject(item, mysbox->GetIndex());
				}
				break;
			}
		}
	}
}

int CKoopas::GetAniIdRedKoopas()
{
	int aniId = -1;

	if (state == KOOPAS_STATE_WALKING)
	{
		if (vx <= 0)
			aniId = ID_ANI_RED_KOOPA_WALKING_LEFT;
		else
			aniId = ID_ANI_RED_KOOPA_WALKING_RIGHT;
	}
	else if (state == KOOPAS_STATE_HIDING)
	{
		if (!isUpSide)
			aniId = ID_ANI_RED_KOOPA_HIDING;
		else
			aniId = ID_ANI_RED_KOOPA_HIDING_UPSIDE;
	}
	else if (state == KOOPAS_STATE_SHAKING)
	{
		if (!isUpSide)
			aniId = ID_ANI_RED_KOOPA_SHAKING;
		else
			aniId = ID_ANI_RED_KOOPA_SHAKING_UPSIDE;
	}
	else if (state == KOOPAS_STATE_ROLLING)
	{
		if (!isUpSide)
			aniId = ID_ANI_RED_KOOPA_ROLLING;
		else
			aniId = ID_ANI_RED_KOOPA_ROLLING_UPSIDE;
	}
	return aniId;
}
int CKoopas::GetAniIdGreenKoopas()
{
	int aniId = -1;

	if (state == KOOPAS_STATE_FLYING)
	{
		if (vx <= 0)
			aniId = ID_ANI_PARA_KOOPAS_FLYING_LEFT;
		else
			aniId = ID_ANI_PARA_KOOPAS_FLYING_RIGHT;
	}
	else if (state == KOOPAS_STATE_WALKING)
	{
		if (vx <= 0)
			aniId = ID_ANI_GREEN_KOOPA_WALKING_LEFT;
		else
			aniId = ID_ANI_GREEN_KOOPA_WALKING_RIGHT;
	}
	else if (state == KOOPAS_STATE_HIDING)
	{
		if (!isUpSide)
			aniId = ID_ANI_GREEN_KOOPA_HIDING;
		else
			aniId = ID_ANI_GREEN_KOOPA_HIDING_UPSIDE;
	}
	else if (state == KOOPAS_STATE_SHAKING)
	{
		if (!isUpSide)
			aniId = ID_ANI_GREEN_KOOPA_SHAKING;
		else
			aniId = ID_ANI_GREEN_KOOPA_SHAKING_UPSIDE;
	}
	else if (state == KOOPAS_STATE_ROLLING)
	{
		if (!isUpSide)
			aniId = ID_ANI_GREEN_KOOPA_ROLLING;
		else
			aniId = ID_ANI_GREEN_KOOPA_ROLLING_UPSIDE;
	}
	//DebugOut(L"%d\n", aniId);
	return aniId;
}

void CKoopas::Render()
{
	if (!checkObjectInCamera(this)) return;

	if (y > OUT_OF_MAP_Y)return;
	int aniId = -1;

	if (koopasType == RED_KOOPA)
		aniId = GetAniIdRedKoopas();
	else
		aniId = GetAniIdGreenKoopas();

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	DebugOut(L"%d", aniId);
	//RenderBoundingBox();
}

void CKoopas::SetState(int state)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_HIDING:
		vx = 0;
		defend_start = GetTickCount64();
		break;
	case KOOPAS_STATE_ROLLING:
		vx = -KOOPAS_ROLLING_SPEED;
		if (mario->GetX() < x)
			vx *= -1;
		defend_start = 0;
		break;
	case KOOPAS_STATE_WALKING:
		vx = -KOOPAS_WALKING_SPEED;
		break;
	case KOOPAS_STATE_FLYING:
		vx = -KOOPAS_WALKING_SPEED;
		vy = -KOOPAS_JUMP_DEFLECT_SPEED;
		break;
	case KOOPAS_STATE_UPSIDE:
		isUpSide = true;
		vy = -KOOPA_JUMP_IS_ATTACKED;
		SetState(KOOPAS_STATE_HIDING);
		break;
	}
}