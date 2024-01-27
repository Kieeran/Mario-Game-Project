#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "Playscene.h"

#define LEAF_GRAVITY 0.0002f
#define MAX_VY 0.02f
#define	ADJUST_MAX_VX	0.085f

#define LEAF_BBOX_WIDTH 15
#define LEAF_BBOX_HEIGHT 15

class CLeaf : public CGameObject
{
protected:
	float ax;
	float ay;
	ULONGLONG delete_start;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithPlayer(LPCOLLISIONEVENT e);

	int IsBlocking() { return 0; }

public:
	CLeaf(float x, float y);
};