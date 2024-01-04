#include "Koopas.h"
#include "Goomba.h"
#include "Mysbox.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Leaf.h"

CKoopas::CKoopas(float x, float y) :CGameObject(x, y)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	this->ay = KOOPAS_GRAVITY;
	this->isShaking = false;
	this->isOnPlatform = false;
	defend_start = -1;
	SetState(KOOPAS_STATE_WALKING);
	this->detector = new CDetector(x - KOOPAS_SET_DETECTOR_X, y);
	scene->AddObject(detector, ADD_OBJECT_MODE_1);
}

void CKoopas::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == KOOPAS_STATE_WALKING)
	{
		l = x - KOOPAS_BBOX_WIDTH / 2;
		t = y - KOOPAS_BBOX_HEIGHT / 2;
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
	if (abs(x - mario->GetX()) >= DISTANCE_SET_ACTIVE)return;
	//if (abs(x - mario->GetX()) >= 100) return;

	vy += ay * dt;

	detector->SetX(x - KOOPAS_SET_DETECTOR_X + ((abs(vx) + vx) / (2 * abs(vx))) * 2 * KOOPAS_SET_DETECTOR_X);

	if (state == KOOPAS_STATE_WALKING && isOnPlatform)
	{
		if (detector->GetY() > y) {

			vx = -vx;
			detector->SetY(y - 10.0f);
		}
	}

	if (GetTickCount64() - defend_start > KOOPAS_COMEBACK_START && !isShaking && defend_start > 0)
	{
		isShaking = true;
		SetState(KOOPAS_STATE_SHAKING);
	}

	if (defend_start > 0)	// Koopa starts hiding in the shell
	{
		if (GetTickCount64() - defend_start <= KOOPAS_DEFEND_TIMEOUT)	// Koopa still hides in the shell
		{
			if (!mario->GetIsHolding() && isHeld)
			{
				mario->StartKicking();
				SetState(KOOPAS_STATE_ROLLING);
				isHeld = false;
				DebugOut(L">>> Drop koopa shell >>> \n");
			}
		}

		else	// Koopa comes out of the shell
		{
			if (mario->GetIsHolding())
			{
				mario->SetIsHolding(false);
				mario->SetLevelLower();
				mario->StartUntouchable();
			}

			isShaking = false;
			SetState(KOOPAS_STATE_WALKING);
			y -= 10.0f;
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

	isOnPlatform = false;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	//if (!e->obj->IsBlocking()) return;
	//if (dynamic_cast<CDetector*>(e->obj))return;
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
		this->OnCollisionWithGoomba(e);
	else if (dynamic_cast<CMysBox*>(e->obj))
		this->OnCollisionWithMysbox(e);
}

void CKoopas::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (state == KOOPAS_STATE_ROLLING)
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			goomba->SetState(GOOMBA_STATE_DIE_UPSIDE_DOWN);
		}
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
		if (mysbox->GetState() == MYSBOX_STATE_CARRY_OBJECT)
		{
			mysbox->SetState(MYSBOX_STATE_EMPTY);
			int itemType = mysbox->GetItemType();
			CGameObject* item = NULL;
			switch (itemType)
			{
			case ITEM_TYPE_COIN:
				item = new CCoin(mysbox->GetX(), mysbox->GetY(), HIDDEN_COIN_TYPE);
				scene->AddObject(item);
				mario->SetCoinNum(mario->GetCoinNum() + 1);
				break;
			case ITEM_TYPE_MUSHROOM:
				item = new CMushroom(mysbox->GetX(), mysbox->GetY());
				scene->AddObject(item, mysbox->GetIndex());
				break;
			case ITEM_TYPE_LEAF:
				item = new CLeaf(mysbox->GetX(), mysbox->GetY());
				scene->AddObject(item, mysbox->GetIndex());
				break;
			}
		}

	}
}

void CKoopas::Render()
{
	int aniId = -1;
	if (state == KOOPAS_STATE_WALKING)
	{
		if (vx <= 0)
			aniId = ID_ANI_RED_KOOPA_WALKING_LEFT;
		else
			aniId = ID_ANI_RED_KOOPA_WALKING_RIGHT;
	}
	else if (state == KOOPAS_STATE_HIDE)
	{
		aniId = ID_ANI_RED_KOOPA_HIDE;
	}
	else if (state == KOOPAS_STATE_SHAKING)
	{
		aniId = ID_ANI_RED_KOOPA_SHAKING;
	}
	else if (state == KOOPAS_STATE_ROLLING)
	{
		aniId = ID_ANI_RED_KOOPA_ROLLING;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CKoopas::SetState(int state)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_HIDE:
		vx = 0;
		ax = 0;
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
	}
}