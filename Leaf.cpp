#include "Leaf.h"
#include "MysBox.h"
#include "Platform.h"

CLeaf::CLeaf(float x, float y) :CGameObject(x, y)
{
	this->ax = 0.0001f;
	this->ay = LEAF_GRAVITY;
	this->vy = -0.13f;
	this->delete_start = 0;
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
	//if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CLeaf*>(e->obj)) return;
	//if (dynamic_cast<CMysBox*>(e->obj)) return;
	//if (dynamic_cast<CPlatform*>(e->obj)) return;
	/*if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}*/
	if (dynamic_cast<CMario*>(e->obj))
		OnCollisionWithPlayer(e);
}

void CLeaf::OnCollisionWithPlayer(LPCOLLISIONEVENT e)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	mario->SetLevelHigher();
	e->obj->Delete();
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

	if (vy > 0) {
		if (vx <= ADJUST_MAX_VX)
		{
			vx += ax * dt;
		}
		else
		{
			vx = -vx;
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CLeaf::Render()
{
	int aniId = -1;

	if (vx <= 0)
		aniId = ID_ANI_LEAF_LEFT;
	else
		aniId = ID_ANI_LEAF_RIGHT;

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}