#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define ID_SPRITE_HUD	100100
#define ID_ANI_HUD		100150

#define ID_SPRITE_NUM_0		100200
#define ID_SPRITE_NUM_1		(ID_SPRITE_NUM_0 + 1)
#define ID_SPRITE_NUM_2		(ID_SPRITE_NUM_0 + 2)
#define ID_SPRITE_NUM_3		(ID_SPRITE_NUM_0 + 3)
#define ID_SPRITE_NUM_4		(ID_SPRITE_NUM_0 + 4)
#define ID_SPRITE_NUM_5		(ID_SPRITE_NUM_0 + 5)
#define ID_SPRITE_NUM_6		(ID_SPRITE_NUM_0 + 6)
#define ID_SPRITE_NUM_7		(ID_SPRITE_NUM_0 + 7)
#define ID_SPRITE_NUM_8		(ID_SPRITE_NUM_0 + 8)
#define ID_SPRITE_NUM_9		(ID_SPRITE_NUM_0 + 9)

#define ID_ANI_NUM_0		100250
#define ID_ANI_NUM_1		(ID_ANI_NUM_0 + 1)
#define ID_ANI_NUM_2		(ID_ANI_NUM_0 + 2)
#define ID_ANI_NUM_3		(ID_ANI_NUM_0 + 3)
#define ID_ANI_NUM_4		(ID_ANI_NUM_0 + 4)
#define ID_ANI_NUM_5		(ID_ANI_NUM_0 + 5)
#define ID_ANI_NUM_6		(ID_ANI_NUM_0 + 6)
#define ID_ANI_NUM_7		(ID_ANI_NUM_0 + 7)
#define ID_ANI_NUM_8		(ID_ANI_NUM_0 + 8)
#define ID_ANI_NUM_9		(ID_ANI_NUM_0 + 9)

class CHud : public CGameObject
{
public:
	CHud(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}

	void DrawNumber(int num, float x, float y);
};