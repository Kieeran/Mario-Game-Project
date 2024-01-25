#include "WorldMapKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "WorldMapScene.h"
#include "WorldMapPlayer.h"

void CWorldMapKeyEventHandler::OnKeyDown(int KeyCode)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	CWorldMapPlayer* mario = (CWorldMapPlayer*)((LPWORLDMAPSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (!mario->GetCanMove())return;

	CDataGame* data = CGame::GetInstance()->GetDataGame();
	switch (KeyCode)
	{
	case DIK_LEFT:
		if (data->GetAllowGoLeft())
			mario->SetState(MARIO_STATE_GO_LEFT);
		break;
	case DIK_RIGHT:
		if (data->GetAllowGoRight())
			mario->SetState(MARIO_STATE_GO_RIGHT);
		break;
	case DIK_UP:
		if (data->GetAllowGoUp())
			mario->SetState(MARIO_STATE_GO_UP);
		break;
	case DIK_DOWN:
		if (data->GetAllowGoDown())
			mario->SetState(MARIO_STATE_GO_DOWN);
		break;
	case DIK_S:
		CGame::GetInstance()->InitiateSwitchScene(TYPE_WORLD_PLAY);
		break;
	case DIK_ESCAPE:
		CGame::GetInstance()->InitiateSwitchScene(TYPE_WORLD_INTRO);
		break;
	}
}

void CWorldMapKeyEventHandler::OnKeyUp(int KeyCode)
{
	//DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);

	//CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	//switch (KeyCode)
	//{
	//case DIK_S:
	//	mario->SetState(MARIO_STATE_RELEASE_JUMP);
	//	break;
	//case DIK_DOWN:
	//	mario->SetState(MARIO_STATE_SIT_RELEASE);
	//	break;
	//case DIK_A:
	//	if (mario->GetIsHolding())
	//	{
	//		mario->SetIsHolding(false);
	//		//mario->StartKicking();
	//	}
	//	break;
	//}
}

void CWorldMapKeyEventHandler::KeyState(BYTE* states)
{
	/*LPGAME game = CGame::GetInstance();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(MARIO_STATE_RUNNING_RIGHT);
		else
			mario->SetState(MARIO_STATE_WALKING_RIGHT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(MARIO_STATE_RUNNING_LEFT);
		else
			mario->SetState(MARIO_STATE_WALKING_LEFT);
	}
	else
		mario->SetState(MARIO_STATE_IDLE);*/
}