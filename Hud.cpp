#include "Hud.h"

void CHud::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_HUD)->Render(x, y);
	DrawNumber(1, x, y);
	DrawNumber(2, x + 10.0f, y);
}

void CHud::DrawNumber(int num, float x, float y)
{
	int aniId = -1;
	switch (num)
	{
	case 0:
		aniId = ID_ANI_NUM_0;
		break;
	case 1:
		aniId = ID_ANI_NUM_1;
		break;
	case 2:
		aniId = ID_ANI_NUM_2;
		break;
	case 3:
		aniId = ID_ANI_NUM_3;
		break;
	case 4:
		aniId = ID_ANI_NUM_4;
		break;
	case 5:
		aniId = ID_ANI_NUM_5;
		break;
	case 6:
		aniId = ID_ANI_NUM_6;
		break;
	case 7:
		aniId = ID_ANI_NUM_7;
		break;
	case 8:
		aniId = ID_ANI_NUM_8;
		break;
	case 9:
		aniId = ID_ANI_NUM_9;
		break;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}