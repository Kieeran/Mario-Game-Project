#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO	0
#define ID_TEX_ENEMIES	10
#define ID_TEX_ITEMS	21
#define ID_TEX_TILESET	22
#define ID_TEX_HUD		23
#define	ID_TEX_MISC4	24

//object type ids: 0 -> 50
#define OBJECT_TYPE_MARIO	0
#define OBJECT_TYPE_BRICK	1
#define OBJECT_TYPE_GOOMBA	2
#define OBJECT_TYPE_KOOPAS	3
#define OBJECT_TYPE_COIN 4
#define OBJECT_TYPE_PLATFORM 5

#define OBJECT_TYPE_CLOUD	6
#define OBJECT_TYPE_BIGGRASS 7
#define OBJECT_TYPE_SMALLGRASS 8
#define OBJECT_TYPE_MYSBOX	9
#define OBJECT_TYPE_BOXES	10
#define OBJECT_TYPE_PIPE	11
#define OBJECT_TYPE_HUD		12
#define OBJECT_TYPE_FIREFLOWER 13
#define OBJECT_TYPE_KOOMBA 14

#define OBJECT_TYPE_PORTAL	50

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

//------------------red goomba------------------
#define ID_ANI_RED_GOOMBA_SMALL_JUMP 30052
#define ID_ANI_RED_GOOMBA_JUMP	30053

#define ID_SPRITE_RED_GOOMBA_FLY_1 (ID_SPRITE_GOOMBA + 4)
#define ID_SPRITE_RED_GOOMBA_FLY_2 (ID_SPRITE_GOOMBA + 5)
#define ID_SPRITE_RED_GOOMBA_FLY_3 (ID_SPRITE_GOOMBA + 6)
#define ID_SPRITE_RED_GOOMBA_FLY_4 (ID_SPRITE_GOOMBA + 7)

#define ID_ANI_RED_WING_GOOMBA_WALKING	30054
#define ID_ANI_RED_GOOMBA_WALKING		30055
#define ID_SPRITE_RED_GOOMBA_WALK_1 (ID_SPRITE_GOOMBA + 8)
#define ID_SPRITE_RED_GOOMBA_WALK_2 (ID_SPRITE_GOOMBA + 9)

#define ID_ANI_RED_GOOMBA_DIE 30056
#define ID_SPRITE_RED_GOOMBA_DIE (ID_SPRITE_GOOMBA + 10)

// brick id: 30100 -> 30199
#define ID_ANI_BRICK 30150
#define ID_SPRITE_BRICK 30100

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

#define ID_ANI_BIGGRASS 30550
#define	ID_SPRITE_BIGGRASS_TOP_LEFT			(ID_SPRITE_BIGGRASS + 1) 
#define	ID_SPRITE_BIGGRASS_TOP_RIGHT		(ID_SPRITE_BIGGRASS + 2)
#define	ID_SPRITE_BIGGRASS_BOTTOM_LEFT		(ID_SPRITE_BIGGRASS + 3)
#define	ID_SPRITE_BIGGRASS_BOTTOM_RIGHT		(ID_SPRITE_BIGGRASS + 4)
#define	ID_SPRITE_BIGGRASS_LEFT_FSQUARE		(ID_SPRITE_BIGGRASS + 5)
#define	ID_SPRITE_BIGGRASS_RIGHT_FSQUARE	(ID_SPRITE_BIGGRASS + 6)
#define	ID_SPRITE_BIGGRASS_SINGLE			(ID_SPRITE_BIGGRASS + 7)

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
#define	ID_SPRITE_PINK_BOX_TOP_RIGHT		(ID_SPRITE_BOXES + 13)
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
#define ID_SPRITE_FIREFLOWER 31100

#define ID_SPRITE_FIREFLOWER_1 (ID_SPRITE_FIREFLOWER + 1)
#define ID_SPRITE_FIREFLOWER_2 (ID_SPRITE_FIREFLOWER + 2)
#define ID_SPRITE_FIREFLOWER_3 (ID_SPRITE_FIREFLOWER + 3)
#define ID_SPRITE_FIREFLOWER_4 (ID_SPRITE_FIREFLOWER + 4)
#define ID_SPRITE_FIREFLOWER_5 (ID_SPRITE_FIREFLOWER + 5)
#define ID_SPRITE_FIREFLOWER_6 (ID_SPRITE_FIREFLOWER + 6)
#define ID_SPRITE_FIREFLOWER_7 (ID_SPRITE_FIREFLOWER + 7)
#define ID_SPRITE_FIREFLOWER_8 (ID_SPRITE_FIREFLOWER + 8)

#define ID_ANI_FIREFLOWER_LOOKDOWN_LEFT		31150
#define ID_ANI_FIREFLOWER_LOOKUP_LEFT		31151
#define ID_ANI_FIREFLOWER_LOOKDOWN_RIGHT	31152
#define ID_ANI_FIREFLOWER_LOOKUP_RIGHT		31153

// fire bullet id: 31200 -> 31299

#define ID_SPRITE_FIREBULLET 31200

#define ID_ANI_FIREBULLET	31250
#define ID_SPRITE_FIREBULLET_1 (ID_SPRITE_FIREBULLET + 1)
#define ID_SPRITE_FIREBULLET_2 (ID_SPRITE_FIREBULLET + 2)
#define ID_SPRITE_FIREBULLET_3 (ID_SPRITE_FIREBULLET + 3)
#define ID_SPRITE_FIREBULLET_4 (ID_SPRITE_FIREBULLET + 4)

// koomba id: 31300 -> 31399

#define ID_SPRITE_KOOMBA	31300

//------------------------------red koomba------------------------------
#define ID_ANI_RED_KOOMBA_WALKING_LEFT	31350
#define ID_ANI_RED_KOOMBA_WALKING_RIGHT 31351
#define ID_ANI_RED_KOOMBA_HIDE			31352
#define ID_ANI_RED_KOOMBA_SHAKING		31353
#define ID_ANI_RED_KOOMBA_ROLLING		31354

#define ID_ANI_RED_WING_KOOMBA_WALKING_LEFT 31355
#define ID_ANI_RED_WING_KOOMBA_WALKING_RIGHT 31356
// red wing koomba will become red koomba if hit once

#define ID_SPRITE_RED_KOOMBA_WALKING_LEFT_1		(ID_SPRITE_KOOMBA + 1)
#define ID_SPRITE_RED_KOOMBA_WALKING_LEFT_2		(ID_SPRITE_KOOMBA + 2)
#define ID_SPRITE_RED_KOOMBA_WALKING_RIGHT_1	(ID_SPRITE_KOOMBA + 3)
#define ID_SPRITE_RED_KOOMBA_WALKING_RIGHT_2	(ID_SPRITE_KOOMBA + 4)
#define ID_SPRITE_RED_KOOMBA_HIDE				(ID_SPRITE_KOOMBA + 5)
#define ID_SPRITE_RED_KOOMBA_SHAKING			(ID_SPRITE_KOOMBA + 6)
#define ID_SPRITE_RED_KOOMBA_ROLLING_1			(ID_SPRITE_KOOMBA + 7)
#define ID_SPRITE_RED_KOOMBA_ROLLING_2			(ID_SPRITE_KOOMBA + 8)
#define ID_SPRITE_RED_KOOMBA_ROLLING_3			(ID_SPRITE_KOOMBA + 9)

#define ID_SPRITE_RED_WING_KOOMBA_WALKING_LEFT_1	(ID_SPRITE_KOOMBA + 10)
#define ID_SPRITE_RED_WING_KOOMBA_WALKING_LEFT_2	(ID_SPRITE_KOOMBA + 11)
#define ID_SPRITE_RED_WING_KOOMBA_WALKING_RIGHT_1	(ID_SPRITE_KOOMBA + 12)
#define ID_SPRITE_RED_WING_KOOMBA_WALKING_RIGHT_2	(ID_SPRITE_KOOMBA + 13)

//-----------------------------green koomba-----------------------------
#define ID_ANI_GREEN_KOOMBA_WALKING_LEFT	31357
#define ID_ANI_GREEN_KOOMBA_WALKING_RIGHT	31358
#define ID_ANI_GREEN_KOOMBA_HIDE			31359
#define ID_ANI_GREEN_KOOMBA_SHAKING			31360
#define ID_ANI_GREEN_KOOMBA_ROLLING			31361

#define ID_ANI_GREEN_WING_KOOMBA_WALKING_LEFT 31362
#define ID_ANI_GREEN_WING_KOOMBA_WALKING_RIGHT 31363
// green wing koomba will become green koomba if hit once

#define ID_SPRITE_GREEN_KOOMBA_WALKING_LEFT_1		(ID_SPRITE_KOOMBA + 21)
#define ID_SPRITE_GREEN_KOOMBA_WALKING_LEFT_2		(ID_SPRITE_KOOMBA + 22)
#define ID_SPRITE_GREEN_KOOMBA_WALKING_RIGHT_1		(ID_SPRITE_KOOMBA + 23)
#define ID_SPRITE_GREEN_KOOMBA_WALKING_RIGHT_2		(ID_SPRITE_KOOMBA + 24)
#define ID_SPRITE_GREEN_KOOMBA_HIDE					(ID_SPRITE_KOOMBA + 25)
#define ID_SPRITE_GREEN_KOOMBA_SHAKING				(ID_SPRITE_KOOMBA + 26)
#define ID_SPRITE_GREEN_KOOMBA_ROLLING_1			(ID_SPRITE_KOOMBA + 27)
#define ID_SPRITE_GREEN_KOOMBA_ROLLING_2			(ID_SPRITE_KOOMBA + 28)
#define ID_SPRITE_GREEN_KOOMBA_ROLLING_3			(ID_SPRITE_KOOMBA + 29)

#define ID_SPRITE_GREEN_WING_KOOMBA_WALKING_LEFT_1	(ID_SPRITE_KOOMBA + 30)
#define ID_SPRITE_GREEN_WING_KOOMBA_WALKING_LEFT_2	(ID_SPRITE_KOOMBA + 31)
#define ID_SPRITE_GREEN_WING_KOOMBA_WALKING_RIGHT_1	(ID_SPRITE_KOOMBA + 32)
#define ID_SPRITE_GREEN_WING_KOOMBA_WALKING_RIGHT_2	(ID_SPRITE_KOOMBA + 33)

#define ID_SPRITE_HUD	11111