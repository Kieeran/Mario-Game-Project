#include "Tail.h"

CTail::CTail(float x, float y) :CGameObject(x, y)
{
	/*this->ax = 0;
	this->ay = MUSHROOM_GRAVITY;
	this->vx = 0;
	this->vy = 0;
	this->Origin_Y = y;
	this->SetState(MUSHROOM_STATE_WAKEUP);*/
}

void CTail::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	/*l = x - MUSHROOM_BBOX_WIDTH / 2;
	t = y - MUSHROOM_BBOX_HEIGHT / 2;
	r = l + MUSHROOM_BBOX_WIDTH;
	b = t + MUSHROOM_BBOX_HEIGHT;*/
}

void CTail::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CTail::OnCollisionWith(LPCOLLISIONEVENT e)
{
	/*if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CMushroom*>(e->obj)) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}*/
}

void CTail::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CTail::SetState(int state)
{
	CGameObject::SetState(state);
}