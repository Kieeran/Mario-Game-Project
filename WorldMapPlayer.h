#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "debug.h"

#include "Mario.h"
#include "WorldMapNode.h"

#define MARIO_SPEED 0.1f
#define MARIO_STATE_GO_LEFT		100
#define MARIO_STATE_GO_RIGHT	200
#define MARIO_STATE_GO_UP		300
#define MARIO_STATE_GO_DOWN		400

#define MARIO_BBOX_WIDTH 1
#define MARIO_BBOX_HEIGHT 1

class CWorldMapPlayer : public CGameObject
{
protected:
	bool isAllowGoLeft;
	bool isAllowGoRight;
	bool isAllowGoUp;
	bool isAllowGoDown;

	bool canMove;
public:
	CWorldMapPlayer(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);

	virtual int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 1; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithNode(LPCOLLISIONEVENT e);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	bool GetCanMove() { return canMove; }
	void SetCanMove(bool m) { canMove = m; }
};