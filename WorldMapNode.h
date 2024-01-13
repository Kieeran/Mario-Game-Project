#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define NODE_BBOX_WIDTH	 8
#define NODE_BBOX_HEIGHT 8

class CWorldMapNode : public CGameObject
{
	string Direction;

public:
	CWorldMapNode(float x, float y, string Direction);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	string GetDirection() { return Direction; }
};