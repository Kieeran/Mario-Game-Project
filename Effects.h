#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

#define UNKNOWN_EFFECT	-1
#define HELP_EFFECT		40

class CEffects : public CGameObject
{
protected:
	int effectType;
	bool doneAnimation;

	ULONGLONG delete_start;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}

public:
	CEffects(float x, float y, int effectType);

	bool GetDoneAnimation() { return doneAnimation; }
	void SetDoneAnimation(bool d) { doneAnimation = d; }

	void SetEffect(int effectType) { this->effectType = effectType; }
};