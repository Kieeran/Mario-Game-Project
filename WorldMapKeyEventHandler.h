#pragma once

#include "Scene.h"

class CWorldMapKeyEventHandler : public CSceneKeyHandler
{
public:
	void KeyState(BYTE* states);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	CWorldMapKeyEventHandler(LPSCENE s) :CSceneKeyHandler(s) {}
};