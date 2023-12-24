#include "HardBlock.h"

void CHardBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_HARDBLOCK)->Render(x, y);
	//RenderBoundingBox();
}

void CHardBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - HARDBLOCK_BBOX_WIDTH / 2;
	t = y - HARDBLOCK_BBOX_HEIGHT / 2;
	r = l + HARDBLOCK_BBOX_WIDTH;
	b = t + HARDBLOCK_BBOX_HEIGHT;
}