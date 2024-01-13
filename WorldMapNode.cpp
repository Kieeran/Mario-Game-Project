#include "WorldMapNode.h"

CWorldMapNode::CWorldMapNode(float x, float y, string Direction) : CGameObject(x, y)
{
	this->Direction = Direction;
}
void CWorldMapNode::Render()
{
	RenderBoundingBox();
}

void CWorldMapNode::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - NODE_BBOX_WIDTH / 2;
	t = y - NODE_BBOX_HEIGHT / 2;
	r = l + NODE_BBOX_WIDTH;
	b = t + NODE_BBOX_HEIGHT;
}