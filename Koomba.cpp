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
	/*if (state == KOOMBA_STATE_DIE)
	{
		left = x - KOOMBA_BBOX_WIDTH / 2;
		top = y - KOOMBA_BBOX_HEIGHT_DIE / 2;
		right = left + KOOMBA_BBOX_WIDTH;
		bottom = top + KOOMBA_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - KOOMBA_BBOX_WIDTH / 2;
		top = y - KOOMBA_BBOX_HEIGHT / 2;
		right = left + KOOMBA_BBOX_WIDTH;
		bottom = top + KOOMBA_BBOX_HEIGHT;
	}*/
	l = 0;
	t = 0;
	r = 0;
	b = 0;
}

//void CKoomba::OnNoCollision(DWORD dt)
//{
//	x += vx * dt;
//	y += vy * dt;
//};

//void CKoomba::OnCollisionWith(LPCOLLISIONEVENT e)
//{
//	if (!e->obj->IsBlocking()) return;
//	if (dynamic_cast<CKoomba*>(e->obj)) return;
//
//	if (e->ny != 0)
//	{
//		vy = 0;
//	}
//	else if (e->nx != 0)
//	{
//		vx = -vx;
//	}
//}

//void CKoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
//{
//	vy += ay * dt;
//	vx += ax * dt;
//
//	if ((state == KOOMBA_STATE_DIE) && (GetTickCount64() - die_start > KOOMBA_DIE_TIMEOUT))
//	{
//		isDeleted = true;
//		return;
//	}
//
//	CGameObject::Update(dt, coObjects);
//	CCollision::GetInstance()->Process(this, dt, coObjects);
//}

void CKoomba::Render()
{
	/*int aniId = ID_ANI_YELLOW_GOOMBA_WALKING;
	if (state == KOOMBA_STATE_DIE)
	{
		aniId = ID_ANI_YELLOW_GOOMBA_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();*/
	CAnimations::GetInstance()->Get(ID_ANI_RED_KOOMBA)->Render(x, y);
}

//void CKoomba::SetState(int state)
//{
//	CGameObject::SetState(state);
//	switch (state)
//	{
//	case KOOMBA_STATE_DIE:
//		die_start = GetTickCount64();
//		//y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
//		vx = 0;
//		vy = 0;
//		ay = 0;
//		break;
//	case KOOMBA_STATE_WALKING:
//		vx = -KOOMBA_WALKING_SPEED;
//		break;
//	}
//}
