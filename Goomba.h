#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "PlayScene.h"

#define GOOMBA_GRAVITY 0.002f
#define GOOMBA_WALKING_SPEED 0.05f

#define GOOMBA_TYPE_UNKNOWN -1
#define GOOMBA_TYPE_YELLOW 1
#define GOOMBA_TYPE_RED	2

#define DISTANCE_SET_ACTIVE	200.0f
#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 14
#define GOOMBA_BBOX_HEIGHT_DIE 7

#define RED_WING_GOOMBA_BBOX_WIDTH 20
#define RED_WING_GOOMBA_BBOX_HEIGHT 24

#define GOOMBA_DIE_TIMEOUT 500

#define YELLOW_GOOMBA_STATE_WALKING 100
#define YELLOW_GOOMBA_STATE_DIE 200

#define RED_GOOMBA_STATE_FLYING 300
#define RED_GOOMBA_STATE_WALKING 400
#define RED_GOOMBA_STATE_DIE 500

class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	int goomba_type;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	int GetAniGoombaYellow();
	int GetAniGoombaRed();

public:
	CGoomba(float x, float y, int goomba_type);
	virtual void SetState(int state);
	int GetGoombaType() { return goomba_type; }
};