#pragma once

#include "Scene.h"

class CWorldMapKeyEventHandler : public CSceneKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CWorldMapKeyEventHandler(LPSCENE s) :CSceneKeyHandler(s) {}
};