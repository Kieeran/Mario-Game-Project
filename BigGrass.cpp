#include "BigGrass.h"

void CBigGrass::Render()
{
	if (!checkObjectInCamera(this)) return;

	CSprites* s = CSprites::GetInstance();
	s->Get(spriteId)->Draw(x, y);
}

void CBigGrass::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 1;
	b = 1;
}