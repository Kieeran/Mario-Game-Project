#include <algorithm>
#include "debug.h"

#include "WorldMapPlayer.h"
#include "Game.h"

#include "Collision.h"
CWorldMapPlayer::CWorldMapPlayer(float x, float y) :CGameObject(x, y)
{
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	isAllowGoLeft = data->GetAllowGoLeft();
	isAllowGoRight = data->GetAllowGoRight();
	isAllowGoUp = data->GetAllowGoUp();
	isAllowGoDown = data->GetAllowGoDown();

	vx = 0;
	vy = 0;
}

void CWorldMapPlayer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CWorldMapPlayer::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CWorldMapPlayer::Render()
{
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	int aniId = -1;
	switch (data->GetLevel())
	{
	case MARIO_LEVEL_SMALL:
		aniId = 60250;
		break;
	case MARIO_LEVEL_BIG:
		aniId = ID_ANI_BIG_MARIO_WORLD_MAP;
		break;
	case MARIO_LEVEL_TAIL:
		aniId = ID_ANI_TAIL_MARIO_WORLD_MAP;
		break;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CWorldMapPlayer::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MARIO_BBOX_WIDTH / 2;
	t = y - MARIO_BBOX_HEIGHT / 2;
	r = l + MARIO_BBOX_WIDTH;
	b = t + MARIO_BBOX_HEIGHT;
}

void CWorldMapPlayer::SetState(int state)
{
	switch (state)
	{
	case MARIO_STATE_GO_LEFT:
		vx = -MARIO_SPEED;
		vy = 0.0f;
		break;
	case MARIO_STATE_GO_RIGHT:
		vx = MARIO_SPEED;
		vy = 0.0f;
		break;
	case MARIO_STATE_GO_UP:
		vx = 0.0f;
		vy = -MARIO_SPEED;
		break;
	case MARIO_STATE_GO_DOWN:
		vx = 0.0f;
		vy = MARIO_SPEED;
		break;
	}
	CGameObject::SetState(state);
}