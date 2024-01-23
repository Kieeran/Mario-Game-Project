#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Playscene.h"

#define BUTTON_RISEUP_SPEED			0.02f
#define BUTTON_RISEUP_HEIGHT_MAX	16.0f

#define BUTTON_BBOX_WIDTH 16
#define BUTTON_BBOX_HEIGHT 16

class CButton : public CGameObject
{
protected:

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWithPlayer(LPCOLLISIONEVENT e);

public:
	CButton(float x, float y);
	void SetState(int state);
};