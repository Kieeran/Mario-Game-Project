#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

#define SPEED_EFFECT 0.025f
#define TIME_EFFECT_DELETE 700

#define UNKNOWN_EFFECT	-1
#define HELP_EFFECT		40
#define SCORE_100_EFFECT	100
#define SCORE_200_EFFECT	200
#define SCORE_400_EFFECT	400
#define SCORE_800_EFFECT	800
#define SCORE_1000_EFFECT	1000
#define SCORE_2000_EFFECT	2000
#define SCORE_4000_EFFECT	4000
#define SCORE_8000_EFFECT	8000

class CEffects : public CGameObject
{
protected:
	int effectType;
	bool doneAnimation;

	ULONGLONG delete_start;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}

	void OnNoCollision(DWORD dt);
public:
	CEffects(float x, float y, int effectType);

	bool GetDoneAnimation() { return doneAnimation; }
	void SetDoneAnimation(bool d) { doneAnimation = d; }

	void SetEffect(int effectType) { this->effectType = effectType; }
};