#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define STAR_CARD		1
#define MUSHROOM_CARD	2
#define PLANT_CARD		3

#define TIME_CHANGE_CARD 150

#define CARD_BBOX_WIDTH 16
#define CARD_BBOX_HEIGHT 16

class CCard : public CGameObject
{
protected:
	int card;
	ULONGLONG change_start;
	bool isCollected;

public:
	CCard(float x, float y) : CGameObject(x, y)
	{
		card = STAR_CARD;
		change_start = GetTickCount64();
		isCollected = false;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}

	virtual int IsCollidable() { return 1; }
	virtual int IsBlocking() { return 1; }
};