#include "WorldMapObjects.h"

void CWorldMapObjects::Render()
{
	int aniId = -1;

	switch (objectType)
	{
	case HAMMER_BROS:
		aniId = ID_ANI_HAMMER_BROS_WALKING_RIGHT;
		break;
	case HELP_EFFECT:
		aniId = ID_ANI_HELP_EFFECT;
		break;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}