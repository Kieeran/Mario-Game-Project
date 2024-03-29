#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "PlayScene.h"

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (mario->GetIsChanging()) return;
	if (mario->GetIsPrepareEndScene()) return;

	switch (KeyCode)
	{
	case DIK_UP:
		if (!mario->GetIsUsePipe() && (mario->GetIsAtPortalExit()))
			mario->SetState(MARIO_STATE_USE_PIPE);
		break;
	case DIK_DOWN:
		if (!mario->GetIsUsePipe() && mario->GetIsAtPortalEntrance())
		{
			mario->SetState(MARIO_STATE_USE_PIPE);
			break;
		}
		if (!mario->GetIsHolding() && mario->GetState() == MARIO_STATE_IDLE &&
			!mario->GetIsTailAttack() && !mario->GetIsTailAttack())
			mario->SetState(MARIO_STATE_SIT);
		break;
	case DIK_S:
		if (mario->GetIsOnPlatform())
			mario->SetState(MARIO_STATE_JUMP);
		else
		{
			if (mario->GetLevel() == MARIO_LEVEL_TAIL)
				mario->SetState(MARIO_STATE_FLY);
		}
		break;
	case DIK_A:
		if (mario->GetLevel() == MARIO_LEVEL_TAIL && !mario->GetIsTailAttack())
		{
			mario->SetState(MARIO_STATE_TAIL_ATTACK);
		}
		break;
	case DIK_1:
		mario->SetLevel(MARIO_LEVEL_SMALL);
		break;
	case DIK_2:
		mario->SetLevel(MARIO_LEVEL_BIG);
		break;
	case DIK_3:
		mario->SetLevel(MARIO_LEVEL_TAIL);
		break;
	case DIK_0:
		mario->SetState(MARIO_STATE_DIE);
		break;
	case DIK_R: // reset
		//Reload();
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	//DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (mario->GetIsChanging()) return;
	if (mario->GetIsPrepareEndScene()) return;

	switch (KeyCode)
	{
	case DIK_S:
		mario->SetState(MARIO_STATE_RELEASE_JUMP);
		break;
	case DIK_DOWN:
		mario->SetState(MARIO_STATE_SIT_RELEASE);
		break;
	case DIK_A:
		if (mario->GetIsHolding())
		{
			mario->SetIsHolding(false);
			//mario->StartKicking();
		}
		break;
	case DIK_LEFT:
		mario->SetState(MARIO_STATE_PHYSICS_MOVE);
		break;
	case DIK_RIGHT:
		mario->SetState(MARIO_STATE_PHYSICS_MOVE);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE* states)
{
	LPGAME game = CGame::GetInstance();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (mario->GetIsChanging()) return;
	if (mario->GetIsPrepareEndScene()) return;

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
	/*else
	{
		if (mario->GetState() != MARIO_STATE_IDLE && !mario->GetMomentumMove())
			mario->SetState(MARIO_STATE_PHYSICS_MOVE);
	}*/
}