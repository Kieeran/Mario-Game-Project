#include "FireBullet.h"

CFireBullet::CFireBullet(float x, float y) : CGameObject(x, y)
{
	vx = 0;
	vy = 0;
	switch (MarioLocation())
	{
	case PARTITION_1:
		vx = BULLET_SPEED_X_1;
		vy = -BULLET_SPEED_Y_1;
		break;
	case PARTITION_2:
		vx = BULLET_SPEED_X_2;
		vy = -BULLET_SPEED_Y_2;
		break;
	case PARTITION_3:
		vx = BULLET_SPEED_X_2;
		vy = BULLET_SPEED_Y_2;
		break;
	case PARTITION_4:
		vx = BULLET_SPEED_X_1;
		vy = BULLET_SPEED_Y_1;
		break;
	case PARTITION_5:
		vx = -BULLET_SPEED_X_1;
		vy = BULLET_SPEED_Y_1;
		break;
	case PARTITION_6:
		vx = -BULLET_SPEED_X_2;
		vy = BULLET_SPEED_Y_2;
		break;
	case PARTITION_7:
		vx = -BULLET_SPEED_X_2;
		vy = -BULLET_SPEED_Y_2;
		break;
	case PARTITION_8:
		vx = -BULLET_SPEED_X_1;
		vy = -BULLET_SPEED_Y_1;
		break;
	}
	start_delete = GetTickCount64();
}

void CFireBullet::Render()
{
	if (!checkObjectInCamera(this)) return;

	if (y > OUT_OF_MAP_Y) return;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FIREBULLET)->Render(x, y);
}

void CFireBullet::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CFireBullet::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CMario*>(e->obj))
		OnCollisionWithPlayer(e);
}
void CFireBullet::OnCollisionWithPlayer(LPCOLLISIONEVENT e)
{
	CMario* mario = dynamic_cast<CMario*>(e->obj);
	if (!mario->GetIsUntouchable())
	{
		mario->SetLevelLower();
	}
}

void CFireBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!checkObjectInCamera(this)) return;

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
	if (x == COORDINATEX_A1)
	{
		if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_D1, 2 * COORDINATEY_A1 - COORDINATEY_D1, COORDINATEX_E1, 2 * COORDINATEY_A1 - COORDINATEY_D1))
			return PARTITION_1;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_E1, 2 * COORDINATEY_A1 - COORDINATEY_D1, COORDINATEX_E1, COORDINATEY_A1))
			return PARTITION_2;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_E1, COORDINATEY_A1, COORDINATEX_E1, COORDINATEY_E1))
			return PARTITION_3;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_E1, COORDINATEY_E1, COORDINATEX_D1, COORDINATEY_D1))
			return PARTITION_4;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_B1, COORDINATEY_B1, COORDINATEX_C1, COORDINATEY_C1))
			return PARTITION_5;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_C1, COORDINATEY_C1, COORDINATEX_C1, COORDINATEY_A1))
			return PARTITION_6;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_C1, COORDINATEY_A1, COORDINATEX_C1, 2 * COORDINATEY_A1 - COORDINATEY_C1))
			return PARTITION_7;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A1, COORDINATEY_A1,
			COORDINATEX_C1, 2 * COORDINATEY_A1 - COORDINATEY_C1, COORDINATEX_B1, 2 * COORDINATEY_A1 - COORDINATEY_C1))
			return PARTITION_8;
	}

	else if (x == COORDINATEX_A2)
	{
		if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_D2, 2 * COORDINATEY_A2 - COORDINATEY_D2, COORDINATEX_E2, 2 * COORDINATEY_A2 - COORDINATEY_D2))
			return PARTITION_1;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_E2, 2 * COORDINATEY_A2 - COORDINATEY_D2, COORDINATEX_E2, COORDINATEY_A2))
			return PARTITION_2;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_E2, COORDINATEY_A2, COORDINATEX_E2, COORDINATEY_E2))
			return PARTITION_3;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_E2, COORDINATEY_E2, COORDINATEX_D2, COORDINATEY_D2))
			return PARTITION_4;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_B2, COORDINATEY_B2, COORDINATEX_C2, COORDINATEY_C2))
			return PARTITION_5;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_C2, COORDINATEY_C2, COORDINATEX_C2, COORDINATEY_A2))
			return PARTITION_6;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_C2, COORDINATEY_A2, COORDINATEX_C2, 2 * COORDINATEY_A2 - COORDINATEY_C2))
			return PARTITION_7;

		else if (Barycentric_Coordinates(mario->GetX(), mario->GetY(), COORDINATEX_A2, COORDINATEY_A2,
			COORDINATEX_C2, 2 * COORDINATEY_A2 - COORDINATEY_C2, COORDINATEX_B2, 2 * COORDINATEY_A2 - COORDINATEY_C2))
			return PARTITION_8;
	}
}

void CFireBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BULLET_BBOX_WIDTH / 2;
	t = y - BULLET_BBOX_HEIGHT / 2;
	r = l + BULLET_BBOX_WIDTH;
	b = t + BULLET_BBOX_HEIGHT;
}