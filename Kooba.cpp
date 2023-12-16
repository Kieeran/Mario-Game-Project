#include "Kooba.h"
#include "Goomba.h"
#include "Mysbox.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Leaf.h"

CKooba::CKooba(float x, float y) :CGameObject(x, y)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	this->ay = KOOBA_GRAVITY;
	this->isShaking = false;
	this->isOnPlatform = false;
	defend_start = -1;
	SetState(KOOBA_STATE_WALKING);
	this->detector = new CDetector(x - KOOPA_SET_DETECTOR_X, y);
	isSet = false;
	scene->AddObject(detector, ADD_OBJECT_MODE_1);
}

void CKooba::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == KOOBA_STATE_WALKING)
	{
		l = x - KOOBA_BBOX_WIDTH / 2;
		t = y - KOOBA_BBOX_HEIGHT / 2;
		r = l + KOOBA_BBOX_WIDTH;
		b = t + KOOBA_BBOX_HEIGHT;
	}
	else
	{
		l = x - KOOBA_SHELL_BBOX_WIDTH / 2;
		t = y - KOOBA_SHELL_BBOX_HEIGHT / 2;
		r = l + KOOBA_SHELL_BBOX_WIDTH;
		b = t + KOOBA_SHELL_BBOX_HEIGHT;
	}
}

void CKooba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CKooba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (abs(x - mario->GetX()) >= DISTANCE_SET_ACTIVE)return;
	//if (abs(x - mario->GetX()) >= 100) return;

	vy += ay * dt;

	detector->SetX(x - KOOPA_SET_DETECTOR_X + ((abs(vx) + vx) / (2 * abs(vx))) * 2 * KOOPA_SET_DETECTOR_X);

	if (state == KOOBA_STATE_WALKING && isOnPlatform)
	{
		if (detector->GetY() > y) {

			vx = -vx;
			detector->SetY(y - 3.0f);
		}
	}

	if (GetTickCount64() - defend_start > KOOPA_COMBACK_START && !isShaking && defend_start > 0)
	{
		isShaking = true;
		SetState(KOOBA_STATE_SHAKING);
	}

	if (GetTickCount64() - defend_start > KOOPA_DEFEND_TIMEOUT && isShaking && defend_start > 0)
	{
		isShaking = false;
		SetState(KOOBA_STATE_WALKING);
		y -= 5.0f;
		defend_start = 0;
	}

	//isOnPlatform = false;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKooba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	//if (!e->obj->IsBlocking()) return;
	//if (dynamic_cast<CDetector*>(e->obj))return;
	if (dynamic_cast<CKooba*>(e->obj)) return;

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

void CKooba::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (state == KOOBA_STATE_ROLLING)
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			goomba->SetState(GOOMBA_STATE_DIE_UPSIDE_DOWN);
		}
	}
}

void CKooba::OnCollisionWithMysbox(LPCOLLISIONEVENT e)
{
	if (state != KOOBA_STATE_ROLLING) return;

	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMysBox* mysbox = dynamic_cast<CMysBox*>(e->obj);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	//DebugOut(L"Kooba rolling hit mysbox \n");

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

void CKooba::Render()
{
	int aniId = -1;
	if (state == KOOBA_STATE_WALKING)
	{
		if (vx <= 0)
			aniId = ID_ANI_RED_KOOBA_WALKING_LEFT;
		else
			aniId = ID_ANI_RED_KOOBA_WALKING_RIGHT;
	}
	else if (state == KOOBA_STATE_HIDE)
	{
		aniId = ID_ANI_RED_KOOBA_HIDE;
	}
	else if (state == KOOBA_STATE_SHAKING)
	{
		aniId = ID_ANI_RED_KOOBA_SHAKING;
	}
	else if (state == KOOBA_STATE_ROLLING)
	{
		aniId = ID_ANI_RED_KOOBA_ROLLING;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CKooba::SetState(int state)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOBA_STATE_HIDE:
		vx = 0;
		ax = 0;
		defend_start = GetTickCount64();
		break;
	case KOOBA_STATE_ROLLING:
		vx = -KOOBA_ROLLING_SPEED;
		if (mario->GetX() < x)
			vx *= -1;
		defend_start = 0;
		break;
	case KOOBA_STATE_WALKING:
		vx = -KOOBA_WALKING_SPEED;
		break;
	}
}