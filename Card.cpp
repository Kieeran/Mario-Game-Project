#include "Card.h"

void CCard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!checkObjectInCamera(this)) return;

	if (!isCollected)
	{
		if (GetTickCount64() - change_start > TIME_CHANGE_CARD && change_start > 0)
		{
			if (card == STAR_CARD)
				card = MUSHROOM_CARD;
			else if (card == MUSHROOM_CARD)
				card = PLANT_CARD;
			else if (card == PLANT_CARD)
				card = STAR_CARD;
			change_start = GetTickCount64();
		}
	}
	else
	{
		if (GetTickCount64() - delete_start > TIME_DELETE_CARD && delete_start > 0)
		{
			delete_start = 0;
			Delete();
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CCard::Render()
{
	if (!checkObjectInCamera(this)) return;

	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch (card)
	{
	case STAR_CARD:
		aniId = ID_ANI_STAR_CARD;
		if (isCollected)
			aniId = ID_ANI_STAR_WHITE_CARD;
		break;
	case MUSHROOM_CARD:
		aniId = ID_ANI_MUSHROOM_CARD;
		if (isCollected)
			aniId = ID_ANI_MUSHROOM_WHITE_CARD;
		break;
	case PLANT_CARD:
		aniId = ID_ANI_PLANT_CARD;
		if (isCollected)
			aniId = ID_ANI_PLANT_WHITE_CARD;
		break;
	}
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CCard::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - CARD_BBOX_WIDTH / 2;
	t = y - CARD_BBOX_HEIGHT / 2;
	r = l + CARD_BBOX_WIDTH;
	b = t + CARD_BBOX_HEIGHT;
}

void CCard::SetState(int state)
{
	switch (state) {
	case CARD_STATE_COLLECTED:
		isCollected = true;
		vy = -SPEED_CARD;
		delete_start = GetTickCount64();
		break;
	}

	CGameObject::SetState(state);
}