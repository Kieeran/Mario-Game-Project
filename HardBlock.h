#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define HARDBLOCK_BBOX_WIDTH 16
#define HARDBLOCK_BBOX_HEIGHT 16

class CHardBlock : public CGameObject
{
public:
	CHardBlock(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};