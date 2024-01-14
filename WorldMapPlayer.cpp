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
	canMove = true;

	vx = 0;
	vy = 0;
}

void CWorldMapPlayer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CWorldMapPlayer::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CWorldMapPlayer::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CWorldMapNode*>(e->obj))
		OnCollisionWithNode(e);
}

void CWorldMapPlayer::OnCollisionWithNode(LPCOLLISIONEVENT e)
{
	CWorldMapNode* node = dynamic_cast<CWorldMapNode*>(e->obj);
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	x = node->GetX();
	y = node->GetY();
	vx = 0;
	vy = 0;

	string direction = node->GetDirection();

	data->SetAllowGoLeft(direction[0] - '0');
	data->SetAllowGoRight(direction[1] - '0');
	data->SetAllowGoUp(direction[2] - '0');
	data->SetAllowGoDown(direction[3] - '0');

	canMove = true;
	//DebugOut(L">>> %d \t %d \t %d \t %d >>> \n", direction[0] - '0', direction[1] - '0', direction[2] - '0', direction[3] - '0');
	//DebugOut(L">>> %f \t %f >>> \n", node->GetX(), node->GetY());
}

void CWorldMapPlayer::Render()
{
	CDataGame* data = CGame::GetInstance()->GetDataGame();
	int aniId = -1;
	switch (data->GetLevel())
	{
	case MARIO_LEVEL_SMALL:
		aniId = ID_ANI_SMALL_MARIO_WORLD_MAP;
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
		canMove = false;
		break;
	case MARIO_STATE_GO_RIGHT:
		vx = MARIO_SPEED;
		vy = 0.0f;
		canMove = false;
		break;
	case MARIO_STATE_GO_UP:
		vx = 0.0f;
		vy = -MARIO_SPEED;
		canMove = false;
		break;
	case MARIO_STATE_GO_DOWN:
		vx = 0.0f;
		vy = MARIO_SPEED;
		canMove = false;
		break;
	}
	CGameObject::SetState(state);
}