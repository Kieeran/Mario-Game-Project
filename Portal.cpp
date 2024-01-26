#include "Portal.h"
#include "Game.h"
#include "Textures.h"

CPortal::CPortal(float x, float y, float width, float height, int portalType) :CGameObject(x, y)
{
	this->width = width;
	this->height = height;
	this->portalType = portalType;
}

void CPortal::Render()
{
	RenderBoundingBox();
}

void CPortal::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - width / 2;
	t = y - height / 2;
	r = l + width;
	b = t + height;
}