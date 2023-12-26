#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "Playscene.h"
#include "FireBullet.h"

#define FIREFLOWER_TYPE		1
#define GREENFLOWER_TYPE	2

#define FLOWER_RISEUP_SPEED 0.03f
#define FLOWER_RISEUP_HEIGHT_MAX 24.0f

#define FLOWER_TRIGGER_DISTANCE			100.0f
#define FLOWER_TRIGGER_DISTANCE_LIMIT	30.0f

#define FIREFLOWER_RISING_TIME		2000
#define FIREFLOWER_WAITING_TIME		1000

#define FIREFLOWER_BBOX_WIDTH 16
#define FIREFLOWER_BBOX_HEIGHT 32

#define FLOWER_STATE_SLEEP	100
#define FIREFLOWER_STATE_LOOKUP_LEFT	200
#define FIREFLOWER_STATE_LOOKDOWN_LEFT	300
#define FIREFLOWER_STATE_LOOKUP_RIGHT	400
#define FIREFLOWER_STATE_LOOKDOWN_RIGHT	500

#define FIREFLOWER_STATE_IDLE_LOOKUP_LEFT		600
#define FIREFLOWER_STATE_IDLE_LOOKDOWN_LEFT		700
#define FIREFLOWER_STATE_IDLE_LOOKUP_RIGHT		800
#define FIREFLOWER_STATE_IDLE_LOOKDOWN_RIGHT	900

#define GREENFLOWER_STATE_RISING	1000

class CFireFlower : public CGameObject
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
		CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		return abs(this->x - mario->GetX()) <= FLOWER_TRIGGER_DISTANCE &&
			abs(this->x - mario->GetX()) >= 30;
	}
public:
	CFireFlower(float x, float y, int flowerType);
	void SetState(int state);
};