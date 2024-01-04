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
#define CoordinateX_A1	365
#define CoordinateY_A1	106
#define CoordinateX_B1	334
#define CoordinateY_B1	170
#define CoordinateX_C1	265	
#define CoordinateY_C1	170
#define CoordinateX_D1	395
#define CoordinateY_D1	170
#define CoordinateX_E1	464	
#define CoordinateY_E1	170
#define Denominator1_1	(CoordinateX_C1 - CoordinateX_B1) * (CoordinateY_A1 - CoordinateY_C1)
#define Denominator1_2	(CoordinateY_C1 - CoordinateY_A1) * (CoordinateX_A1 - CoordinateX_C1)

// Piranha plant 2
#define CoordinateX_A2	1825
#define CoordinateY_A2	114
#define CoordinateX_B2	1794
#define CoordinateY_B2	170
#define CoordinateX_C2	1725
#define CoordinateY_C2	170
#define CoordinateX_D2	1855
#define CoordinateY_D2	170
#define CoordinateX_E2	1924
#define CoordinateY_E2	170
#define Denominator2_1	(CoordinateY_B1 - CoordinateY_C1) * (CoordinateX_A1 - CoordinateX_C1) + (CoordinateX_C1 - CoordinateX_B1) * (CoordinateY_A1 - CoordinateY_C1)
#define Denominator2_2	(CoordinateY_B1 - CoordinateY_C1) * (CoordinateX_A1 - CoordinateX_C1) + (CoordinateX_C1 - CoordinateX_B1) * (CoordinateY_A1 - CoordinateY_C1)

#define Partition_1	1
#define Partition_2	2
#define Partition_3	3
#define Partition_4	4
#define Partition_5	5
#define Partition_6	6
#define Partition_7	7
#define Partition_8	8

#define BULLET_SPEED_X 0.05f
#define BULLET_SPEED_Y 0.05f

#define TIME_BULLET_DELETE 4000

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
	int MarioLocation();
	bool Barycentric_Coordinates(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3);
public:
	CFireBullet(float x, float y);
};