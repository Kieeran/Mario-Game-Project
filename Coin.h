#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define COIN_BOUCING_SPEED	0.48f
#define COIN_GRAVITY	0.0015f

#define SHOWED_COIN_TYPE	0
#define HIDDEN_COIN_TYPE	1
#define COIN_BBOX_WIDTH 16
#define COIN_BBOX_HEIGHT 16

#define COIN_STATE_UNBOXING	100
#define COIN_STATE_NOT_UNBOX 200

#define TIME_COIN_TURN_TO_BRICK	10000
#define TIME_COIN_DELETE  550

class CCoin : public CGameObject
{
protected:
	float ay;

	int coin_type;
	float Origin_Y;

	bool isMoving;

	ULONGLONG waiting_time;
	ULONGLONG delete_start;

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void OnNoCollision(DWORD dt);
	int IsCollidable() { return coin_type == SHOWED_COIN_TYPE; }
	int IsBlocking() { return 0; }

public:
	CCoin(float x, float y, int coin_type = SHOWED_COIN_TYPE);

	void SetIsMoving(bool b) { isMoving = b; }
	void SetWaitingTime(ULONGLONG t) { waiting_time = t; }
};