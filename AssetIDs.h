#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO	0
#define ID_TEX_ENEMY	10
#define ID_TEX_MISC		21
#define ID_TEX_MISC2	22
#define ID_TEX_MISC3	23
#define	ID_TEX_MISC4	24


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


#define OBJECT_TYPE_PORTAL	50


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

#define ID_SPRITE_BRICK 20000

#define ID_SPRITE_GOOMBA 30000
#define ID_SPRITE_GOOMBA_WALK (ID_SPRITE_GOOMBA + 1000)
#define ID_SPRITE_GOOMBA_DIE (ID_SPRITE_GOOMBA + 2000)

#define ID_SPRITE_COIN	40000
#define ID_SPRITE_SHOWED_COIN_1		(ID_SPRITE_COIN + 1)
#define ID_SPRITE_SHOWED_COIN_2		(ID_SPRITE_COIN + 2)
#define ID_SPRITE_SHOWED_COIN_3		(ID_SPRITE_COIN + 3)
#define ID_SPRITE_SHOWED_COIN_4		(ID_SPRITE_COIN + 4)
#define ID_SPRITE_SHOWED_COIN_5		(ID_SPRITE_COIN + 5)
#define ID_SPRITE_HIDDEN_COIN_1		(ID_SPRITE_COIN + 6)
#define ID_SPRITE_HIDDEN_COIN_2		(ID_SPRITE_COIN + 7)
#define ID_SPRITE_HIDDEN_COIN_3		(ID_SPRITE_COIN + 8)

#define ID_SPRITE_CLOUD					200000
#define ID_SPRITE_CLOUD_TOP_LEFT		(ID_SPRITE_CLOUD + 10000)
#define ID_SPRITE_CLOUD_TOP_MIDDLE		(ID_SPRITE_CLOUD + 20000)
#define ID_SPRITE_CLOUD_TOP_RIGHT		(ID_SPRITE_CLOUD + 30000)
#define ID_SPRITE_CLOUD_BOTTOM_LEFT		(ID_SPRITE_CLOUD + 40000)
#define ID_SPRITE_CLOUD_BOTTOM_MIDDLE	(ID_SPRITE_CLOUD + 50000)
#define ID_SPRITE_CLOUD_BOTTOM_RIGHT	(ID_SPRITE_CLOUD + 60000)


#define ID_SPRITE_GROUND 500000
#define ID_SPRITE_GROUND_BEGIN (ID_SPRITE_GROUND + 10000)
#define ID_SPRITE_GROUND_MIDDLE (ID_SPRITE_GROUND + 20000)
#define ID_SPRITE_GROUND_END (ID_SPRITE_GROUND + 30000)

#define	ID_SPRITE_BIGGRASS 300000
#define	ID_SPRITE_BIGGRASS_TOP_LEFT			(ID_SPRITE_BIGGRASS + 10000) 
#define	ID_SPRITE_BIGGRASS_TOP_RIGHT		(ID_SPRITE_BIGGRASS + 20000)
#define	ID_SPRITE_BIGGRASS_BOTTOM_LEFT		(ID_SPRITE_BIGGRASS + 30000)
#define	ID_SPRITE_BIGGRASS_BOTTOM_RIGHT		(ID_SPRITE_BIGGRASS + 40000)
#define	ID_SPRITE_BIGGRASS_LEFT_FSQUARE		(ID_SPRITE_BIGGRASS + 50000)
#define	ID_SPRITE_BIGGRASS_RIGHT_FSQUARE	(ID_SPRITE_BIGGRASS + 60000)
#define	ID_SPRITE_BIGGRASS_SINGLE			(ID_SPRITE_BIGGRASS + 70000)

#define ID_SPRITE_SMALLGRASS	300001

#define ID_SPRITE_MYSBOX_0	600000
#define ID_SPRITE_MYSBOX_1	600001
#define ID_SPRITE_MYSBOX_2	600002
#define ID_SPRITE_MYSBOX_3	600003
#define ID_SPRITE_MYSBOX_4	600004

#define ID_SPRITE_BOXES		700000

#define	ID_SPRITE_PINK_BOX_TOP_LEFT			700011
#define	ID_SPRITE_PINK_BOX_TOP_MIDDLE		700012
#define	ID_SPRITE_PINK_BOX_TOP_RIGHT		700013
#define	ID_SPRITE_PINK_BOX_MIDDLE_LEFT		700014
#define	ID_SPRITE_PINK_BOX_CENTER			700015
#define	ID_SPRITE_PINK_BOX_MIDDLE_RIGHT		700016
#define	ID_SPRITE_PINK_BOX_BOTTOM_LEFT		700017
#define	ID_SPRITE_PINK_BOX_BOTTOM_MIDDLE	700018
#define	ID_SPRITE_PINK_BOX_BOTTOM_RIGHT		700019

#define	ID_SPRITE_BLUE_BOX_TOP_LEFT			700021
#define	ID_SPRITE_BLUE_BOX_TOP_MIDDLE		700022
#define	ID_SPRITE_PINK_BOX_TOP_RIGHT		700023
#define	ID_SPRITE_BLUE_BOX_MIDDLE_LEFT		700024
#define	ID_SPRITE_BLUE_BOX_CENTER			700025
#define	ID_SPRITE_BLUE_BOX_MIDDLE_RIGHT		700026
#define	ID_SPRITE_BLUE_BOX_BOTTOM_LEFT		700027
#define	ID_SPRITE_BLUE_BOX_BOTTOM_MIDDLE	700028
#define	ID_SPRITE_BLUE_BOX_BOTTOM_RIGHT		700029

#define	ID_SPRITE_GREEN_BOX_TOP_LEFT		700031
#define	ID_SPRITE_GREEN_BOX_TOP_MIDDLE		700032
#define	ID_SPRITE_GREEN_BOX_TOP_RIGHT		700033
#define	ID_SPRITE_GREEN_BOX_MIDDLE_LEFT		700034
#define	ID_SPRITE_GREEN_BOX_CENTER			700035
#define	ID_SPRITE_GREEN_BOX_MIDDLE_RIGHT	700036
#define	ID_SPRITE_GREEN_BOX_BOTTOM_LEFT		700037
#define	ID_SPRITE_GREEN_BOX_BOTTOM_MIDDLE	700038
#define	ID_SPRITE_GREEN_BOX_BOTTOM_RIGHT	700039

#define	ID_SPRITE_WHITE_BOX_TOP_LEFT		700041
#define	ID_SPRITE_WHITE_BOX_TOP_MIDDLE		700042
#define	ID_SPRITE_WHITE_BOX_TOP_RIGHT		700043
#define	ID_SPRITE_WHITE_BOX_MIDDLE_LEFT		700044
#define	ID_SPRITE_WHITE_BOX_CENTER			700045
#define	ID_SPRITE_WHITE_BOX_MIDDLE_RIGHT	700046
#define	ID_SPRITE_WHITE_BOX_BOTTOM_LEFT		700047
#define	ID_SPRITE_WHITE_BOX_BOTTOM_MIDDLE	700048
#define	ID_SPRITE_WHITE_BOX_BOTTOM_RIGHT	700049

#define	ID_SPRITE_SHADOW_TOP	700051
#define	ID_SPRITE_SHADOW_REST	700052

#define ID_SPRITE_PIPE					800000
#define ID_SPRITE_PIPE_TOP_LEFT			800001
#define ID_SPRITE_PIPE_TOP_RIGHT		800002
#define ID_SPRITE_PIPE_BOTTOM_LEFT		800003
#define ID_SPRITE_PIPE_BOTTOM_RIGHT		800004

#define ID_SPRITE_HUD	11111