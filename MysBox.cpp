#include "MysBox.h"
#include "PlayScene.h"

CMysBox::CMysBox(float x, float y, int itemType, int index, int mushroomType) :CGameObject()
{
	this->itemType = itemType;
	this->index = index;
	this->mushroomType = mushroomType;

	ay = MYSBOX_GRAVITY;
	Unbox = true;
	Origin_Y = y;
	SetState(MYSBOX_STATE_CARRY_ITEMS);
}

void CMysBox::Render()
{
	int aniId = ID_ANI_MYSBOX_CARRY_OBJECT;
	if (state == MYSBOX_STATE_EMPTY)
	{
		aniId = ID_ANI_MYSBOX_EMPTY;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}

void CMysBox::OnNoCollision(DWORD dt)
{
	y += vy * dt;
}

void CMysBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->GetState() == MYSBOX_STATE_EMPTY && this->Unbox)
	{
		vy += ay * dt;
		if (y > this->Origin_Y)
		{
			y = this->Origin_Y;
			vy = 0;
			ay = 0;
			this->Unbox = false;
		}
	}
	//if (!this->Unbox && y != this->Origin_Y)
	//	y = this->Origin_Y;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMysBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - MYSBOX_BBOX_WIDTH / 2;
	t = y - MYSBOX_BBOX_HEIGHT / 2;
	r = l + MYSBOX_BBOX_WIDTH;
	b = t + MYSBOX_BBOX_HEIGHT;
}

void CMysBox::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case MYSBOX_STATE_EMPTY:
		vy = -MYSBOX_BOUCING_SPEED;
		break;
	}
}