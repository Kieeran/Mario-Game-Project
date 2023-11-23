#include "Goomba.h"

CGoomba::CGoomba(float x, float y, int goomba_type) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	die_start = -1;
	SetState(YELLOW_GOOMBA_STATE_WALKING);
	if (goomba_type == GOOMBA_TYPE_RED)
		SetState(RED_GOOMBA_STATE_FLYING);
	this->goomba_type = goomba_type;
}

void CGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == YELLOW_GOOMBA_STATE_DIE || state == RED_GOOMBA_STATE_DIE)
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	else if (state == RED_GOOMBA_STATE_FLYING)
	{
		left = x - RED_WING_GOOMBA_BBOX_WIDTH / 2;
		top = y - RED_WING_GOOMBA_BBOX_HEIGHT / 2;
		right = left + RED_WING_GOOMBA_BBOX_WIDTH;
		bottom = top + RED_WING_GOOMBA_BBOX_HEIGHT;
	}
	else
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
}

void CGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (x - mario->GetX() >= DISTANCE_SET_ACTIVE)return;

	vy += ay * dt;
	vx += ax * dt;

	if ((state == YELLOW_GOOMBA_STATE_DIE || state == RED_GOOMBA_STATE_DIE) &&
		(GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}


	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

int CGoomba::GetAniGoombaYellow()
{
	if (state == YELLOW_GOOMBA_STATE_WALKING)
		return ID_ANI_YELLOW_GOOMBA_WALKING;
	else if (state == YELLOW_GOOMBA_STATE_DIE)
		return ID_ANI_YELLOW_GOOMBA_DIE;
}
int CGoomba::GetAniGoombaRed()
{
	if (state == RED_GOOMBA_STATE_FLYING)
		return ID_ANI_RED_GOOMBA_FLYING;
	else if (state == RED_GOOMBA_STATE_WALKING)
		return ID_ANI_RED_GOOMBA_WALKING;
	else if (RED_GOOMBA_STATE_DIE)
		return ID_ANI_RED_GOOMBA_DIE;
}

void CGoomba::Render()
{
	int aniId = GetAniGoombaYellow();;
	if (goomba_type == GOOMBA_TYPE_RED)
	{
		aniId = GetAniGoombaRed();
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CGoomba::SetState(int state)
{
	CGameObject::SetState(state);

	if (state == YELLOW_GOOMBA_STATE_DIE || state == RED_GOOMBA_STATE_DIE)
	{
		die_start = GetTickCount64();
		//y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
		vx = 0;
		vy = 0;
		ay = 0;
	}
	else
	{
		vx = -GOOMBA_WALKING_SPEED;
	}

	//switch (state)
	//{
	//case YELLOW_GOOMBA_STATE_DIE:
	//	die_start = GetTickCount64();
	//	//y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
	//	vx = 0;
	//	vy = 0;
	//	ay = 0;
	//	break;
	//case YELLOW_GOOMBA_STATE_WALKING:
	//	vx = -GOOMBA_WALKING_SPEED;
	//	break;
	//case RED_GOOMBA_STATE_WALKING:
	//	vx = -GOOMBA_WALKING_SPEED;
	//	break;
	//case RED_GOOMBA_STATE_FLYING:
	//	break;
	//}
}
