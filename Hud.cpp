#include "Hud.h"

CHud::CHud(float x, float y) : CGameObject(x, y)
{
	//CGame::GetInstance()->GetCamPos(x, y);
}

void CHud::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (mario->GetX() >= 152.0f && mario->GetX() <= 2608)
		x = mario->GetX();
	else
	{
		if (mario->GetX() < 152.0f)
			x = 152.0f;
		else if (mario->GetX() > 2608)
			x = 2608.0f;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CHud::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_HUD)->Render(x, y);

	//DisplayTime(0);
	//DisplayScore(1000);
	//DisplayLives(2);
	//DisplayCoin(21);
}

void CHud::DrawNumber(int  num, float x, float y)
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

void CHud::DisplayTime(int num)
{
	if (num > 999 || num < 0) return;

	string s = to_string(num);

	while (s.length() < TIME_DISPLAY_WIDTH)
	{
		s = '0' + s;
	}

	for (int i = 0; i < TIME_DISPLAY_WIDTH; i++)
	{
		DrawNumber(s[i] - '0', x + TIME_DISPLAY_X_COORD + NUMBER_SIZE * i, y + TIME_DISPLAY_Y_COORD);
	}
}
void CHud::DisplayScore(int num)
{
	if (num > 9999999 || num < 0) return;

	string s = to_string(num);

	while (s.length() < SCORE_DISPLAY_WIDTH)
	{
		s = '0' + s;
	}

	for (int i = 0; i < SCORE_DISPLAY_WIDTH; i++)
	{
		DrawNumber(s[i] - '0', x + SCORE_DISPLAY_X_COORD + NUMBER_SIZE * i, y + SCORE_DISPLAY_Y_COORD);
	}
}
void CHud::DisplayLives(int num)
{
	if (num > 9 || num < 0) return;

	DrawNumber(num, x + LIVES_DISPLAY_X_COORD, y + LIVES_DISPLAY_Y_COORD);
}
void CHud::DisplayCoin(int num)
{
	if (num > 99 || num < 0) return;

	if (num < 10)
		DrawNumber(num, x + COIN_DISPLAY_X_COORD + NUMBER_SIZE, y + COIN_DISPLAY_Y_COORD);
	else
	{
		DrawNumber(num / 10, x + COIN_DISPLAY_X_COORD, y + COIN_DISPLAY_Y_COORD);
		DrawNumber(num % 10, x + COIN_DISPLAY_X_COORD + NUMBER_SIZE, y + COIN_DISPLAY_Y_COORD);
	}

	/*string s = to_string(num);

	while (s.length() < TIME_DISPLAY_WIDTH)
	{
		s = '0' + s;
	}

	for (int i = 0; i < TIME_DISPLAY_WIDTH; i++)
	{
		DrawNumber(s[i] - '0', x + TIME_DISPLAY_X_COORD + NUMBER_SIZE * i, y + TIME_DISPLAY_Y_COORD);
	}*/
}