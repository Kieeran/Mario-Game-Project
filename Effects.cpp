#include "Effects.h"

CEffects::CEffects(float x, float y, int effectType) :CGameObject(x, y)
{
	this->x = x;
	this->y = y;
	this->effectType = effectType;

	/*this->ax = 0;
	this->ay = MUSHROOM_GRAVITY;
	this->vx = 0;
	this->vy = 0;
	this->Origin_Y = y;
	this->SetState(MUSHROOM_STATE_WAKEUP);*/
}

void CEffects::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	/*l = x - MUSHROOM_BBOX_WIDTH / 2;
	t = y - MUSHROOM_BBOX_HEIGHT / 2;
	r = l + MUSHROOM_BBOX_WIDTH;
	b = t + MUSHROOM_BBOX_HEIGHT;*/
}

void CEffects::OnNoCollision(DWORD dt)
{
	/*x += vx * dt;
	y += vy * dt;*/
}

void CEffects::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	/*if (state == MUSHROOM_STATE_WALKING)
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
	}*/
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CEffects::Render()
{
	int aniId = -1;
	switch (effectType)
	{
	case HELP_EFFECT:
		aniId = ID_ANI_HELP_EFFECT;
		break;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}

void CEffects::SetState(int state)
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
	}*/
	CGameObject::SetState(state);
}