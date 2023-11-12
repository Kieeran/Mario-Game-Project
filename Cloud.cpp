#include "Cloud.h"
#include "AssetIDs.h"
void CCloud::Render()
{
	if (this->nCloud <= 0)return;
	CSprites* s = CSprites::GetInstance();
	s->Get(ID_SPRITE_CLOUD_TOP_LEFT)->Draw(x, y);
	s->Get(ID_SPRITE_CLOUD_BOTTOM_LEFT)->Draw(x, y + CELL_CLOUD_SIDE);
	for (int i = 1; i <= this->nCloud; i++)
	{
		s->Get(ID_SPRITE_CLOUD_TOP_MIDDLE)->Draw(x + CELL_CLOUD_SIDE * i, y);
		s->Get(ID_SPRITE_CLOUD_BOTTOM_MIDDLE)->Draw(x + CELL_CLOUD_SIDE * i, y + CELL_CLOUD_SIDE);
	}
	s->Get(ID_SPRITE_CLOUD_TOP_RIGHT)->Draw(x + (this->nCloud + 1) * CELL_CLOUD_SIDE, y);
	s->Get(ID_SPRITE_CLOUD_BOTTOM_RIGHT)->Draw(x + (this->nCloud + 1) * CELL_CLOUD_SIDE, y + CELL_CLOUD_SIDE);
}
void CCloud::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 1;
	b = 1;
}