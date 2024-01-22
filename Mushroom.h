#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Pipe.h"
#include "Mario.h"
#include "Playscene.h"
#define UNKNOWN_TYPE	-1
#define RED_MUSHROOM_TYPE	1
#define GREEN_MUSHROOM_TYPE	2

#define MUSHROOM_GRAVITY 0.001f
#define MUSHROOM_WALKING_SPEED 0.05f

#define MUSHROOM_RISEUP_SPEED 0.02f
#define MUSHROOM_RISEUP_HEIGHT_MAX	16.0f

#define MUSHROOM_BBOX_WIDTH 15
#define MUSHROOM_BBOX_HEIGHT 15

#define MUSHROOM_STATE_WAKEUP		100
#define MUSHROOM_STATE_WALKING		200

class CMushroom : public CGameObject
{
protected:
	int mushroomType;

	float ax;
	float ay;
	float Origin_Y;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithPlayer(LPCOLLISIONEVENT e);

public:
	CMushroom(float x, float y, int mushroomType);
	void SetState(int state);
};