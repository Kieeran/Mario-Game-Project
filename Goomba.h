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
#define GOOMBA_DIE_UPSIDE_TIMEOUT 1500

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_DIE 200

#define GOOMBA_STATE_SMALL_JUMP	300
#define GOOMBA_STATE_JUMP 400
#define GOOMBA_STATE_DIE_UPSIDE_DOWN 500

class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	int goombaType;
	bool isOnPlatform;
	bool Wing;
	bool IsJump;
	int num_small_jump;

	ULONGLONG die_start;
	ULONGLONG jump_start;

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();

	int IsCollidable()
	{
		return (state != GOOMBA_STATE_DIE_UPSIDE_DOWN);
	}
	int IsBlocking() { return 0; }

	void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);

	void OnCollisionWithPlatform(LPCOLLISIONEVENT e);
	void OnCollisionWithPlayer(LPCOLLISIONEVENT e);

	int GetAniGoombaYellow();
	int GetAniGoombaRed();

public:
	CGoomba(float x, float y, int goombaType);
	void SetState(int state);
	int GetGoombaType() { return goombaType; }
	bool GetStateWing() { return Wing; }
	void SetStateWing(bool Wing) { this->Wing = Wing; }
};