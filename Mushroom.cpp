#include "Mushroom.h"

CMushroom::CMushroom(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = MUSHROOM_GRAVITY;
	this->vy = 0;
	this->Origin_Y = y;
	SetState(MUSHROOM_STATE_SLEEP);
}

void CMushroom::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MUSHROOM_BBOX_WIDTH / 2;
	t = y - MUSHROOM_BBOX_HEIGHT / 2;
	r = l + MUSHROOM_BBOX_WIDTH;
	b = t + MUSHROOM_BBOX_HEIGHT;
}

void CMushroom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CMushroom*>(e->obj)) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->GetState() == MUSHROOM_STATE_WALKING)
	{
		vx += ax * dt;
		vy += ay * dt;
	}
	else if (this->GetState() == MUSHROOM_STATE_WAKEUP)
	{
		if (Origin_Y - y < MUSHROOM_RISEUP_HEIGHT_MAX)
		{
			vy = -MUSHROOM_RISEUP_SPEED;
			vx = 0;
		}
		else
		{
			this->SetState(MUSHROOM_STATE_WALKING);
		}
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMushroom::Render()
{
	if (this->GetState() == MUSHROOM_STATE_SLEEP)return;
	CAnimations::GetInstance()->Get(ID_ANI_MUSHROOM)->Render(x, y);
}

void CMushroom::SetState(int state)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (state)
	{
	case MUSHROOM_STATE_WALKING:
		if (this->x < mario->GetX())
		{
			vx = -MUSHROOM_WALKING_SPEED;
		}
		else
		{
			vx = MUSHROOM_WALKING_SPEED;
		}
		break;
	}
	CGameObject::SetState(state);
}