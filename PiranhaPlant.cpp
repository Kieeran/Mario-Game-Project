#include "PiranhaPlant.h"

CPiranhaPlant::CPiranhaPlant(float x, float y, int flowerType) : CGameObject(x, y)
{
	this->x = x;
	this->y = y;
	this->flowerType = flowerType;
	SetState(PIRANHA_PLANT_STATE_SLEEP);
	Origin_Y = y;
	rising = false;
	sleeping = false;
	Up = false;
	Left = false;
	rising_start = 0;
	reload = -1;
}

void CPiranhaPlant::Render()
{
	//if (state == FIREFLOWER_STATE_SLEEP)return;

	//CAnimations* animations = CAnimations::GetInstance();
	//CSprites* s = CSprites::GetInstance();

	//if (flowerType == RED_FIREFLOWER_TYPE)
	//{
	//	switch (state)
	//	{
	//	case FIREFLOWER_STATE_LOOKDOWN_LEFT:				//fire flower rise up look down left
	//		animations->Get(ID_ANI_FIREFLOWER_LOOKDOWN_LEFT)->Render(x, y);
	//		return;
	//	case FIREFLOWER_STATE_IDLE_LOOKDOWN_LEFT:			//fire flower look down left
	//		s->Get(ID_SPRITE_FIREFLOWER_1)->Draw(x, y);
	//		return;
	//	case FIREFLOWER_STATE_LOOKUP_LEFT:					//fire flower rise up look up left
	//		animations->Get(ID_ANI_FIREFLOWER_LOOKUP_LEFT)->Render(x, y);
	//		return;
	//	case FIREFLOWER_STATE_IDLE_LOOKUP_LEFT:				//fire flower look up left
	//		s->Get(ID_SPRITE_FIREFLOWER_3)->Draw(x, y);
	//		return;

	//	case FIREFLOWER_STATE_LOOKDOWN_RIGHT:				//fire flower rise up look down right
	//		animations->Get(ID_ANI_FIREFLOWER_LOOKDOWN_RIGHT)->Render(x, y);
	//		return;
	//	case FIREFLOWER_STATE_IDLE_LOOKDOWN_RIGHT:			//fire flower look down right
	//		s->Get(ID_SPRITE_FIREFLOWER_8)->Draw(x, y);
	//		return;
	//	case FIREFLOWER_STATE_LOOKUP_RIGHT:					//fire flower rise up look up right
	//		animations->Get(ID_ANI_FIREFLOWER_LOOKUP_RIGHT)->Render(x, y);
	//		break;
	//	case FIREFLOWER_STATE_IDLE_LOOKUP_RIGHT:			//fire flower look up right
	//		s->Get(ID_SPRITE_FIREFLOWER_6)->Draw(x, y);
	//		return;
	//	}
	//}

	//else
	//{
	//	animations->Get(ID_ANI_GREENFLOWER)->Render(x, y);
	//}

	//RenderBoundingBox();
}

void CPiranhaPlant::OnNoCollision(DWORD dt)
{
	y += vy * dt;
}

void CPiranhaPlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	/*CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (flowerType == RED_FIREFLOWER_TYPE)
	{
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
			if (this->Origin_Y - this->y >= FLOWER_RISEUP_HEIGHT_MAX)
			{
				this->y = this->Origin_Y - FLOWER_RISEUP_HEIGHT_MAX;
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
				SetState(FLOWER_STATE_SLEEP);
				rising_start = 0;
			}
		}
	}

	else
	{
		if (IsMarioOnTriggerDistance() && state == FLOWER_STATE_SLEEP && rising_start <= 0)
		{
			SetState(GREENFLOWER_STATE_RISING);
			vy = -FLOWER_RISEUP_SPEED;
			DebugOut(L">>> start rising >>> \n");
		}

		if (Origin_Y - y > FLOWER_RISEUP_HEIGHT_MAX)
		{
			y = Origin_Y - FLOWER_RISEUP_HEIGHT_MAX;
			vy = 0;
			rising_start = GetTickCount64();
			DebugOut(L">>> start waiting >>> \n");
		}

		if (GetTickCount64() - rising_start > 500 && rising_start > 0)
		{
			vy = FLOWER_RISEUP_SPEED;
			DebugOut(L">>> start !rising >>> \n");
		}

		if (GetTickCount64() - rising_start > 3000 && rising_start > 0)
		{
			rising_start = 0;
			DebugOut(L">>> done >>> \n");
		}

		if (Origin_Y - y < 0)
		{
			y = Origin_Y;
			vy = 0;
			SetState(FLOWER_STATE_SLEEP);
			DebugOut(L">>> sleep >>> \n");
		}
	}*/

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CPiranhaPlant::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	/*l = x - PLANT_BBOX_WIDTH / 2;
	t = y - PLANT_BBOX_HEIGHT / 2;
	r = l + PLANT_BBOX_WIDTH;
	b = t + PLANT_BBOX_HEIGHT;*/
}
void CPiranhaPlant::SetState(int state)
{
	CGameObject::SetState(state);
	/*switch (state)
	{
	case FLOWER_STATE_SLEEP:
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
	if (state != FLOWER_STATE_SLEEP && state != GREENFLOWER_STATE_RISING)
	{
		vy = FLOWER_RISEUP_SPEED;
	}*/
}