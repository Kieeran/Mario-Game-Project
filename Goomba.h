#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Platform.h"

#define GOOMBA_GRAVITY 0.001f
#define GOOMBA_WALKING_SPEED 0.05f

#define GOOMBA_TIME_SMALL_JUMP	750
#define GOOMBA_TIME_FLYING	1850

#define GOOMBA_JUMP_DEFLECT_SPEED 0.25f

#define GOOMBA_TYPE_UNKNOWN -1
#define GOOMBA_TYPE_YELLOW 1
#define GOOMBA_TYPE_RED	2

#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 14
#define GOOMBA_BBOX_HEIGHT_DIE 7

#define GOOMBA_DIE_TIMEOUT 500

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_DIE 200

#define GOOMBA_STATE_SMALL_JUMP	300
#define GOOMBA_STATE_JUMP		400
#define GOOMBA_STATE_DIE_UPSIDE_DOWN	500

class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	int goomba_type;
	bool isOnPlatform;
	bool Wing;
	bool IsJump;
	int num_small_jump;

	ULONGLONG die_start;
	ULONGLONG jump_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; }
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void OnCollisionWithPlatform(LPCOLLISIONEVENT e);

	int GetAniGoombaYellow();
	int GetAniGoombaRed();

public:
	CGoomba(float x, float y, int goomba_type);
	virtual void SetState(int state);
	int GetGoombaType() { return goomba_type; }
	bool GetStateWing() { return Wing; }
	void SetStateWing(bool Wing) { this->Wing = Wing; }
};