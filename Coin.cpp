#include "Coin.h"
#include "debug.h"

CCoin::CCoin(float x, float y, int coin_type) :CGameObject()
{
	this->x = x;
	this->y = y;
	this->coin_type = coin_type;
	ay = COIN_GRAVITY;
	vy = 0;
	if (coin_type == HIDDEN_COIN_TYPE)
		vy = -COIN_BOUCING_SPEED;
	Origin_Y = y;

	isMoving = true;
}
void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (coin_type == SHOWED_COIN_TYPE)
	{
		if (isMoving)
			animations->Get(ID_ANI_SHOWED_COIN)->Render(x, y);
		else
			CSprites::GetInstance()->Get(ID_SPRITE_SHOWED_COIN_1)->Draw(x, y);
	}
	else if (coin_type == HIDDEN_COIN_TYPE)
	{
		animations->Get(ID_ANI_HIDDEN_COIN)->Render(x, y);
	}
	//RenderBoundingBox();
}

void CCoin::OnNoCollision(DWORD dt)
{
	if (coin_type == HIDDEN_COIN_TYPE)
		y += vy * dt;
}

void CCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (coin_type == HIDDEN_COIN_TYPE)
	{
		vy += ay * dt;
		if (y > Origin_Y)
			Delete();
	}

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