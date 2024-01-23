#include "Boxes.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void CBoxes::Render()
{
	if (lengthWidth <= 0 || lengthHeight <= 0)return;
	CSprites* s = CSprites::GetInstance();
	float xx, yy;
	//Render the top row of the box
	s->Get(spriteIdTopLeft)->Draw(x, y);
	for (int i = 1; i <= lengthWidth - 2; i++)
	{
		s->Get(spriteIdTopMiddle)->Draw(x + lengthCellSide * i, y);
	}
	s->Get(spriteIdTopRight)->Draw(x + lengthCellSide * (lengthWidth - 1), y);

	//Render the bottom row of the box
	yy = y + lengthCellSide * (lengthHeight - 1);
	s->Get(spriteIdBottomLeft)->Draw(x, yy);
	for (int i = 1; i <= lengthWidth - 2; i++)
	{
		s->Get(spriteIdBottomMiddle)->Draw(x + lengthCellSide * i, yy);
	}
	s->Get(spriteIdBottomRight)->Draw(x + lengthCellSide * (lengthWidth - 1), yy);

	//Render the middle matrix of the box
	for (int i = 1; i <= lengthHeight - 2; i++)
	{
		yy = y + lengthCellSide * i;
		s->Get(spriteIdMiddleLeft)->Draw(x, yy);
		int j = 0;
		for (j = 1; j <= lengthWidth - 2; j++)
		{
			s->Get(spriteIdCenter)->Draw(x + lengthCellSide * j, yy);
		}
		s->Get(spriteIdMiddleRight)->Draw(x + lengthCellSide * j, yy);
	}

	//Render the shadow of the box
	xx = x + lengthCellSide * lengthWidth;
	yy = y + lengthCellSide;
	s->Get(spriteIdShadowTop)->Draw(xx, y);
	for (int i = 0; i < lengthHeight - 1; i++)
	{
		s->Get(spriteIdShadowRest)->Draw(xx, yy);
		yy += lengthCellSide;
	}
	s->Get(ID_SPRITE_SHADOW_3)->Draw(xx, yy);

	xx = x;
	s->Get(ID_SPRITE_SHADOW_5)->Draw(xx, yy);
	for (int i = 0; i < lengthWidth - 1; i++)
	{
		xx += lengthCellSide;
		s->Get(ID_SPRITE_SHADOW_4)->Draw(xx, yy);
	}
}

void CBoxes::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x + 2.25f - lengthCellSide / 2;
	t = y - lengthCellSide / 2;
	r = l + lengthCellSide * lengthWidth - 2.25f;
	b = t + lengthCellSide * lengthHeight;
}