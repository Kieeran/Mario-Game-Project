#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Pipe.h"

#define MUSHROOM_GRAVITY 0.0005f
#define MUSHROOM_WALKING_SPEED 0.05f

#define MUSHROOM_BBOX_WIDTH 16
#define MUSHROOM_BBOX_HEIGHT 16

#define MUSHROOM_STATE_SLEEP		100
#define MUSHROOM_STATE_WAKEUP		200
#define MUSHROOM_STATE_GOT_EATEN	300

class CMushroom : public CGameObject
{
protected:
	float ax;
	float ay;

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CMushroom(float x, float y);
	virtual void SetState(int state);
};