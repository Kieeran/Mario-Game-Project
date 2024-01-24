#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define DETECTOR_GRAVITY	0.0009f

#define DETECTOR_BBOX_WIDTH 15
#define DETECTOR_BBOX_HEIGHT 26

class CDetector : public CGameObject
{
protected:
	float ay;
public:
	CDetector(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual int IsCollidable() { return 1; }
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
};