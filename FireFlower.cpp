#include "FireFlower.h"

CFireFlower::CFireFlower(float x, float y) :CGameObject()
{
	this->x = x;
	this->y = y;
	this->SetState(FIREFLOWER_STATE_SLEEP);
	this->Origin_Y = y;
	this->rising = false;
	this->sleeping = false;
}

void CFireFlower::Render()
{
	if (state == FIREFLOWER_STATE_SLEEP)return;
	CAnimations* animations = CAnimations::GetInstance();
	CSprites* s = CSprites::GetInstance();
	switch (state)
	{
	case FIREFLOWER_STATE_LOOKDOWN_LEFT:				//fire flower rise up look down left
		animations->Get(ID_ANI_FIREFLOWER_LOOKDOWN_LEFT)->Render(x, y);
		return;
	case FIREFLOWER_STATE_IDLE_LOOKDOWN_LEFT:			//fire flower look down left
		s->Get(ID_SPRITE_FIREFLOWER_1)->Draw(x, y);
		return;
	case FIREFLOWER_STATE_LOOKUP_LEFT:					//fire flower rise up look up left
		animations->Get(ID_ANI_FIREFLOWER_LOOKUP_LEFT)->Render(x, y);
		return;
	case FIREFLOWER_STATE_IDLE_LOOKUP_LEFT:				//fire flower look up left
		s->Get(ID_SPRITE_FIREFLOWER_3)->Draw(x, y);
		return;

	case FIREFLOWER_STATE_LOOKDOWN_RIGHT:				//fire flower rise up look down right
		animations->Get(ID_ANI_FIREFLOWER_LOOKDOWN_RIGHT)->Render(x, y);
		return;
	case FIREFLOWER_STATE_IDLE_LOOKDOWN_RIGHT:			//fire flower look down right
		s->Get(ID_SPRITE_FIREFLOWER_8)->Draw(x, y);
		return;
	case FIREFLOWER_STATE_LOOKUP_RIGHT:					//fire flower rise up look up right
		animations->Get(ID_ANI_FIREFLOWER_LOOKUP_RIGHT)->Render(x, y);
		break;
	case FIREFLOWER_STATE_IDLE_LOOKUP_RIGHT:			//fire flower look up right
		s->Get(ID_SPRITE_FIREFLOWER_6)->Draw(x, y);
		return;
	}
	//RenderBoundingBox();
}

void CFireFlower::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (this->x > mario->GetX() && this->y < mario->GetY())
	{
		if (rising || sleeping)
			SetState(FIREFLOWER_STATE_LOOKDOWN_LEFT);
		else
			SetState(FIREFLOWER_STATE_IDLE_LOOKDOWN_LEFT);
	}
	else if (this->x > mario->GetX() && this->y > mario->GetY())
	{
		if (rising || sleeping)
			SetState(FIREFLOWER_STATE_LOOKUP_LEFT);
		else
			SetState(FIREFLOWER_STATE_IDLE_LOOKUP_LEFT);
	}
	else if (this->x < mario->GetX() && this->y < mario->GetY())
	{
		if (rising || sleeping)
			SetState(FIREFLOWER_STATE_LOOKDOWN_RIGHT);
		else
			SetState(FIREFLOWER_STATE_IDLE_LOOKDOWN_RIGHT);
	}
	else if (this->x < mario->GetX() && this->y > mario->GetY())
	{
		if (rising || sleeping)
			SetState(FIREFLOWER_STATE_LOOKUP_RIGHT);
		else
			SetState(FIREFLOWER_STATE_IDLE_LOOKUP_RIGHT);
	}

	if (abs(this->x - mario->GetX()) <= FIREFLOWER_TRIGGER_DISTANCE)
	{
		rising = true;
		sleeping = false;
	}
	else
	{
		rising = false;
		sleeping = true;
	}

	if (rising)
	{
		y -= vy * dt;
		if (this->Origin_Y - this->y >= FIREFLOWER_RISEUP_HEIGHT_MAX)
		{
			this->y = this->Origin_Y - FIREFLOWER_RISEUP_HEIGHT_MAX;
			rising = false;
		}
	}
	else
	{
		y += vy * dt;
		if (this->y >= this->Origin_Y)
		{
			this->y = this->Origin_Y;
			sleeping = false;
			SetState(FIREFLOWER_STATE_SLEEP);
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFireFlower::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FIREFLOWER_BBOX_WIDTH / 2;
	t = y - FIREFLOWER_BBOX_HEIGHT / 2;
	r = l + FIREFLOWER_BBOX_WIDTH;
	b = t + FIREFLOWER_BBOX_HEIGHT;
}
void CFireFlower::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == FIREFLOWER_STATE_SLEEP)
	{
		vy = 0;
	}
	else
	{
		vy = FIREFLOWER_RISEUP_SPEED;
	}
}