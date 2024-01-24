#include "Effects.h"
#include "Playscene.h"

CEffects::CEffects(float x, float y, int effectType) :CGameObject(x, y)
{
	this->effectType = effectType;
	doneAnimation = false;
	delete_start = GetTickCount64();
}

void CEffects::OnNoCollision(DWORD dt)
{
	y += vy * dt;
}

void CEffects::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (effectType >= SCORE_100_EFFECT && effectType <= SCORE_8000_EFFECT)
	{
		vy = -SPEED_EFFECT;
		if (GetTickCount64() - delete_start > TIME_EFFECT_DELETE && delete_start > 0)
		{
			delete_start = 0;
			Delete();
		}
	}

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
	case SCORE_100_EFFECT:
		aniId = ID_ANI_100_SCORES_EFFECT;
		break;
	case SCORE_200_EFFECT:
		aniId = ID_ANI_200_SCORES_EFFECT;
		break;
	case SCORE_400_EFFECT:
		aniId = ID_ANI_400_SCORES_EFFECT;
		break;
	case SCORE_800_EFFECT:
		aniId = ID_ANI_800_SCORES_EFFECT;
		break;
	case SCORE_1000_EFFECT:
		aniId = ID_ANI_1000_SCORES_EFFECT;
		break;
	case SCORE_2000_EFFECT:
		aniId = ID_ANI_2000_SCORES_EFFECT;
		break;
	case SCORE_4000_EFFECT:
		aniId = ID_ANI_4000_SCORES_EFFECT;
		break;
	case SCORE_8000_EFFECT:
		aniId = ID_ANI_8000_SCORES_EFFECT;
		break;
	}
	animations->Get(aniId)->Render(x, y);
}