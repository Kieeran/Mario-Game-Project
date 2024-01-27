#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#include "Mario.h"
#include "PlayScene.h"
#include "PiranhaPlant.h"
#include "Pipe.h"
#include "Platform.h"

// Utilize the Barycentric Coordinates method to determine Mario's position, 
// and consequently, ascertain the trajectory of the bullet.

// Piranha plant 1
#define COORDINATEX_A1	365
#define COORDINATEY_A1	106
#define COORDINATEX_B1	334
#define COORDINATEY_B1	200
#define COORDINATEX_C1	265	
#define COORDINATEY_C1	200
#define COORDINATEX_D1	395
#define COORDINATEY_D1	200
#define COORDINATEX_E1	464	
#define COORDINATEY_E1	200

// Piranha plant 2
#define COORDINATEX_A2	1825
#define COORDINATEY_A2	114
#define COORDINATEX_B2	1794
#define COORDINATEY_B2	200
#define COORDINATEX_C2	1725
#define COORDINATEY_C2	200
#define COORDINATEX_D2	1855
#define COORDINATEY_D2	200
#define COORDINATEX_E2	1924
#define COORDINATEY_E2	200

#define PARTITION_1	1
#define PARTITION_2	2
#define PARTITION_3	3
#define PARTITION_4	4
#define PARTITION_5	5
#define PARTITION_6	6
#define PARTITION_7	7
#define PARTITION_8	8

#define BULLET_SPEED_X_1 0.05f
#define BULLET_SPEED_Y_1 0.05f
#define BULLET_SPEED_X_2 0.065f
#define BULLET_SPEED_Y_2 0.03f

#define TIME_BULLET_DELETE 4000
#define OUT_OF_MAP_Y	187.0f

#define BULLET_BBOX_WIDTH 7
#define BULLET_BBOX_HEIGHT 7

class CFireBullet : public CGameObject
{
protected:
	ULONGLONG start_delete;

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithPlayer(LPCOLLISIONEVENT e);

	int MarioLocation();
	bool Barycentric_Coordinates(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3);
public:
	CFireBullet(float x, float y);
};