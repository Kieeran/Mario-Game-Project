#include "Detector.h"
#include "Mario.h"
#include "Playscene.h"

CDetector::CDetector(float x, float y)
{
	this->x = x;
	this->y = y;
	this->ay = DETECTOR_GRAVITY;
}

void CDetector::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!checkObjectInCamera(this)) return;

	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (abs(x - mario->GetX()) >= DISTANCE_SET_ACTIVE)return;

	vy += ay * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CDetector::OnNoCollision(DWORD dt)
{
	y += vy * dt;
}

void CDetector::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny < 0)
	{
		vy = 0;
	}
}

void CDetector::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - DETECTOR_BBOX_WIDTH / 2;
	t = y - DETECTOR_BBOX_HEIGHT / 2;
	r = l + DETECTOR_BBOX_WIDTH;
	b = t + DETECTOR_BBOX_HEIGHT;
}

void CDetector::Render()
{
	if (!checkObjectInCamera(this)) return;

	//CAnimations::GetInstance()->Get(ID_ANI_DETECTOR)->Render(x, y);
	//RenderBoundingBox();
}