#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#include "Coin.h"
#include "Portal.h"
#include "MysBox.h"
#include "Mushroom.h"
#include "PiranhaPlant.h"
#include "FireBullet.h"
#include "Koopas.h"
#include "Leaf.h"

#include "Collision.h"
CMario::CMario(float x, float y) :CGameObject(x, y)
{
	CDataGame* dataGame = CGame::GetInstance()->GetDataGame();

	isSitting = false;
	maxVx = 0.0f;
	ax = 0.0f;
	ay = MARIO_GRAVITY;

	tail = NULL;
	level = dataGame->GetLevel();

	untouchable_start = 0;
	untouchable = 0;
	kick_start = 0;
	hold_start = 0;
	tail_attack_start = 0;

	coin = 0;

	isOnPlatform = false;
	isHolding = false;
	isKicking = false;
	isRunning = false;
	isTailAttack = false;
	isChanging = false;
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

	//avoid mario from droping out of the world at the left edge at the beginning of the stage
	if (x < 20.0f) x = 20.0f;

	if (isChanging)
	{
		vx = 0;
		vy = 0;
	}
	else
	{
		vy += ay * dt;
		vx += ax * dt;
	}

	//*
	if (!isOnPlatform)
	{
		ax = 0;
	}

	if (abs(vx) > abs(maxVx)) vx = maxVx;

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount64() - untouchable_start > MARIO_UNTOUCHABLE_TIME && untouchable_start > 0)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	if (GetTickCount64() - kick_start > TIME_KICK_ANIMATION && kick_start > 0)
	{
		isKicking = false;
		kick_start = 0;
	}

	if (GetTickCount64() - tail_attack_start > TIME_TAIL_ATTACK && tail_attack_start > 0)
	{
		isTailAttack = false;
		tail_attack_start = 0;
	}

	isOnPlatform = false;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMario::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CMario::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = 0;
	}

	if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
	else if (dynamic_cast<CCoin*>(e->obj))
		OnCollisionWithCoin(e);
	else if (dynamic_cast<CPortal*>(e->obj))
		OnCollisionWithPortal(e);
	else if (dynamic_cast<CMysBox*>(e->obj))
		OnCollisionWithMysBox(e);
	else if (dynamic_cast<CLeaf*>(e->obj))
		OnCollisionWithLeaf(e);
	else if (dynamic_cast<CMushroom*>(e->obj))
		OnCollisionWithMushroom(e);
	else if (dynamic_cast<CPiranhaPlant*>(e->obj))
		OnCollisionWithPiranhaPlant(e);
	else if (dynamic_cast<CFireBullet*>(e->obj))
		OnCollisionWithFireBullet(e);
	else if (dynamic_cast<CKoopas*>(e->obj))
		OnCollisionWithKoopas(e);
}

void CMario::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (e->ny >= 0)// hit by Goomba
	{
		SetLevelLower();
		/*if (untouchable == 0)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				if (level > MARIO_LEVEL_SMALL)
				{
					level = MARIO_LEVEL_SMALL;
					StartUntouchable();
				}
				else
				{
					DebugOut(L">>> Mario DIE >>> \n");
					SetState(MARIO_STATE_DIE);
				}
			}
		}*/
	}
	else
	{
		// jump on top >> kill Goomba and deflect a bit 
		if (goomba->GetGoombaType() == GOOMBA_TYPE_YELLOW)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				goomba->SetState(GOOMBA_STATE_DIE);
				vy = -MARIO_JUMP_DEFLECT_SPEED;
			}
		}
		else
		{
			if (goomba->GetStateWing())
			{
				goomba->SetStateWing(false);
				goomba->SetState(GOOMBA_STATE_WALKING);
				vy = -MARIO_JUMP_DEFLECT_SPEED;
			}
			else if (goomba->GetState() == GOOMBA_STATE_WALKING)
			{
				if (goomba->GetState() != GOOMBA_STATE_DIE)
				{
					goomba->SetState(GOOMBA_STATE_DIE);
					vy = -MARIO_JUMP_DEFLECT_SPEED;
				}
			}
		}
	}
}

void CMario::OnCollisionWithKoopas(LPCOLLISIONEVENT e)
{
	CKoopas* koopas = dynamic_cast<CKoopas*>(e->obj);

	if (e->ny < 0)	//collision from top to bottom
	{
		if (koopas->GetState() == KOOPAS_STATE_FLYING)
		{
			koopas->SetState(KOOPAS_STATE_WALKING);
			koopas->SetY(koopas->GetY() - 2.0f);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
		else if (koopas->GetState() == KOOPAS_STATE_WALKING)
		{
			koopas->SetState(KOOPAS_STATE_HIDING);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
		else if (koopas->GetState() == KOOPAS_STATE_HIDING || koopas->GetState() == KOOPAS_STATE_SHAKING)
		{
			koopas->SetState(KOOPAS_STATE_ROLLING);
			koopas->SetY(koopas->GetY() - 2.0f);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
	}
	else if (e->ny > 0)
	{
		SetLevelLower();
	}
	else if (e->nx != 0)	//collision from left to right or from right to left
	{
		if (untouchable == 0)
		{
			if (koopas->GetState() == KOOPAS_STATE_WALKING || koopas->GetState() == KOOPAS_STATE_ROLLING ||
				koopas->GetState() == KOOPAS_STATE_FLYING)
			{
				SetLevelLower();
			}
			else if (koopas->GetState() == KOOPAS_STATE_HIDING || koopas->GetState() == KOOPAS_STATE_SHAKING)
			{
				if (!isRunning)
				{
					koopas->SetIsHeld(false);
					StartKicking();
					koopas->SetState(KOOPAS_STATE_ROLLING);
				}
				else
				{
					isHolding = true;
					koopas->SetIsHeld(true);
					hold_start = GetTickCount64();
				}
			}
		}
	}
}

void CMario::OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e)
{
	if (untouchable == 0)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			level = MARIO_LEVEL_SMALL;
			StartUntouchable();
		}
		else
		{
			DebugOut(L">>> Mario DIE >>> \n");
			SetState(MARIO_STATE_DIE);
		}
	}
}

void CMario::OnCollisionWithFireBullet(LPCOLLISIONEVENT e)
{
	if (untouchable == 0)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			level = MARIO_LEVEL_SMALL;
			StartUntouchable();
		}
		else
		{
			DebugOut(L">>> Mario DIE >>> \n");
			SetState(MARIO_STATE_DIE);
		}
	}
}

void CMario::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
	DebugOut(L">>> Show coin delete >>> \n");
	coin++;
}

void CMario::OnCollisionWithLeaf(LPCOLLISIONEVENT e)
{
	SetLevel(MARIO_LEVEL_TAIL);
	e->obj->Delete();
}

void CMario::OnCollisionWithMushroom(LPCOLLISIONEVENT e)
{
	SetLevel(MARIO_LEVEL_BIG);
	e->obj->Delete();
}

void CMario::OnCollisionWithMysBox(LPCOLLISIONEVENT e)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMysBox* mysbox = dynamic_cast<CMysBox*>(e->obj);

	//jump and hit the bottom of the box
	if (e->ny > 0)
	{
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
				coin++;
				break;
			case ITEMS:
				if (level == MARIO_LEVEL_SMALL)
				{
					item = new CMushroom(mysbox->GetX(), mysbox->GetY());
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
}

void CMario::OnCollisionWithPortal(LPCOLLISIONEVENT e)
{
	CPortal* p = (CPortal*)e->obj;
	CGame::GetInstance()->InitiateSwitchScene(p->GetSceneId());
}

void CMario::SetLevelLower()
{
	if (level == MARIO_LEVEL_TAIL)
	{
		level = MARIO_LEVEL_BIG;
		StartUntouchable();
	}
	else if (level == MARIO_LEVEL_BIG)
	{
		level = MARIO_LEVEL_SMALL;
		StartUntouchable();
	}
	else
	{
		DebugOut(L">>> Mario DIE >>> \n");
		SetState(MARIO_STATE_DIE);
	}
}

//
// Get animation ID for tail Mario
//
int CMario::GetAniIdTail()
{
	int aniId = -1;
	if (!isOnPlatform)
	{
		if (!isHolding)
		{
			if (vy < 0)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_JUMPING_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_JUMPING_LEFT;
			}
			else
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_LANDING_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_LANDING_LEFT;
			}


			/*if (abs(ax) == MARIO_ACCEL_RUN_X)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT;
			}
			else
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT;
			}*/
		}
		else
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_TAIL_HOLDING_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_TAIL_HOLDING_JUMP_LEFT;
		}
	}
	else
	{
		if (!isHolding)
		{
			if (isSitting)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_SITTING_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_SITTING_LEFT;
			}
			else
			{
				if (vx == 0)
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_TAIL_IDLING_RIGHT;
					else
						aniId = ID_ANI_MARIO_TAIL_IDLING_LEFT;
				}
				else if (vx > 0)
				{
					if (ax < 0)
						aniId = ID_ANI_MARIO_TAIL_BRACING_RIGHT;
					else if (ax == MARIO_ACCEL_RUN_X)
						aniId = ID_ANI_MARIO_TAIL_RUNNING_RIGHT;
					else if (ax == MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_TAIL_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_TAIL_BRACING_LEFT;
					else if (ax == -MARIO_ACCEL_RUN_X)
						aniId = ID_ANI_MARIO_TAIL_RUNNING_LEFT;
					else if (ax == -MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_TAIL_WALKING_LEFT;
				}
			}
		}
		else
		{
			if (vx == 0)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_HOLDING_IDLE_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_HOLDING_IDLE_LEFT;
			}
			else
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_TAIL_HOLDING_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_TAIL_HOLDING_RUN_LEFT;
			}
		}
	}

	if (isTailAttack)
	{
		if (nx > 0)
			aniId = ID_ANI_MARIO_TAIL_ATTACKING_RIGHT;
		else
			aniId = ID_ANI_MARIO_TAIL_ATTACKING_LEFT;
	}

	if (isKicking)
	{
		if (nx > 0)
			aniId = ID_ANI_MARIO_TAIL_KICKING_RIGHT;
		else
			aniId = ID_ANI_MARIO_TAIL_KICKING_LEFT;
	}

	if (aniId == -1)
	{
		if (nx > 0)
			aniId = ID_ANI_MARIO_TAIL_ATTACKING_RIGHT;
		else
			aniId = ID_ANI_MARIO_TAIL_ATTACKING_LEFT;
	}

	return aniId;
}

//
// Get animdation ID for big Mario
//
int CMario::GetAniIdBig()
{
	int aniId = -1;
	if (!isOnPlatform)
	{
		if (!isHolding)
		{
			if (abs(ax) == MARIO_ACCEL_RUN_X)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_BIG_JUMP_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_BIG_JUMP_RUN_LEFT;
			}
			else
			{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_BIG_JUMP_WALK_RIGHT;
				else
					aniId = ID_ANI_MARIO_BIG_JUMP_WALK_LEFT;
			}
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_BIG_HOLD_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_BIG_HOLD_JUMP_LEFT;
		}

	}
	else
	{
		if (!isHolding)
		{
			if (isSitting)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_BIG_SIT_RIGHT;
				else
					aniId = ID_ANI_MARIO_BIG_SIT_LEFT;
			}
			else
			{
				if (vx == 0)
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_BIG_IDLE_RIGHT;
					else
						aniId = ID_ANI_MARIO_BIG_IDLE_LEFT;
				}
				else if (vx > 0)
				{
					if (ax < 0)
						aniId = ID_ANI_MARIO_BIG_BRACE_RIGHT;
					else if (ax == MARIO_ACCEL_RUN_X)
						aniId = ID_ANI_MARIO_BIG_RUNNING_RIGHT;
					else if (ax == MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_BIG_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_BIG_BRACE_LEFT;
					else if (ax == -MARIO_ACCEL_RUN_X)
						aniId = ID_ANI_MARIO_BIG_RUNNING_LEFT;
					else if (ax == -MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_BIG_WALKING_LEFT;
				}
			}
		}
		else
		{
			if (vx == 0)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_BIG_HOLD_IDLE_RIGHT;
				else
					aniId = ID_ANI_MARIO_BIG_HOLD_IDLE_LEFT;
			}
			else
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_BIG_HOLD_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_BIG_HOLD_RUN_LEFT;
			}
		}

	}

	if (isKicking)
	{
		if (nx > 0)
			aniId = ID_ANI_MARIO_BIG_KICK_RIGHT;
		else
			aniId = ID_ANI_MARIO_BIG_KICK_LEFT;
	}

	if (aniId == -1) aniId = ID_ANI_MARIO_BIG_IDLE_RIGHT;

	return aniId;
}

//
// Get animation ID for small Mario
//
int CMario::GetAniIdSmall()
{
	int aniId = -1;
	if (!isOnPlatform)
	{
		if (!isHolding)
		{
			//if (abs(ax) == MARIO_ACCEL_RUN_X)
			if (abs(vx) >= MAX_MARIO_RUNNING_SPEED)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT;
			}
			else
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT;
				else
					aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT;
			}
		}
		else
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_HOLD_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_HOLD_JUMP_LEFT;
		}

	}
	else	// Is on platform
	{
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_BIG_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_BIG_SIT_LEFT;
		}
		else
		{
			if (!isHolding)
			{
				if (vx == 0)
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
					else
						aniId = ID_ANI_MARIO_SMALL_IDLE_LEFT;
				}
				else if (vx > 0)
				{
					if (ax < 0)
						aniId = ID_ANI_MARIO_SMALL_BRACE_RIGHT;
					//else if (ax == MARIO_ACCEL_RUN_X)
					else if (abs(vx) >= MAX_MARIO_RUNNING_SPEED)
						aniId = ID_ANI_MARIO_SMALL_RUNNING_RIGHT;
					//else if (ax == MARIO_ACCEL_WALK_X)
					else
						aniId = ID_ANI_MARIO_SMALL_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_SMALL_BRACE_LEFT;
					//else if (ax == -MARIO_ACCEL_RUN_X)
					else if (abs(vx) >= MAX_MARIO_RUNNING_SPEED)
						aniId = ID_ANI_MARIO_SMALL_RUNNING_LEFT;
					//else if (ax == -MARIO_ACCEL_WALK_X)
					else
						aniId = ID_ANI_MARIO_SMALL_WALKING_LEFT;
				}
			}
			else
			{
				if (vx == 0)
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_SMALL_HOLD_IDLE_RIGHT;
					else
						aniId = ID_ANI_MARIO_SMALL_HOLD_IDLE_LEFT;
				}
				else
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_SMALL_HOLD_RUN_RIGHT;
					else
						aniId = ID_ANI_MARIO_SMALL_HOLD_RUN_LEFT;
				}
			}
		}
	}

	if (isKicking)
	{
		if (nx > 0)
			aniId = ID_ANI_MARIO_SMALL_KICK_RIGHT;
		else
			aniId = ID_ANI_MARIO_SMALL_KICK_LEFT;
	}

	if (aniId == -1) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;

	return aniId;
}

void CMario::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (state == MARIO_STATE_DIE)
		aniId = ID_ANI_MARIO_DIE;

	else if (level == MARIO_LEVEL_TAIL)
		aniId = GetAniIdTail();

	else if (level == MARIO_LEVEL_BIG)
		aniId = GetAniIdBig();

	else if (level == MARIO_LEVEL_SMALL)
		aniId = GetAniIdSmall();

	if (!isChanging)
		animations->Get(aniId)->Render(x, y);

	//RenderBoundingBox();

	DebugOutTitle(L"X = %f \t Y = %f \t VX =  %f \t VY = %f", x, y, vx, vy);
}

void CMario::SetState(int state)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();

	// DIE is the end state, cannot be changed! 
	if (this->state == MARIO_STATE_DIE) return;

	switch (state)
	{
	case MARIO_STATE_RUNNING_RIGHT:
		if (isSitting) break;
		maxVx = MAX_MARIO_RUNNING_SPEED;
		ax = MARIO_ACCEL_RUN_X;
		isRunning = true;
		nx = 1;
		break;
	case MARIO_STATE_RUNNING_LEFT:
		if (isSitting) break;
		maxVx = -MAX_MARIO_RUNNING_SPEED;
		ax = -MARIO_ACCEL_RUN_X;
		isRunning = true;
		nx = -1;
		break;
	case MARIO_STATE_WALKING_RIGHT:
		if (isSitting) break;
		maxVx = MAX_MARIO_WALKING_SPEED;
		ax = MARIO_ACCEL_WALK_X;
		isRunning = false;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT:
		if (isSitting) break;
		maxVx = -MAX_MARIO_WALKING_SPEED;
		ax = -MARIO_ACCEL_WALK_X;
		isRunning = false;
		nx = -1;
		break;
	case MARIO_STATE_JUMP:
		if (isSitting) break;
		if (isOnPlatform)
		{
			if (abs(this->vx) == MAX_MARIO_RUNNING_SPEED)
				vy = -MARIO_JUMP_RUN_SPEED_Y;
			else
				vy = -MARIO_JUMP_SPEED_Y;
		}
		break;

	case MARIO_STATE_RELEASE_JUMP:
		if (vy < 0)
			vy += MARIO_JUMP_SPEED_Y / 2;
		isRunning = false;
		break;

	case MARIO_STATE_TAIL_ATTACK:
		isTailAttack = true;
		tail_attack_start = GetTickCount64();
		tail = new CTail(x, y + 7.0f);
		scene->AddObject(tail, ADD_OBJECT_BACK);
		break;

	case MARIO_STATE_SIT:
		if (isOnPlatform && level != MARIO_LEVEL_SMALL)
		{
			state = MARIO_STATE_IDLE;
			isSitting = true;
			isRunning = false;
			vx = 0; vy = 0.0f;
			y += MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_SIT_RELEASE:
		if (isSitting)
		{
			isSitting = false;
			state = MARIO_STATE_IDLE;
			y -= MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;

	case MARIO_STATE_DIE:
		vy = -MARIO_JUMP_DEFLECT_SPEED;
		vx = 0;
		ax = 0;
		break;
	}

	CGameObject::SetState(state);
}

void CMario::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (level == MARIO_LEVEL_TAIL)
	{
		if (nx > 0)
		{
			if (isSitting)
			{
				left = x - MARIO_TAIL_SITTING_BBOX_WIDTH / 2;
				top = y - MARIO_TAIL_SITTING_BBOX_HEIGHT / 2;
				right = left + MARIO_TAIL_SITTING_BBOX_WIDTH;
				bottom = top + MARIO_TAIL_SITTING_BBOX_HEIGHT;
			}
			else
			{
				left = x - MARIO_TAIL_BBOX_WIDTH / 2;
				top = y - MARIO_TAIL_BBOX_HEIGHT / 2;
				right = left + MARIO_TAIL_BBOX_WIDTH;
				bottom = top + MARIO_TAIL_BBOX_HEIGHT;
			}
		}
		else
		{
			if (isSitting)
			{
				left = x - MARIO_TAIL_SITTING_BBOX_WIDTH / 2;
				top = y - MARIO_TAIL_SITTING_BBOX_HEIGHT / 2;
				right = left + MARIO_TAIL_SITTING_BBOX_WIDTH;
				bottom = top + MARIO_TAIL_SITTING_BBOX_HEIGHT;
			}
			else
			{
				left = x - MARIO_TAIL_BBOX_WIDTH / 2;
				top = y - MARIO_TAIL_BBOX_HEIGHT / 2;
				right = left + MARIO_TAIL_BBOX_WIDTH;
				bottom = top + MARIO_TAIL_BBOX_HEIGHT;
			}
		}
	}

	else if (level == MARIO_LEVEL_BIG)
	{
		if (isSitting)
		{
			left = x - MARIO_BIG_SITTING_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_SITTING_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_SITTING_BBOX_WIDTH;
			bottom = top + MARIO_BIG_SITTING_BBOX_HEIGHT;
		}
		else
		{
			left = x - MARIO_BIG_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_BBOX_WIDTH;
			bottom = top + MARIO_BIG_BBOX_HEIGHT;
		}
	}
	else
	{
		left = x - MARIO_SMALL_BBOX_WIDTH / 2;
		top = y - MARIO_SMALL_BBOX_HEIGHT / 2;
		right = left + MARIO_SMALL_BBOX_WIDTH;
		bottom = top + MARIO_SMALL_BBOX_HEIGHT;
	}
}

void CMario::SetLevel(int l)
{
	// Adjust position to avoid falling off platform
	y -= MARIO_TAIL_BBOX_HEIGHT / 2;

	isChanging = true;
	level = l;
}