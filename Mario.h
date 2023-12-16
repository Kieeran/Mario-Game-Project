#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.2f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.0007f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f

#define MARIO_GRAVITY			0.002f

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


#pragma region ANIMATION_ID

// TAIL MARIO
#define ID_ANI_MARIO_TAIL_IDLE_LEFT			15050
#define ID_ANI_MARIO_TAIL_IDLE_RIGHT		15051

#define ID_ANI_MARIO_TAIL_WALKING_LEFT		15052
#define ID_ANI_MARIO_TAIL_WALKING_RIGHT		15053

#define ID_ANI_MARIO_TAIL_RUNNING_LEFT		15054
#define ID_ANI_MARIO_TAIL_RUNNING_RIGHT		15055

#define ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT	15056
#define ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT	15057

#define ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT		15058
#define ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT	15059

#define ID_ANI_MARIO_TAIL_SIT_LEFT			15060
#define ID_ANI_MARIO_TAIL_SIT_RIGHT			15061

#define ID_ANI_MARIO_TAIL_BRACE_LEFT		15062
#define ID_ANI_MARIO_TAIL_BRACE_RIGHT		15063

#define ID_ANI_MARIO_TAIL_KICK_LEFT			15064
#define ID_ANI_MARIO_TAIL_KICK_RIGHT		15065

// BIG MARIO
#define ID_ANI_MARIO_BIG_IDLE_RIGHT 400
#define ID_ANI_MARIO_BIG_IDLE_LEFT 401

#define ID_ANI_MARIO_BIG_WALKING_RIGHT 500
#define ID_ANI_MARIO_BIG_WALKING_LEFT 501

#define ID_ANI_MARIO_BIG_RUNNING_RIGHT 600
#define ID_ANI_MARIO_BIG_RUNNING_LEFT 601

#define ID_ANI_MARIO_BIG_JUMP_WALK_RIGHT 700
#define ID_ANI_MARIO_BIG_JUMP_WALK_LEFT 701

#define ID_ANI_MARIO_BIG_JUMP_RUN_RIGHT 800
#define ID_ANI_MARIO_BIG_JUMP_RUN_LEFT 801

#define ID_ANI_MARIO_BIG_SIT_RIGHT 900
#define ID_ANI_MARIO_BIG_SIT_LEFT 901

#define ID_ANI_MARIO_BIG_BRACE_RIGHT 1000
#define ID_ANI_MARIO_BIG_BRACE_LEFT 1001

#define ID_ANI_MARIO_BIG_KICK_LEFT		16150
#define ID_ANI_MARIO_BIG_KICK_RIGHT		16151

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 1100
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 1102

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 1200
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 1201

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 1300
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 1301

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 1400
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 1401

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 1500
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 1501

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 1600
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 1601

#define ID_ANI_MARIO_SMALL_KICK_LEFT		16050
#define ID_ANI_MARIO_SMALL_KICK_RIGHT		16051

#define ID_ANI_MARIO_DIE 999

#pragma endregion

#define GROUND_Y 160.0f


#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define	MARIO_LEVEL_TAIL	3

#define MARIO_TAIL_BBOX_WIDTH  17
#define MARIO_TAIL_BBOX_HEIGHT 24
#define MARIO_TAIL_SITTING_BBOX_WIDTH  17
#define MARIO_TAIL_SITTING_BBOX_HEIGHT 16

#define MARIO_BIG_BBOX_WIDTH  14
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16


#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_UNTOUCHABLE_TIME	2500
#define TIME_KICK_ANIMATION		100

class CMario : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 

	int level;
	int untouchable;
	ULONGLONG untouchable_start;
	ULONGLONG	kick_start;
	BOOLEAN isOnPlatform;
	int coin;

	bool isFaceLeft;
	bool isHolding;
	bool isKicking;

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);
	void OnCollisionWithMysBox(LPCOLLISIONEVENT e);
	void OnCollisionWithMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithFireFlower(LPCOLLISIONEVENT e);
	void OnCollisionWithFireBullet(LPCOLLISIONEVENT e);
	void OnCollisionWithKooba(LPCOLLISIONEVENT e);

	int GetAniIdTail();
	int GetAniIdBig();
	int GetAniIdSmall();

public:
	CMario(float x, float y) : CGameObject(x, y)
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		ay = MARIO_GRAVITY;

		level = MARIO_LEVEL_SMALL;
		untouchable = 0;
		untouchable_start = -1;
		kick_start = -1;
		isOnPlatform = false;
		coin = 0;

		isFaceLeft = false;
		isHolding = false;
		isKicking = false;

	}
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

	void SetLevel(int l);
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }
	//void StartKicking() { kick_start = GetTickCount64(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	bool GetIsKicking() { return isKicking; }


	void SetIsKicking(bool b) { isKicking = b; }
};