#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO		0
#define ID_TEX_ENEMIES		10
#define ID_TEX_ITEMS		21
#define ID_TEX_TILESET		22
#define ID_TEX_HUD			23
#define	ID_TEX_MISC4		24
#define	ID_TEX_TITLESCREEN	25
#define	ID_TEX_MAP			26

//object type ids: 0 -> 50
#define OBJECT_TYPE_MARIO				0
#define OBJECT_TYPE_BRICK				1
#define OBJECT_TYPE_GOOMBA				2
#define OBJECT_TYPE_KOOPAS				3
#define OBJECT_TYPE_COIN				4
#define OBJECT_TYPE_PLATFORM			5
#define OBJECT_TYPE_CLOUD				6
#define OBJECT_TYPE_BIGGRASS			7
#define OBJECT_TYPE_SMALLGRASS			8
#define OBJECT_TYPE_MYSBOX				9
#define OBJECT_TYPE_BOXES				10
#define OBJECT_TYPE_PIPE				11
#define OBJECT_TYPE_HUD					12
#define OBJECT_TYPE_FIREFLOWER			13
#define OBJECT_TYPE_KOOPAS				14
#define OBJECT_TYPE_HARDBLOCK			15
#define OBJECT_TYPE_BLACKBACKGROUND		16
#define OBJECT_TYPE_CARD				17
#define OBJECT_TYPE_CURTAIN				18
#define OBJECT_TYPE_MAP					19
#define OBJECT_TYPE_DANCING_SHRUB		20
#define OBJECT_TYPE_INTRO_OBJECTS		21

#define OBJECT_TYPE_PORTAL		50

// mario id: 10000 -> 19999
#pragma region MARIO 

#define ID_SPRITE_MARIO 10000
#define ID_SPRITE_MARIO_BIG (ID_SPRITE_MARIO + 1000)
#define ID_SPRITE_MARIO_BIG_IDLE (ID_SPRITE_MARIO_BIG + 100)
#define ID_SPRITE_MARIO_BIG_IDLE_LEFT (ID_SPRITE_MARIO_BIG_IDLE + 10)
#define ID_SPRITE_MARIO_BIG_IDLE_RIGHT (ID_SPRITE_MARIO_BIG_IDLE + 20)

#define ID_SPRITE_MARIO_BIG_WALKING (ID_SPRITE_MARIO_BIG + 200)
#define ID_SPRITE_MARIO_BIG_WALKING_LEFT (ID_SPRITE_MARIO_BIG_WALKING + 10)
#define ID_SPRITE_MARIO_BIG_WALKING_RIGHT (ID_SPRITE_MARIO_BIG_WALKING + 20)
#define ID_SPRITE_MARIO_BIG_RUNNING (ID_SPRITE_MARIO_BIG + 300)
#define ID_SPRITE_MARIO_BIG_RUNNING_LEFT (ID_SPRITE_MARIO_BIG_RUNNING + 10)
#define ID_SPRITE_MARIO_BIG_RUNNING_RIGHT (ID_SPRITE_MARIO_BIG_RUNNING + 20)
#define ID_SPRITE_MARIO_BIG_JUMP (ID_SPRITE_MARIO_BIG + 400)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK (ID_SPRITE_MARIO_BIG_JUMP + 10)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN (ID_SPRITE_MARIO_BIG_JUMP + 20)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 6)
#define ID_SPRITE_MARIO_BIG_SIT (ID_SPRITE_MARIO_BIG + 500)
#define ID_SPRITE_MARIO_BIG_SIT_LEFT (ID_SPRITE_MARIO_BIG_SIT + 10)
#define ID_SPRITE_MARIO_BIG_SIT_RIGHT (ID_SPRITE_MARIO_BIG_SIT + 20)
#define ID_SPRITE_MARIO_BIG_BRACE (ID_SPRITE_MARIO_BIG + 600)
#define ID_SPRITE_MARIO_BIG_BRACE_LEFT (ID_SPRITE_MARIO_BIG_BRACE + 10)
#define ID_SPRITE_MARIO_BIG_BRACE_RIGHT (ID_SPRITE_MARIO_BIG_BRACE + 20)

#define ID_SPRITE_MARIO_DIE (ID_SPRITE_MARIO + 3000)

#define ID_SPRITE_MARIO_SMALL (ID_SPRITE_MARIO + 2000)
#define ID_SPRITE_MARIO_SMALL_IDLE (ID_SPRITE_MARIO_SMALL + 100)
#define ID_SPRITE_MARIO_SMALL_IDLE_LEFT (ID_SPRITE_MARIO_SMALL_IDLE + 10)
#define ID_SPRITE_MARIO_SMALL_IDLE_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE + 20)

#define ID_SPRITE_MARIO_SMALL_WALKING (ID_SPRITE_MARIO_SMALL + 200)
#define ID_SPRITE_MARIO_SMALL_WALKING_LEFT (ID_SPRITE_MARIO_SMALL_WALKING + 10)
#define ID_SPRITE_MARIO_SMALL_WALKING_RIGHT (ID_SPRITE_MARIO_SMALL_WALKING + 20)
#define ID_SPRITE_MARIO_SMALL_RUNNING (ID_SPRITE_MARIO_SMALL + 300)
#define ID_SPRITE_MARIO_SMALL_RUNNING_LEFT (ID_SPRITE_MARIO_SMALL_RUNNING + 10)
#define ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT (ID_SPRITE_MARIO_SMALL_RUNNING + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP (ID_SPRITE_MARIO_SMALL + 400)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK (ID_SPRITE_MARIO_SMALL_JUMP + 10)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN (ID_SPRITE_MARIO_SMALL_JUMP + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_SMALL_SIT (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_SIT_LEFT (ID_SPRITE_MARIO_SMALL_SIT + 10)
#define ID_SPRITE_MARIO_SMALL_SIT_RIGHT (ID_SPRITE_MARIO_SMALL_SIT + 20)

#define ID_SPRITE_MARIO_SMALL_BRACE (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_BRACE_LEFT (ID_SPRITE_MARIO_SMALL_BRACE + 10)
#define ID_SPRITE_MARIO_SMALL_BRACE_RIGHT (ID_SPRITE_MARIO_SMALL_BRACE + 20)

//=============================MARIO SMALL AND BIG EXTRAS=============================

//=================================== small mario ===================================
// 16000 -> 16099

#define ID_SPRITE_MARIO_SMALL	16000

// kick KOOPAS left & right
#define ID_SPRITE_MARIO_SMALL_KICK_LEFT		(ID_SPRITE_MARIO_SMALL + 1)
#define ID_SPRITE_MARIO_SMALL_KICK_RIGHT	(ID_SPRITE_MARIO_SMALL + 2)

// hold KOOPAS left 
#define ID_SPRITE_MARIO_SMALL_HOLD_LEFT_1	(ID_SPRITE_MARIO_SMALL + 3)
#define ID_SPRITE_MARIO_SMALL_HOLD_LEFT_2	(ID_SPRITE_MARIO_SMALL + 4)

// hold KOOPAS right
#define ID_SPRITE_MARIO_SMALL_HOLD_RIGHT_1	(ID_SPRITE_MARIO_SMALL + 5)
#define ID_SPRITE_MARIO_SMALL_HOLD_RIGHT_2	(ID_SPRITE_MARIO_SMALL + 6)

//==================================== big mario ====================================
// 16100 -> 16199

#define ID_SPRITE_MARIO_BIG		16100

// kick KOOPAS left & right
#define ID_SPRITE_MARIO_BIG_KICK_LEFT		(ID_SPRITE_MARIO_BIG + 1)
#define ID_SPRITE_MARIO_BIG_KICK_RIGHT		(ID_SPRITE_MARIO_BIG + 2)

// hold KOOPAS left 
#define ID_SPRITE_MARIO_BIG_HOLD_LEFT_1		(ID_SPRITE_MARIO_BIG + 3)
#define ID_SPRITE_MARIO_BIG_HOLD_LEFT_2		(ID_SPRITE_MARIO_BIG + 4)
#define ID_SPRITE_MARIO_BIG_HOLD_LEFT_3		(ID_SPRITE_MARIO_BIG + 5)

// hold KOOPAS right
#define ID_SPRITE_MARIO_BIG_HOLD_RIGHT_1	(ID_SPRITE_MARIO_BIG + 6)
#define ID_SPRITE_MARIO_BIG_HOLD_RIGHT_2	(ID_SPRITE_MARIO_BIG + 7)
#define ID_SPRITE_MARIO_BIG_HOLD_RIGHT_3	(ID_SPRITE_MARIO_BIG + 8)

//=====================================MARIO TAIL=====================================

// mario tail: 15000 -> 15999
#define ID_SPRITE_MARIO_TAIL	15000
// idle left & right
#define ID_SPRITE_MARIO_TAIL_IDLE_LEFT	(ID_SPRITE_MARIO_TAIL + 1)
#define ID_SPRITE_MARIO_TAIL_IDLE_RIGHT	(ID_SPRITE_MARIO_TAIL + 2)

// walking left
#define ID_SPRITE_MARIO_TAIL_WALKING_LEFT_1	(ID_SPRITE_MARIO_TAIL + 3)
#define ID_SPRITE_MARIO_TAIL_WALKING_LEFT_2	(ID_SPRITE_MARIO_TAIL + 4)
#define ID_SPRITE_MARIO_TAIL_WALKING_LEFT_3	(ID_SPRITE_MARIO_TAIL + 5)

// walking right
#define ID_SPRITE_MARIO_TAIL_WALKING_RIGHT_1	(ID_SPRITE_MARIO_TAIL + 6)
#define ID_SPRITE_MARIO_TAIL_WALKING_RIGHT_2	(ID_SPRITE_MARIO_TAIL + 7)
#define ID_SPRITE_MARIO_TAIL_WALKING_RIGHT_3	(ID_SPRITE_MARIO_TAIL + 8)

// running left
#define ID_SPRITE_MARIO_TAIL_RUNNING_LEFT_1	(ID_SPRITE_MARIO_TAIL + 9)
#define ID_SPRITE_MARIO_TAIL_RUNNING_LEFT_2	(ID_SPRITE_MARIO_TAIL + 10)
#define ID_SPRITE_MARIO_TAIL_RUNNING_LEFT_3	(ID_SPRITE_MARIO_TAIL + 11)

// running right
#define ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT_1	(ID_SPRITE_MARIO_TAIL + 12)
#define ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT_2	(ID_SPRITE_MARIO_TAIL + 13)
#define ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT_3	(ID_SPRITE_MARIO_TAIL + 14)

// bracing left & right
#define ID_SPRITE_MARIO_TAIL_BRACING_LEFT		(ID_SPRITE_MARIO_TAIL + 15)
#define ID_SPRITE_MARIO_TAIL_BRACING_RIGHT	(ID_SPRITE_MARIO_TAIL + 16)

// jumping left
#define ID_SPRITE_MARIO_TAIL_JUMPING_LEFT		(ID_SPRITE_MARIO_TAIL + 17)
#define ID_SPRITE_MARIO_TAIL_LANDING_LEFT		(ID_SPRITE_MARIO_TAIL + 18)

// jumping right
#define ID_SPRITE_MARIO_TAIL_JUMPING_RIGHT		(ID_SPRITE_MARIO_TAIL + 19)
#define ID_SPRITE_MARIO_TAIL_LANDING_RIGHT		(ID_SPRITE_MARIO_TAIL + 20)

// flying up left
#define ID_SPRITE_MARIO_TAIL_FLYING_UP_LEFT_1		(ID_SPRITE_MARIO_TAIL + 21)
#define ID_SPRITE_MARIO_TAIL_FLYING_UP_LEFT_2		(ID_SPRITE_MARIO_TAIL + 22)

// flying up right
#define ID_SPRITE_MARIO_TAIL_FLYING_UP_RIGHT_1		(ID_SPRITE_MARIO_TAIL + 23)
#define ID_SPRITE_MARIO_TAIL_FLYING_UP_RIGHT_2		(ID_SPRITE_MARIO_TAIL + 24)

// flying down left
#define ID_SPRITE_MARIO_TAIL_FLYING_DOWN_LEFT_1		(ID_SPRITE_MARIO_TAIL + 25)
#define ID_SPRITE_MARIO_TAIL_FLYING_DOWN_LEFT_2		(ID_SPRITE_MARIO_TAIL + 26)

// flying down right
#define ID_SPRITE_MARIO_TAIL_FLYING_DOWN_RIGHT_1		(ID_SPRITE_MARIO_TAIL + 27)
#define ID_SPRITE_MARIO_TAIL_FLYING_DOWN_RIGHT_2		(ID_SPRITE_MARIO_TAIL + 28)

// waving tail left
#define ID_SPRITE_MARIO_TAIL_WAVING_TAIL_LEFT_1		(ID_SPRITE_MARIO_TAIL + 29)
#define ID_SPRITE_MARIO_TAIL_WAVING_TAIL_LEFT_2		(ID_SPRITE_MARIO_TAIL + 30)
#define ID_SPRITE_MARIO_TAIL_WAVING_TAIL_LEFT_3		(ID_SPRITE_MARIO_TAIL + 31)

// waving tail right
#define ID_SPRITE_MARIO_TAIL_WAVING_TAIL_RIGHT_1		(ID_SPRITE_MARIO_TAIL + 32)
#define ID_SPRITE_MARIO_TAIL_WAVING_TAIL_RIGHT_2		(ID_SPRITE_MARIO_TAIL + 33)
#define ID_SPRITE_MARIO_TAIL_WAVING_TAIL_RIGHT_3		(ID_SPRITE_MARIO_TAIL + 34)

// sit left & right
#define ID_SPRITE_MARIO_TAIL_SIT_LEFT		(ID_SPRITE_MARIO_TAIL + 35)
#define ID_SPRITE_MARIO_TAIL_SIT_RIGHT		(ID_SPRITE_MARIO_TAIL + 36)

// kick KOOPAS left & right
#define ID_SPRITE_MARIO_TAIL_KICK_LEFT		(ID_SPRITE_MARIO_TAIL + 37)
#define ID_SPRITE_MARIO_TAIL_KICK_RIGHT		(ID_SPRITE_MARIO_TAIL + 38)

// hold KOOPAS left 
#define ID_SPRITE_MARIO_TAIL_HOLD_LEFT_1	(ID_SPRITE_MARIO_TAIL + 39)
#define ID_SPRITE_MARIO_TAIL_HOLD_LEFT_2	(ID_SPRITE_MARIO_TAIL + 40)
#define ID_SPRITE_MARIO_TAIL_HOLD_LEFT_3	(ID_SPRITE_MARIO_TAIL + 41)

// hold KOOPAS right
#define ID_SPRITE_MARIO_TAIL_HOLD_RIGHT_1	(ID_SPRITE_MARIO_TAIL + 42)
#define ID_SPRITE_MARIO_TAIL_HOLD_RIGHT_2	(ID_SPRITE_MARIO_TAIL + 43)
#define ID_SPRITE_MARIO_TAIL_HOLD_RIGHT_3	(ID_SPRITE_MARIO_TAIL + 44)

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

#define ID_ANI_MARIO_TAIL_HOLD_IDLE_LEFT	15066
#define ID_ANI_MARIO_TAIL_HOLD_IDLE_RIGHT	15067

#define ID_ANI_MARIO_TAIL_HOLD_RUN_LEFT		15068
#define ID_ANI_MARIO_TAIL_HOLD_RUN_RIGHT	15069

#define ID_ANI_MARIO_TAIL_HOLD_JUMP_LEFT	15070
#define ID_ANI_MARIO_TAIL_HOLD_JUMP_RIGHT	15071

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

#define ID_ANI_MARIO_BIG_HOLD_IDLE_LEFT		16152
#define ID_ANI_MARIO_BIG_HOLD_IDLE_RIGHT	16153

#define ID_ANI_MARIO_BIG_HOLD_RUN_LEFT		16154
#define ID_ANI_MARIO_BIG_HOLD_RUN_RIGHT		16155

#define ID_ANI_MARIO_BIG_HOLD_JUMP_LEFT		16156
#define ID_ANI_MARIO_BIG_HOLD_JUMP_RIGHT	16157

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

#define ID_ANI_MARIO_SMALL_HOLD_IDLE_LEFT	16052
#define ID_ANI_MARIO_SMALL_HOLD_IDLE_RIGHT	16053

#define ID_ANI_MARIO_SMALL_HOLD_RUN_LEFT	16054
#define ID_ANI_MARIO_SMALL_HOLD_RUN_RIGHT	16055

#define ID_ANI_MARIO_SMALL_HOLD_JUMP_LEFT	16056
#define ID_ANI_MARIO_SMALL_HOLD_JUMP_RIGHT	16057

#define ID_ANI_MARIO_DIE 999

#pragma endregion 

// 50 first values is for sprite id, 50 second values is for animation id
// goomba id: 30000 -> 30099
#define ID_SPRITE_GOOMBA 30000

//------------------yellow goomba------------------
#define ID_ANI_YELLOW_GOOMBA_WALKING 30050
#define ID_SPRITE_YELLOW_GOOMBA_WALK_1 (ID_SPRITE_GOOMBA + 1)
#define ID_SPRITE_YELLOW_GOOMBA_WALK_2 (ID_SPRITE_GOOMBA + 2)

#define ID_ANI_YELLOW_GOOMBA_DIE 30051
#define ID_SPRITE_YELLOW_GOOMBA_DIE (ID_SPRITE_GOOMBA + 3)

#define ID_ANI_YELLOW_GOOMBA_UPSIDE_DOWN	30052
#define ID_SPRITE_YELLOW_GOOMBA_UPSIDE_DOWN	(ID_SPRITE_GOOMBA + 4)

//------------------red goomba------------------
#define ID_ANI_RED_GOOMBA_SMALL_JUMP 30053
#define ID_ANI_RED_GOOMBA_JUMP	30054

#define ID_SPRITE_RED_GOOMBA_FLY_1 (ID_SPRITE_GOOMBA + 5)
#define ID_SPRITE_RED_GOOMBA_FLY_2 (ID_SPRITE_GOOMBA + 6)
#define ID_SPRITE_RED_GOOMBA_FLY_3 (ID_SPRITE_GOOMBA + 7)
#define ID_SPRITE_RED_GOOMBA_FLY_4 (ID_SPRITE_GOOMBA + 8)

#define ID_ANI_RED_WING_GOOMBA_WALKING	30055
#define ID_ANI_RED_GOOMBA_WALKING		30056
#define ID_SPRITE_RED_GOOMBA_WALK_1 (ID_SPRITE_GOOMBA + 9)
#define ID_SPRITE_RED_GOOMBA_WALK_2 (ID_SPRITE_GOOMBA + 10)

#define ID_ANI_RED_GOOMBA_DIE 30057
#define ID_SPRITE_RED_GOOMBA_DIE (ID_SPRITE_GOOMBA + 11)

#define ID_ANI_RED_GOOMBA_UPSIDE_DOWN	30058
#define ID_SPRITE_RED_GOOMBA_UPSIDE_DOWN	(ID_SPRITE_GOOMBA + 12)

// brick id: 30100 -> 30199

#define ID_SPRITE_BRICK 30100

#define ID_SPRITE_BRICK_1 (ID_SPRITE_BRICK + 1)
#define ID_SPRITE_BRICK_2 (ID_SPRITE_BRICK + 2)
#define ID_SPRITE_BRICK_3 (ID_SPRITE_BRICK + 3)
#define ID_SPRITE_BRICK_4 (ID_SPRITE_BRICK + 4)

#define ID_ANI_BRICK 30150


// coin id: 30200 -> 30299
#define ID_SPRITE_COIN	30200

#define ID_ANI_SHOWED_COIN 30250
#define ID_SPRITE_SHOWED_COIN_1		(ID_SPRITE_COIN + 1)
#define ID_SPRITE_SHOWED_COIN_2		(ID_SPRITE_COIN + 2)
#define ID_SPRITE_SHOWED_COIN_3		(ID_SPRITE_COIN + 3)
#define ID_SPRITE_SHOWED_COIN_4		(ID_SPRITE_COIN + 4)
#define ID_SPRITE_SHOWED_COIN_5		(ID_SPRITE_COIN + 5)

#define ID_ANI_HIDDEN_COIN 30251
#define ID_SPRITE_HIDDEN_COIN_1		(ID_SPRITE_COIN + 6)
#define ID_SPRITE_HIDDEN_COIN_2		(ID_SPRITE_COIN + 7)
#define ID_SPRITE_HIDDEN_COIN_3		(ID_SPRITE_COIN + 8)

// cloud id: 30300 -> 30399
#define ID_SPRITE_CLOUD	30300

#define ID_ANI_CLOUD 30350
#define ID_SPRITE_CLOUD_TOP_LEFT		(ID_SPRITE_CLOUD + 1)
#define ID_SPRITE_CLOUD_TOP_MIDDLE		(ID_SPRITE_CLOUD + 2)
#define ID_SPRITE_CLOUD_TOP_RIGHT		(ID_SPRITE_CLOUD + 3)
#define ID_SPRITE_CLOUD_BOTTOM_LEFT		(ID_SPRITE_CLOUD + 4)
#define ID_SPRITE_CLOUD_BOTTOM_MIDDLE	(ID_SPRITE_CLOUD + 5)
#define ID_SPRITE_CLOUD_BOTTOM_RIGHT	(ID_SPRITE_CLOUD + 6)

// ground id: 30400 -> 30499
#define ID_SPRITE_GROUND 30400

#define ID_ANI_TOP_GROUND 30450
#define ID_SPRITE_GROUND_TOP_LEFT	(ID_SPRITE_GROUND + 1)
#define ID_SPRITE_GROUND_TOP_MIDDLE (ID_SPRITE_GROUND + 2)
#define ID_SPRITE_GROUND_TOP_RIGHT	(ID_SPRITE_GROUND + 3)

#define ID_ANI_BOT_GROUND 30451
#define ID_SPRITE_GROUND_BOT_LEFT	(ID_SPRITE_GROUND + 4)
#define ID_SPRITE_GROUND_BOT_MIDDLE	(ID_SPRITE_GROUND + 5)
#define ID_SPRITE_GROUND_BOT_RIGHT	(ID_SPRITE_GROUND + 6)

// big grass id: 30500 -> 30599

#define	ID_SPRITE_BIGGRASS	30500

#define	ID_SPRITE_BIGGRASS_TOP_LEFT			(ID_SPRITE_BIGGRASS + 1) 
#define	ID_SPRITE_BIGGRASS_TOP_RIGHT		(ID_SPRITE_BIGGRASS + 2)
#define	ID_SPRITE_BIGGRASS_BOTTOM_LEFT		(ID_SPRITE_BIGGRASS + 3)
#define	ID_SPRITE_BIGGRASS_BOTTOM_RIGHT		(ID_SPRITE_BIGGRASS + 4)
#define	ID_SPRITE_BIGGRASS_LEFT_FSQUARE		(ID_SPRITE_BIGGRASS + 5)
#define	ID_SPRITE_BIGGRASS_RIGHT_FSQUARE	(ID_SPRITE_BIGGRASS + 6)
#define	ID_SPRITE_BIGGRASS_SINGLE			(ID_SPRITE_BIGGRASS + 7)

#define	ID_SPRITE_BLACK_BIGGRASS_LEFT_FSQUARE		(ID_SPRITE_BIGGRASS + 8)
#define	ID_SPRITE_BLACK_BIGGRASS_RIGHT_FSQUARE		(ID_SPRITE_BIGGRASS + 9)
#define	ID_SPRITE_BLACK_BIGGRASS_BOTTOM_LEFT		(ID_SPRITE_BIGGRASS + 10)
#define	ID_SPRITE_BLACK_BIGGRASS_BOTTOM_RIGHT		(ID_SPRITE_BIGGRASS + 11)


// small grass id: 30600 -> 30699
#define ID_ANI_SMALLGRASS		30650
#define ID_SPRITE_SMALLGRASS	30600

// mysbox id: 30700 -> 30799
#define ID_SPRITE_MYSBOX	30700

#define ID_ANI_MYSBOX_CARRY_OBJECT 30750
#define ID_SPRITE_MYSBOX_1	(ID_SPRITE_MYSBOX + 1)
#define ID_SPRITE_MYSBOX_2	(ID_SPRITE_MYSBOX + 2)
#define ID_SPRITE_MYSBOX_3	(ID_SPRITE_MYSBOX + 3)
#define ID_SPRITE_MYSBOX_4	(ID_SPRITE_MYSBOX + 4)

#define ID_ANI_MYSBOX_EMPTY 30751
#define ID_SPRITE_MYSBOX_5	(ID_SPRITE_MYSBOX + 5)

// box id: 30800 -> 30899
#define ID_SPRITE_BOXES	30800

#define ID_ANI_PINK_BOX	30850
#define	ID_SPRITE_PINK_BOX_TOP_LEFT			(ID_SPRITE_BOXES + 1)
#define	ID_SPRITE_PINK_BOX_TOP_MIDDLE		(ID_SPRITE_BOXES + 2)
#define	ID_SPRITE_PINK_BOX_TOP_RIGHT		(ID_SPRITE_BOXES + 3)
#define	ID_SPRITE_PINK_BOX_MIDDLE_LEFT		(ID_SPRITE_BOXES + 4)
#define	ID_SPRITE_PINK_BOX_CENTER			(ID_SPRITE_BOXES + 5)
#define	ID_SPRITE_PINK_BOX_MIDDLE_RIGHT		(ID_SPRITE_BOXES + 6)
#define	ID_SPRITE_PINK_BOX_BOTTOM_LEFT		(ID_SPRITE_BOXES + 7)
#define	ID_SPRITE_PINK_BOX_BOTTOM_MIDDLE	(ID_SPRITE_BOXES + 8)
#define	ID_SPRITE_PINK_BOX_BOTTOM_RIGHT		(ID_SPRITE_BOXES + 9)


#define ID_ANI_BLUE_BOX	30851
#define	ID_SPRITE_BLUE_BOX_TOP_LEFT			(ID_SPRITE_BOXES + 11)
#define	ID_SPRITE_BLUE_BOX_TOP_MIDDLE		(ID_SPRITE_BOXES + 12)
#define	ID_SPRITE_BLUE_BOX_TOP_RIGHT		(ID_SPRITE_BOXES + 13)
#define	ID_SPRITE_BLUE_BOX_MIDDLE_LEFT		(ID_SPRITE_BOXES + 14)
#define	ID_SPRITE_BLUE_BOX_CENTER			(ID_SPRITE_BOXES + 15)
#define	ID_SPRITE_BLUE_BOX_MIDDLE_RIGHT		(ID_SPRITE_BOXES + 16)
#define	ID_SPRITE_BLUE_BOX_BOTTOM_LEFT		(ID_SPRITE_BOXES + 17)
#define	ID_SPRITE_BLUE_BOX_BOTTOM_MIDDLE	(ID_SPRITE_BOXES + 18)
#define	ID_SPRITE_BLUE_BOX_BOTTOM_RIGHT		(ID_SPRITE_BOXES + 19)


#define ID_ANI_GREEN_BOX 30852
#define	ID_SPRITE_GREEN_BOX_TOP_LEFT		(ID_SPRITE_BOXES + 21)
#define	ID_SPRITE_GREEN_BOX_TOP_MIDDLE		(ID_SPRITE_BOXES + 22)
#define	ID_SPRITE_GREEN_BOX_TOP_RIGHT		(ID_SPRITE_BOXES + 23)
#define	ID_SPRITE_GREEN_BOX_MIDDLE_LEFT		(ID_SPRITE_BOXES + 24)
#define	ID_SPRITE_GREEN_BOX_CENTER			(ID_SPRITE_BOXES + 25)
#define	ID_SPRITE_GREEN_BOX_MIDDLE_RIGHT	(ID_SPRITE_BOXES + 26)
#define	ID_SPRITE_GREEN_BOX_BOTTOM_LEFT		(ID_SPRITE_BOXES + 27)
#define	ID_SPRITE_GREEN_BOX_BOTTOM_MIDDLE	(ID_SPRITE_BOXES + 28)
#define	ID_SPRITE_GREEN_BOX_BOTTOM_RIGHT	(ID_SPRITE_BOXES + 29)

#define ID_ANI_WHITE_BOX 30853
#define	ID_SPRITE_WHITE_BOX_TOP_LEFT		(ID_SPRITE_BOXES + 31)
#define	ID_SPRITE_WHITE_BOX_TOP_MIDDLE		(ID_SPRITE_BOXES + 32)
#define	ID_SPRITE_WHITE_BOX_TOP_RIGHT		(ID_SPRITE_BOXES + 33)
#define	ID_SPRITE_WHITE_BOX_MIDDLE_LEFT		(ID_SPRITE_BOXES + 34)
#define	ID_SPRITE_WHITE_BOX_CENTER			(ID_SPRITE_BOXES + 35)
#define	ID_SPRITE_WHITE_BOX_MIDDLE_RIGHT	(ID_SPRITE_BOXES + 36)
#define	ID_SPRITE_WHITE_BOX_BOTTOM_LEFT		(ID_SPRITE_BOXES + 37)
#define	ID_SPRITE_WHITE_BOX_BOTTOM_MIDDLE	(ID_SPRITE_BOXES + 38)
#define	ID_SPRITE_WHITE_BOX_BOTTOM_RIGHT	(ID_SPRITE_BOXES + 39)

// shadow id is used by all type of boxes
#define	ID_SPRITE_SHADOW_TOP	30840
#define	ID_SPRITE_SHADOW_REST	30841

// pipe id: 30900 -> 30999
#define ID_SPRITE_PIPE	30900

#define ID_ANI_PIPE 30950
#define ID_SPRITE_PIPE_TOP_LEFT			(ID_SPRITE_PIPE + 1)
#define ID_SPRITE_PIPE_TOP_RIGHT		(ID_SPRITE_PIPE + 2)
#define ID_SPRITE_PIPE_BOTTOM_LEFT		(ID_SPRITE_PIPE + 3)
#define ID_SPRITE_PIPE_BOTTOM_RIGHT		(ID_SPRITE_PIPE + 4)

// mushroom id: 31000 -> 31099
#define ID_SPRITE_MUSHROOM 31000
#define ID_ANI_MUSHROOM 31050

// fire flower id: 31100 -> 31199
#define ID_SPRITE_PIRANHA_PLANT 31100

#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_1		(ID_SPRITE_PIRANHA_PLANT + 1)
#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_2		(ID_SPRITE_PIRANHA_PLANT + 2)
#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_3		(ID_SPRITE_PIRANHA_PLANT + 3)
#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_4		(ID_SPRITE_PIRANHA_PLANT + 4)

#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_5		(ID_SPRITE_PIRANHA_PLANT + 5)
#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_6		(ID_SPRITE_PIRANHA_PLANT + 6)
#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_7		(ID_SPRITE_PIRANHA_PLANT + 7)
#define ID_SPRITE_RED_FIRE_PIRANHA_PLANT_8		(ID_SPRITE_PIRANHA_PLANT + 8)

//

#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_1	(ID_SPRITE_PIRANHA_PLANT + 11)
#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_2	(ID_SPRITE_PIRANHA_PLANT + 12)
#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_3	(ID_SPRITE_PIRANHA_PLANT + 13)
#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_4	(ID_SPRITE_PIRANHA_PLANT + 14)

#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_5	(ID_SPRITE_PIRANHA_PLANT + 15)
#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_6	(ID_SPRITE_PIRANHA_PLANT + 16)
#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_7	(ID_SPRITE_PIRANHA_PLANT + 17)
#define ID_SPRITE_GREEN_FIRE_PIRANHA_PLANT_8	(ID_SPRITE_PIRANHA_PLANT + 18)

//

#define ID_SPRITE_GREEN_PIRANHA_PLANT_1			(ID_SPRITE_PIRANHA_PLANT + 19)
#define ID_SPRITE_GREEN_PIRANHA_PLANT_2			(ID_SPRITE_PIRANHA_PLANT + 20)

// animation

#define ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKDOWN_LEFT			31150
#define ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKUP_LEFT			31151
#define ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKDOWN_RIGHT		31152
#define ID_ANI_RED_FIRE_PIRANHA_PLANT_LOOKUP_RIGHT			31153

#define ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_LEFT	31154
#define ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_LEFT		31155
#define ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_RIGHT	31156
#define ID_ANI_RED_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_RIGHT		31157

//

#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKDOWN_LEFT		31158
#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKUP_LEFT			31159
#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKDOWN_RIGHT		31160
#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_LOOKUP_RIGHT		31161

#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_LEFT	31162
#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_LEFT	31163
#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKDOWN_RIGHT	31164
#define ID_ANI_GREEN_FIRE_PIRANHA_PLANT_IDLE_LOOKUP_RIGHT	31165

#define ID_ANI_GREEN_PIRANHA_PLANT							31166

// fire bullet id: 31200 -> 31299

#define ID_SPRITE_FIREBULLET 31200

#define ID_ANI_FIREBULLET	31250
#define ID_SPRITE_FIREBULLET_1 (ID_SPRITE_FIREBULLET + 1)
#define ID_SPRITE_FIREBULLET_2 (ID_SPRITE_FIREBULLET + 2)
#define ID_SPRITE_FIREBULLET_3 (ID_SPRITE_FIREBULLET + 3)
#define ID_SPRITE_FIREBULLET_4 (ID_SPRITE_FIREBULLET + 4)

// koopas id: 31300 -> 31399

#define ID_SPRITE_KOOPA	31300
//------------------------------red koopa------------------------------

#define ID_SPRITE_RED_KOOPA_WALKING_LEFT_1	(ID_SPRITE_KOOPA + 1)
#define ID_SPRITE_RED_KOOPA_WALKING_LEFT_2	(ID_SPRITE_KOOPA + 2)
#define ID_SPRITE_RED_KOOPA_WALKING_RIGHT_1	(ID_SPRITE_KOOPA + 3)
#define ID_SPRITE_RED_KOOPA_WALKING_RIGHT_2	(ID_SPRITE_KOOPA + 4)
#define ID_SPRITE_RED_KOOPA_HIDE			(ID_SPRITE_KOOPA + 5)
#define ID_SPRITE_RED_KOOPA_SHAKING			(ID_SPRITE_KOOPA + 6)
#define ID_SPRITE_RED_KOOPA_ROLLING_1		(ID_SPRITE_KOOPA + 7)
#define ID_SPRITE_RED_KOOPA_ROLLING_2		(ID_SPRITE_KOOPA + 8)
#define ID_SPRITE_RED_KOOPA_ROLLING_3		(ID_SPRITE_KOOPA + 9)

#define ID_ANI_RED_KOOPA_WALKING_LEFT	31350
#define ID_ANI_RED_KOOPA_WALKING_RIGHT	31351
#define ID_ANI_RED_KOOPA_HIDING			31352
#define ID_ANI_RED_KOOPA_SHAKING		31353
#define ID_ANI_RED_KOOPA_ROLLING		31354

//-----------------------------green koopa-----------------------------
// para-koopas will become green koopa if hit once

#define ID_SPRITE_GREEN_KOOPA_WALKING_LEFT_1	(ID_SPRITE_KOOPA + 11)
#define ID_SPRITE_GREEN_KOOPA_WALKING_LEFT_2	(ID_SPRITE_KOOPA + 12)
#define ID_SPRITE_GREEN_KOOPA_WALKING_RIGHT_1	(ID_SPRITE_KOOPA + 13)
#define ID_SPRITE_GREEN_KOOPA_WALKING_RIGHT_2	(ID_SPRITE_KOOPA + 14)
#define ID_SPRITE_GREEN_KOOPA_HIDE				(ID_SPRITE_KOOPA + 15)
#define ID_SPRITE_GREEN_KOOPA_SHAKING			(ID_SPRITE_KOOPA + 16)
#define ID_SPRITE_GREEN_KOOPA_ROLLING_1			(ID_SPRITE_KOOPA + 17)
#define ID_SPRITE_GREEN_KOOPA_ROLLING_2			(ID_SPRITE_KOOPA + 18)
#define ID_SPRITE_GREEN_KOOPA_ROLLING_3			(ID_SPRITE_KOOPA + 19)

#define ID_SPRITE_PARA_KOOPAS_WALKING_LEFT_1	(ID_SPRITE_KOOMBA + 20)
#define ID_SPRITE_PARA_KOOPAS_WALKING_LEFT_2	(ID_SPRITE_KOOMBA + 21)
#define ID_SPRITE_PARA_KOOPAS_WALKING_RIGHT_1	(ID_SPRITE_KOOMBA + 22)
#define ID_SPRITE_PARA_KOOPAS_WALKING_RIGHT_2	(ID_SPRITE_KOOMBA + 23)

#define ID_ANI_GREEN_KOOPA_WALKING_LEFT		31355
#define ID_ANI_GREEN_KOOPA_WALKING_RIGHT	31356
#define ID_ANI_GREEN_KOOPA_HIDING			31357
#define ID_ANI_GREEN_KOOPA_SHAKING			31358
#define ID_ANI_GREEN_KOOPA_ROLLING			31359

#define ID_ANI_PARA_KOOPAS_FLYING_LEFT		31360
#define ID_ANI_PARA_KOOPAS_FLYING_RIGHT		31361

// leaf id: 31400 -> 31499

#define ID_SPRITE_LEAF_1 31400
#define ID_SPRITE_LEAF_2 31401

#define ID_ANI_LEAF_LEFT 31450
#define ID_ANI_LEAF_RIGHT 31451

// hard block id: 31500 -> 31599

#define ID_SPRITE_HARDBLOCK 31500

#define ID_ANI_HARDBLOCK 31550

// black background id:	31600 -> 31699

#define ID_SPRITE_BLACK_BLOCK		31600
#define ID_SPRITE_SERRATED_BLOCK	31601
#define ID_SPRITE_CARD_BOX			31602

// card id:	31700 -> 31799

#define ID_SPRITE_CARD	31700

#define ID_ANI_CARD	31750
#define ID_SPRITE_STAR_CARD		(ID_SPRITE_CARD + 1)
#define ID_SPRITE_MUSHROOM_CARD	(ID_SPRITE_CARD + 2)
#define ID_SPRITE_FLOWER_CARD	(ID_SPRITE_CARD + 3)

//======================================Intro part======================================
#define ID_SPRITE_CURTAIN	50000
#define ID_ANI_CURTAIN		50050

#define ID_SPRITE_INTRO_BACKGROUND	50100
#define ID_ANI_INTRO_BACKGROUND		50150	

//====================================World map part====================================

#define ID_SPRITE_MAP		60000
#define ID_ANI_MAP			60050

#define ID_SPRITE_DANCING_SHRUB		60100
#define ID_SPRITE_DANCING_SHRUB_1	(ID_SPRITE_DANCING_SHRUB + 1)
#define ID_SPRITE_DANCING_SHRUB_2	(ID_SPRITE_DANCING_SHRUB + 2)
#define ID_SPRITE_DANCING_SHRUB_3	(ID_SPRITE_DANCING_SHRUB + 3)
#define ID_SPRITE_DANCING_SHRUB_4	(ID_SPRITE_DANCING_SHRUB + 4)

#define ID_ANI_DANCING_SHRUB		60150

//==================================================================

#define ID_SPRITE_DETECTOR	100000
#define ID_ANI_DETECTOR		100001