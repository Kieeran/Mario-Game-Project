#include "MysBox.h"

void CMysBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_MYSBOX)->Render(x, y);
	//RenderBoundingBox();
}

void CMysBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MYSBOX_BBOX_WIDTH / 2;
	t = y - MYSBOX_BBOX_HEIGHT / 2;
	r = l + MYSBOX_BBOX_WIDTH;
	b = t + MYSBOX_BBOX_HEIGHT;
}