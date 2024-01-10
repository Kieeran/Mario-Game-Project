#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define	UNKNOWN				-1
#define	INTRO_BACKGROUND	1

class CIntroObjects : public CGameObject
{
protected:
	int objectType;
public:
	CIntroObjects(float x, float y, int objectType) : CGameObject(x, y)
	{
		this->objectType = objectType;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
};