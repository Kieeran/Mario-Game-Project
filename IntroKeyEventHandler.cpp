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
	}
}