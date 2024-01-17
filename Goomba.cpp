#include "Goomba.h"

CGoomba::CGoomba(float x, float y, int goombaType) :CGameObject(x, y)
{
	this->goombaType = goombaType;
	ax = 0;
	ay = GOOMBA_GRAVITY;
	vx = -GOOMBA_WALKING_SPEED;
	vy = 0;
	die_start = 0;
	jump_start = 0;
	SetState(GOOMBA_STATE_WALKING);
	isOnPlatform = false;
	IsJump = false;
	Wing = true;
	if (goombaType == GOOMBA_TYPE_YELLOW)
		Wing = false;
	num_small_jump = 0;
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

	if (die_start > 0)
	{
		if (state == GOOMBA_STATE_DIE && GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT)
		{
			isDeleted = true;
		}
		else if(state == GOOMBA_STATE_DIE_UPSIDE_DOWN && GetTickCount64() - die_start > GOOMBA_DIE_UPSIDE_TIMEOUT)
		{
			isDeleted = true;
		}
	}

	if (vy < 0)
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
			if ((vx >= 0 && mario->GetX() < x) || (vx < 0 && mario->GetX() > x))
			{
				vx = -vx;
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
	int aniId = ID_ANI_YELLOW_GOOMBA_WALKING;

	if (state == GOOMBA_STATE_DIE)
		aniId = ID_ANI_YELLOW_GOOMBA_DIE;

	else if (state == GOOMBA_STATE_DIE_UPSIDE_DOWN)
		aniId = ID_ANI_YELLOW_GOOMBA_UPSIDE_DOWN;
	return aniId;
}

int CGoomba::GetAniGoombaRed()
{
	int aniId = ID_ANI_RED_GOOMBA_SMALL_JUMP;

	if (state == GOOMBA_STATE_JUMP)
		aniId = ID_ANI_RED_GOOMBA_JUMP;

	else if (state == GOOMBA_STATE_WALKING)
	{
		if (Wing)
			aniId = ID_ANI_RED_WING_GOOMBA_WALKING;
		else
			aniId = ID_ANI_RED_GOOMBA_WALKING;
	}
	else if (state == GOOMBA_STATE_DIE)
		aniId = ID_ANI_RED_GOOMBA_DIE;

	else if (state == GOOMBA_STATE_DIE_UPSIDE_DOWN)
		aniId = ID_ANI_RED_GOOMBA_UPSIDE_DOWN;
	return aniId;
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
		vx = 0;
		vy = 0;
		ax = 0;
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
		die_start = GetTickCount64();
		vx = 0;
		vy = -GOOMBA_JUMP_DEFLECT_SPEED;
		break;
	}
}