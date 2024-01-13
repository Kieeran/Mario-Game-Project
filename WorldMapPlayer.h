#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "debug.h"

#define MARIO_SPEED 0.1f

class CWorldMapPlayer : public CGameObject
{
protected:
	bool isAllowGoLeft;
	bool isAllowGoRight;
	bool isAllowGoUp;
	bool isAllowGoDown;
public:
	CWorldMapPlayer(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);

	void OnNoCollision(DWORD dt);

	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
};