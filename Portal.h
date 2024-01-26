#pragma once

#include "GameObject.h"

#define ENTRANCE_PORTAL	1
#define EXIT_PORTAL		2

/*
	Object that triggers scene switching
*/
class CPortal : public CGameObject
{
	int portalType;

	float width;
	float height;
public:
	CPortal(float x, float y, float width, float height, int scene_id);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

	//void RenderBoundingBox(void);

	int GetPortalType() { return portalType; }
	int IsBlocking() { return 0; }
};