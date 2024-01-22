#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Coin.h"

#define MYSBOX_BOUCING_SPEED	0.1f
#define MYSBOX_GRAVITY	0.001f

#define	COIN	1
#define	ITEMS	2

#define MYSBOX_WIDTH 16
#define MYSBOX_BBOX_WIDTH 16
#define MYSBOX_BBOX_HEIGHT 16

#define MYSBOX_STATE_EMPTY			100
#define MYSBOX_STATE_CARRY_ITEMS	200
class CMysBox : public CGameObject
{
protected:
	float ay;

	float Origin_Y;
	int itemType;
	int mushroomType;
	bool Unbox;
	int index;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual void OnNoCollision(DWORD dt);
	virtual int IsCollidable() { return 0; }
	virtual int IsBlocking() { return 1; }

public:
	CMysBox(float x, float y, int itemType, int index, int mushroomType);
	virtual void SetState(int state);
	int GetItemType() { return itemType; }
	int GetIndex() { return index; }
	int GetMushroomType() { return mushroomType; }
};