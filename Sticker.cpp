#include "Sticker.h"

void CSticker::Render()
{
	if (!checkObjectInCamera(this)) return;

	int aniId = -1;
	switch (stickerType)
	{
	case MUSHROOM_STICKER:
		aniId = ID_ANI_MUSHROOM_STICKER;
		break;

	case STAR_STICKER:
		aniId = ID_ANI_STAR_STICKER;
		break;

	case PLANT_STICKER:
		aniId = ID_ANI_PLANT_STICKER;
		break;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}