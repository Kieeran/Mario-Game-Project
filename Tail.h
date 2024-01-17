#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Pipe.h"
#include "Mario.h"
#include "Playscene.h"

#define TAIL_BBOX_WIDTH 15
#define TAIL_BBOX_HEIGHT 15

class CTail : public CGameObject
{
protected:
	float ax;
	float ay;
	float Origin_Y;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render() {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CTail(float x, float y);
	void SetState(int state);
};