#include "FireBullet.h"

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

//void CFireBullet::OnCollisionWith(LPCOLLISIONEVENT e)
//{
//	if (dynamic_cast<CPipe*>(e->obj)) return;
//	if (e->obj->IsBlocking()) isDeleted = true;
//}

void CFireBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64() - start_delete > TIME_BULLET_DELETE) {
		isDeleted = true;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFireBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BULLET_BBOX_WIDTH / 2;
	t = y - BULLET_BBOX_HEIGHT / 2;
	r = l + BULLET_BBOX_WIDTH;
	b = t + BULLET_BBOX_HEIGHT;
}