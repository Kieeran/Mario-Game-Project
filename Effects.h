#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

class CEffects : public CGameObject
{
protected:
	int effectType;

	float ax;
	float ay;
	float Origin_Y;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	//int IsCollidable() { return 1; };
	//int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);

public:
	CEffects(float x, float y, int effectType);
	void SetState(int state);
};