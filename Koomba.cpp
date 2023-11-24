#include "Koomba.h"

CKoomba::CKoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOMBA_GRAVITY;
	die_start = -1;
	SetState(KOOMBA_STATE_WALKING);
}

void CKoomba::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == KOOMBA_STATE_WALKING)
	{
		l = x - KOOMBA_BBOX_WIDTH / 2;
		t = y - KOOMBA_BBOX_HEIGHT / 2;
		r = l + KOOMBA_BBOX_WIDTH;
		b = t + KOOMBA_BBOX_HEIGHT;
	}
	else
	{
		l = x - KOOMBA_SHELL_BBOX_WIDTH / 2;
		t = y - KOOMBA_SHELL_BBOX_HEIGHT / 2;
		r = l + KOOMBA_SHELL_BBOX_WIDTH;
		b = t + KOOMBA_SHELL_BBOX_HEIGHT;
	}
}

void CKoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	vy += ay * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CKoomba::Render()
{
	int aniId = -1;
	if (state == KOOMBA_STATE_WALKING)
	{
		if (vx <= 0)
			aniId = ID_ANI_RED_KOOMBA_WALKING_LEFT;
		else
			aniId = ID_ANI_RED_KOOMBA_WALKING_RIGHT;
	}
	else if (state == KOOMBA_STATE_HIDE)
	{
		aniId = ID_ANI_RED_KOOMBA_HIDE;
	}
	else if (state == KOOMBA_STATE_SHAKING)
	{
		aniId = ID_ANI_RED_KOOMBA_SHAKING;
	}
	else if (state == KOOMBA_STATE_ROLLING)
	{
		aniId = ID_ANI_RED_KOOMBA_ROLLING;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}

void CKoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{

		//{
		//case KOOMBA_STATE_DIE:
		//	die_start = GetTickCount64();
		//	//y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
		//	vx = 0;
		//	vy = 0;
		//	ay = 0;
		//	break;
	case KOOMBA_STATE_WALKING:
		vx = -KOOMBA_WALKING_SPEED;
		break;
	}
}
