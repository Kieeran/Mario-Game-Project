#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define STAR_CARD		1
#define MUSHROOM_CARD	2
#define PLANT_CARD		3

#define SPEED_CARD	0.12f

#define CARD_BBOX_WIDTH 16
#define CARD_BBOX_HEIGHT 16

#define TIME_CHANGE_CARD 150
#define TIME_DELETE_CARD 1500

#define CARD_STATE_COLLECTED 100

class CCard : public CGameObject
{
protected:
	int card;
	bool isCollected;

	ULONGLONG change_start;
	ULONGLONG delete_start;

public:
	CCard(float x, float y) : CGameObject(x, y)
	{
		card = STAR_CARD;
		change_start = GetTickCount64();
		delete_start = 0;
		isCollected = false;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void SetState(int state);

	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}

	virtual int IsCollidable() { return !isCollected; }
	virtual int IsBlocking() { return !isCollected; }

	bool GetIsCollected() { return isCollected; }

	int GetCard() { return card; }
};