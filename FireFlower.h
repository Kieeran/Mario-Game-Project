#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "Playscene.h"
#include "FireBullet.h"

#define FIREFLOWER_RISEUP_SPEED 0.03f
#define FIREFLOWER_RISEUP_HEIGHT_MAX 38.0f

#define FIREFLOWER_TRIGGER_DISTANCE	100.0f
#define FIREFLOWER_TRIGGER_DISTANCE_LIMIT 30.0f

#define FIREFLOWER_RISING_TIME		2000
#define FIREFLOWER_WAITING_TIME		1000

#define FIREFLOWER_BBOX_WIDTH 16
#define FIREFLOWER_BBOX_HEIGHT 32

#define FIREFLOWER_STATE_SLEEP	100
#define FIREFLOWER_STATE_LOOKUP_LEFT	200
#define FIREFLOWER_STATE_LOOKDOWN_LEFT	300
#define FIREFLOWER_STATE_LOOKUP_RIGHT	400
#define FIREFLOWER_STATE_LOOKDOWN_RIGHT	500

#define FIREFLOWER_STATE_IDLE_LOOKUP_LEFT		600
#define FIREFLOWER_STATE_IDLE_LOOKDOWN_LEFT		700
#define FIREFLOWER_STATE_IDLE_LOOKUP_RIGHT		800
#define FIREFLOWER_STATE_IDLE_LOOKDOWN_RIGHT	900

class CFireFlower : public CGameObject
{
protected:
	float Origin_Y;
	bool rising;
	bool sleeping;
	bool Up;
	bool Left;
	ULONGLONG reload;
	ULONGLONG rising_start;
	ULONGLONG waiting;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	bool IsMarioOnTriggerDistance()
	{
		CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		return abs(this->x - mario->GetX()) <= FIREFLOWER_TRIGGER_DISTANCE &&
			abs(this->x - mario->GetX()) >= 30;
	}
public:
	CFireFlower(float x, float y)
	{
		this->x = x;
		this->y = y;
		this->SetState(FIREFLOWER_STATE_SLEEP);
		this->Origin_Y = y;
		this->rising = false;
		this->sleeping = false;
		this->Up = false;
		this->Left = false;
		this->rising_start = 0;
		this->reload = -1;
	}
	void SetState(int state);
};