#include "BlackObject.h"

void CBlackObject::Render()
{
	CSprites* s = CSprites::GetInstance();

	if (lengthWidth < 0)
	{
		if (lengthHeight < 0)
		{
			s->Get(ID_SPRITE_CARD_BOX)->Draw(x, y);
		}
		else
		{
			for (int i = 0; i < lengthHeight; i++)
			{
				s->Get(ID_SPRITE_SERRATED_BLOCK_1)->Draw(x, y - BLACK_BLOCK_SIZE * i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lengthHeight; i++)
		{
			for (int j = 0; j < lengthWidth; j++)
			{
				s->Get(ID_SPRITE_BLACK_BLOCK)->Draw(x + BLACK_BLOCK_SIZE * j, y + BLACK_BLOCK_SIZE * i);
			}
		}
	}
}
void CBlackObject::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 1;
	b = 1;
}