#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

#define KOOMBA_GRAVITY 0.002f
#define KOOMBA_WALKING_SPEED 0.05f


#define KOOMBA_BBOX_WIDTH 16
#define KOOMBA_BBOX_HEIGHT 26

#define KOOMBA_SHELL_BBOX_WIDTH 16
#define KOOMBA_SHELL_BBOX_HEIGHT 16

#define KOOMBA_DIE_TIMEOUT 500

#define KOOMBA_STATE_WALKING 100
#define KOOMBA_STATE_DIE 200
#define KOOMBA_STATE_HIDE 300
#define KOOMBA_STATE_SHAKING 400
#define KOOMBA_STATE_ROLLING 500

class CKoomba : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CKoomba(float x, float y);
	virtual void SetState(int state);
};