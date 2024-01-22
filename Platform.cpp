#include "Platform.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void CPlatform::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);

	float xx = x - cellWidth / 2 + rect.right / 2;

	CGame::GetInstance()->Draw(xx - cx, y - cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

void CPlatform::Render()
{
	if (length <= 0) return;
	float xx = x;
	CSprites* s = CSprites::GetInstance();
	s->Get(spriteIdBegin)->Draw(xx, y);
	xx += cellWidth;
	for (int i = 1; i < length - 1; i++)
	{
		s->Get(spriteIdMiddle)->Draw(xx, y);
		xx += cellWidth;
	}
	if (length > 1)
		s->Get(spriteIdEnd)->Draw(xx, y);
	//RenderBoundingBox();
}

void CPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - cellWidth / 2;
	t = y - cellHeight / 2;
	r = l + cellWidth * length;
	b = t + cellHeight;
}