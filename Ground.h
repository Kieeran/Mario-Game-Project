#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_GROUND 300000
#define GROUND_WIDTH 16
#define GROUND_BBOX_WIDTH 16
#define GROUND_BBOX_HEIGHT 16

class CGround : public CGameObject
{
public:
	CGround(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};