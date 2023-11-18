#include "FireFlower.h"

CFireFlower::CFireFlower(float x, float y) :CGameObject()
{
	this->x = x;
	this->y = y;
	/*this->SetState(COIN_STATE_NOT_UNBOX);
	this->Origin_Y = y;
	this->collected = false;*/
}
void CFireFlower::Render()
{
	/*CAnimations* animations = CAnimations::GetInstance();
	if (this->coin_type == SHOWED_COIN_TYPE)
	{
		animations->Get(ID_ANI_SHOWED_COIN)->Render(x, y);
	}
	if (this->coin_type == HIDDEN_COIN_TYPE && this->state == COIN_STATE_UNBOXING)
	{
		animations->Get(ID_ANI_HIDDEN_COIN)->Render(x, y);
	}*/
	//RenderBoundingBox();
	CAnimations::GetInstance()->Get(ID_ANI_FIREFLOWER_FACELEFT)->Render(x, y);
}

void CFireFlower::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	/*if (this->coin_type == HIDDEN_COIN_TYPE && this->state == COIN_STATE_UNBOXING)
	{
		y += vy * dt;
		if (y <= this->Origin_Y - COIN_BOUNCING_HEIGHT_MAX)
		{
			vy *= -1;
		}
		if (y >= this->Origin_Y)
		{
			this->collected = true;
		}
	}
	if (this->collected)
		this->Delete();*/
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFireFlower::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FIREFLOWER_BBOX_WIDTH / 2;
	t = y - FIREFLOWER_BBOX_HEIGHT / 2;
	r = l + FIREFLOWER_BBOX_WIDTH;
	b = t + FIREFLOWER_BBOX_HEIGHT;
}
void CFireFlower::SetState(int state)
{
	/*CGameObject::SetState(state);
	switch (state)
	{
	case COIN_STATE_UNBOXING:
		vy = -COIN_BOUCING_SPEED;
		break;
	}*/
}