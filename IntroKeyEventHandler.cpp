#include "IntroKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "IntroScene.h"

void CIntroKeyEventHandler::OnKeyDown(int KeyCode)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	//CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	//switch (KeyCode)
	//{
	//case DIK_DOWN:
	//	if (!mario->GetIsHolding() && mario->GetState() == MARIO_STATE_IDLE)
	//		mario->SetState(MARIO_STATE_SIT);
	//	break;
	//case DIK_S:
	//	mario->SetState(MARIO_STATE_JUMP);
	//	break;
	//case DIK_1:
	//	mario->SetLevel(MARIO_LEVEL_SMALL);
	//	break;
	//case DIK_2:
	//	mario->SetLevel(MARIO_LEVEL_BIG);
	//	break;
	//case DIK_3:
	//	mario->SetLevel(MARIO_LEVEL_TAIL);
	//	break;
	//case DIK_0:
	//	mario->SetState(MARIO_STATE_DIE);
	//	break;
	//case DIK_R: // reset
	//	//Reload();
	//	break;
	//}
}

void CIntroKeyEventHandler::OnKeyUp(int KeyCode)
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

void CIntroKeyEventHandler::KeyState(BYTE* states)
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