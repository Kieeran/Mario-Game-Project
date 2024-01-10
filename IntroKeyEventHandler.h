#pragma once

#include "Scene.h"
#include "IntroObjects.h"

class CIntroKeyEventHandler : public CSceneKeyHandler
{
public:
	void OnKeyDown(int KeyCode);
	void KeyState(BYTE* states) {}
	void OnKeyUp(int KeyCode) {}
	CIntroKeyEventHandler(LPSCENE s) :CSceneKeyHandler(s) {}
};