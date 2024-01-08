#include "Map.h"

void CMap::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_MAP)->Render(x, y);
	//RenderBoundingBox();
}

void CMap::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MAP_BBOX_WIDTH / 2;
	t = y - MAP_BBOX_HEIGHT / 2;
	r = l + MAP_BBOX_WIDTH;
	b = t + MAP_BBOX_HEIGHT;
}