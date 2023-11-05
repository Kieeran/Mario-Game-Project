#include "SmallGrass.h"

void CSmallGrass::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_SMALLGRASS)->Render(x, y);
	//RenderBoundingBox();
}

void CSmallGrass::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 1;
	b = 1;
}