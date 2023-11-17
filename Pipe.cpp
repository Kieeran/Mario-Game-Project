#include "Pipe.h"

void CPipe::Render()
{
	if (this->lengthHeight <= 0)return;
	CSprites* s = CSprites::GetInstance();
	//Render the top row of the pipe
	s->Get(this->spriteIdTopLeft)->Draw(x, y);
	s->Get(this->spriteIdTopRight)->Draw(x + this->lenthCellSide, y);
	for (int i = 1; i <= this->lengthHeight - 1; i++)
	{
		s->Get(this->spriteIdBotLeft)->Draw(x, y + this->lenthCellSide * i);
		s->Get(this->spriteIdBotRight)->Draw(x + this->lenthCellSide, y + this->lenthCellSide * i);
	}
}

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - lenthCellSide / 2 + 3.5f;
	t = y - lenthCellSide / 2;
	r = l + lenthCellSide * 2 - 3.5f;
	b = t + lenthCellSide * lengthHeight;
}