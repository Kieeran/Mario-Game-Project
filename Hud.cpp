#include "Hud.h"

void CHud::Render()
{
	/*CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_HUD)->Render(x, y);*/

	CSprites* s = CSprites::GetInstance();
	s->Get(11112)->Draw(x, y);
	s->Get(11111)->Draw(x, y);
}
//void CHud::Update(DWORD dt)
//{
//
//}
void CHud::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 1;
	b = 1;
}