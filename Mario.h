#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#include "Tail.h"

#define MAX_MARIO_WALKING_SPEED 0.1f
#define MAX_MARIO_RUNNING_SPEED	0.1f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.00016f

#define MARIO_JUMP_SPEED_Y		0.4f
#define MARIO_JUMP_RUN_SPEED_Y	0.5f

#define MARIO_GRAVITY	0.0008f
#define MARIO_FLYING	0.27f

#define MARIO_JUMP_DEFLECT_SPEED  0.4f

#define MARIO_STATE_DIE				-10
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200

#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RELEASE_JUMP    301

#define MARIO_STATE_RUNNING_RIGHT	400
#define MARIO_STATE_RUNNING_LEFT	500

#define MARIO_STATE_SIT				600
#define MARIO_STATE_SIT_RELEASE		601
#define MARIO_STATE_TAIL_ATTACK		700
#define MARIO_STATE_FLY				800

#define GROUND_Y 160.0f

#define	MARIO_LEVEL_TAIL	3
#define	MARIO_LEVEL_BIG		2
#define	MARIO_LEVEL_SMALL	1

#define MARIO_TAIL_BBOX_WIDTH  14
#define MARIO_TAIL_BBOX_HEIGHT 27
#define MARIO_TAIL_SITTING_BBOX_WIDTH  14
#define MARIO_TAIL_SITTING_BBOX_HEIGHT 20

#define MARIO_BIG_BBOX_WIDTH  14
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12

#define	SPEED_LEVEL_RUN	0.021f
#define LEVEL_RUN_MAX	7

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT - MARIO_BIG_SITTING_BBOX_HEIGHT) / 2)

#define MARIO_UNTOUCHABLE_TIME	2500
#define TIME_KICK_ANIMATION	 100
#define TIME_PREPARE_RUN  700
#define TIME_SPEED	150

class CMario : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 

	int index;
	int level;
	int levelRun;
	int untouchable;

	ULONGLONG untouchable_start;
	ULONGLONG kick_start;
	ULONGLONG hold_start;
	ULONGLONG speed_start;
	ULONGLONG speed_stop;
	ULONGLONG prepare_start;

	BOOLEAN isOnPlatform;
	int coin;
	CTail* tail;

	bool isHolding;
	bool isKicking;
	bool isRunning;
	bool isTailAttack;
	bool isChanging;
	bool isLower;
	bool isFlying;

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);
	void OnCollisionWithMysBox(LPCOLLISIONEVENT e);
	void OnCollisionWithMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithLeaf(LPCOLLISIONEVENT e);
	void OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e);
	void OnCollisionWithFireBullet(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopas(LPCOLLISIONEVENT e);
	void OnCollisionWithBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithButton(LPCOLLISIONEVENT e);

	int GetAniIdTail();
	int GetAniIdBig();
	int GetAniIdSmall();

public:
	CMario(float x, float y, int index);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);

	int IsCollidable()
	{
		return (state != MARIO_STATE_DIE);
	}

	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable == 0); }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	int GetLevel() { return level; }
	void SetLevel(int l)
	{
		y -= MARIO_TAIL_BBOX_HEIGHT / 2;
		level = l;
	}

	void SetLevelHigher();
	void SetLevelLower();
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }
	void StartKicking() { isKicking = true; kick_start = GetTickCount64(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	bool GetIsKicking() { return isKicking; }
	void SetIsKicking(bool b) { isKicking = b; }

	int GetCoinNum() { return coin; }
	void SetCoinNum(int coin) { this->coin = coin; }

	bool GetIsHolding() { return isHolding; }
	void SetIsHolding(bool isHolding) { this->isHolding = isHolding; }

	bool GetIsTailAttack() { return isTailAttack; }
	void SetIsTailAttack(bool t) { isTailAttack = t; }

	bool GetIsChanging() { return isChanging; }
	void SetIsChanging(bool c) { isChanging = c; }

	bool GetIsOnPlatform() { return isOnPlatform; }
	void SetIsOnPlatform(bool p) { isOnPlatform = p; }

	bool GetIsFlying() { return isFlying; }

	int GetLevelRun() { return levelRun; }

	int GetIndex() { return index; }

	bool IsNotFlying() { return levelRun <= LEVEL_RUN_MAX - 4; }
};