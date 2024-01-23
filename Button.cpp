#include "Button.h"

CButton::CButton(float x, float y) :CGameObject(x, y)
{

}

void CButton::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BUTTON_BBOX_WIDTH / 2;
	t = y - BUTTON_BBOX_HEIGHT / 2;
	r = l + BUTTON_BBOX_WIDTH;
	b = t + BUTTON_BBOX_HEIGHT;
}

void CButton::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CButton::OnCollisionWithPlayer(LPCOLLISIONEVENT e)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	mario->SetLevelHigher();
	e->obj->Delete();
}

void CButton::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CButton::Render()
{
	//CAnimations::GetInstance()->Get(ID_ANI_GREEN_MUSHROOM)->Render(x, y);
}

void CButton::SetState(int state)
{
	CGameObject::SetState(state);
}