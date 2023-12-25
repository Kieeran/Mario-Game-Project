#include "Card.h"

void CCard::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_CARD)->Render(x, y);
	//RenderBoundingBox();
}

void CCard::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - CARD_BBOX_WIDTH / 2;
	t = y - CARD_BBOX_HEIGHT / 2;
	r = l + CARD_BBOX_WIDTH;
	b = t + CARD_BBOX_HEIGHT;
}