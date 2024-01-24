#include "Brick.h"
#include "Button.h"
#include "Coin.h"

#include "Playscene.h"

CBrick::CBrick(float x, float y, int brickType) : CGameObject(x, y)
{
	this->brickType = brickType;

	isBroken = false;
	isUnboxed = false;
	isGold = false;
	SetState(BRICK_STATE_NORMAL);
}

void CBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (state != BRICK_STATE_NORMAL_FOREVER && state != BRICK_STATE_DELETE)
	{
		if (isUnboxed)
		{
			if (brickType == BRICK_WITH_BUTTON)
			{
				CButton* button = new CButton(x, y - 16.0f);
				scene->AddObject(button, mario->GetIndex());
			}

			isUnboxed = false;
		}
		else
		{
			for (size_t i = 0; i < scene->GetListObject().size(); i++)
			{
				if (dynamic_cast<CButton*>(scene->GetListObject()[i]))
				{
					//DebugOut(L"BUTTON\n");
					CButton* button = dynamic_cast<CButton*>(scene->GetListObject()[i]);
					if (button->GetIsPressed() && brickType == NORMAL_BRICK)
						SetState(BRICK_STATE_GOLD);
				}
			}
		}

		if (isGold)
		{
			CCoin* coin = new CCoin(x, y);
			coin->SetIsMoving(false);
			coin->SetWaitingTime(GetTickCount64());
			scene->AddObject(coin, mario->GetIndex());
			Delete();
			isGold = false;
		}
	}

	if (isBroken)
	{
		Delete();
		isBroken = false;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CBrick::Render()
{
	if (state == BRICK_STATE_NORMAL || state == BRICK_STATE_NORMAL_FOREVER)
		CAnimations::GetInstance()->Get(ID_ANI_BRICK)->Render(x, y);
	else
		CAnimations::GetInstance()->Get(ID_ANI_BRICK_UNBOXED)->Render(x, y);
	//RenderBoundingBox();
}

void CBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BRICK_BBOX_WIDTH / 2;
	t = y - BRICK_BBOX_HEIGHT / 2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}

void CBrick::SetState(int state)
{
	switch (state)
	{
	case BRICK_STATE_UNBOXED:
		isUnboxed = true;
		break;

	case BRICK_STATE_GOLD:
		isGold = true;
		break;

	case BRICK_STATE_DELETE:
		isBroken = true;
		break;
	}
	CGameObject::SetState(state);
}