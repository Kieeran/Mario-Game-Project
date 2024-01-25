#include "Pipe.h"

void CPipe::Render()
{
	if (this->lengthHeight <= 0)return;
	CSprites* s = CSprites::GetInstance();
	float xx = x - lenthCellSide / 2;
	float yy = y - lenthCellSide * (lengthHeight - 1) / 2;
	//Render the top row of the pipe
	s->Get(this->spriteIdTopLeft)->Draw(xx, yy);
	s->Get(this->spriteIdTopRight)->Draw(xx + this->lenthCellSide, yy);
	for (int i = 1; i <= this->lengthHeight - 1; i++)
	{
		s->Get(this->spriteIdBotLeft)->Draw(xx, yy + this->lenthCellSide * i);
		s->Get(this->spriteIdBotRight)->Draw(xx + this->lenthCellSide, yy + this->lenthCellSide * i);
	}
	//RenderBoundingBox();
}

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - lenthCellSide + 3.0f;
	t = y - lenthCellSide * lengthHeight / 2;
	r = l + lenthCellSide * 2 - 3.0f;
	b = t + lenthCellSide * lengthHeight;
}