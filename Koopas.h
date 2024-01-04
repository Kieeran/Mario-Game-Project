#pragma once
#include "GameObject.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Detector.h"
#include "AssetIDs.h"

#define KOOPAS_GRAVITY 0.002f
#define KOOPAS_WALKING_SPEED 0.05f
#define KOOPAS_ROLLING_SPEED 0.25f


#define KOOPAS_BBOX_WIDTH 16
#define KOOPAS_BBOX_HEIGHT 26

#define KOOPAS_SHELL_BBOX_WIDTH 16
#define KOOPAS_SHELL_BBOX_HEIGHT 16

#define KOOPAS_DEFEND_TIMEOUT 8000
#define KOOPAS_COMEBACK_START 6000

#define KOOPAS_SET_DETECTOR_X	(KOOPAS_BBOX_WIDTH + 2) / 2

#define KOOPAS_STATE_WALKING 100
#define KOOPAS_STATE_DIE 200
#define KOOPAS_STATE_HIDE 300
#define KOOPAS_STATE_SHAKING 400
#define KOOPAS_STATE_ROLLING 500

class CKoopas : public CGameObject
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
	CKoopas(float x, float y);
	void SetState(int state);

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	bool GetIsHeld() { return isHeld; }
	void SetIsHeld(bool isHeld) { this->isHeld = isHeld; }

	ULONGLONG GetDefendStart() { return defend_start; }
};