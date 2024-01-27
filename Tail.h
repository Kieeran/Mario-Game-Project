#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

#define TAIL_BBOX_WIDTH 16
#define TAIL_BBOX_HEIGHT 8
#define TIME_TAIL_ATTACK 100
#define TAIL_SPEED	0.09f

class CTail : public CGameObject
{
protected:
	float ax;
	float Origin_X;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render() {
		RenderBoundingBox();
	}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithMysBox(LPCOLLISIONEVENT e);
	void OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopas(LPCOLLISIONEVENT e);
	void OnCollisionWithBrick(LPCOLLISIONEVENT e);

public:
	CTail(float x, float y);
};