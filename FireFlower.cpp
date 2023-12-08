#include "FireFlower.h"

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
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
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

	if (GetTickCount64() - reload > TIME_BULLET_DELETE && reload != 0)
	{
		reload = 0;
	}

	if (IsMarioOnTriggerDistance() && rising_start == 0)
	{
		rising_start = GetTickCount64();
		rising = true;
	}

	if (GetTickCount64() - rising_start > FIREFLOWER_RISING_TIME && rising_start != 0)
	{
		if (IsMarioOnTriggerDistance() && !sleeping)
		{
			if (reload == 0)
			{
				CFireBullet* bullet = new CFireBullet(x, y, Up, Left);
				scene->AddObject(bullet, ADD_OBJECT_MODE_1);
				reload = GetTickCount64();
				waiting = GetTickCount64();
			}
		}
		else
			sleeping = true;
	}

	if (GetTickCount64() - waiting > FIREFLOWER_WAITING_TIME && waiting != 0)
	{
		waiting = 0;
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
	else if (sleeping)
	{
		y += vy * dt;
		if (this->y >= this->Origin_Y)
		{
			this->y = this->Origin_Y;
			sleeping = false;
			SetState(FIREFLOWER_STATE_SLEEP);
			rising_start = 0;
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
	switch (state)
	{
	case FIREFLOWER_STATE_SLEEP:
		vy = 0;
		break;
	case FIREFLOWER_STATE_IDLE_LOOKDOWN_LEFT:
		Up = false;
		Left = true;
		break;
	case FIREFLOWER_STATE_IDLE_LOOKUP_LEFT:
		Up = true;
		Left = true;
		break;
	case FIREFLOWER_STATE_IDLE_LOOKDOWN_RIGHT:
		Up = false;
		Left = false;
		break;
	case FIREFLOWER_STATE_IDLE_LOOKUP_RIGHT:
		Up = true;
		Left = false;
		break;
	}
	if (state != FIREFLOWER_STATE_SLEEP)
	{
		vy = FIREFLOWER_RISEUP_SPEED;
	}
}