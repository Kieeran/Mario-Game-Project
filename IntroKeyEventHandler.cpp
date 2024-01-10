#include "IntroKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "IntroScene.h"

void CIntroKeyEventHandler::OnKeyDown(int KeyCode)
{
	CIntroObjects* arrow = (CIntroObjects*)((LPINTROSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch (KeyCode)
	{
	case DIK_Q:
		arrow->SetIsOnePlayer(!arrow->GetIsOnePlayer());
		break;
	case DIK_W:
		CGame::GetInstance()->InitiateSwitchScene(TYPE_WORLD_MAP);
		break;
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
	}
}