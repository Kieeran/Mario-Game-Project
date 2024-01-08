#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define DANCING_SHRUB_WIDTH 16
#define DANCING_SHRUB_BBOX_WIDTH 16
#define DANCING_SHRUB_BBOX_HEIGHT 16

class CDancingShrub : public CGameObject
{
public:
	CDancingShrub(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};