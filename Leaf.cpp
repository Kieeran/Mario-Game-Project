#include "Leaf.h"

CLeaf::CLeaf(float x, float y) :CGameObject(x, y)
{
	this->ax = 0.0001f;
	this->ay = LEAF_GRAVITY;
	this->vy = -0.13f;
	this->delete_start = -1;
}

void CLeaf::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - LEAF_BBOX_WIDTH / 2;
	t = y - LEAF_BBOX_HEIGHT / 2;
	r = l + LEAF_BBOX_WIDTH;
	b = t + LEAF_BBOX_HEIGHT;
}

void CLeaf::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CLeaf::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CLeaf*>(e->obj)) return;
	/*if (e->ny != 0)
	{
		vy = 0;
	}*/
	/*else if (e->nx != 0)
	{
		vx = -vx;
	}*/
}

void CLeaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (vy < MAX_VY)
	{
		vy += ay * dt;
	}

	else
	{
		vy = ay * dt;
	}

	/*if (vy > 0)
	{
		if (vx <= ADJUST_MAX_VX)
		{
			vx += ax * dt;
		}
		else vx = -vx;
	}*/
	if (vy > 0)
	{
		vx += ax * dt;
		if (vx > ADJUST_MAX_VX)
		{
			ax = -ax;
		}
		else if (vx < -0.005)ax = ax;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CLeaf::Render()
{
	if (vx <= 0)CAnimations::GetInstance()->Get(ID_ANI_LEAF_LEFT)->Render(x, y);
	else CAnimations::GetInstance()->Get(ID_ANI_LEAF_RIGHT)->Render(x, y);
}

void CLeaf::SetState(int state)
{
	/*CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
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
	CGameObject::SetState(state);*/
}