#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define CELL_CLOUD_SIDE 16
#define CLOUD_BBOX_WIDTH 16
#define CLOUD_BBOX_HEIGHT 16

class CCloud : public CGameObject
{
protected:
	int nCloud;
public:
	CCloud(float x, float y, int nCloud) : CGameObject(x, y)
	{
		this->nCloud = nCloud;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};