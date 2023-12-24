#pragma once
#include "GameObject.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Detector.h"
#include "AssetIDs.h"

#define KOOBA_GRAVITY 0.002f
#define KOOBA_WALKING_SPEED 0.05f
#define KOOBA_ROLLING_SPEED 0.25f


#define KOOBA_BBOX_WIDTH 16
#define KOOBA_BBOX_HEIGHT 26

#define KOOBA_SHELL_BBOX_WIDTH 16
#define KOOBA_SHELL_BBOX_HEIGHT 16

#define KOOPA_DEFEND_TIMEOUT 8000
#define KOOPA_COMBACK_START 6000

#define KOOPA_SET_DETECTOR_X	(KOOBA_BBOX_WIDTH + 2) / 2

#define KOOBA_STATE_WALKING 100
#define KOOBA_STATE_DIE 200
#define KOOBA_STATE_HIDE 300
#define KOOBA_STATE_SHAKING 400
#define KOOBA_STATE_ROLLING 500

class CKooba : public CGameObject
{
protected:
	float ax;
	float ay;
	CDetector* detector;

	ULONGLONG defend_start;

	bool isShaking;
	bool isOnPlatform;
	bool isHeld;

	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();

	int IsCollidable() { return 1; }
	int IsBlocking() { return 0; }

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithMysbox(LPCOLLISIONEVENT e);

public:
	CKooba(float x, float y);
	virtual void SetState(int state);

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	bool GetIsHeld() { return isHeld; }
	void SetIsHeld(bool isHeld) { this->isHeld = isHeld; }

	//ULONGLONG GetDefendStart() { return defend_start; }
};