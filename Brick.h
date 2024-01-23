#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define NORMAL_BRICK	1
#define BRICK_WITH_ITEM	2

#define BRICK_STATE_DELETE 100

#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

class CBrick : public CGameObject
{
protected:
	int brickType;

	bool isBroken;
	bool isUseButton;
public:
	CBrick(float x, float y, int brickType) : CGameObject(x, y)
	{
		this->brickType = brickType;
		isBroken = false;
		isUseButton = false;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void SetState(int state);
};