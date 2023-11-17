#include "Coin.h"
#include "MysBox.h"

CCoin::CCoin(float x, float y, int coin_type) :CGameObject()
{
	this->x = x;
	this->y = y;
	this->coin_type = coin_type;
	this->SetState(COIN_STATE_NOT_UNBOX);
	this->Origin_Y = y;
	this->collected = false;
}
void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->coin_type == SHOWED_COIN_TYPE)
	{
		animations->Get(ID_ANI_SHOWED_COIN)->Render(x, y);
	}
	if (this->coin_type == HIDDEN_COIN_TYPE && this->state == COIN_STATE_UNBOXING)
	{
		animations->Get(ID_ANI_HIDDEN_COIN)->Render(x, y);
	}
	//RenderBoundingBox();
}

void CCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->coin_type == HIDDEN_COIN_TYPE && this->state == COIN_STATE_UNBOXING)
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
		this->Delete();
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}
void CCoin::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case COIN_STATE_UNBOXING:
		vy = -COIN_BOUCING_SPEED;
		break;
	}
}