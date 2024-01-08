#include "Curtain.h"

void CCurtain::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_CURTAIN)->Render(x, y);
	//RenderBoundingBox();
}

void CCurtain::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - CURTAIN_BBOX_WIDTH / 2;
	t = y - CURTAIN_BBOX_HEIGHT / 2;
	r = l + CURTAIN_BBOX_WIDTH;
	b = t + CURTAIN_BBOX_HEIGHT;
}