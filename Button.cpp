#include "Button.h"

CButton::CButton(float x, float y) : CGameObject(x, y)
{
	isPressed = false;
	Origin_X = x;
	Origin_Y = y;
}

void CButton::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!checkObjectInCamera(this)) return;

	if (x != Origin_X)
		x = Origin_X;
	if (y != Origin_Y)
		y = Origin_Y;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CButton::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (!isPressed)
	{
		l = x - BUTTON_BBOX_WIDTH / 2;
		t = y - BUTTON_BBOX_HEIGHT / 2;
		r = l + BUTTON_BBOX_WIDTH;
		b = t + BUTTON_BBOX_HEIGHT;
	}
}

void CButton::Render()
{
	if (!checkObjectInCamera(this)) return;

	if (!isPressed)
		CAnimations::GetInstance()->Get(ID_ANI_BUTTON_NOT_COLLECTED)->Render(x, y);
	else
		CAnimations::GetInstance()->Get(ID_ANI_BUTTON_COLLECTED)->Render(x, y);

	//RenderBoundingBox();
}