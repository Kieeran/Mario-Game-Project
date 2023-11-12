#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_CLOUD 100000
#define CELL_CLOUD_SIDE 16
class CCloud : public CGameObject
{
protected:
	int nCloud;
public:
	CCloud(float x, float y, int nCloud) : CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->nCloud = nCloud;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};