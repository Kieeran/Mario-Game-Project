#include "IntroObjects.h"

void CIntroObjects::Render()
{
	int aniId = -1;

	switch (objectType)
	{
	case INTRO_BACKGROUND:
		aniId = ID_ANI_INTRO_BACKGROUND;
		break;
	case NUMBER_3:
		aniId = ID_ANI_NUMBER_3;
		break;
	case ARROW:
		if (isOnePlayer)
			aniId = ID_ANI_ARROW_1_PLAYER_GAME;
		else
			aniId = ID_ANI_ARROW_2_PLAYER_GAME;
		break;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}