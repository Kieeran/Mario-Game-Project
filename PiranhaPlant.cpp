#include "PiranhaPlant.h"

CPiranhaPlant::CPiranhaPlant(float x, float y, int plantType) : CGameObject(x, y)
{
	this->x = x;
	this->y = y;
	this->plantType = plantType;
	SetState(PIRANHA_PLANT_STATE_SLEEP);
	Origin_Y = y;
	reload = -1;
	waiting = -1;
	sleepTime = -1;
}

int CPiranhaPlant::GetAniIdRedFirePiranhaPlant()
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	int aniId = -1;
	if (x > mario->GetX() && y <= mario->GetY())			// mario in the bottom left corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKDOWN_LEFT;
		}

		else if (Origin_Y - y >= RED_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_LEFT;
		}
	}

	else if (x > mario->GetX() && y > mario->GetY())	// mario in the upper left corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKUP_LEFT;
		}

		else if (Origin_Y - y >= RED_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_LEFT;
		}
	}

	else if (x <= mario->GetX() && y <= mario->GetY())	// mario in the bottom right corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKDOWN_RIGHT;
		}

		else if (Origin_Y - y >= RED_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_RIGHT;
		}
	}

	else if (x <= mario->GetX() && y > mario->GetY())	// mario in the upper right corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKUP_RIGHT;
		}

		else if (Origin_Y - y >= RED_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_RIGHT;
		}
	}

	return aniId;
}
int CPiranhaPlant::GetAniIdGreenFirePiranhaPlant()
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	int aniId = -1;

	if (x > mario->GetX() && y <= mario->GetY())			// mario in the bottom left corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKDOWN_LEFT;
		}

		else if (Origin_Y - y >= GREEN_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_LEFT;
		}
	}

	else if (x > mario->GetX() && y > mario->GetY())	// mario in the upper left corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKUP_LEFT;
		}

		else if (Origin_Y - y >= GREEN_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_LEFT;
		}
	}

	else if (x <= mario->GetX() && y <= mario->GetY())	// mario in the bottom right corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKDOWN_RIGHT;
		}

		else if (Origin_Y - y >= GREEN_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_RIGHT;
		}
	}

	else if (x <= mario->GetX() && y > mario->GetY())	// mario in the upper right corner
	{
		if (vy != 0)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKUP_RIGHT;
		}

		else if (Origin_Y - y >= GREEN_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX)
		{
			aniId = ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_RIGHT;
		}
	}

	return aniId;
}

void CPiranhaPlant::Render()
{
	//if (state == PIRANHA_PLANT_STATE_SLEEP) return;

	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (plantType == RED_FIRE_PIRANHA_PLANT)
	{
		aniId = GetAniIdRedFirePiranhaPlant();
	}

	else if (plantType == GREEN_FIRE_PIRANHA_PLANT)
	{
		aniId = GetAniIdGreenFirePiranhaPlant();
	}

	else if (plantType == GREEN_PIRANHA_PLANT)
	{
		aniId = ID_ANI_GREEN_PIRANHA_PLANT;
	}
	if (aniId == -1) return;
	animations->Get(aniId)->Render(x, y);

	RenderBoundingBox();
}

void CPiranhaPlant::OnNoCollision(DWORD dt)
{
	y += vy * dt;
}

void CPiranhaPlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	float heightMax = -1;
	float riseupSpeed = -1;
	if (plantType == RED_FIRE_PIRANHA_PLANT)
	{
		heightMax = RED_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX;
		riseupSpeed = RED_PIRANHA_PLANT_RISEUP_SPEED;
	}

	else if (plantType == GREEN_FIRE_PIRANHA_PLANT)
	{
		heightMax = GREEN_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX;
		riseupSpeed = GREEN_PIRANHA_PLANT_RISEUP_SPEED;
	}

	else
	{
		heightMax = GREEN_PIRANHA_PLANT_RISEUP_HEIGHT_MAX;
		riseupSpeed = GREEN_PIRANHA_PLANT_RISEUP_SPEED;
	}

	if (state == PIRANHA_PLANT_STATE_SLEEP && isMarioOnTriggerDistance())
	{
		SetState(PIRANHA_PLANT_STATE_RISING);
		vy = -riseupSpeed;
		//DebugOut(L">>> rising >>> \n");
	}

	if (Origin_Y - y > heightMax)
	{
		y = Origin_Y - heightMax;
		vy = 0;
		SetState(PIRANHA_PLANT_STATE_IDLE);
		//DebugOut(L">>> waiting >>> \n");
		waiting = GetTickCount64();
	}

	if (GetTickCount64() - waiting > PIRANHA_PLANT_WAITING_TIME && waiting > 0)
	{
		waiting = 0;

		if (plantType == GREEN_PIRANHA_PLANT)
		{
			//DebugOut(L">>> diving >>> \n");
			vy = riseupSpeed;
			SetState(PIRANHA_PLANT_STATE_DIVING);
		}
		else
		{
			if (isMarioOnTriggerDistance())
			{
				//DebugOut(L">>> reloading >>> \n");
				reload = GetTickCount64();
				CFireBullet* bullet = new CFireBullet(x, y - 5.0f);
				DebugOut(L"X = %f \t Y = %f\n", x, y - 5.0f);
				scene->AddObject(bullet, ADD_OBJECT_MODE_1);
				reload = GetTickCount64();
			}
			else
			{
				//DebugOut(L">>> diving >>> \n");
				vy = riseupSpeed;
				SetState(PIRANHA_PLANT_STATE_DIVING);
			}
		}
	}

	if (GetTickCount64() - reload > PIRANHA_PLANT_RELOADING_TIME && reload > 0)
	{
		reload = 0;
		//DebugOut(L">>> diving >>> \n");
		vy = riseupSpeed;
		SetState(PIRANHA_PLANT_STATE_DIVING);
	}

	if (y > Origin_Y)
	{
		y = Origin_Y;
		vy = 0;
		sleepTime = GetTickCount64();
		//DebugOut(L">>> waiting >>> \n");
	}

	if (GetTickCount64() - sleepTime > PIRANHA_PLANT_WAITING_TIME && sleepTime > 0)
	{
		sleepTime = 0;
		SetState(PIRANHA_PLANT_STATE_SLEEP);
		//DebugOut(L">>> sleeping >>> \n");
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CPiranhaPlant::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PIRANHA_PLANT_BBOX_WIDTH / 2;
	t = y - PIRANHA_PLANT_BBOX_HEIGHT / 2;
	r = l + PIRANHA_PLANT_BBOX_WIDTH;
	b = t + PIRANHA_PLANT_BBOX_HEIGHT;
}
void CPiranhaPlant::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PIRANHA_PLANT_STATE_SLEEP:
		break;
	case PIRANHA_PLANT_STATE_RISING:
		break;
	case PIRANHA_PLANT_STATE_IDLE:
		break;
	case PIRANHA_PLANT_STATE_DIVING:
		break;
	}
}