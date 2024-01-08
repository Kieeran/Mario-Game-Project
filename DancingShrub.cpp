#include "DancingShrub.h"

void CDancingShrub::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_DANCING_SHRUB)->Render(x, y);
	//RenderBoundingBox();
}

void CDancingShrub::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - DANCING_SHRUB_BBOX_WIDTH / 2;
	t = y - DANCING_SHRUB_BBOX_HEIGHT / 2;
	r = l + DANCING_SHRUB_BBOX_WIDTH;
	b = t + DANCING_SHRUB_BBOX_HEIGHT;
}