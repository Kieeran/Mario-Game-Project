#include "Cloud.h"

void CCloud::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_CLOUD)->Render(x, y);
	//RenderBoundingBox();
}

void CCloud::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - CLOUD_BBOX_WIDTH / 2;
	t = y - CLOUD_BBOX_HEIGHT / 2;
	r = l + CLOUD_BBOX_WIDTH;
	b = t + CLOUD_BBOX_HEIGHT;
}