#include "Boxes.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void CBoxes::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	//LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);
	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);

	float xx = x - this->lengthCellSide / 2 + rect.right / 2;

	CGame::GetInstance()->Draw(xx - cx, y - cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

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
	xx = x + this->lengthCellSide * this->lengthWidth;
	yy = y;
	s->Get(this->spriteIdShadowTop)->Draw(xx, yy);
	for (int i = 1; i <= this->lengthHeight - 1; i++)
	{
		s->Get(this->spriteIdShadowRest)->Draw(xx, yy + this->lengthCellSide * i);
	}
}

void CBoxes::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x + 3.5f - this->lengthCellSide / 2;
	t = y - this->lengthCellSide / 2;
	r = l + this->lengthCellSide * this->lengthWidth;
	b = t + this->lengthCellSide * this->lengthHeight;
}
int CBoxes::IsDirectionColliable(float nx, float ny)
{
	if (nx == 0 && ny == -1) return 1;
	else return 0;
}