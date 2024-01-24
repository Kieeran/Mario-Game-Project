#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define NORMAL_BRICK		1
#define BRICK_WITH_BUTTON	2
#define BRICK_WITH_MUSHROOM	3

#define BRICK_STATE_NORMAL	100
#define BRICK_STATE_UNBOXED 200
#define BRICK_STATE_GOLD	300
#define BRICK_STATE_DELETE	400

#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

class CBrick : public CGameObject
{
protected:
	int brickType;

	bool isBroken;
	bool isGold;
	bool isUnboxed;
public:
	CBrick(float x, float y, int brickType);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int GetBrickType() { return brickType; }

	virtual void SetState(int state);
};