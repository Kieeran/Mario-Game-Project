#pragma once

#include "Scene.h"

class CIntroKeyEventHandler : public CSceneKeyHandler
{
public:
	void KeyState(BYTE* states);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	CIntroKeyEventHandler(LPSCENE s) :CSceneKeyHandler(s) {}
};