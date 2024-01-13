#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define	UNKNOWN				-1
#define	HAMMER_BROS			1
#define	HELP_EFFECT			2

class CWorldMapObjects : public CGameObject
{
protected:
	int objectType;
public:
	CWorldMapObjects(float x, float y, int objectType) : CGameObject(x, y)
	{
		this->objectType = objectType;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
};