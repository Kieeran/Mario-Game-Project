#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"
#include "Game.h"
#include "Playscene.h"

#include "string"

#define ID_SPRITE_HUD	100100
#define ID_ANI_HUD		100150

#define ID_SPRITE_POWER_HUD_1	100101
#define ID_SPRITE_POWER_HUD_2	100102

#define ID_ANI_POWER_HUD_1		100151
#define ID_ANI_POWER_HUD_2		100152

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

#define TIME_DISPLAY_X_COORD	12.0f
#define TIME_DISPLAY_Y_COORD	5.0f
#define TIME_DISPLAY_WIDTH	3

#define SCORE_DISPLAY_X_COORD	-60.0f
#define SCORE_DISPLAY_Y_COORD	5.0f
#define SCORE_DISPLAY_WIDTH	7	

#define	POWER_DISPLAY_X_COORD	-60.0f
#define POWER_DISPLAY_Y_COORD	-3.0f
#define DISTANCE_EVERY_LEVEL_RUN 8.0f

#define	POWER_MAX_DISPLAY_X_COORD	-7.0f
#define POWER_MAX_DISPLAY_Y_COORD	-3.0f

#define LIVES_DISPLAY_X_COORD	-75.0f
#define LIVES_DISPLAY_Y_COORD	5.0f
#define LIVES_DISPLAY	1

#define COIN_DISPLAY_X_COORD	20.0f
#define COIN_DISPLAY_Y_COORD	-3.0f
#define COIN_DISPLAY	2

#define NUMBER_SIZE		8.0f

class CHud : public CGameObject
{
public:
	CHud(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}

	void DrawNumber(int num, float x, float y);
	void DisplayTime(int num);
	void DisplayScore(int num);
	void DisplayLives(int num);
	void DisplayCoin(int num);
};