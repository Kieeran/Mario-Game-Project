#include "Mushroom.h"

CMushroom::CMushroom(float x, float y, int mushroomType) :CGameObject(x, y)
{
	this->mushroomType = mushroomType;
	ax = 0;
	ay = MUSHROOM_GRAVITY;
	vx = 0;
	vy = 0;
	Origin_Y = y;
	SetState(MUSHROOM_STATE_WAKEUP);
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
}

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

	if (dynamic_cast<CMario*>(e->obj))
		OnCollisionWithPlayer(e);
}

void CMushroom::OnCollisionWithPlayer(LPCOLLISIONEVENT e)
{
	CMario* mario = dynamic_cast<CMario*>(e->obj);
	mario->SetLevelHigher();
	e->obj->Delete();
}

void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!checkObjectInCamera(this)) return;

	if (state == MUSHROOM_STATE_WALKING)
	{
		vx += ax * dt;
		vy += ay * dt;
	}
	else if (state == MUSHROOM_STATE_WAKEUP)
	{
		if (Origin_Y - y < MUSHROOM_RISEUP_HEIGHT_MAX)
		{
			vy = -MUSHROOM_RISEUP_SPEED;
			vx = 0;
		}
		else
		{
			SetState(MUSHROOM_STATE_WALKING);
		}
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMushroom::Render()
{
	if (!checkObjectInCamera(this)) return;

	if (mushroomType == RED_MUSHROOM_TYPE)
		CAnimations::GetInstance()->Get(ID_ANI_RED_MUSHROOM)->Render(x, y);
	else
		CAnimations::GetInstance()->Get(ID_ANI_GREEN_MUSHROOM)->Render(x, y);
}

void CMushroom::SetState(int state)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (state)
	{
	case MUSHROOM_STATE_WALKING:
		if (this->x < mario->GetX())
		{
			vx = MUSHROOM_WALKING_SPEED;
		}
		else
		{
			vx = -MUSHROOM_WALKING_SPEED;
		}
		break;
	}
	CGameObject::SetState(state);
}