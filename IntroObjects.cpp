#include "IntroObjects.h"

void CIntroObjects::Render()
{
	int aniId = -1;

	switch (objectType)
	{
	case INTRO_BACKGROUND:
		aniId = ID_ANI_INTRO_BACKGROUND;
		break;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}