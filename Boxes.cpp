#include "Boxes.h"

void CBoxes::Render()
{
	if (this->lengthWidth <= 0 || this->lengthHeight <= 0)return;
	CSprites* s = CSprites::GetInstance();
	float xx, yy;
	//Render the top row of the box
	s->Get(this->spriteIdTopLeft)->Draw(x, y);
	for (int i = 1; i <= this->lengthWidth - 2; i++)
	{
		s->Get(this->spriteIdTopMiddle)->Draw(x + this->lengthCellSide * i, y);
	}
	s->Get(this->spriteIdTopRight)->Draw(x + this->lengthCellSide * (this->lengthWidth - 1), y);

	//Render the bottom row of the box
	yy = y + this->lengthCellSide * (this->lengthHeight - 1);
	s->Get(this->spriteIdBottomLeft)->Draw(x, yy);
	for (int i = 1; i <= this->lengthWidth - 2; i++)
	{
		s->Get(this->spriteIdBottomMiddle)->Draw(x + this->lengthCellSide * i, yy);
	}
	s->Get(this->spriteIdBottomRight)->Draw(x + this->lengthCellSide * (this->lengthWidth - 1), yy);

	//Render the middle matrix of the box
	for (int i = 1; i <= this->lengthHeight - 2; i++)
	{
		yy = y + this->lengthCellSide * i;
		s->Get(this->spriteIdMiddleLeft)->Draw(x, yy);
		int j = 0;
		for (j = 1; j <= this->lengthWidth - 2; j++)
		{
			s->Get(this->spriteIdCenter)->Draw(x + this->lengthCellSide * j, yy);
		}
		s->Get(this->spriteIdMiddleRight)->Draw(x + this->lengthCellSide * j, yy);
	}

	//Render the shadow of the box
	xx = x + this->lengthCellSide * this->lengthWidth - 3;
	yy = y;
	s->Get(this->spriteIdShadowTop)->Draw(xx, yy);
	for (int i = 1; i <= this->lengthHeight - 1; i++)
	{
		s->Get(this->spriteIdShadowRest)->Draw(xx, yy + this->lengthCellSide * i);
	}
}

void CBoxes::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 1;
	b = 1;
}