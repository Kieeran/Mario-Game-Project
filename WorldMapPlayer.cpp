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

void CWorldMapPlayer::OnCollisionWith(LPCOLLISIONEVENT e)
{

}

void CWorldMapPlayer::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_SMALL_MARIO_WORLD_MAP)->Render(x, y);
}

void CWorldMapPlayer::SetState(int state)
{
	CGameObject::SetState(state);
}