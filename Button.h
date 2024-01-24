#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

#define BUTTON_BBOX_WIDTH 16
#define BUTTON_BBOX_HEIGHT 16

class CButton : public CGameObject
{
protected:
	float Origin_X;
	float Origin_Y;

	bool isPressed;

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsCollidable() { return 1; }

public:
	CButton(float x, float y);

	bool GetIsPressed() { return isPressed; }
	void SetIsPressed(bool b) { isPressed = b; }
};