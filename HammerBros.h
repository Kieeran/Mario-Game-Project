#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "WorldMapScene.h"

#define HAMMER_BROS_WALKING_SPEED 0.05f

#define HAMMER_BROS_BBOX_WIDTH 15
#define HAMMER_BROS_BBOX_HEIGHT 15

#define HAMMER_BROS_STATE_WAKEUP	100
#define HAMMER_BROS_STATE_WALKING	200

class CHammerBros : public CGameObject
{
protected:
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

public:
	CHammerBros(float x, float y);
	void SetState(int state);
};