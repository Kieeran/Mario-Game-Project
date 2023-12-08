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

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

	//virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CLeaf(float x, float y);
	virtual void SetState(int state);
};