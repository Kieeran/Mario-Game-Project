#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define MAP_BBOX_WIDTH 16
#define MAP_BBOX_HEIGHT 16

class CMap : public CGameObject
{
public:
	CMap(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};