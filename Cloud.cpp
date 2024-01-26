#include "Cloud.h"
#include "AssetIDs.h"
void CCloud::Render()
{
	if (!checkObjectInCamera(this)) return;

	if (nCloud > 0)
	{
		CSprites* s = CSprites::GetInstance();
		s->Get(ID_SPRITE_CLOUD_TOP_LEFT)->Draw(x, y);
		s->Get(ID_SPRITE_CLOUD_BOTTOM_LEFT)->Draw(x, y + CELL_CLOUD_SIDE);
		for (int i = 1; i <= nCloud; i++)
		{
			s->Get(ID_SPRITE_CLOUD_TOP_MIDDLE)->Draw(x + CELL_CLOUD_SIDE * i, y);
			s->Get(ID_SPRITE_CLOUD_BOTTOM_MIDDLE)->Draw(x + CELL_CLOUD_SIDE * i, y + CELL_CLOUD_SIDE);
		}
		s->Get(ID_SPRITE_CLOUD_TOP_RIGHT)->Draw(x + (nCloud + 1) * CELL_CLOUD_SIDE, y);
		s->Get(ID_SPRITE_CLOUD_BOTTOM_RIGHT)->Draw(x + (nCloud + 1) * CELL_CLOUD_SIDE, y + CELL_CLOUD_SIDE);
	}
	else
		CAnimations::GetInstance()->Get(ID_ANI_SINGLE_CLOUD)->Render(x, y);
}
void CCloud::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (nCloud == 0)
	{
		l = x - CLOUD_BBOX_WIDTH / 2;
		t = y - CLOUD_BBOX_HEIGHT / 2;
		r = l + CLOUD_BBOX_WIDTH;
		b = t + CLOUD_BBOX_HEIGHT;
	}
}