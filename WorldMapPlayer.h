#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "debug.h"

#define MARIO_SPEED 0.1f
#define MARIO_STATE_GO_LEFT		100
#define MARIO_STATE_GO_RIGHT	200
#define MARIO_STATE_GO_UP		300
#define MARIO_STATE_GO_DOWN		400

#define MARIO_BBOX_WIDTH 8.0f
#define MARIO_BBOX_HEIGHT 8.0f

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

	void GetBoundingBox(float& l, float& t, float& r, float& b);
};