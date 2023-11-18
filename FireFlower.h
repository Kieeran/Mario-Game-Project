#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define FIREFLOWER_BOUCING_SPEED	0.3f
#define FIREFLOWER_BOUNCING_HEIGHT_MAX	50.0f

#define FIREFLOWER_BBOX_WIDTH 16
#define FIREFLOWER_BBOX_HEIGHT 32

class CFireFlower : public CGameObject
{
protected:
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	//int IsBlocking() { return 0; }
public:

	CFireFlower(float x, float y);
	void SetState(int state);
};