#include "Goomba.h"

CGoomba::CGoomba(float x, float y, int goomba_type) :CGameObject(x, y)
{
	this->goombaType = goomba_type;
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	this->vx = -GOOMBA_WALKING_SPEED;
	die_start = -1;
	jump_start = -1;
	SetState(GOOMBA_STATE_WALKING);
	this->isOnPlatform = false;
	this->IsJump = false;
	this->Wing = true;
	if (goomba_type == GOOMBA_TYPE_YELLOW)
		this->Wing = false;
	this->num_small_jump = 0;
}

void CGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (Wing)
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT / 4;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
	else
	{
		if (state == GOOMBA_STATE_DIE)
		{
			left = x - GOOMBA_BBOX_WIDTH / 2;
			top = y - GOOMBA_BBOX_HEIGHT_DIE / 2;
			right = left + GOOMBA_BBOX_WIDTH;
			bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
		}
		else
		{
			left = x - GOOMBA_BBOX_WIDTH / 2;
			top = y - GOOMBA_BBOX_HEIGHT / 2;
			right = left + GOOMBA_BBOX_WIDTH;
			bottom = top + GOOMBA_BBOX_HEIGHT;
		}
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
	if (dynamic_cast<CPlatform*>(e->obj))
		OnCollisionWithPlatform(e);
}
void CGoomba::OnCollisionWithPlatform(LPCOLLISIONEVENT e)
{
	if (e->ny < 0)
	{
		isOnPlatform = true;
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (abs(x - mario->GetX()) >= DISTANCE_SET_ACTIVE)
	{
		jump_start = GetTickCount64();
		return;
	}

	vx += ax * dt;
	vy += ay * dt;

	if (state == GOOMBA_STATE_DIE && GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT)
	{
		isDeleted = true;
		return;
	}

	//if (vy < 0)
	if (vy != 0)
	{
		isOnPlatform = false;
	}

	if (Wing)
	{
		//small jump before flying
		if (GetTickCount64() - jump_start >= GOOMBA_TIME_FLYING - GOOMBA_TIME_SMALL_JUMP &&
			GetTickCount64() - jump_start < GOOMBA_TIME_FLYING)
		{
			SetState(GOOMBA_STATE_SMALL_JUMP);
			if (isOnPlatform && num_small_jump < 3)
			{
				vy = -GOOMBA_JUMP_DEFLECT_SPEED / 2.15f;
				num_small_jump += 1;
			}
		}
		//flying
		if (GetTickCount64() - jump_start >= GOOMBA_TIME_FLYING && !IsJump)
		{
			SetState(GOOMBA_STATE_JUMP);
			if (vx >= 0 && mario->GetX() < x)
			{
				vx = -GOOMBA_WALKING_SPEED;
			}
			else if (vx < 0 && mario->GetX() > x)
			{
				vx = GOOMBA_WALKING_SPEED;
			}
			num_small_jump = 0;
		}

		if (IsJump)
		{
			if (isOnPlatform)
			{
				SetState(GOOMBA_STATE_WALKING);
				jump_start = GetTickCount64();
				IsJump = false;
			}
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

int CGoomba::GetAniGoombaYellow()
{
	if (state == GOOMBA_STATE_WALKING)
		return ID_ANI_YELLOW_GOOMBA_WALKING;

	else if (state == GOOMBA_STATE_DIE)
		return ID_ANI_YELLOW_GOOMBA_DIE;

	else if (state == GOOMBA_STATE_DIE_UPSIDE_DOWN)
		return ID_ANI_YELLOW_GOOMBA_UPSIDE_DOWN;

}
int CGoomba::GetAniGoombaRed()
{
	if (state == GOOMBA_STATE_SMALL_JUMP)
		return ID_ANI_RED_GOOMBA_SMALL_JUMP;

	else if (state == GOOMBA_STATE_JUMP)
		return ID_ANI_RED_GOOMBA_JUMP;

	else if (state == GOOMBA_STATE_WALKING)
	{
		if (Wing)
			return ID_ANI_RED_WING_GOOMBA_WALKING;
		else
			return ID_ANI_RED_GOOMBA_WALKING;
	}
	else if (GOOMBA_STATE_DIE)
		return ID_ANI_RED_GOOMBA_DIE;

	else if (GOOMBA_STATE_DIE_UPSIDE_DOWN)
		return ID_ANI_RED_GOOMBA_UPSIDE_DOWN;
}

void CGoomba::Render()
{
	int aniId = GetAniGoombaYellow();
	if (goombaType == GOOMBA_TYPE_RED)
	{
		aniId = GetAniGoombaRed();
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GOOMBA_STATE_DIE:
		die_start = GetTickCount64();
		//y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case GOOMBA_STATE_WALKING:
		if (!Wing)
			vx = -GOOMBA_WALKING_SPEED;
		break;
	case GOOMBA_STATE_JUMP:
		vy = -GOOMBA_JUMP_DEFLECT_SPEED;
		IsJump = true;
		break;
	case GOOMBA_STATE_DIE_UPSIDE_DOWN:
		vy = -GOOMBA_JUMP_DEFLECT_SPEED;
		vx = 0;
		ax = 0;
		break;
	}
}