#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define MYSBOX_BOUCING_SPEED	0.05f
#define MYSBOX_BOUNCING_HEIGHT_MAX	5.0f

#define ID_ANI_MYSBOX_CARRY_OBJECT 500000
#define ID_ANI_MYSBOX_EMPTY 501000
#define ID_ANI_MYSBOX 500000
#define MYSBOX_WIDTH 16
#define MYSBOX_BBOX_WIDTH 16
#define MYSBOX_BBOX_HEIGHT 16
	
#define MYSBOX_STATE_EMPTY			501000
#define MYSBOX_STATE_CARRY_OBJECT	502000
class CMysBox : public CGameObject
{
protected:

	float Origin_Y;
	bool Unbox;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	//virtual void OnNoCollision(DWORD dt);
	
	//int IsDirectionColliable(float nx, float ny);
public:
	CMysBox(float x, float y);
	virtual void SetState(int state);
};