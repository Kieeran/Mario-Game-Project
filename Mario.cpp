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
#include "Button.h"
#include "Card.h"

#include "Effects.h"
#include "Collision.h"
CMario::CMario(float x, float y, int index) :CGameObject(x, y)
{
	CDataGame* dataGame = CGame::GetInstance()->GetDataGame();

	isSitting = false;
	maxVx = 0.0f;
	ax = 0.0f;
	ay = MARIO_GRAVITY;
	momentum = 0;

	state = MARIO_STATE_IDLE;
	nx = 1;

	tail = NULL;
	coin = dataGame->GetCoin();
	level = dataGame->GetLevel();
	score = dataGame->GetScore();
	lives = dataGame->GetLives();

	card1 = dataGame->GetCard1();
	card2 = dataGame->GetCard2();
	card3 = dataGame->GetCard3();

	untouchable_start = 0;
	kick_start = 0;
	hold_start = 0;
	speed_start = 0;
	speed_stop = 0;
	use_pipe_start = 0;
	prepare_start = 0;
	change_scene_die_start = 0;
	change_scene_not_die_start = 0;

	time_one_second = 0;

	this->index = index;

	levelRun = 0;
	clock = 300;

	isOnPlatform = false;
	isHolding = false;
	isKicking = false;
	isRunning = false;
	isTailAttack = false;
	isChanging = false;
	isUntouchable = false;
	isLower = false;
	isFlying = false;
	isUsePipe = false;
	momentumMove = false;
	isComboGoombaKill = false;
	isAtPortalEntrance = false;
	isAtPortalExit = false;
	isPrepareEndScene = false;
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//DebugOut(L"%d\n", levelRun);
	//DebugOut(L"%d\n", isRunning);
	//DebugOut(L"%d\n", state);
	//avoid mario from droping out of the world at the left edge and the right edge of the stage
	if (x < 20.0f) x = 20.0f;
	if (!isPrepareEndScene)
		if (x > 2740.0f) x = 2740.0f;

	CDataGame* dataGame = CGame::GetInstance()->GetDataGame();

	if (isChanging)
	{
		vx = 0;
		vy = 0;
	}
	else
	{
		vx += ax * dt;
		vy += ay * dt;
	}

	if (MarioInDeadZone())
		SetState(MARIO_STATE_DIE);

	if ((state != MARIO_STATE_DIE) || !isChanging)
		DownTimeClock1Second();

	if (state == MARIO_STATE_DIE)
		ChangeToWorldMapWhenDie();

	if (state == MARIO_STATE_END_SCENE)
		ChangeToWorldMapWhenNotDie();

	if (abs(vx) > abs(maxVx)) vx = maxVx;

	if (isFlying)
	{
		if (isOnPlatform)
		{
			isFlying = false;
			ay = MARIO_GRAVITY;
		}
	}

	if (state == MARIO_STATE_PHYSICS_MOVE)
	{
		vx += momentum * dt;
		if (vx * momentum > 0)
		{
			momentum = 0;
			momentumMove = false;
			SetState(MARIO_STATE_IDLE);
		}
	}

	if (isOnPlatform)
		isComboGoombaKill = false;

	if (isUsePipe)
	{
		if (GetTickCount64() - use_pipe_start > TIME_USE_PIPE && use_pipe_start > 0)
		{
			if (isAtPortalEntrance)
			{
				SetPosition(POSITION_X_IN_HIDDEN_MAP, POSITION_Y_IN_HIDDEN_MAP);
				dataGame->SetIsInHiddenPlace(true);
				isAtPortalEntrance = false;
			}
			else if (isAtPortalExit)
			{
				SetPosition(POSITION_X_OUT_HIDDEN_MAP, POSITION_Y_OUT_HIDDEN_MAP);
				dataGame->SetIsInHiddenPlace(false);
				isAtPortalExit = false;
			}
			isUsePipe = false;
			ay = MARIO_GRAVITY;
		}
	}

	if (!isRunning || vx == 0 || IsBrace() || (!isOnPlatform && levelRun != LEVEL_RUN_MAX) || state == MARIO_STATE_PHYSICS_MOVE)
	{
		speed_start = GetTickCount64();
		if (GetTickCount64() - speed_stop > TIME_SPEED && speed_stop > 0)
		{
			if (levelRun > 0)
				levelRun--;
			speed_stop = GetTickCount64();
		}
		prepare_start = GetTickCount64();
	}
	else
	{
		speed_stop = GetTickCount64();
		if (GetTickCount64() - prepare_start > TIME_PREPARE_RUN && prepare_start > 0)
		{
			if (GetTickCount64() - speed_start > TIME_SPEED && speed_start > 0)
			{
				if (levelRun < LEVEL_RUN_MAX)
				{
					levelRun++;
				}
				speed_start = GetTickCount64();
			}
		}
	}

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount64() - untouchable_start > MARIO_UNTOUCHABLE_TIME && untouchable_start > 0)
	{
		untouchable_start = 0;
		isUntouchable = false;
	}

	if (GetTickCount64() - kick_start > TIME_KICK_ANIMATION && kick_start > 0)
	{
		isKicking = false;
		kick_start = 0;
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
		if (e->ny < 0)
			isOnPlatform = true;
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
	else if (dynamic_cast<CBrick*>(e->obj))
		OnCollisionWithBrick(e);
	else if (dynamic_cast<CButton*>(e->obj))
		OnCollisionWithButton(e);
	else if (dynamic_cast<CCard*>(e->obj))
		OnCollisionWithCard(e);
}

void CMario::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (e->ny >= 0)// hit by Goomba
	{
		SetLevelLower();
	}
	else
	{
		// jump on top >> kill Goomba and deflect a bit 
		if (goomba->GetGoombaType() == GOOMBA_TYPE_YELLOW)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				if (isComboGoombaKill)
					AddScore(goomba->GetX(), goomba->GetY(), 200);
				else
					AddScore(goomba->GetX(), goomba->GetY(), 100);

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

			if (isComboGoombaKill)
				AddScore(goomba->GetX(), goomba->GetY(), 200);
			else
				AddScore(goomba->GetX(), goomba->GetY(), 100);

		}

		if (!isOnPlatform && !isComboGoombaKill)
			isComboGoombaKill = true;
	}
}

void CMario::OnCollisionWithBrick(LPCOLLISIONEVENT e)
{
	CBrick* brick = dynamic_cast<CBrick*>(e->obj);

	if (e->ny > 0)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			if (brick->GetBrickType() == NORMAL_BRICK)
				brick->SetState(BRICK_STATE_DELETE);
			else
			{
				if (brick->GetState() == BRICK_STATE_NORMAL)
					brick->SetState(BRICK_STATE_UNBOXED);
			}
		}
	}
}

void CMario::OnCollisionWithButton(LPCOLLISIONEVENT e)
{
	CButton* button = dynamic_cast<CButton*>(e->obj);
	button->SetIsPressed(true);
}

void CMario::OnCollisionWithCard(LPCOLLISIONEVENT e)
{
	CCard* card = dynamic_cast<CCard*>(e->obj);

	card->SetState(CARD_STATE_COLLECTED);
	if (card1 == 0)
		card1 = card->GetCard();
	else if (card2 == 0)
		card2 = card->GetCard();
	else if (card3 == 0)
		card3 = card->GetCard();

	SetState(MARIO_STATE_END_SCENE);
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
			AddScore(koopas->GetX(), koopas->GetY(), 100);
			koopas->SetState(KOOPAS_STATE_HIDING);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
		else if (koopas->GetState() == KOOPAS_STATE_HIDING || koopas->GetState() == KOOPAS_STATE_SHAKING)
		{
			AddScore(koopas->GetX(), koopas->GetY(), 100);
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
		if (!isUntouchable)
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
	if (!isUntouchable)
		SetLevelLower();
}

void CMario::OnCollisionWithFireBullet(LPCOLLISIONEVENT e)
{
	if (!isUntouchable)
		SetLevelLower();
}

void CMario::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
	coin++;
}

void CMario::OnCollisionWithLeaf(LPCOLLISIONEVENT e)
{
	AddScore(x, y, 1000);
	SetLevelHigher();
	e->obj->Delete();
}

void CMario::OnCollisionWithMushroom(LPCOLLISIONEVENT e)
{
	CMushroom* mushroom = dynamic_cast<CMushroom*>(e->obj);
	if (mushroom->GetMushroomType() == RED_MUSHROOM_TYPE)
		SetLevelHigher();
	else
	{
		lives += 1;
		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		CEffects* effect = new CEffects(x, y, UP_EFFECT);
		scene->AddObject(effect, ADD_OBJECT_BACK);
	}
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
}

void CMario::OnCollisionWithPortal(LPCOLLISIONEVENT e)
{
	CPortal* portal = dynamic_cast<CPortal*>(e->obj);

	if (portal->GetPortalType() == ENTRANCE_PORTAL)
		isAtPortalEntrance = true;
	else if (portal->GetPortalType() == EXIT_PORTAL)
		isAtPortalExit = true;
}

void CMario::AddScore(float x, float y, int scoreAdd)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CEffects* effect = new CEffects(x, y, scoreAdd);
	scene->AddObject(effect, ADD_OBJECT_BACK);
	score += scoreAdd;
}

void CMario::ChangeToWorldMapWhenDie()
{
	if (GetTickCount64() - change_scene_die_start > TIME_CHANGE_SCENE && change_scene_die_start > 0)
	{
		level = MARIO_LEVEL_SMALL;
		change_scene_die_start = 0;
		SaveDataGame();
		CGame::GetInstance()->InitiateSwitchScene(TYPE_WORLD_MAP);
	}
}

void CMario::ChangeToWorldMapWhenNotDie()
{
	if (GetTickCount64() - change_scene_not_die_start > TIME_CHANGE_SCENE && change_scene_not_die_start > 0)
	{
		change_scene_not_die_start = 0;
		SaveDataGame();
		CGame::GetInstance()->InitiateSwitchScene(TYPE_WORLD_MAP);
	}
}

void CMario::SaveDataGame()
{
	CDataGame* dataGame = CGame::GetInstance()->GetDataGame();
	dataGame->SaveCoin(coin);
	dataGame->SaveLevel(level);
	dataGame->SaveScore(score);
	dataGame->SaveLives(lives);
	dataGame->SaveCard1(card1);
	dataGame->SaveCard2(card2);
	dataGame->SaveCard3(card3);
}

void CMario::DownTimeClock1Second()
{
	if (clock > 0)
	{
		if (GetTickCount64() - time_one_second > TIME_ONE_SECOND)
		{
			clock--;
			time_one_second = GetTickCount64();
		}
	}
	else
	{
		clock = 0;
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
			if (!isFlying)
			{
				if (levelRun == LEVEL_RUN_MAX)
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT;
					else
						aniId = ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT;
				}
				else
				{
					if (vy < 0)
					{
						if (nx > 0)
							aniId = ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT;
						else
							aniId = ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT;
					}
					else
					{
						if (nx > 0)
							aniId = ID_ANI_MARIO_TAIL_LANDING_RIGHT;
						else
							aniId = ID_ANI_MARIO_TAIL_LANDING_LEFT;
					}
				}

			}
			else
			{
				if (levelRun == LEVEL_RUN_MAX)
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_TAIL_FLYING_UP_RIGHT;
					else
						aniId = ID_ANI_MARIO_TAIL_FLYING_UP_LEFT;
				}
				else
				{
					if (nx > 0)
						aniId = ID_ANI_MARIO_TAIL_FLYING_DOWN_RIGHT;
					else
						aniId = ID_ANI_MARIO_TAIL_FLYING_DOWN_LEFT;
				}
			}
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
					else if (levelRun == LEVEL_RUN_MAX)
						aniId = ID_ANI_MARIO_TAIL_RUNNING_RIGHT;
					else
						aniId = ID_ANI_MARIO_TAIL_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_TAIL_BRACING_LEFT;
					else if (levelRun == LEVEL_RUN_MAX)
						aniId = ID_ANI_MARIO_TAIL_RUNNING_LEFT;
					else
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

	if (isUsePipe)
		aniId = ID_ANI_MARIO_TAIL_USE_PIPE;

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
			if (levelRun == LEVEL_RUN_MAX)
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
					else if (levelRun == LEVEL_RUN_MAX)
						aniId = ID_ANI_MARIO_BIG_RUNNING_RIGHT;
					else
						aniId = ID_ANI_MARIO_BIG_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_BIG_BRACE_LEFT;
					else if (levelRun == LEVEL_RUN_MAX)
						aniId = ID_ANI_MARIO_BIG_RUNNING_LEFT;
					else
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

	if (isUsePipe)
		aniId = ID_ANI_MARIO_BIG_USE_PIPE;

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
			if (levelRun == LEVEL_RUN_MAX)
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
					else if (levelRun == LEVEL_RUN_MAX)
						aniId = ID_ANI_MARIO_SMALL_RUNNING_RIGHT;
					else
						aniId = ID_ANI_MARIO_SMALL_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_SMALL_BRACE_LEFT;
					else if (levelRun == LEVEL_RUN_MAX)
						aniId = ID_ANI_MARIO_SMALL_RUNNING_LEFT;
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

	if (isUsePipe)
		aniId = ID_ANI_MARIO_SMALL_USE_PIPE;

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

	if (aniId == -1)
		return;

	if (!isChanging && !isTailAttack && !MarioInDeadZone())
		animations->Get(aniId)->Render(x, y);

	else
	{
		if (isTailAttack)
		{
			animations->Get(aniId)->RenderOnce(x, y);
			if (animations->Get(aniId)->GetDoneRenderOnce())
			{
				animations->Get(aniId)->SetDoneRenderOnce(false);
				isTailAttack = false;
			}
		}

		else if (isChanging)
		{
			if (!isLower)
			{
				if (level == MARIO_LEVEL_BIG)
				{
					if (nx > 0)
					{
						aniId = ID_ANI_MARIO_SMALL_TO_BIG_RIGHT_EFFECT;
					}
					else
						aniId = ID_ANI_MARIO_SMALL_TO_BIG_LEFT_EFFECT;
				}
			}

			else
			{
				if (level == MARIO_LEVEL_SMALL)
				{
					if (nx > 0)
					{
						aniId = ID_ANI_MARIO_BIG_TO_SMALL_RIGHT_EFFECT;
					}
					else
						aniId = ID_ANI_MARIO_BIG_TO_SMALL_LEFT_EFFECT;
				}
			}

			animations->Get(aniId)->RenderOnce(x, y);
			if (animations->Get(aniId)->GetDoneRenderOnce())
			{
				animations->Get(aniId)->SetDoneRenderOnce(false);
				isChanging = false;
			}
		}
	}

	//RenderBoundingBox();

	DebugOutTitle(L"X = %f \t Y = %f \t VX =  %f \t VY = %f \t LevelRun = %d", x, y, vx, vy, levelRun);
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

void CMario::SetLevelLower()
{
	if (level == MARIO_LEVEL_TAIL)
	{
		level = MARIO_LEVEL_BIG;
		StartUntouchable();
		isChanging = true;
	}
	else if (level == MARIO_LEVEL_BIG)
	{
		level = MARIO_LEVEL_SMALL;
		StartUntouchable();
		isChanging = true;
	}
	else
	{
		DebugOut(L">>> Mario DIE >>> \n");
		SetState(MARIO_STATE_DIE);
	}
	isLower = true;
}

void CMario::SetLevelHigher()
{
	// Adjust position to avoid falling off platform
	y -= MARIO_TAIL_BBOX_HEIGHT / 2;
	isChanging = true;

	if (level == MARIO_LEVEL_SMALL)
	{
		level = MARIO_LEVEL_BIG;
	}
	else if (level == MARIO_LEVEL_BIG)
	{
		level = MARIO_LEVEL_TAIL;
	}
	isLower = false;
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
		maxVx = MAX_MARIO_RUNNING_SPEED + levelRun * SPEED_LEVEL_RUN;
		ax = MARIO_ACCEL_RUN_X;
		isRunning = true;
		nx = 1;
		break;
	case MARIO_STATE_RUNNING_LEFT:
		if (isSitting) break;
		maxVx = -(MAX_MARIO_RUNNING_SPEED + levelRun * SPEED_LEVEL_RUN);
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
			if (levelRun == LEVEL_RUN_MAX)
				vy = -MARIO_JUMP_RUN_SPEED_Y;
			else
				vy = -MARIO_JUMP_SPEED_Y;
		}
		break;

	case MARIO_STATE_RELEASE_JUMP:
		if (vy < 0)
			vy += MARIO_JUMP_SPEED_Y / 3;
		isRunning = false;
		break;

	case MARIO_STATE_TAIL_ATTACK:
		isTailAttack = true;
		if (nx > 0)
			tail = new CTail(x - 3.0f, y + 7.0f);
		else
			tail = new CTail(x + 3.0f, y + 7.0f);
		scene->AddObject(tail, ADD_OBJECT_BACK);
		break;

	case MARIO_STATE_FLY:
		isFlying = true;
		isOnPlatform = false;
		if (levelRun == LEVEL_RUN_MAX)
		{
			vy = -MARIO_FLYING;
		}
		else
		{
			vy = 0;
		}
		break;

	case MARIO_STATE_SIT:
		if (isOnPlatform && level != MARIO_LEVEL_SMALL)
		{
			state = MARIO_STATE_IDLE;
			isSitting = true;
			isRunning = false;
			vx = 0.0f;
			vy = 0.0f;
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

	case MARIO_STATE_USE_PIPE:
		isUsePipe = true;
		vx = 0;
		ay = 0;
		momentum = 0;
		use_pipe_start = GetTickCount64();
		if (isAtPortalEntrance)
			vy = MARIO_SPEED_USE_PIPE;
		else if (isAtPortalExit)
			vy = -MARIO_SPEED_USE_PIPE;
		break;
	case MARIO_STATE_PHYSICS_MOVE:
		ax = 0.0f;
		momentumMove = true;
		if (vx > 0)
			momentum = -MARIO_MOMENTUM;
		else
			momentum = MARIO_MOMENTUM;
		break;

	case MARIO_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;

	case MARIO_STATE_DIE:
		vy = -MARIO_JUMP_DEFLECT_SPEED;
		change_scene_die_start = GetTickCount64();
		lives--;
		vx = 0;
		ax = 0;
		break;

	case MARIO_STATE_END_SCENE:
		isPrepareEndScene = true;
		maxVx = MAX_MARIO_WALKING_SPEED;
		ax = MARIO_ACCEL_WALK_X;
		isRunning = false;
		nx = 1;
		change_scene_not_die_start = GetTickCount64();
		break;
	}

	CGameObject::SetState(state);
	DebugOut(L"%d\n", state);
}