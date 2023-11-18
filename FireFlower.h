#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "Playscene.h"

//#define FIREFLOWER_RISEUP_SPEED 0.06f
#define FIREFLOWER_RISEUP_SPEED 0.03f
#define FIREFLOWER_RISEUP_HEIGHT_MAX 38.0f

#define FIREFLOWER_TRIGGER_DISTANCE	115.0f

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
	bool finish_riseup;
	bool finish_risedown;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
public:
	CFireFlower(float x, float y);
	void SetState(int state);
};