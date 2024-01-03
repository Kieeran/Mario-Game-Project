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

#define RED_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX		40.0f
#define GREEN_FIRE_PIRANHA_PLANT_RISEUP_HEIGHT_MAX		32.0f
#define GREEN_PIRANHA_PLANT_RISEUP_HEIGHT_MAX			24.0f

#define PIRANHA_PLANT_TRIGGER_DISTANCE_OUTER_LIMIT	100.0f
#define PIRANHA_PLANT_TRIGGER_DISTANCE_INNER_LIMIT	30.0f

#define PIRANHA_PLANT_WAITING_TIME		800
#define PIRANHA_PLANT_RELOADING_TIME	1000

#define PIRANHA_PLANT_BBOX_WIDTH	16
#define PIRANHA_PLANT_BBOX_HEIGHT	32

#define RED_FIRE_PIRANHA_PLANT_HEIGHT	35
#define GREEN_FIRE_PIRANHA_PLANT_HEIGHT	24
#define GREEN_PIRANHA_PLANT_HEIGHT		24

#define PIRANHA_PLANT_STATE_SLEEP	100
#define PIRANHA_PLANT_STATE_RISING	200
#define PIRANHA_PLANT_STATE_IDLE	300
#define PIRANHA_PLANT_STATE_DIVING	400

class CPiranhaPlant : public CGameObject
{
protected:
	float Origin_Y;
	int plantType;

	ULONGLONG reload;
	ULONGLONG waiting;
	ULONGLONG sleepTime;

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void OnNoCollision(DWORD dt);

	int GetAniIdRedFirePiranhaPlant();
	int GetAniIdGreenFirePiranhaPlant();

	bool isMarioOnTriggerDistance()
	{
		CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		return abs(x - mario->GetX()) <= PIRANHA_PLANT_TRIGGER_DISTANCE_OUTER_LIMIT &&
			abs(x - mario->GetX()) >= PIRANHA_PLANT_TRIGGER_DISTANCE_INNER_LIMIT;
	}
public:
	CPiranhaPlant(float x, float y, int plantType);
	void SetState(int state);
};