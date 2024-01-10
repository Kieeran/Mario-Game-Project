#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define	UNKNOWN				-1
#define	INTRO_BACKGROUND	1
#define	NUMBER_3			2
#define	ARROW				3

class CIntroObjects : public CGameObject
{
protected:
	int objectType;
	bool isOnePlayer;
public:
	CIntroObjects(float x, float y, int objectType) : CGameObject(x, y)
	{
		this->objectType = objectType;
		isOnePlayer = true;
	}

	bool GetIsOnePlayer() { return isOnePlayer; }
	void SetIsOnePlayer(bool b) { isOnePlayer = b; }

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
};