#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define MYSBOX_BOUCING_SPEED	0.05f
#define MYSBOX_BOUNCING_HEIGHT_MAX	5.0f

#define	ITEM_TYPE_UNKNOWN  -1
#define	ITEM_TYPE_COIN		1

#define MYSBOX_WIDTH 16
#define MYSBOX_BBOX_WIDTH 16
#define MYSBOX_BBOX_HEIGHT 16
	
#define MYSBOX_STATE_EMPTY			100
#define MYSBOX_STATE_CARRY_OBJECT	200
class CMysBox : public CGameObject
{
protected:

	float Origin_Y;
	bool Unbox;

	int ItemType;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

public:
	CMysBox(float x, float y, int ItemType);
	virtual void SetState(int state);
};