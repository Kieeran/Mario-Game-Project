#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define UNKNOWN_STICKER	-1
#define MUSHROOM_STICKER	1
#define STAR_STICKER	2
#define PLANT_STICKER	3

class CSticker : public CGameObject
{
private:
	int stickerType;
public:
	CSticker(float x, float y, int stickerType) : CGameObject(x, y)
	{
		this->stickerType = stickerType;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
};