#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#include "Mario.h"
#include "PlayScene.h"
#include "FireFlower.h"
#include "Pipe.h"
#include "Platform.h"

//#define FIREBULLET_SPEED 0.08f
#define BULLET_SPEED_X 0.07f
#define BULLET_SPEED_Y 0.05f

#define TIME_BULLET_DELETE 2500

#define BULLET_BBOX_WIDTH 7
#define BULLET_BBOX_HEIGHT 7

class CFireBullet : public CGameObject
{
protected:
	ULONGLONG start_delete;
	bool Up;
	bool Left;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnNoCollision(DWORD dt);
	//void OnCollisionWith(LPCOLLISIONEVENT e);
public:
	CFireBullet(float x, float y, bool Up, bool Left) : CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->Up = Up;
		this->Left = Left;
		if (Up)
		{
			vy = -BULLET_SPEED_Y;
		}
		else
		{
			vy = BULLET_SPEED_Y;
		}

		if (Left)
		{
			vx = -BULLET_SPEED_X;
		}
		else
		{
			vx = BULLET_SPEED_X;
		}
		start_delete = GetTickCount64();
	}
};