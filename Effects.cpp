#include "Effects.h"
#include "Playscene.h"

CEffects::CEffects(float x, float y, int effectType) :CGameObject(x, y)
{
	this->x = x;
	this->y = y;
	this->effectType = effectType;
	doneAnimation = false;
	delete_start = 0;
	/*if (this->effectType == MARIO_CHANGE_LEVEL_EFFECT)
	{
		delete_start = GetTickCount64();
	}*/
}

void CEffects::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	/*if (delete_start > 0)
	{
		if (GetTickCount64() - delete_start > TIME_MARIO_CHANGING)
			Delete();
	}*/
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CEffects::Render()
{
	if (effectType == UNKNOWN_EFFECT) return;

	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch (effectType)
	{
	case HELP_EFFECT:
		aniId = ID_ANI_HELP_EFFECT;
		break;
	}
	animations->Get(aniId)->Render(x, y);
	//DebugOut(L"Current frame = %d\tFrames size = %d\n", animations->Get(aniId)->GetCurrentFrame(), animations->Get(aniId)->GetFramesSize());
}