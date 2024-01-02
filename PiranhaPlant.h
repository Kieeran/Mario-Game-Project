#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "Playscene.h"
#include "FireBullet.h"

#define RED_FIRE_PIRANHA_PLANT		1
#define GREEN_FIRE_PIRANHA_PLANT	2
#define GREEN_PIRANHA_PLANT			3

#define PIRANHA_PLANT_RISEUP_SPEED		0.03f
#define PIRANHA_PLANT_RISEUP_HEIGHT_MAX 24.0f

#define PIRANHA_PLANT_TRIGGER_DISTANCE			100.0f
#define PIRANHA_PLANT_TRIGGER_DISTANCE_LIMIT	30.0f

#define PIRANHA_PLANT_RISING_TIME		2000
#define PIRANHA_PLANT_WAITING_TIME		1000

#define PIRANHA_PLANT_BBOX_WIDTH	16
#define PIRANHA_PLANT_BBOX_HEIGHT	32

#define PIRANHA_PLANT_STATE_SLEEP	100
#define PIRANHA_PLANT_STATE_RISING	200
#define PIRANHA_PLANT_STATE_IDLE	300
#define PIRANHA_PLANT_STATE_DIVING	400

#define GREENFLOWER_STATE_RISING	1000

class CPiranhaPlant : public CGameObject
{
protected:
	float Origin_Y;
	int flowerType;

	bool rising;
	bool sleeping;
	bool Up;
	bool Left;
	ULONGLONG reload;
	ULONGLONG rising_start;
	ULONGLONG waiting;

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void OnNoCollision(DWORD dt);

	bool IsMarioOnTriggerDistance()
	{
		/*CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		return abs(this->x - mario->GetX()) <= FLOWER_TRIGGER_DISTANCE &&
			abs(this->x - mario->GetX()) >= 30;*/
	}
public:
	CPiranhaPlant(float x, float y, int flowerType);
	void SetState(int state);
};