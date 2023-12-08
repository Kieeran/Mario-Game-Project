#include "Kooba.h"
#include "Goomba.h"
#include "Coin.h"

CKooba::CKooba(float x, float y) :CGameObject(x, y)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	this->ax = 0;
	this->ay = KOOBA_GRAVITY;
	this->isShaking = false;
	this->isOnPlatform = false;
	this->isSet = false;
	defend_start = -1;
	SetState(KOOBA_STATE_WALKING);
	this->detector = new CDetector(x - KOOPA_SET_DETECTOR_X, y);
	scene->AddObject(detector, ADD_OBJECT_MODE_1);
}

void CKooba::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == KOOBA_STATE_WALKING)
	{
		l = x - KOOBA_BBOX_WIDTH / 2;
		t = y - KOOBA_BBOX_HEIGHT / 2 + 3.0f;
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
	//if (abs(x - mario->GetX()) >= 100)return;

	vx += ax * dt;
	vy += ay * dt;

	detector->SetX(x - KOOPA_SET_DETECTOR_X + ((abs(vx) + vx) / (2 * abs(vx))) * 2 * KOOPA_SET_DETECTOR_X);

	if (isOnPlatform && !isSet)
	{
		detector->SetY(y);
		isSet = true;
	}

	if (state == KOOBA_STATE_WALKING)
	{
		if (detector->GetY() > y) {
			vx *= -1;
			detector->SetY(detector->GetOriginY());
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
		isSet = false;
		defend_start = 0;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKooba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	//if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CDetector*>(e->obj))return;
	if (dynamic_cast<CKooba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = -vx;
	}
	if (dynamic_cast<CPlatform*>(e->obj))
		this->OnCollisionWithPlatform(e);
	else if (dynamic_cast<CGoomba*>(e->obj))
		this->OnCollisionWithGoomba(e);
	else if (dynamic_cast<CCoin*>(e->obj))
		this->OnCollisionWithCoin(e);
}

void CKooba::OnCollisionWithPlatform(LPCOLLISIONEVENT e)
{
	if (e->ny < 0)
	{
		isOnPlatform = true;
	}
}

void CKooba::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (state == KOOBA_STATE_ROLLING)
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			goomba->SetState(GOOMBA_STATE_DIE_UPSIDE_DOWN);
			//goomba->SetState(GOOMBA_STATE_DIE);
		}
	}
}

void CKooba::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
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
	RenderBoundingBox();
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
