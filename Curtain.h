#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define CURTAIN_BBOX_WIDTH 16
#define CURTAIN_BBOX_HEIGHT 16

class CCurtain : public CGameObject
{
public:
	CCurtain(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};