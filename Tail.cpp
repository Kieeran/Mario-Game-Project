#include "Tail.h"
#include "Goomba.h"
#include "MysBox.h"
#include "PiranhaPlant.h"
#include "Koopas.h"
#include "Mushroom.h"
#include "Leaf.h"
#include "Brick.h"

CTail::CTail(float x, float y) :CGameObject(x, y)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (mario->GetNX() > 0)
		vx = TAIL_SPEED;
	else
		vx = -TAIL_SPEED;
	Origin_X = x;
	ax = 0;
}

void CTail::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	if (abs(x - Origin_X) > 8.0f)
	{
		Delete();
		//vx = 0;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CTail::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TAIL_BBOX_WIDTH / 2;
	t = y - TAIL_BBOX_HEIGHT / 2;
	r = l + TAIL_BBOX_WIDTH;
	b = t + TAIL_BBOX_HEIGHT;
}

void CTail::OnNoCollision(DWORD dt)
{
	x += vx * dt;
}

void CTail::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0)return;

	if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
	else if (dynamic_cast<CMysBox*>(e->obj))
		OnCollisionWithMysBox(e);
	else if (dynamic_cast<CPiranhaPlant*>(e->obj))
		OnCollisionWithPiranhaPlant(e);
	else if (dynamic_cast<CKoopas*>(e->obj))
		OnCollisionWithKoopas(e);
	else if (dynamic_cast<CBrick*>(e->obj))
		OnCollisionWithBrick(e);

	Delete();
}

void CTail::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

	if (goomba->GetState() != GOOMBA_STATE_DIE)
		goomba->SetState(GOOMBA_STATE_DIE_UPSIDE_DOWN);
}
void CTail::OnCollisionWithMysBox(LPCOLLISIONEVENT e)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMysBox* mysbox = dynamic_cast<CMysBox*>(e->obj);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (mysbox->GetState() == MYSBOX_STATE_CARRY_ITEMS)
	{
		mysbox->SetState(MYSBOX_STATE_EMPTY);
		int itemType = mysbox->GetItemType();
		CGameObject* item = NULL;
		switch (itemType)
		{
		case COIN:
			item = new CCoin(mysbox->GetX(), mysbox->GetY(), HIDDEN_COIN_TYPE);
			scene->AddObject(item);
			mario->SetCoinNum(mario->GetCoinNum() + 1);
			break;
		case ITEMS:
			if (mario->GetLevel() == MARIO_LEVEL_SMALL)
			{
				item = new CMushroom(mysbox->GetX(), mysbox->GetY(), mysbox->GetMushroomType());
				scene->AddObject(item, mysbox->GetIndex());
			}
			else
			{
				item = new CLeaf(mysbox->GetX(), mysbox->GetY());
				scene->AddObject(item, ADD_OBJECT_BACK);
			}
			break;
		}
	}
}

void CTail::OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e)
{
	
}

void CTail::OnCollisionWithKoopas(LPCOLLISIONEVENT e)
{

}

void CTail::OnCollisionWithBrick(LPCOLLISIONEVENT e)
{
	CBrick* brick = dynamic_cast<CBrick*>(e->obj);

	if (brick->GetBrickType() == NORMAL_BRICK)
		brick->SetState(BRICK_STATE_DELETE);
	else
		brick->SetState(BRICK_STATE_UNBOXED);
}