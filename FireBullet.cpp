#include "FireBullet.h"

CFireBullet::CFireBullet(float x, float y) : CGameObject(x, y)
{
	vx = -BULLET_SPEED_X;
	vy = BULLET_SPEED_Y;
	start_delete = GetTickCount64();
}

void CFireBullet::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FIREBULLET)->Render(x, y);
}

void CFireBullet::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CFireBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64() - start_delete > TIME_BULLET_DELETE) {
		isDeleted = true;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

bool CFireBullet::Barycentric_Coordinates(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3)
{
	float Denominator = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
	float a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / Denominator;
	float b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / Denominator;
	float c = 1 - a - b;
	return a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1;
}

int CFireBullet::MarioLocation()
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	float a, b, c;
	a = -1;
	b = -1;
	c = -1;
	if (x == CoordinateX_A1)
	{
		/*if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_1;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_2;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_3;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_4;*/

		if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_5;

		/*else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_6;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_7;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_8;*/
	}

	else if (x == CoordinateX_A2)
	{
		/*if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_1;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_2;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_3;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_4;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_5;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_6;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_7;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), CoordinateX_A1, CoordinateY_A1,
			CoordinateX_B1, CoordinateY_B1, CoordinateX_C1, CoordinateY_C1))
			return Partition_8;*/
	}
}

void CFireBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BULLET_BBOX_WIDTH / 2;
	t = y - BULLET_BBOX_HEIGHT / 2;
	r = l + BULLET_BBOX_WIDTH;
	b = t + BULLET_BBOX_HEIGHT;
}