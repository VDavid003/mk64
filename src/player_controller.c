#include <ultra64.h>
#include <macros.h>
#include <defines.h>
#include <mk64.h>
#include <variables.h>

#include "player_controller.h"
#include "code_800029B0.h"
#include "kart_attributes.h"
#include "racing/memory.h"
#include "math_util.h"
#include "code_8001F980.h"
#include "code_8008C1D0.h"
#include "collision.h"
#include "waypoints.h"
#include "audio/external.h"
#include "code_8003DC40.h"
#include "main.h"

extern s8 D_80164A89;
extern s16 D_801633F8;
extern s32 D_8018D168;

s16 D_800E3810[] = {
    1, 2, 3, 4, 5, 6, 7, 0
};

s16 D_800E3820[] = {
    0, 2, 3, 4, 5, 6, 7, 0
};

s16 D_800E3830[] = {
    0, 1, 3, 4, 5, 6, 7, 0
};

s16 D_800E3840[] = {
    0, 1, 2, 4, 5, 6, 7, 0
};

s16 D_800E3850[] = {
    0, 1, 2, 3, 5, 6, 7, 0
};

s16 D_800E3860[] = {
    0, 1, 2, 3, 4, 6, 7, 0
};

s16 D_800E3870[] = {
    0, 1, 2, 3, 4, 5, 7, 0
};

s16 D_800E3880[] = {
    0, 1, 2, 3, 4, 5, 6, 0
};

s16 *D_800E3890[] = {
    D_800E3810, D_800E3820, D_800E3830, D_800E3840,
    D_800E3850, D_800E3860, D_800E3870, D_800E3880
};

s16 D_800E38B0[] = {
    2, 3, 4, 5, 6, 7
};

s16 D_800E38BC[] = {
    1, 3, 4, 5, 6, 7
};

s16 D_800E38C8[] = {
    1, 2, 4, 5, 6, 7
};

s16 D_800E38D4[] = {
    1, 2, 3, 5, 6, 7
};

s16 D_800E38E0[] = {
    1, 2, 3, 4, 6, 7
};

s16 D_800E38EC[] = {
    1, 2, 3, 4, 5, 7
};

s16 D_800E38F8[] = {
    1, 2, 3, 4, 5, 6
};

s16 D_800E3904[] = {
    2, 3, 4, 5, 6, 7
};

s16 D_800E3910[] = {
    0, 3, 4, 5, 6, 7
};

s16 D_800E391C[] = {
    0, 2, 4, 5, 6, 7
};

s16 D_800E3928[] = {
    0, 2, 3, 5, 6, 7
};

s16 D_800E3934[] = {
    0, 2, 3, 4, 6, 7
};

s16 D_800E3940[] = {
    0, 2, 3, 4, 5, 7
};

s16 D_800E394C[] = {
    0, 2, 3, 4, 5, 6
};

s16 D_800E3958[] = {
    1, 3, 4, 5, 6, 7
};

s16 D_800E3964[] = {
    0, 3, 4, 5, 6, 7
};

s16 D_800E3970[] = {
    0, 1, 4, 5, 6, 7
};

s16 D_800E397C[] = {
    0, 1, 3, 5, 6, 7
};

s16 D_800E3988[] = {
    0, 1, 3, 4, 6, 7
};

s16 D_800E3994[] = {
    0, 1, 3, 4, 5, 7
};

s16 D_800E39A0[] = {
    0, 1, 3, 4, 5, 6
};

s16 D_800E39AC[] = {
    1, 2, 4, 5, 6, 7
};

s16 D_800E39B8[] = {
    0, 2, 4, 5, 6, 7
};

s16 D_800E39C4[] = {
    0, 1, 4, 5, 6, 7
};

s16 D_800E39D0[] = {
    0, 1, 2, 5, 6, 7
};

s16 D_800E39DC[] = {
    0, 1, 2, 4, 6, 7
};

s16 D_800E39E8[] = {
    0, 1, 2, 4, 5, 7
};

s16 D_800E39F4[] = {
    0, 1, 2, 4, 5, 6
};

s16 D_800E3A00[] = {
    1, 2, 3, 5, 6, 7
};

s16 D_800E3A0C[] = {
    0, 2, 3, 5, 6, 7
};

s16 D_800E3A18[] = {
    0, 1, 3, 5, 6, 7
};

s16 D_800E3A24[] = {
    0, 1, 2, 5, 6, 7
};

s16 D_800E3A30[] = {
    0, 1, 2, 3, 6, 7
};

s16 D_800E3A3C[] = {
    0, 1, 2, 3, 5, 7
};

s16 D_800E3A48[] = {
    0, 1, 2, 3, 5, 6
};

s16 D_800E3A54[] = {
    1, 2, 3, 4, 6, 7
};

s16 D_800E3A60[] = {
    0, 2, 3, 4, 6, 7
};

s16 D_800E3A6C[] = {
    0, 1, 3, 4, 6, 7
};

s16 D_800E3A78[] = {
    0, 1, 2, 3, 6, 7
};

s16 D_800E3A84[] = {
    0, 1, 2, 4, 6, 7
};

s16 D_800E3A90[] = {
    0, 1, 2, 3, 4, 7
};

s16 D_800E3A9C[] = {
    0, 1, 2, 3, 4, 6
};

s16 D_800E3AA8[] = {
    1, 2, 3, 4, 5, 7
};

s16 D_800E3AB4[] = {
    0, 2, 3, 4, 5, 7
};

s16 D_800E3AC0[] = {
    0, 1, 3, 4, 5, 7
};

s16 D_800E3ACC[] = {
    0, 1, 2, 3, 5, 7
};

s16 D_800E3AD8[] = {
    0, 1, 2, 3, 4, 7
};

s16 D_800E3AE4[] = {
    0, 1, 2, 4, 5, 7
};

s16 D_800E3AF0[] = {
    0, 1, 2, 3, 4, 5
};

s16 D_800E3AFC[] = {
    1, 2, 3, 4, 5, 6
};

s16 D_800E3B08[] = {
    0, 2, 3, 4, 5, 6
};

s16 D_800E3B14[] = {
    0, 1, 3, 4, 5, 6
};

s16 D_800E3B20[] = {
    0, 1, 2, 3, 5, 6
};

s16 D_800E3B2C[] = {
    0, 1, 2, 3, 4, 6
};

s16 D_800E3B38[] = {
    0, 1, 2, 4, 5, 6
};

s16 D_800E3B44[] = {
    0, 1, 2, 3, 4, 5
};

s16 *D_800E3B50[] = {
    D_800E38B0, D_800E38B0, D_800E38BC, D_800E38C8,
    D_800E38D4, D_800E38E0, D_800E38EC, D_800E38F8
};

s16 *D_800E3B70[] = {
    D_800E3904, D_800E3904, D_800E3910, D_800E391C,
    D_800E3928, D_800E3934, D_800E3940, D_800E394C
};

s16 *D_800E3B90[] = {
    D_800E3958, D_800E3964, D_800E3964, D_800E3970,
    D_800E397C, D_800E3988, D_800E3994, D_800E39A0
};

s16 *D_800E3BB0[] = {
    D_800E39AC, D_800E39B8, D_800E39C4, D_800E39C4,
    D_800E39D0, D_800E39DC, D_800E39E8, D_800E39F4
};

s16 *D_800E3BD0[] = {
    D_800E3A00, D_800E3A0C, D_800E3A18, D_800E3A24,
    D_800E3A24, D_800E3A30, D_800E3A3C, D_800E3A48
};

s16 *D_800E3BF0[] = {
    D_800E3A54, D_800E3A60, D_800E3A6C, D_800E3A84,
    D_800E3A78, D_800E3A78, D_800E3A90, D_800E3A9C
};

s16 *D_800E3C10[] = {
    D_800E3AA8, D_800E3AB4, D_800E3AC0, D_800E3AE4,
    D_800E3ACC, D_800E3AD8, D_800E3ACC, D_800E3AF0
};

s16 *D_800E3C30[] = {
    D_800E3AFC, D_800E3B08, D_800E3B14, D_800E3B38,
    D_800E3B20, D_800E3B2C, D_800E3B44, D_800E3B44
};

s16 **D_800E3C50[] = {
    D_800E3B50, D_800E3B70, D_800E3B90, D_800E3BB0,
    D_800E3BD0, D_800E3BF0, D_800E3C10, D_800E3C30
};

// func_80027D00
s32 get_player_index_for_player(Player *player) {
    s32 index;

    if (player == gPlayerOne) {
        index = 0;
    }
    if (player == gPlayerTwo) {
        index = 1;
    }
    if (player == gPlayerThree) {
        index = 2;
    }
    if (player == gPlayerFour) {
        index = 3;
    }
    if (player == gPlayerFive) {
        index = 4;
    }
    if (player == gPlayerSix) {
        index = 5;
    }
    if (player == gPlayerSeven) {
        index = 6;
    }
    if (player == gPlayerEight) {
        index = 7;
    }
    return index;
}

void func_80027DA8(Player *arg0, s8 arg1) {
    if (D_8015F890 != 1) {
        if ((arg0->type & 0x10) != 0x10) {
            if (((D_8018D168 == 1) && ((arg0->type & 0x4000) == 0x4000)) && ((arg0->type & 0x100) != 0x100)) {
                func_800C94A4(arg1);
                arg0->type |= 0x10;
            } else if ((arg0->type & 0x2000) == 0) {
                func_800C9A88(arg1);
                arg0->type |= 0x10;
            }
        }
    } else if ((arg0->type & 0x10) != 0x10) {
        if ((D_8018D168 == 1) && (arg0 == gPlayerOne)) {
            func_800C94A4(arg1);
            arg0->type |= 0x10;
        } else if ((arg0->type & 0x2000) == 0) {
            func_800C9A88(arg1);
            arg0->type |= 0x10;
        }
    }
}

void func_80027EDC(Player *player, s8 playerId) {
    UNUSED s32 pad;
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
        switch (gCurrentCourseId) {
        case COURSE_MARIO_RACEWAY:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x19B) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x1B9)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_CHOCO_MOUNTAIN:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0xA0) && ((s16)gNearestWaypointByPlayerId[playerId] < 0xB4)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_BOWSER_CASTLE:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x29) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x1D2)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x41);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_BANSHEE_BOARDWALK:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x180) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x1E1)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x41);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_LUIGI_RACEWAY:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x145) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x18B)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_TOADS_TURNPIKE:
            if ((player->type & PLAYER_CINEMATIC_MODE) != PLAYER_CINEMATIC_MODE) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x1e);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_SHERBET_LAND:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x11C) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x209)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA288(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA2B8(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_DK_JUNGLE:
            if ((((s16)gNearestWaypointByPlayerId[playerId] >=     0) && ((s16)gNearestWaypointByPlayerId[playerId] <  0x65)) ||
                (((s16)gNearestWaypointByPlayerId[playerId] >= 0x14A) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x21F))) {
                if (D_80165300[playerId] != 2) {
                    func_800C8F80(playerId, 0x0170802D);
                }
                D_80165300[playerId] = 2;
            } else {
                if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x288) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x305)) {
                    if (D_80165300[playerId] != 1) {
                        func_800CA288(playerId, 0x55);
                    }
                    D_80165300[playerId] = 1;
                } else {
                    if (D_80165300[playerId] != 0) {
                        if (D_80165300[playerId] == 1) {
                            func_800CA2B8(playerId);
                        }
                        if (D_80165300[playerId] == 2) {
                            func_800C9018(playerId, 0x0170802D);
                        }
                        D_80165300[playerId] = 0;
                    }
                }
            }
            break;
        default:
            break;
        }
    } else {
        switch (gCurrentCourseId) {
        case COURSE_MARIO_RACEWAY:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x19B) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x1B9)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_CHOCO_MOUNTAIN:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0xA0) && ((s16)gNearestWaypointByPlayerId[playerId] < 0xB4)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_BOWSER_CASTLE:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x29) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x1D2)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x41);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_BANSHEE_BOARDWALK:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x180) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x1E1)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x41);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_LUIGI_RACEWAY:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x145) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x18B)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_TOADS_TURNPIKE:
            if ((player->type & PLAYER_CINEMATIC_MODE) != PLAYER_CINEMATIC_MODE) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x1E);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_SHERBET_LAND:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x11C) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x209)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        case COURSE_DK_JUNGLE:
            if (((s16)gNearestWaypointByPlayerId[playerId] >= 0x288) && ((s16)gNearestWaypointByPlayerId[playerId] < 0x305)) {
                if (D_80165300[playerId] != 1) {
                    func_800CA2E4(playerId, 0x55);
                }
                D_80165300[playerId] = 1;
            } else {
                if (D_80165300[playerId] != 0) {
                    func_800CA30C(playerId);
                    D_80165300[playerId] = 0;
                }
            }
            break;
        default:
            break;
        }
    }
}

void func_80028864(Player *player, Camera *camera, s8 arg2, s8 arg3) {
    u16 sp1E;
    
    if (!(player->type & PLAYER_START_SEQUENCE)) {
        switch (gActiveScreenMode) {
            case SCREEN_MODE_1P:
                sp1E = check_player_camera_collision(player, camera1, (f32) D_8016557C, 0.0f);
                break;
            case SCREEN_MODE_2P_SPLITSCREEN_HORIZONTAL:
            case SCREEN_MODE_2P_SPLITSCREEN_VERTICAL:
                sp1E = check_player_camera_collision(player, camera1, (f32) D_8016557C, 0.0f);
                if (sp1E == 1) break;
                sp1E = check_player_camera_collision(player, camera2, (f32) D_8016557C, 0.0f);
                break;
            case SCREEN_MODE_3P_4P_SPLITSCREEN:
                sp1E = check_player_camera_collision(player, camera1, (f32) D_8016557C, 0.0f); 
                if (sp1E == 1) break;
                sp1E = check_player_camera_collision(player, camera2, (f32) D_8016557C, 0.0f);    
                if (sp1E == 1) break; 
                sp1E = check_player_camera_collision(player, camera3, (f32) D_8016557C, 0.0f);        
                if (sp1E == 1) break; 
                sp1E = check_player_camera_collision(player, camera4, (f32) D_8016557C, 0.0f);
                break;   
        }
        if ((sp1E == 1) || 
            ((player->type & PLAYER_INVISIBLE_OR_BOMB) == PLAYER_INVISIBLE_OR_BOMB) || 
            (gModeSelection == 3) || 
            ((player->unk_0CA & 2) != 0) || 
            (player->unk_0CA & 8) || 
            ((*((&D_801633F8) + (arg2))) == ((s16) 1U))) {
                player->effects &= ~0x1000;
                if (((player->effects & 0x80) == 0x80) || 
                    ((player->effects & 0x40) == 0x40) || 
                    ((player->effects & 0x400) == 0x400) || 
                    ((player->effects & 0x4000) == 0x4000) || 
                    ((player->effects & 0x80000) == 0x80000) || 
                    ((player->effects & 0x800000) == 0x800000) || 
                    ((player->effects & 0x01000000) == 0x01000000) || 
                    ((player->effects & 0x02000000) == 0x02000000) || 
                    ((player->effects & 0x20000) == 0x20000) || 
                    (player->unk_044 & 0x800)) {
                        func_8002E594(player, camera, arg3, arg2);
                } else {
                    func_8002D268(player, camera, arg3, arg2);
                }
        } else {
            control_cpu_movement(player, camera, arg3, arg2);
        }
    } else if ((player->type & PLAYER_STAGING) == PLAYER_STAGING) {
        func_8002D028(player, arg2);
        func_8002F730(player, camera, arg3, arg2);
    } else if (player->type & 0x80) {
        func_8002D268(player, camera, arg3, arg2);
    } else {
        if ((player->type & PLAYER_HUMAN) != PLAYER_HUMAN) {
            player->currentSpeed = 50.0f;
        }
        player->effects &= ~8;
    }
}

void func_80028C44(Player *player, Camera *camera, s8 arg2, s8 arg3) { 
    if ((player->type & PLAYER_START_SEQUENCE) == 0) {
        player->effects &= ~0x1000;
        if (((player->effects & 0x80) == 0x80) || 
            ((player->effects & 0x40) == 0x40) || 
            ((player->effects & 0x400) == 0x400) || 
            ((player->effects & 0x4000) == 0x4000) || 
            ((player->effects & 0x80000) == 0x80000) || 
            ((player->effects & 0x800000) == 0x800000) || 
            ((player->effects & 0x1000000) == 0x1000000) || 
            ((player->effects & 0x2000000) == 0x2000000) || 
            ((player->effects & 0x20000) == 0x20000) || 
            ((player->unk_044 & 0x800) != 0)) {
                func_8002E594(player, camera, arg3, arg2);
        } else {
			func_8002D268(player, camera, arg3, arg2);
		}
    } else {
		player->effects &= -9;
	}
}

void func_80028D3C(Player *player, Camera *camera, s8 arg2, s8 arg3) {
   if ((((player->type & PLAYER_START_SEQUENCE) == 0)
        && (D_800DC510 != 5))
        || (player->unk_0CA & 2) != 0
        || (player->unk_0CA & 8) != 0
        || (player->effects & 0x4F010CC0) != 0) {
            player->effects &= ~0x1000;
       
            if (((player->effects & 0x80) == 0x80) || 
                ((player->effects & 0x40) == 0x40) || 
                ((player->effects & 0x400) == 0x400) || 
                ((player->effects & 0x4000) == 0x4000) || 
                ((player->effects & 0x80000) == 0x80000) || 
                ((player->effects & 0x800000) == 0x800000) || 
                ((player->effects & 0x1000000) == 0x1000000) || 
                ((player->effects & 0x2000000) == 0x2000000) || 
                ((player->effects & 0x20000) == 0x20000) || 
                ((player->unk_044 & 0x800) != 0)) {
                    func_8002E594(player, camera, arg3, arg2);
            } else {
                func_8002D268(player, camera, arg3, arg2);
            }
    } else {
        player->effects = player->effects & ~8;
    }
}

void func_80028E70(Player *player, Camera *camera, s8 arg2, s8 arg3)  {
    if ((player->type & PLAYER_EXISTS) == PLAYER_EXISTS) {
        switch (gGamestate) {
            case ENDING_SEQUENCE:
                if (!(player->type & PLAYER_START_SEQUENCE)) {
                    func_80038C6C(player, camera, arg3, arg2);
                } else {
                    player->effects &= ~8;
                }         
                break;
            default: 
                func_80027DA8(player, arg2);
                switch (gModeSelection) {
                    case TIME_TRIALS:
                    case VERSUS:
                        func_80028C44(player, camera, arg2, arg3);
                        break;
                    case BATTLE:
                        func_80028D3C(player, camera, arg2, arg3);
                        break;
                    default:
                        func_80028864(player, camera, arg2, arg3);
                        break;
                } 
                break;
        }
    }
}

UNUSED void func_80028F5C(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2, UNUSED s32 arg3) {

}

void func_80028F70(void) {
    gMatrixEffectCount = 0;
    func_80028E70(gPlayerOneCopy, camera1, 0, 0);
    func_80028E70(gPlayerTwo, camera1, 1, 0);
    func_80028E70(gPlayerThree, camera1, 2, 0);
    func_80028E70(gPlayerFour, camera1, 3, 0);
    func_80028E70(gPlayerFive, camera1, 4, 0);
    func_80028E70(gPlayerSix, camera1, 5, 0);
    func_80028E70(gPlayerSeven, camera1, 6, 0);
    func_80028E70(gPlayerEight, camera1, 7, 0);
}

void func_80029060(void) {
    gMatrixEffectCount = 0;
    func_80028E70(gPlayerOneCopy, camera1, 0, 0);
    func_80028E70(gPlayerTwo, camera1, 1, 0);
    func_80028E70(gPlayerThree, camera1, 2, 0);
    func_80028E70(gPlayerFour, camera1, 3, 0);
    func_80028E70(gPlayerFive, camera1, 4, 0);
    func_80028E70(gPlayerSix, camera1, 5, 0);
    func_80028E70(gPlayerSeven, camera1, 6, 0);
    func_80028E70(gPlayerEight, camera1, 7, 0);
}

void func_80029150(void) {

}

void func_80029158(void) {
    gMatrixEffectCount = 0;
    func_80028E70(gPlayerOneCopy, camera1, 0, 0);
    func_80028E70(gPlayerTwo, camera1, 1, 0);
    func_80028E70(gPlayerThree, camera1, 2, 0);
    func_80028E70(gPlayerFour, camera1, 3, 0);
}

void func_800291E8(void) {

}

void func_800291F0(void) {

}

void func_800291F8(void) {

}

void func_80029200(Player *player, s8 arg1) {
    if ((s32) player->slopeAccel < -0x71B) {
        player->animGroupSelector[arg1] = 0;
    }
    if (((s32) player->slopeAccel < -0x4F9) && ((s32) player->slopeAccel >= -0x71B)) {
        player->animGroupSelector[arg1] = 1;
    }
    if ((player->slopeAccel < -0x221) && (player->slopeAccel >= -0x4F9)) {
        player->animGroupSelector[arg1] = 2;
    }
    if ((player->slopeAccel < -0x16B) && (player->slopeAccel >= -0x221)) {
        player->animGroupSelector[arg1] = 3;
    }
    if ((player->slopeAccel < 0x16C) && (player->slopeAccel >= -0x16B)) {
        player->animGroupSelector[arg1] = 4;
    }
    if ((player->slopeAccel >= 0x16C) && (player->slopeAccel < 0x222)) {
        player->animGroupSelector[arg1] = 5;
    }
    if ((player->slopeAccel >= 0x222) && (player->slopeAccel < 0x4FA)) {
        player->animGroupSelector[arg1] = 6;
    }
    if ((player->slopeAccel >= 0x4FA) && (player->slopeAccel < 0x71C)) {
        player->animGroupSelector[arg1] = 7;
    }
    if (player->slopeAccel >= 0x71C) {
        player->animGroupSelector[arg1] = 8;
    }
}

void func_8002934C(Player *player, Camera *camera, s8 arg2, s8 playerId) {
    UNUSED s32 pad[2];
    f32 temp_f0;
    f32 temp_f2;
    UNUSED s32 pad2[3];
    f32 var_f0;
    s16 temp_a0;
    s32 temp_a0_2;
    s32 var_a1;
    s32 var_t0;
    u16 var_a0;

    player->unk_048[arg2] = atan2s(player->pos[0] - camera->pos[0], player->pos[2] - camera->pos[2]);
    player->animFrameSelector[arg2] = (u16) ( (((player->unk_048[arg2]) + player->unk_02C[1] + player->unk_0C0))) / 128;

    temp_f2 = (gCharacterSize[player->characterId] * 18.0f) * player->size;
    temp_f0 = player->unk_230 - player->unk_23C;
    if ((player->effects & 8) != 8) {
        if ((player->effects & LIGHTNING_EFFECT) == LIGHTNING_EFFECT) {
            player->unk_0CC[arg2] = (s16) ((s32) (((f64) func_802B7C40(temp_f0 / temp_f2)) * 1.6));
        } else {
            player->unk_0CC[arg2] = func_802B7C40(temp_f0 / temp_f2) * 2;
        }
    }
    if ((player->effects & 0x04000000) == 0x04000000) {
        player->unk_0CC[arg2] = (s16) ((s32) player->unk_D9C);
    }
    if ((player->effects & 8) != 8) {
        temp_f0 = player->unk_1F8 - player->unk_1FC;
        player->unk_0D4[arg2] = (((func_802B7C40(temp_f0 / temp_f2)) * 0.9));
    }
    else {
        if (((player->animFrameSelector[arg2]) >= 0) && ((player->animFrameSelector[arg2]) < 0x101)) {
            var_f0 = player->rotY - player->pos[1];
        } else {
            var_f0 = player->pos[1] - player->rotY;
        }
        player->unk_0D4[arg2] = (s16) ((s32) (((f64) func_802B7C40(var_f0 / temp_f2)) * 0.5));
    }
    if ((player->effects & 0x04000000) == 0x04000000) {
        player->unk_0D4[arg2] = (s16) ((s32) player->unk_D9C);
    }
    func_80029200(player, arg2);
    temp_a0 = ((player->unk_048[arg2] + player->unk_02C[1]) + player->unk_0C0);
    temp_a0 = (s16) player->unk_0D4[arg2] * sins((u16) temp_a0) + player->unk_0CC[arg2] * coss((u16) temp_a0);
    move_s16_towards(&player->unk_050[arg2], temp_a0, 0.5f);
    var_a0 = player->animFrameSelector[arg2];
    player->unk_002 = player->unk_002 & (~(4 << (arg2 * 4)));
    if (var_a0 >= 0x101) {
        var_a0 = 0x201 - var_a0;
        player->unk_002 |= (4 << (arg2 * 4));
    }
    if (((player->effects & 0x80) != 0x80)
        && ((player->effects & 0x40) != 0x40)
        && ((player->effects & 0x80000) != 0x80000)
        && ((player->effects & 0x800000) != 0x800000)
        && ((player->effects & 0x20000) != 0x20000)
        && (!(player->unk_044 & 0x800))) {
        if (var_a0 < 0x51) {
            var_a1 = 0x208;
            var_t0 = 0;
        } else {
            var_a1 = 0x666;
            var_t0 = 0xF;
        }
    }
    else {
        var_a1 = 0x666;
        var_t0 = 0;
    }
    if (((player->effects & 0x80000) == 0x80000)
        || ((player->effects & 0x800000) == 0x800000)
        || (player->unk_044 & 0x800)) {
        player->unk_050[arg2] = 0;
    }
    if (((player->effects & 8) == 8) 
        && ((player->unk_0CA & 2) == 2)) {
        player->unk_050[arg2] = 0;
    }
    var_a0 = (player->unk_048[arg2] + player->unk_02C[1] + player->unk_0C0);
    if (((player->effects & 0x80) == 0x80)
        || ((player->effects & 0x40) == 0x40)
        || ((player->effects & 0x80000) == 0x80000)
        || ((player->effects & 0x800000) == 0x800000)
        || ((player->effects & 0x20000) == 0x20000)
        || (player->unk_044 & 0x800)) {
        if (var_a0 >= 0x7FF9) {
            var_a0 = -var_a0;
            var_a0 /= var_a1;
            if (var_a0 == 0) {
                var_a0 = 1;
            }
        } else {
            var_a0 /= var_a1;
        }
    } else {
        if (var_a0 >= 0x7FF9) {
            var_a0 = (-var_a0);
        }
        var_a0 /= var_a1;
    }
    player->animFrameSelector[arg2] = var_a0 + var_t0;
    if ((player->animFrameSelector[arg2]) >= 0x23) {
        player->animFrameSelector[arg2] = 0x22;
    }
    if ((player->effects & 0x80)
        || (player->effects & 0x40)
        || (player->effects & 0x80000)
        || (player->effects & 0x800000)
        || (player->effects & 0x20000)
        || (player->unk_044 & 0x800)) {
        
        if ((player->animFrameSelector[arg2]) >= 0x14) {
            player->animFrameSelector[arg2] = 0;
        }
    }
    if ((player->animGroupSelector[arg2]) >= 9) {
        player->animGroupSelector[arg2] = 4;
    }
    if (((player->effects & 0x80000) == 0x80000)
        || ((player->effects & 0x800000) == 0x800000)
        ||  (player->unk_044 & 0x800)) {

        player->animGroupSelector[arg2] = 4;
    }
    if (((player->effects & 0x400) == 0x400)
        || ((player->effects & 0x01000000) == 0x01000000)
        || ((player->effects & 0x02000000) == 0x02000000)
        || (player->effects & 0x10000)
        || (player->effects & 0x80)
        || (player->effects & 0x40)) {
        
        player->unk_002 |= 1 << (arg2 * 4);
        D_80165190[arg2][playerId] = 1;
        
        if ((player->effects & 0x80) || (player->effects & 0x40)) {
            if ((player->animFrameSelector[arg2] == D_801650D0[arg2][playerId])
                && (player->animGroupSelector[arg2] == D_80165110[arg2][playerId])) {
                player->unk_002 &= ~(1 << (arg2 * 4));
                D_80165190[arg2][playerId] = 1;
            }
        } else if (((player->unk_0A8) >> 8) == D_80165150[arg2][playerId] >> 8) {
            player->unk_002 &= ~(1 << (arg2 * 4));
        }
    } else {
        player->unk_002 |= 1 << (arg2 * 4);
        if (((player->animFrameSelector[arg2] == D_801650D0[arg2][playerId]) && (player->animGroupSelector[arg2] == D_80165110[arg2][playerId])) && ((D_80165190[arg2][playerId]) == 0)) {
            player->unk_002 &= ~(1 << (arg2 * 4));
        }
    }
    temp_a0_2 = D_801650D0[arg2][playerId] - player->animFrameSelector[arg2];
    if ((temp_a0_2 >= 0x14) || (temp_a0_2 < (-0x13))) {
        player->unk_002 |= 1 << (arg2 * 4);
    }
}

void func_80029B4C(Player *player, UNUSED f32 arg1, f32 arg2, UNUSED f32 arg3) {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    Vec3f sp8C;
    Vec3f sp80;
    Mat3 sp5C;
    UNUSED s32 pad;
    f32 temp_f0_2;
    f32 temp_f2_3;
    s16 temp_v0;
    f32 var_f12;

    if ((player->effects & LIGHTNING_EFFECT) == LIGHTNING_EFFECT) {
        var_f12 = 18.0f * ((((gCharacterSize[player->characterId] / 2)) * ((player->size) * 1.5)));
    }
    else {
        var_f12 = 18.0f * (gCharacterSize[player->characterId] / 2);
    }
    
    calculate_orientation_matrix(sp5C, 0.0f, 1.0f, 0.0f, (player->unk_02C[1] + player->unk_0C0));
    sp8C[0] = var_f12 - 3.6;
    sp8C[1] = -player->boundingBoxSize;
    sp8C[2] = var_f12 - 2.0f;
    mtxf_translate_vec3f_mat3(sp8C, sp5C);
    sp80[0] = player->boundingBoxCorners[0].cornerPos[0];
    sp80[1] = player->boundingBoxCorners[0].cornerPos[1];
    sp80[2] = player->boundingBoxCorners[0].cornerPos[2];
    player->boundingBoxCorners[0].cornerPos[0] = player->pos[0] + sp8C[0];
    player->boundingBoxCorners[0].cornerPos[1] = player->pos[1] + sp8C[1];
    player->boundingBoxCorners[0].cornerPos[2] = player->pos[2] + sp8C[2];
    process_collision(player, &player->boundingBoxCorners[0], sp80[0], sp80[1], sp80[2]);
    
    sp8C[0] = (-var_f12) + 3.6;
    sp8C[1] = -player->boundingBoxSize;
    sp8C[2] = var_f12 - 2.0f;
    mtxf_translate_vec3f_mat3(sp8C, sp5C);
    sp80[0] = player->boundingBoxCorners[1].cornerPos[0];
    sp80[1] = player->boundingBoxCorners[1].cornerPos[1];
    sp80[2] = player->boundingBoxCorners[1].cornerPos[2];
    player->boundingBoxCorners[1].cornerPos[0] = player->pos[0] + sp8C[0];
    player->boundingBoxCorners[1].cornerPos[1] = player->pos[1] + sp8C[1];
    player->boundingBoxCorners[1].cornerPos[2] = player->pos[2] + sp8C[2];
    process_collision(player, &player->boundingBoxCorners[1], sp80[0], sp80[1], sp80[2]);
    
    sp8C[0] = var_f12 - 2.6;
    sp8C[1] = -player->boundingBoxSize;
    sp8C[2] = (-var_f12) + 4.0f;
    mtxf_translate_vec3f_mat3(sp8C, sp5C);
    sp80[0] = player->boundingBoxCorners[2].cornerPos[0];
    sp80[1] = player->boundingBoxCorners[2].cornerPos[1];
    sp80[2] = player->boundingBoxCorners[2].cornerPos[2];
    player->boundingBoxCorners[2].cornerPos[0] = player->pos[0] + sp8C[0];
    player->boundingBoxCorners[2].cornerPos[1] = player->pos[1] + sp8C[1];
    player->boundingBoxCorners[2].cornerPos[2] = player->pos[2] + sp8C[2];
    process_collision(player, &player->boundingBoxCorners[2], sp80[0], sp80[1], sp80[2]);
    
    sp8C[0] = (-var_f12) + 2.6;
    sp8C[1] = -player->boundingBoxSize;
    sp8C[2] = (-var_f12) + 4.0f;
    mtxf_translate_vec3f_mat3(sp8C, sp5C);
    sp80[0] = player->boundingBoxCorners[3].cornerPos[0];
    sp80[1] = player->boundingBoxCorners[3].cornerPos[1];
    sp80[2] = player->boundingBoxCorners[3].cornerPos[2];
    player->boundingBoxCorners[3].cornerPos[0] = player->pos[0] + sp8C[0];
    player->boundingBoxCorners[3].cornerPos[1] = player->pos[1] + sp8C[1];
    player->boundingBoxCorners[3].cornerPos[2] = player->pos[2] + sp8C[2];
    process_collision(player, &player->boundingBoxCorners[3], sp80[0], sp80[1], sp80[2]);
    
    if (!(player->effects & 8)) {
        a = (player->boundingBoxCorners[2].cornerGroundY + player->boundingBoxCorners[0].cornerGroundY) / 2;
        move_f32_towards(&player->unk_230, a, 0.5f);

        b = (player->boundingBoxCorners[3].cornerGroundY + player->boundingBoxCorners[1].cornerGroundY) / 2;
        move_f32_towards(&player->unk_23C, b, 0.5f);

        c = (player->boundingBoxCorners[1].cornerGroundY + player->boundingBoxCorners[0].cornerGroundY) / 2;
        move_f32_towards(&player->unk_1FC, c, 0.5f);

        d = (player->boundingBoxCorners[3].cornerGroundY + player->boundingBoxCorners[2].cornerGroundY) / 2;
        move_f32_towards(&player->unk_1F8, d, 0.5f);
    }
    temp_f2_3 = ((gCharacterSize[player->characterId] * 18.0f) + 1.0f) * player->size;
    temp_f0_2 = player->unk_23C - player->unk_230;
    player->unk_206 = -func_802B7C40(temp_f0_2 / temp_f2_3);
    if (((player->unk_0CA & 2) == 2) || (player->effects & 8)) {
        player->unk_206 = 0;
    }
    if ((player->effects & 8) != 8) {
        temp_f0_2 = player->unk_1F8 - player->unk_1FC;
        move_s16_towards(&player->slopeAccel, func_802B7C40(temp_f0_2 / temp_f2_3), 0.5f);
    }
    else {
        temp_f0_2 = player->rotY - arg2;
        temp_v0 = func_802B7C40(temp_f0_2 / temp_f2_3);
        if (temp_f0_2 >= 0.0f) {
            temp_v0 /= 4;
        }
        else {
            temp_v0 *= 10;
        }
        move_s16_towards(&player->slopeAccel, temp_v0, 0.5f);
    }
    if (((player->effects & 8) == 8) && ((player->unk_0CA & 2) == 2)) {
        player->slopeAccel = (s16) ((s32) player->unk_D9C);
    }
    player->unk_0F8 = get_surface_type(player->unk_110.unk3A) & 0xFF;
    if (player->unk_0F8 == 0xFE) {
        if (((player->effects & 0x100000) != 0x100000) && ((player->effects & 8) != 8)) {
            player->statusEffects |= 0x800000;
        }
    }
    if (player->unk_0F8 == 0xFC) {
        if (((player->effects & 4) != 4) && ((player->effects & 8) != 8)) {
            player->statusEffects |= 0x8000;
        }
    }
}

void func_8002A194(Player *player, f32 arg1, f32 arg2, f32 arg3) {
    UNUSED s32 pad[2];
    f32 temp_f12;
    f32 var_f20;
    s32 temp_v0;
    s16 temp_v1;
    s16 var_a1;
    UNUSED s32 pad2;
    f32 temp_f0;

    temp_v1 = -player->unk_02C[1] - player->unk_0C0;
    if ((player->effects & LIGHTNING_EFFECT) == LIGHTNING_EFFECT) {
        var_f20 = (((gCharacterSize[player->characterId] * 18) / 2) * (player->size * 1.5)) - 1;
    } else {
        var_f20 = (((gCharacterSize[player->characterId] * 18) / 2) * player->size) - 1;
    }

    player->boundingBoxCorners[0].cornerPos[2] = (coss(temp_v1 + 0x2000) * var_f20) + arg3;
    temp_f12 = (sins(temp_v1 + 0x2000) * var_f20) + arg1;
    player->boundingBoxCorners[0].cornerPos[0] = temp_f12;
    player->boundingBoxCorners[0].cornerGroundY = func_802ABE30(temp_f12, arg2, player->boundingBoxCorners[0].cornerPos[2], player->unk_110.unk3A);

    player->boundingBoxCorners[1].cornerPos[2] = (coss(temp_v1 - 0x2000) * var_f20) + arg3;
    temp_f12 = (sins(temp_v1 - 0x2000) * var_f20) + arg1;
    player->boundingBoxCorners[1].cornerPos[0] = temp_f12;
    player->boundingBoxCorners[1].cornerGroundY = func_802ABE30(temp_f12, arg2, player->boundingBoxCorners[1].cornerPos[2], player->unk_110.unk3A);

    player->boundingBoxCorners[2].cornerPos[2] = (coss(temp_v1 + 0x6000) * var_f20) + arg3;
    temp_f12 = (sins(temp_v1 + 0x6000) * var_f20) + arg1;
    player->boundingBoxCorners[2].cornerPos[0] = temp_f12;
    player->boundingBoxCorners[2].cornerGroundY = func_802ABE30(temp_f12, arg2, player->boundingBoxCorners[2].cornerPos[2], player->unk_110.unk3A);

    player->boundingBoxCorners[3].cornerPos[2] = (coss(temp_v1 - 0x6000) * var_f20) + arg3;
    player->boundingBoxCorners[3].cornerPos[0] = (sins(temp_v1 - 0x6000) * var_f20) + arg1;
    player->boundingBoxCorners[3].cornerGroundY = func_802ABE30(player->boundingBoxCorners[2].cornerPos[0], arg2, player->boundingBoxCorners[2].cornerPos[2], player->unk_110.unk3A);

    if ((player->effects & 8) != 8) {
        player->unk_230 = (player->boundingBoxCorners[2].cornerGroundY + player->boundingBoxCorners[0].cornerGroundY) / 2;
        player->unk_23C = (player->boundingBoxCorners[3].cornerGroundY + player->boundingBoxCorners[1].cornerGroundY) / 2;
        player->unk_1FC = (player->boundingBoxCorners[1].cornerGroundY + player->boundingBoxCorners[0].cornerGroundY) / 2;
        player->unk_1F8 = (player->boundingBoxCorners[3].cornerGroundY + player->boundingBoxCorners[2].cornerGroundY) / 2;
    }
    player->unk_0F8 = (u8)get_surface_type(player->unk_110.unk3A);
    player->boundingBoxCorners[3].surfaceType = player->unk_0F8;
    player->boundingBoxCorners[2].surfaceType = player->unk_0F8;
    player->boundingBoxCorners[1].surfaceType = player->unk_0F8;
    player->boundingBoxCorners[0].surfaceType = player->unk_0F8;
    var_f20 = (gCharacterSize[player->characterId] * 18) + 1;
    temp_f0 = (player->unk_23C - player->unk_230);
    player->unk_206 = -func_802B7C40(temp_f0 / var_f20);
    if ((player->effects & 8) != 8) {
        temp_f0 = (player->unk_1F8 - player->unk_1FC);
        move_s16_towards(&player->slopeAccel, func_802B7C40(temp_f0 / var_f20), 0.5f);
    } else {
        temp_f0 = player->rotY - arg2;
        temp_v0 = func_802B7C40(temp_f0 / var_f20);
        if (temp_f0 >= 0.0f) {
            var_a1 = temp_v0 * 2;
        } else {
            var_a1 = temp_v0 * 0xA;
        }
        move_s16_towards(&player->slopeAccel, var_a1, 0.5f);
    }
    if (func_802ABD7C(player->unk_110.unk3A) != 0) {
        player->boundingBoxCorners[3].unk_14 |= 1;
    } else {
        player->boundingBoxCorners[3].unk_14 &= ~1;
    }
    if (player->unk_0F8 == 0x00FE) {
        if (((player->effects & 0x100000) != 0x100000) && ((player->effects & 8) != 8)) {
            player->statusEffects |= 0x800000;
        }
    }
    if (player->unk_0F8 == 0x00FC) {
        if (((player->effects & 4) != 4) && ((player->effects & 8) != 8)) {
            player->statusEffects |= 0x8000;
        }
    }
}

// Near identical to func_802AC114 in memory.c
void func_8002A5F4(Vec3f arg0, f32 arg1, Vec3f arg2, f32 arg3, f32 arg4) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f20;
    f32 tmp1;
    f32 tmp2;
    f32 tmp3;

    temp_f0  =  arg2[0];
    temp_f2  =  arg2[1];
    temp_f12 =  arg2[2];
    temp_f14 = -arg0[0];
    temp_f16 = -arg0[1];
    temp_f18 = -arg0[2];
    temp_f20 = (temp_f14 * temp_f0) + (temp_f16 * temp_f2) + (temp_f18 * temp_f12);
    tmp1 = temp_f0  - (temp_f20 * temp_f14);
    tmp2 = temp_f2  - (temp_f20 * temp_f16);
    tmp3 = temp_f12 - (temp_f20 * temp_f18);
    if (arg1 < -arg4) {
        arg2[0] = tmp1 - (temp_f20 * temp_f14 * arg3);
        arg2[1] = tmp2 - (temp_f20 * temp_f16 * arg3);
        arg2[2] = tmp3 - (temp_f20 * temp_f18 * arg3);
    } else {
        arg2[0] = tmp1;
        arg2[1] = tmp2;
        arg2[2] = tmp3;
    }
}

void func_8002A704(Player *player, s8 arg1) {
    player->effects |= 0x2000;
    player->statusEffects &= ~0x02000000;
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
        func_800C90F4(0U, (player->characterId * 0x10) + 0x29008001);
        func_800C9060(arg1, 0x1900A40BU);
    }
    player->boostTimer = 0x0050;
}

void func_8002A79C(Player *player, s8 arg1) {
    if (((player->effects & 0x100) != 0x100) && ((player->effects & 0x10) != 0x10) && (player->unk_22A >= 2)) {
        player->effects |= 0x100;
        player->unk_23A = 0;
        player->unk_22A = 0;
        player->unk_228 = 0;
        if (D_8015F890 != 1) {
            if ((player->type & PLAYER_HUMAN) && !(player->type & PLAYER_INVISIBLE_OR_BOMB)) {
                func_800C9250(arg1);
            }
        } else if (player == gPlayerOne) {
            func_800C9250(arg1);
        }
    } else if ((player->effects & 0x100) == 0x100) {
        player->unk_23A += 1;
        if (player->unk_23A >= 0x1F) {
            player->unk_23A = 0;
            player->effects &= ~0x100;
            player->unk_22A = 0;
            player->unk_228 = 0;
        }
    }
}

void func_8002A8A4(Player *player, s8 arg1) {
    if (((s16) player->unk_0C0 / 182) > 0) {
        if (((s32) player->unk_07C >> 0x10) < -9) {
            if (player->unk_228 < 0x65) {
                player->unk_228++;
            }
            if ((player->unk_228 == 0x0064) && (player->type & PLAYER_HUMAN)) {
                func_800C9060(arg1, 0x1900851EU);
            }
        } else {
            if ((player->unk_228 >= 0x12) && (player->unk_228 < 0x64)) {
                if (player->unk_22A < 3) {
                    player->unk_22A++;
                }
            }
            if ((player->unk_228 >= 0xA) && (player->unk_228 < 0x64)) {
                player->unk_228 = 0x000A;
            } else {
                player->unk_228 = 0;
                player->unk_22A = 0;
            }
        }
    } else if (((s32) player->unk_07C >> 0x10) >= 0xA) {
        if (player->unk_228 < 0x65) {
            player->unk_228++;
        }
        if ((player->unk_228 == 0x0064) && (player->type & PLAYER_HUMAN)) {
            func_800C9060(arg1, 0x1900851EU);
        }
    } else {
        if ((player->unk_228 >= 0x12) && (player->unk_228 < 0x64)) {
            if (player->unk_22A < 3) {
                player->unk_22A++;
            }
        }
        if ((player->unk_228 >= 0xA) && (player->unk_228 < 0x64)) {
            player->unk_228 = 0x000A;
        } else {
            player->unk_228 = 0;
            player->unk_22A = 0;
        }
    }
}

void func_8002AA50(Player *player) {
    player->kartHopJerk = gKartHopJerkTable[player->characterId];
    player->kartHopAcceleration = 0.0f;
    player->kartHopVelocity = gKartHopInitialVelocityTable[player->characterId];
    player->effects |= 2;
    player->unk_DAC = 3.0f;
    player->kartGravity = 500.0f;
    func_80036C5C(player);
}

/**
  * Function: func_8002AAC0

  * Parameters:
  *     Player *player - A pointer to a Player

  * First kartHopJerk is subtracted from kartHopAcceleration
  * Then kartHopAcceleration is added to kartHopVelocity.

  * If kartHopVelocity is less than or equal to zero, all three
  * values (kartHop{Jerk,Acceleration,Velocity}) are set to 0.0f,
  * thereby ending the rising portion of the hop.

  * kartHopVelocity is restricted to values in [-INF, 15.0f]

  * kartHopAcceleration is restricted to values in [-9.0f, 9.0f]
**/
void func_8002AAC0(Player *player) {
    player->kartHopAcceleration -= player->kartHopJerk;
    if (player->kartHopAcceleration >= 9.0f) {
        player->kartHopAcceleration = 9.0f;
    }

    if (player->kartHopAcceleration <= -9.0f) {
        player->kartHopAcceleration = -9.0f;
    }

    player->kartHopVelocity += player->kartHopAcceleration;
    if (player->kartHopVelocity >= 15.0f) {
        player->kartHopVelocity = 15.0f;
    }

    if (player->kartHopVelocity <= 0.0f) {
        player->kartHopJerk = 0.0f;
        player->kartHopAcceleration = 0.0f;
        player->kartHopVelocity = 0.0f;
    }
}

void func_8002AB70(Player *player) {
    UNUSED s32 pad[2];
    if (((player->effects & 8) != 8) && (player->unk_08C > 0.0f)) {
        if (((player->slopeAccel / 182) < -1) && ((player->slopeAccel / 182) >= -0x14) && (((player->unk_094 / 18.0f) * 216.0f) >= 20.0f)) {
            move_f32_towards(&player->kartGravity, 500.0f, 1.0f);
            move_f32_towards(&player->unk_DAC, 3.0f, 0.05f);
        } else {
            move_f32_towards(&player->kartGravity, gKartGravityTable[player->characterId], 0.1f);
            move_f32_towards(&player->unk_DAC, 1.0f, 0.07f);
        }
    } else {
        if (player->unk_110.unk3C[2] >= 50.0f) {
            player->unk_DAC = 2.0f;
        }
        move_f32_towards(&player->kartGravity, gKartGravityTable[player->characterId], 0.02f);
        if ((player->effects & 2) == 2) {
            move_f32_towards(&player->unk_DAC, 1.0f, 0.07f);
        } else {
            move_f32_towards(&player->unk_DAC, 1.0f, 0.07f);
        }
    }
    if ((player->effects & 0x100000) == 0x100000) {
        move_f32_towards(&player->unk_DAC, 20.0f, 1.0f);
        player->kartGravity = 3500.0f;
    }
    if ((player->effects & 4) == 4) {
        move_f32_towards(&player->unk_DAC, 25.0f, 1.0f);
        player->kartGravity = 1800.0f;
    }
    if ((player->effects & 0x400) == 0x400) {
        player->kartGravity = 1100.0f;
    }
    if (player->effects & 0x80000) {
        player->kartGravity = 1500.0f;
    }
    if ((player->unk_044 & 0x800) != 0) {
        player->kartGravity = 1900.0f;
    }
    if ((player->effects & 0x800000) == 0x800000) {
        player->kartGravity = 300.0f;
    }
    if ((player->effects & 0x01000000) == 0x01000000) {
        player->kartGravity = 550.0f;
    }
    if ((player->effects & 0x02000000) == 0x02000000) {
        player->kartGravity = 800.0f;
    }
}

UNUSED void func_8002AE20(void) {

}

UNUSED void func_8002AE28(void) {

}

UNUSED void func_8002AE30(void) {

}

void func_8002AE38(Player *player, s8 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    UNUSED s32 pad[4];
    s16 temp_v0_3;
    f32 sp28;
    f32 temp_f16;
    s16 temp_a0;
    s32 var_v1;

    sp28     = (sins(-player->unk_02C[1]) * player->unk_094) + arg2;
    temp_f16 = (coss(-player->unk_02C[1]) * player->unk_094) + arg3;
    if (
        ((player->effects & 0x800) != 0x800) &&
        ((player->effects & 0x10) != 0x10) &&
        !(player->unk_044 & 0x4000) &&
        (
            (((player->unk_094 / 18.0f) * 216.0f) <= 8.0f) ||
            (
                ((player->unk_07C >> 0x10) < 5) &&
                ((player->unk_07C >> 0x10) > -5)
            )
        )) {
        if ((player->effects & 0x20) == 0x20) {
            player->unk_0C0 = (f32)(player->unk_0C0 - (player->unk_0C0 / 10));
        } else {
            temp_v0_3 = player->unk_0C0;
            player->unk_0C0 = player->unk_078 * 9;
            temp_a0 = player->unk_0C0 - temp_v0_3;
            player->unk_0C0 = (f32)(temp_v0_3 + (temp_a0 / 15));
        }
    } else {
        temp_v0_3 = player->unk_0C0;
        if (D_801652C0[arg1] & 8) {
            var_v1 = 2;
        } else {
            var_v1 = 0;
        }
        if ((player->currentSpeed >= 200.0f) &&
            (var_v1 == 2) &&
            (
                ((player->unk_0C0 / 182) >= 0x10) ||
                ((player->unk_0C0 / 182) < -0xF)
            )) {
            player->unk_0C0 = atan2s(arg2 - arg4, arg3 - arg5) - atan2s(arg2 - sp28, arg3 - temp_f16);
        } else {
            player->unk_0C0 = (atan2s(arg2 - arg4, arg3 - arg5) - atan2s(arg2 - sp28, arg3 - temp_f16)) * 2;
        }
        if (((player->effects & 0x10) != 0x10) &&
            (
                (
                    ((player->unk_07C >> 0x10) > 0) &&
                    (player->unk_0C0 < 0)
                ) ||
                (
                    ((player->unk_07C >> 0x10) < 0) &&
                    (player->unk_0C0 > 0)
                )
            )) {
            if (player->unk_0C0 > 0) {
                player->unk_0C0 = player->unk_078 * 0x14;
            }
            if (player->unk_0C0 < 0) {
                player->unk_0C0 = player->unk_078 * 0x14;
            }
            temp_a0 = player->unk_0C0 - temp_v0_3;
            player->unk_0C0 = (f32)(temp_v0_3 + (temp_a0 / 12));
        } else {
            if (player->unk_0C0 >= 0x1C71) {
                player->unk_0C0 = 0x1C70;
            }
            if (player->unk_0C0 < -0x1C70) {
                player->unk_0C0 = -0x1C70;
            }
            temp_a0 = player->unk_0C0 - temp_v0_3;
            player->unk_0C0 = (f32)(temp_v0_3 + (temp_a0 / 12));
        }
    }
}

void func_8002B218(Player *player) {
    u16 someIndex;
    u16 sp38[10] = { 0x0003, 0x0016, 0x0026, 0x003c, 0x0050, 0x0069, 0x0090, 0x009d, 0x00a9, 0x00cc };
    u16 sp24[10] = { 0x000c, 0x0021, 0x002f, 0x0045, 0x005f, 0x007a, 0x0098, 0x00a5, 0x00b3, 0x00d5 };

    for (someIndex = 0; someIndex < 10; someIndex++) {
        if (player->unk_006 == sp38[someIndex]) {
            player->effects |= 0x10;
            func_8002AA50(player);
            player->unk_204 = 0;
            break;
        }

        if (player->unk_006 == sp24[someIndex]) {
            player->effects &= ~0x10;
            break;
        }
    }
}

void func_8002B308(Player *player, s8 arg1, UNUSED s8 arg2) {
    if ((player->statusEffects & 2) == 2) {
        func_8008EAE0(player, arg1);
    }
    if ((player->statusEffects & 4) == 4) {
        func_8008C528(player, arg1);
    }
    if ((player->statusEffects & 1) == 1) {
        func_8008CDC0(player, arg1);
    }
    if ((player->statusEffects & BOOST_EFFECT) == BOOST_EFFECT) {
        func_8008D3C4(player, arg1);
    }
    if ((player->statusEffects & 0x02000000) == 0x02000000) {
        func_8002A704(player, arg1);
    }
    if ((player->statusEffects & 0x1000) == 0x1000) {
        func_8008D570(player, arg1);
    }
    if ((player->statusEffects & 0x20000) == 0x20000) {
        func_8008D7B0(player, arg1);
    }
    if ((player->statusEffects & 0x100) == 0x100) {
        func_8008DABC(player, arg1);
    }
    if ((player->statusEffects & HIT_ROTATING_EFFECT) == HIT_ROTATING_EFFECT) {
        func_8008DF98(player, arg1);
    }
    if ((player->statusEffects & 0x200000) == 0x200000) {
        func_8008C73C(player, arg1);
    }
    if ((player->statusEffects & REVERSE_EFFECT) == REVERSE_EFFECT) {
        func_8008E6C0(player, arg1);
    }
    if ((player->statusEffects & HIT_BY_ITEM_EFFECT) == HIT_BY_ITEM_EFFECT) {
        func_8008EAE0(player, arg1);
    }
    if ((player->statusEffects & 0x00800000) == 0x00800000) {
        func_8008EC88(player, arg1);
    }
    if ((player->statusEffects & 0x8000) == 0x8000) {
        func_8008EEE4(player, arg1);
    }
    if ((player->statusEffects & STAR_EFFECT) == STAR_EFFECT) {
        func_8008F778(player, arg1);
    }
    if ((player->statusEffects & BOO_EFFECT) == BOO_EFFECT) {
        func_8008FA38(player, arg1);
    }
    if (player->statusEffects & 0x80) {
        func_8008D0FC(player, arg1);
    }
    if (player->statusEffects & 0x80000) {
        func_8008E6C0(player, arg1);
    }
}

void func_8002B5C0(Player *player, UNUSED s8 arg1, UNUSED s8 arg2) {
    if (((player->unk_0CA & 8) != 0) || ((player->unk_0CA & 2) != 0)) {
        player->statusEffects &= 0xFE1D0478;
    }
    if ((player->effects & 0x400) == 0x400) {
        player->statusEffects &= 0xFF5D457E;
    }
    if (((player->effects & 0x80) == 0x80) || ((player->effects & 0x40) == 0x40)) {
        player->statusEffects &= 0xFF5F457E;
    }
    if ((player->effects & 0x800) == 0x800) {
        player->statusEffects &= 0xFF5D457E;
    }
    if ((player->unk_044 & 0x4000) != 0) {
        player->statusEffects &= 0xFF5D457E;
    }
    if ((player->effects & 0x80000) == 0x80000) {
        player->statusEffects &= 0xFE1D4478;
    }
    if ((player->effects & 0x800000) == 0x800000) {
        player->statusEffects &= 0xFE1D0478;
    }
    if ((player->effects & 0x04000000) == 0x04000000) {
        player->statusEffects &= 0xFE1D0578;
    }
    if ((player->effects & 0x01000000) == 0x01000000) {
        player->statusEffects &= 0xFE1D4478;
    }
    if ((player->effects & 0x02000000) == 0x02000000) {
        player->statusEffects &= 0xFE1D4478;
    }
    if ((player->effects & 0x100000) == 0x100000) {
        player->statusEffects &= 0xFE1D0478;
    }
    if ((player->effects & 4) == 4) {
        player->statusEffects &= 0xFE1D0478;
    }
    if ((player->effects & 0x10000) == 0x10000) {
        player->statusEffects &= 0xFE1D0478;
    }
    if ((player->effects & 0x200) == 0x200) {
        player->statusEffects &= 0xFE9D8478;
    }
    if ((player->effects & 0x80000000) == 0x80000000) {
        player->statusEffects &= 0xFE9D8678;
    }
    if ((player->effects & 0x4000) == 0x4000) {
        player->statusEffects &= 0xFF5D45FF;
    }
    if ((player->effects & 0x20000) == 0x20000) {
        player->statusEffects &= 0xFE1D0478;
    }
}

void func_8002B830(Player *player, s8 arg1, s8 arg2) {
    if (player->statusEffects != 0) {
        func_8002B5C0(player, arg1, arg2);
    }
    if (player->statusEffects != 0) {
        func_8002B308(player, arg1, arg2);
    }
    if ((player->unk_044 & 0x400) != 0) {
        func_800911B4(player, arg1);
    }
}

void func_8002B8A4(Player *player_one, Player *player_two) {
    s32 var_v1;

    /*
    if's are being done bracket-less on purpose,
    Technically only the `player_one == gPlayerEight` NEEDS to be
    bracket-less that looks weird
    */
    if (player_one == gPlayerOne)   var_v1 = 0;
    if (player_one == gPlayerTwo)   var_v1 = 1;
    if (player_one == gPlayerThree) var_v1 = 2;
    if (player_one == gPlayerFour)  var_v1 = 3;
    if (player_one == gPlayerFive)  var_v1 = 4;
    if (player_one == gPlayerSix)   var_v1 = 5;
    if (player_one == gPlayerSeven) var_v1 = 6;
    if (player_one == gPlayerEight) var_v1 = 7;
    D_801653C0[var_v1] = player_two;
    if (player_two == gPlayerOne)   var_v1 = 0;
    if (player_two == gPlayerTwo)   var_v1 = 1;
    if (player_two == gPlayerThree) var_v1 = 2;
    if (player_two == gPlayerFour)  var_v1 = 3;
    if (player_two == gPlayerFive)  var_v1 = 4;
    if (player_two == gPlayerSix)   var_v1 = 5;
    if (player_two == gPlayerSeven) var_v1 = 6;
    if (player_two == gPlayerEight) var_v1 = 7;
    D_801653C0[var_v1] = player_one;
}

void func_8002B9CC(Player *player, s8 arg1, UNUSED s32 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f14;
    s16 temp;
    s16 temp2;

    if ((player->unk_046 & 2) == 2) {
        temp_f0  = D_8018CE10[arg1].unk_04[0];
        temp_f2  = 0;
        temp_f14 = D_8018CE10[arg1].unk_04[2];
        if (sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14)) >= 6.5) {
            player->unk_08C /= 4;
            player->currentSpeed /= 4;
            if (!(player->effects & 0x80) && !(player->effects & 0x40)) {
                func_8008C73C(player, arg1);
            }
        }
    } else {
        temp_f0  = D_80165070[arg1][0] - player->velocity[0];
        temp_f2  = D_80165070[arg1][1] - player->velocity[1];
        temp_f14 = D_80165070[arg1][2] - player->velocity[2];
        if (sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14)) >= 4.2) {
            player->unk_08C /= 4;
            player->currentSpeed /= 4;
            if (!(player->effects & 0x80) && !(player->effects & 0x40)) {
                func_8008C73C(player, arg1);
            }
        }
        temp = (-(s16)get_angle_between_points(player->pos, &player->rotX));
        temp2 = (player->unk_02C[1] - player->unk_0C0);
        temp = temp - temp2;
        player->unk_234 = temp / 182;

    }
}

void func_8002BB9C(Player *player, f32 *arg1, f32 *arg2, UNUSED s8 arg3, UNUSED s8 arg4, UNUSED Vec3f arg5) {
    Mat3 sp64;
    Vec3f sp58;
    Vec3f sp4C;
    s16 var_v0;
    s16 t0;
    UNUSED s32 pad;
    s16 sp30[10] = {0x0000, 0x00b6, 0x016c, 0x0222, 0x02d8, 0x038e, 0x0444, 0x04fa, 0x05b0, 0x0666};
    
    if (((u16) player->unk_256) <= 0) {
        return;        
    }

    if (((u16) player->unk_256) > 2) {
        return;
    }
    
    if (!(player->unk_046 & 0x20)) {
        return;        
    }
    
    calculate_orientation_matrix(sp64, 0, 1, 0, (s16) 0);
    
    sp58[0] = *arg1;
    sp58[1] = 0;
    sp58[2] = *arg2;
    
    mtxf_translate_vec3f_mat3(sp58, sp64);
    
    sp4C[0] = player->rotX;
    sp4C[1] = 0;
    sp4C[2] = player->rotZ;
    
    mtxf_translate_vec3f_mat3(sp4C, sp64);

    var_v0 = -(s16)get_angle_between_points(sp58, sp4C);
    t0 = player->unk_02C[1];
    var_v0 = 0x10000 + (t0 - var_v0);
    var_v0 /= 182;
    
    if (var_v0 < 0x97 && (var_v0 > -0x97)) {
        return;
    }
    
    var_v0 = (player->unk_07C >> 0x10) / 6;
    
    if (var_v0 < 0) {
        var_v0 *= -1;
    }
    
    if (var_v0 >= 8) {
        var_v0 = 8;
    }
    
    if ((player->unk_07C >> 0x10) < 0) {
        player->unk_02C[1] -= sp30[var_v0];
    } else {
        player->unk_02C[1] += sp30[var_v0];
    }
}
 
void func_8002BD58(Player *player) {
    s32 sp2C[7] = { 0x002f0000, 0x00300000, 0x00310000, 0x00320000, 0x00320000, 0x00320000, 0x00320000 };
    s32  spC[8] = { 0x00280000, 0x002c0000, 0x00300000, 0x00320000, 0x00320000, 0x00320000, 0x00320000, 0x00320000 };
    s16 temp_t5;

    if (player->unk_234 >= 0) {
        if ((player->unk_234 >= 5) && (player->unk_234 < 0x1E)) {
            player->unk_07C = sp2C[player->unk_234 / 6];
        }
        if ((player->unk_234 >= 0x1E) && (player->unk_234 < 0x50)) {
            player->unk_07C = spC[(s32) (player->unk_234 - 0x1E) / 12];
        }
        if (((player->unk_234 < 0x50) || (player->unk_234 >= 0x5B)) && (player->unk_234 >= 0x5B) && (player->unk_234 < 0xA1)) {
            player->unk_07C = spC[1];
        }
    } else {
        temp_t5 = -player->unk_234;
        if ((player->unk_234 < -4) && (player->unk_234 >= -0x1E)) {
            player->unk_07C = sp2C[temp_t5 / 6] * -1;
        }
        if ((player->unk_234 < -0x1E) && (player->unk_234 >= -0x50)) {
            player->unk_07C = spC[(s32) (temp_t5 - 0x1E) / 12] * -1;
        }
        if (((player->unk_234 >= -0x50) || (player->unk_234 < -0x5A)) && (player->unk_234 < -0x5A) && (player->unk_234 >= -0xA0)) {
            player->unk_07C = spC[1] * -1;
        }
    }
}

void func_8002BF4C(Player *player, s8 arg1) {  
    UNUSED s32 pad[3];
    UNUSED s32 uselessAssignment;
    s32 i;
    s32 var_a2;
    Player *playerBorrow;
    Player *players = gPlayerOne;
    
    var_a2 = 0;
    
    if (((player->unk_094 / 18.0f) * 216.0f) < 50.0f) {
        player->unk_0E2 = 0;
        player->effects &= 0xFFDFFFFF;
        return;
    }
    if ((player->effects & 0x200000) == 0x200000) {
        player->unk_0E2 -= 1;
        if (player->unk_0E2 <= 0) {
            player->effects &= 0xFFDFFFFF;
        }
    } else {
        for (i = 0; i < NUM_PLAYERS; i++) {
            playerBorrow = &players[i];
            if (((player != playerBorrow) && 
                ((playerBorrow->type & 0x100) == 0) && 
                (playerBorrow->type & 0x8000)) && 
				((var_a2 = func_8001FD78(player, playerBorrow->pos[0], playerBorrow->pos[1], playerBorrow->pos[2]), var_a2  == 1))) {
                    player->unk_0E2 += 1;
                    if (player->unk_0E2 >= 0x3D) {
                        player->effects |= 0x200000;
                        if ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB) {
                          	uselessAssignment = player->type & PLAYER_INVISIBLE_OR_BOMB;
                           	func_800C90F4(arg1, (player->characterId * 0x10) + 0x29008001);
                        }
                        if ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB) {
                            uselessAssignment = var_a2;
                            func_800C9060(arg1, 0x19008011);
                        }
                    }
                    break;
            }
        }
        
        if (var_a2 == 0) {
            player->unk_0E2 = 0;
        }
    }
}

void func_8002C11C(Player *player) {
    if ((player->effects & 0x10) == 0x10) {
        player->unk_204 += 1;
        if (player->unk_204 >= 0x65) {
            player->unk_204 = 0x64;
        }
    } else {
        player->unk_204 -= 1;
        if (player->unk_204 < 0) {
            player->unk_204 = 0;
        }
    }
}

void func_8002C17C(Player *player, s8 playerId) {
    switch (gCurrentCourseId) {                              /* irregular */
    case COURSE_YOSHI_VALLEY:
        if ((player->unk_110.unk3C[2] >= 600.0f) && (D_80165330[playerId] == 0)) {
            D_80165330[playerId] = 1;
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        } else if (D_80165330[playerId] == 0) {
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        } else if (!(player->effects & 8)) {
            if (func_802ABDF4(player->unk_110.unk3A) == 0) {
                D_80165330[playerId] = 0;
            }
        }
        break;
    case COURSE_FRAPPE_SNOWLAND:
        if ((player->unk_0F8 == 0x000B) && (D_80165330[playerId] == 0)) {
            D_80165330[playerId] = 1;
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        } else if (player->unk_0F8 != 0x000B) {
            D_80165330[playerId] = 0;
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        }
        break;
    case COURSE_ROYAL_RACEWAY:
        if (((player->effects & 0x100000) != 0) && (D_80165330[playerId] == 0)) {
            D_80165330[playerId] = 1;
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        } else if (((player->effects & 0x100000) == 0) && !(player->effects & 8)) {
            D_80165330[playerId] = 0;
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        }
        break;
    case COURSE_RAINBOW_ROAD:
        if ((player->unk_110.unk3C[2] >= 600.0f) && (D_80165330[playerId] == 0)) {
            D_80165330[playerId] = 1;
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        } else if (D_80165330[playerId] == 0) {
            D_80165320[playerId] = gNearestWaypointByPlayerId[playerId];
            D_80165310[playerId] = gPathIndexByPlayerId[playerId];
        } else if (!((player->effects & 8) || (player->unk_0CA & 1))) {
            D_80165330[playerId] = 0;
        }
        break;
    default:
        D_80165330[playerId] = 0;
        if(1){}
        break;
    }
}

void func_8002C4F8(Player *player, s8 arg1) {
    D_801652A0[arg1] = func_802AAB4C(player);
    if (player->pos[1] <= D_801652A0[arg1]) {
        player->unk_0DE |= 0x0002;
    } else {
        player->unk_0DE &= ~0x0002;
    }
    if (player->boundingBoxSize < (D_801652A0[arg1] - player->pos[1])) {
        player->unk_0DE |= 1;
        player->unk_0DE &= ~0x0002;
    } else {
        player->unk_0DE &= ~0x0001;
    }
    if (player->boundingBoxSize < (D_801652A0[arg1] - player->pos[1])) {
        if ((player->unk_0DE & 4) != 4) {
            player->unk_0DE |= 8;
            player->unk_0DE |= 4;
            if ((gCurrentCourseId != COURSE_KOOPA_BEACH)  &&
                (gCurrentCourseId != COURSE_SKYSCRAPER)   &&
                (gCurrentCourseId != COURSE_RAINBOW_ROAD) &&
                ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN)) {
                if ((gCurrentCourseId == COURSE_BOWSER_CASTLE) ||
                    (gCurrentCourseId == COURSE_BIG_DONUT)) {
                    func_800C9060((u8) arg1, 0x1900801CU);
                } else {
                    func_800C9060((u8) arg1, 0x19008008U);
                }
            }
        }
    }
    if ((gCurrentCourseId == COURSE_KOOPA_BEACH) ||
        (gCurrentCourseId == COURSE_SKYSCRAPER)  ||
        (gCurrentCourseId == COURSE_RAINBOW_ROAD)) {
        player->unk_0DE &= ~0x000C;
    }
    if ((player->boundingBoxSize < (D_801652A0[arg1] - player->pos[1])) && (player->unk_110.unk3C[2] >= 600.0f)) {
        player->unk_0CA |= 1;
    }
    if (player->unk_110.unk3C[2] >= 600.0f) {
        player->unk_0CA |= 0x0100;
    } else if ((player->effects & 8) != 8) {
        player->unk_0CA &= ~0x0100;
    }
    if ((player->type & PLAYER_CPU) && ((func_802ABDF4(player->unk_110.unk3A) != 0) || (player->unk_0CA & 1))) {
        if (!(player->unk_0CA & 2) && !(player->unk_0CA & 8) && !(player->effects & 0x1000)) {
            func_80090778(player);
            func_80090868(player);
        }
    }
    if ((player->type & PLAYER_CPU) && (player->unk_0F8 == 0x00FD) && !(player->effects & 8)) {
        func_80090778(player);
        func_80090868(player);
    }
    func_8002C17C(player, arg1);
}

void func_8002C7E4(Player *player, s8 arg1, s8 arg2) {    
    if ((player->unk_046 & 1) != 1) {
        if ((player->effects & 0x8000) == 0x8000) {
            if ((player->effects & 0x2000) != 0x2000) {
                func_8002B9CC(player, arg1, arg2);
            }
            player->unk_044 &= ~0x0001;
            player->unk_046 |= 1;
            player->unk_046 |= 8;
            if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
                func_8001CA24(player, 2.8f);
            }
            if ((player->unk_046 & 2) == 2) {
                if ((player->unk_046 & 4) != 4) {
                    player->unk_046 |= 4;
                    player->unk_046 |= 0x40;
                    if (player->effects & 0x2000) {
                        func_8008D554(player);
                    }
                }
            }
        }
    }
    if ((player->effects & 0x8000) == 0x8000) {
        player->effects &= ~0x8000;
        player->unk_10C = 1;
        player->unk_044 &= ~0x0001;
        return;
    }
    player->unk_046 &= ~0x0001;
    player->effects &= ~0x8000;
    if (player->unk_10C > 0) {
        player->unk_10C += 1;
    }
    if (player->unk_10C >= 0xA) {
        player->unk_10C = 0;
    }
}

void func_8002C954(Player *player, s8 arg1, Vec3f arg2) {
    f32 temp_f0;
    f32 var_f14;
    f32 xdist;
    f32 ydist;
    f32 zdist;

    temp_f0 = player->pos[1] - player->unk_074;
    if (((((player->effects & 0x10000) != 0x10000) && 
        ((player->effects & 0x100000) == 0x100000)) || 
        ((((temp_f0 >= 20.0f) || 
        (temp_f0 < (-1.0f))) && 
        ((player->effects & 0x10000) == 0)) && 
        (player->effects & 8)) || 
        ((player->unk_110.unk34 == 0) && 
        ((player->effects & 0x10000) == 0))) && 
        (((player->unk_0CA & 2) == 0) || 
        (!(player->unk_0CA & 8)))) {
            func_8008F494(player, arg1);
    }
    if ((player->unk_046 & 0x20) != 0x20) {
        if ((player->unk_110.unk3C[0] < (-1.0f)) || (player->unk_110.unk3C[1] < (-1.0f))) {
            player->unk_256 = 1;
        }
        player->unk_046 |= 0x20;
    }
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && (((player->unk_094 / 18.0f) * 216.0f) > 30.0f)) {
        func_8001CA24(player, 3.0f);
    }
    player->unk_046 |= 0x10;
    player->unk_256++;
    if (player->unk_256 >= 0xA) {
        player->unk_256 = 0;
    }
    if ((player->slopeAccel >= 0) && (((player->unk_094 / 18.0f) * 216.0f) > 5.0f)) {
        func_80031F48(player, 18.0f);
    }
    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        xdist = D_80165070[arg1][0] - arg2[0];
        var_f14 = D_80165070[arg1][1] - arg2[1];
        ydist = var_f14; // okay
        zdist = D_80165070[arg1][2] - arg2[2];
        var_f14 = sqrtf((xdist * xdist) + (ydist * ydist) + (zdist * zdist)) / 3; 
        if (var_f14 >= 1.0) {
            var_f14 = 1.0f;
        }
        if ((var_f14 <= 0.6) && 
            (((player->unk_094 / 18.0f) * 216.0f) >= 40.0f) && 
            (!(player->type & PLAYER_INVISIBLE_OR_BOMB))) {
                func_800CAEC4(arg1, 0.6F);
        } else if (!(player->type & PLAYER_INVISIBLE_OR_BOMB)) {
            if ((var_f14 <= 0.6) && 
                (((player->unk_094 / 18.0f) * 216.0f) < 40.0f) && 
                (((player->unk_094 / 18.0f) * 216.0f) >= 10.0f)) {
                    func_800CAEC4(arg1, 0.3F);
            } else {
                func_800CAEC4(arg1, var_f14);
            }
        }
    }
    if (player->effects & 0x2000) {
        func_8008D554(player);
        player->unk_08C /= 2;
    }
}

void func_8002CD48(Player *player, s8 arg1, s8 arg2) {
    if (((player->unk_0CA & 2) == 2) || ((player->unk_0CA & 8) == 8)) {
        func_80090970(player, arg1, arg2);
    }
    if ((player->effects & 0x800) == 0x800) {
        func_8008CEB0(player, arg1);
    }
    if (player->unk_044 & 0x4000) {
        func_8008D170(player, arg1);
    }
    if ((player->effects & 0x2000) == 0x2000) {
        func_8008D4B4(player);
    }
    if ((player->effects & 0x100000) == 0x100000) {
        func_8008EDC0(player);
    }
    if ((player->effects & 4) == 4) {
        func_8008F008(player);
    }
    if ((s32)(player->effects & 0x04000000) == 0x04000000) {
        func_8008DC08(player, arg1);
    }
    if ((player->effects & LIGHTNING_EFFECT) == LIGHTNING_EFFECT) {
        func_8008E118(player, arg1);
    }
    if ((player->effects & 0x10000) == 0x10000) {
        func_8008F3F4(player, arg1);
    }
    if ((player->effects & 0x200) == 0x200) {
        func_8008F650(player, arg1);
    }
    if ((player->effects & 0x80000000) == 0x80000000) {
        func_8008F8DC(player, arg1);
    }
    if (((player->effects & 0x20000000) == 0x20000000) && (player->unk_228 >= 0x64)) {
        func_80031F48(player, 4.0f);
    }
    if (((player->effects & 0x80) == 0x80) || ((player->effects & 0x40) == 0x40)) {
        func_8008C9EC(player, arg1);
    }
    if ((player->effects & 0x400) == 0x400) {
        func_8008C62C(player, arg1);
    }
    if ((player->effects & 0x01000000) == 0x01000000) {
        func_8008E4A4(player, arg1);
    }
    if ((player->effects & 0x02000000) == 0x02000000) {
        func_8008E8D8(player, arg1);
    }
    if ((player->effects & 0x4000) == 0x4000) {
        func_8008F1B8(player, arg1);
    }
    if ((player->effects & 0x80000) == 0x80000) {
        func_8008D698(player, arg1);
    }
    if ((player->effects & 0x800000) == 0x800000) {
        func_8008D8B4(player, arg1);
        func_80031F48(player, 10.0f);
    }
    if (D_800DC510 != 5) {
        if (player->statusEffects & 0x04000000) {
            func_8008FC64(player, arg1);
        }
        if (player->statusEffects & 0x08000000) {
            func_8008FCDC(player, arg1);
        }
    }
    if (player->unk_044 & 0x800) {
        func_80091298(player, arg1);
    }
}

void func_8002D028(Player *player, s8 arg1) {
    Vec3f sp4C;
    f32 temp_f18;
    s16 temp_t1;
    s16 temp;
    s16 temp2;
    f32 thing0;
    UNUSED s32 pad;

    sp4C[0] = D_80165210[D_80165270[arg1]];
    sp4C[1] = 0;
    sp4C[2] = D_80165230[D_80165270[arg1]];

    temp = -(s16)get_angle_between_points(player->pos, sp4C);
    temp2 = player->unk_02C[1];
    temp = (temp - temp2);

    thing0 = 8;

        
    if (temp > ((s16) (thing0 * 182))) {
        temp = (thing0 * 182);
    }
    if (temp < ((s16) (-thing0 * 182))) {
        temp = (-thing0 * 182);
    }

    temp_t1 = (D_80165020[arg1] + ((s16) ((temp * 0x35) / (thing0 * 182)))) / 2;
    func_8003680C(player, (s16) temp_t1);
    D_80165020[arg1] = (s16) temp_t1;

    temp_f18 = sqrtf((sp4C[0] - player->pos[0]) * (sp4C[0] - player->pos[0])+ (sp4C[2] - player->pos[2]) * (sp4C[2] - player->pos[2]));
    if (temp_f18 <= 8.0f) {
        adjust_angle(&player->unk_02C[1], -0x8000, 0x016C);
        if ((player->unk_02C[1] < (-0x7F41)) || (player->unk_02C[1] > 0x7F41)) {
            player->type &= ~0x0200;
        }
        player->unk_08C = 0;
        player->unk_094 = 0;
        player->unk_104 = 0;
        player->unk_240 = 0;
        player->unk_07C = 0;
        player->velocity[0] = 0;
        player->velocity[1] = 0;
        player->velocity[2] = 0;
        player->unk_0C0 = 0;
        player->unk_078 = 0;
    } else {
        player->unk_08C = 1200;
    }
}

void func_8002D268(Player *player, UNUSED Camera *camera, s8 arg2, s8 playerId)
{
    Vec3f sp184 = {0.0, 0.0, 1.0};
    Vec3f sp178 = {0.0, 0.0, 0.0};
    Vec3f sp16C = {0.0, 0.0, 0.0};
    Vec3f sp160 = {0.0, 0.0, 0.0};
    f32 sp104[] = {0.825, 0.8, 0.725, 0.625, 0.425, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3};
    f32 temp;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 temp2;
    s32 temp_v0_3;
    s32 temp3;
    f32 temp_f2_2;
    UNUSED s32 pad[8];
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 temp_var;
    UNUSED s32 pad2;
    Vec3f sp98;
    Vec3f sp8C;
    UNUSED s32 pad3[3];
    s32 sp7C = 0;
    UNUSED s32 pad4[6];

    func_80027EDC(player, playerId);
    func_8002C11C(player);
    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        func_8002A79C(player, playerId);
    }
    func_8002B830(player, playerId, arg2);
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
        func_8002BF4C(player, playerId);
    }
    func_8002CD48(player, playerId, arg2);
    if (((player->effects & 0x20000000) == 0x20000000) && (player->unk_228 >= 0x64)) {
        sp7C = 2;
    }
    func_80037BB4(player, sp160);
    func_8002AB70(player);
    func_8002FCA8(player, playerId);
    if (player->unk_044 & 1) {
        player->unk_064[0] *= -1.0f;
        player->unk_064[2] *= -1.0f;
    }
    if ((player->boundingBoxCorners[2].surfaceType == 1) && (player->boundingBoxCorners[3].surfaceType == 1)) {
        spB4 = (-1 * (player->unk_064[0] + sp16C[0])) + ((-player->unk_110.unk60[0] * player->kartGravity) * 0.925);
        spB0 = (-player->unk_110.unk60[1] * player->kartGravity);
        spAC = (-1 * (player->unk_064[2] + sp16C[2])) + ((-player->unk_110.unk60[2] * player->kartGravity) * 0.925);
    } else {
        temp3 = (((player->unk_094 / 18.0f) * 216.0f) / 10.0f);
        if (temp3 >= 10)
        {
            temp3 = 10;
        }
        spB4 = -1 * (player->unk_064[0] + sp16C[0]) + ((-player->unk_110.unk60[0] * player->kartGravity) * sp104[temp3]);
        spB0 = (-player->unk_110.unk60[1] * player->kartGravity);
        spAC = -1 * (player->unk_064[2] + sp16C[2]) + ((-player->unk_110.unk60[2] * player->kartGravity) * sp104[temp3]);
    }
    if (((player->effects & 8) != 8) && ((player->effects & 0x20) == 0x20)) {
        spB4 = 0 * (player->unk_064[0] + sp16C[0]);
        spB0 = -1 * player->kartGravity / 4;
        spAC = 0 * (player->unk_064[2] + sp16C[2]);
    }
    if ((player->effects & 8) == 8) {
        spB4 = 0 * (player->unk_064[0] + sp16C[0]);
        spB0 = -1 * player->kartGravity;
        spAC = 0 * (player->unk_064[2] + sp16C[2]);
    }
    temp_f2_2 = ((player->rotZ - player->pos[2]) * coss(player->unk_02C[1] + player->unk_0C0)) + (-(player->rotX - player->pos[0]) * sins(player->unk_02C[1] + player->unk_0C0));
    if (temp_f2_2 > 0.1) {
        player->unk_044 |= 8;
    } else {
        player->unk_044 &= 0xFFF7;
    }
    if (((player->unk_08C <= 0.0f) && ((temp_v0_3 = player->effects, (temp_v0_3 & 1) == 1))) && ((temp_v0_3 & 0x20) != 0x20)) {
        sp178[2] = temp_f2_2 * 4500.0f;
    } else {
        sp178[2] = 0.0f;
    }
    sp178[1] = 0.0f;
    mtxf_translate_vec3f_mat3(sp178, player->orientationMatrix);
    spB4 += sp178[0];
    spAC += sp178[2];
    func_8002C7E4(player, playerId, arg2);
    sp184[2] = func_80030150(player, playerId);
    mtxf_translate_vec3f_mat3(sp184, player->orientationMatrix);
    sp98[0] = player->velocity[0];
    sp98[1] = player->velocity[1];
    sp98[2] = player->velocity[2];
    if (((player->unk_10C < 3)
        && (((s32) player->unk_256) < 3))
        || ((player->effects & 0x2000) == 0x2000)) {

        if (((player->unk_07C >> 16) >= 0x28)
            || ((player->unk_07C >> 16) < (-0x27))) {

            sp98[0] += (((((f64) ((sp184[0] + spB4) + sp160[0])) - (sp98[0] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / (((((f64) player->unk_20C) * 0.6) + 1.0) + sp7C));
            sp98[2] += (((((f64) ((sp184[2] + spAC) + sp160[2])) - (sp98[2] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / (((((f64) player->unk_20C) * 0.6) + 1.0) + sp7C));
        } else {
            sp98[0] += (((((f64) ((sp184[0] + spB4) + sp160[0])) - (sp98[0] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / (sp7C + 1));
            sp98[2] += (((((f64) ((sp184[2] + spAC) + sp160[2])) - (sp98[2] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / (sp7C + 1));
        }
    } else {
        sp98[0] += (((((f64) ((sp184[0] + spB4) + sp160[0])) - (sp98[0] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / 30.0);
        sp98[2] += (((((f64) ((sp184[2] + spAC) + sp160[2])) - (sp98[2] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / 30.0);
    }
    sp98[1] += (((((f64) ((sp184[1] + spB0) + sp160[1])) - (sp98[1] * (0.12 * ((f64) player->kartFriction)))) / 6000.0) / ((f64) player->unk_DAC));
    if (((((player->unk_0CA & 2) == 2) || ((player->unk_0CA & 8) == 8)) || ((player->effects & 0x04000000) == 0x04000000)) || (player->unk_0CA & 1)) {
        sp98[0] = 0.0f;
        sp98[1] = 0.0f;
        sp98[2] = 0.0f;
    }
    if ((player->unk_044 & 0x10) == 0x10) {
        player->unk_044 &= 0xFFEF;
    }

    posX = player->pos[0];
    posY = player->pos[1];
    posZ = player->pos[2];
        
    player->rotX = player->pos[0];
    player->rotZ = player->pos[2];
    player->rotY = player->pos[1];
    spFC = posX + player->velocity[0] + D_8018CE10[playerId].unk_04[0];
    spF8 = posY + player->velocity[1];
    spF4 = posZ + player->velocity[2] + D_8018CE10[playerId].unk_04[2];

    if (((((player->unk_0CA & 2) != 2)
        && ((player->unk_0CA & 8) != 8))
        && ((player->effects & 0x04000000) != 0x04000000))
        && (!(player->unk_0CA & 1))) {
        func_8002AAC0(player);
        spF8 += player->kartHopVelocity;
        spF8 -= 0.02;
    }
    func_802AD950(&player->unk_110, player->boundingBoxSize, spFC, spF8, spF4, player->rotX, player->rotY, player->rotZ);
    player->unk_058 = 0.0f;
    player->unk_060 = 0.0f;
    player->unk_05C = 1.0f;
    if ((player->unk_044 & 1) != 1) {
        calculate_orientation_matrix(player->orientationMatrix, player->unk_058, player->unk_05C, player->unk_060, player->unk_02C[1]);
    } else {
        calculate_orientation_matrix(player->orientationMatrix, player->unk_058, player->unk_05C, player->unk_060, player->unk_02C[1] + 0x8000);
    }
    player->effects |= 8;
    player->unk_0C2 += 1;
        temp_var = player->unk_110.unk3C[2];
    if (temp_var <= 0.0f) {
        player->effects = player->effects & (~2);
        player->effects = player->effects & (~8);
        if (player->unk_0C2 >= 35) {
            if (player->unk_0C2 >= 0x32) {
                player->unk_0C2 = 0x32;
            }
            player->unk_DB4.unkC = 3.0f;
            player->unk_DB4.unk18 = 0;
            player->unk_0B6 |= 0x100;
            if ((((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) 
                && ((player->effects & 0x100000) == 0x100000))  
                && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) 
            
                func_800C9060(playerId, 0x1900A60AU);
            else if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB))
            {
                func_800CADD0((u8) playerId, ((f32) player->unk_0C2) / 35.0f);
            }
            if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN)
            {
                player->unk_044 |= 0x100;
            }
        }
        if (((player->unk_0C2 < 0x23) && (player->unk_0C2 >= 0x1C)) && (((player->unk_094 / 18.0f) * 216.0f) >= 20.0f)) {
            player->unk_DB4.unkC = 2.8f;
            player->unk_DB4.unk18 = 0;
            if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) 
                && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
                func_800CADD0((u8) playerId, ((f32) player->unk_0C2) / 35.0f);
            }
            if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
                player->unk_044 |= 0x100;
            }
        }
        if (((player->unk_0C2 < 0x1C) && (player->unk_0C2 >= 4)) && (((player->unk_094 / 18.0f) * 216.0f) >= 20.0f)) {
            player->unk_DB4.unk18 = 0;
            player->unk_DB4.unkC = 1.5f;
            if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
                if (((player->unk_0C2 < 0xB) && (player->unk_0C2 >= 4)) && (gCurrentCourseId == COURSE_BOWSER_CASTLE)) {
                    func_800CADD0((u8) playerId, player->unk_0C2 / 14.0f);
                }
                else {
                    func_800CADD0((u8) playerId, player->unk_0C2 / 25.0f);
                }
            }
        }
        player->unk_0C2 = 0;
        player->kartHopVelocity = player->unk_0C2;
    }
    temp_var = player->unk_110.unk3C[2];
    if (temp_var <= 0.0f) {
        func_8003F46C(player, sp8C, sp98, sp178, &temp_var, &spFC, &spF8, &spF4);
    }
    temp_var = player->unk_110.unk3C[0];
    if (temp_var < 0.0f) {
        func_8003F734(player, sp8C, sp98, &temp_var, &spFC, &spF8, &spF4);
        func_8002C954(player, playerId, sp98);
    }
    temp_var = player->unk_110.unk3C[1];
    if (temp_var < 0.0f) {
        func_8003FBAC(player, sp8C, sp98, &temp_var, &spFC, &spF8, &spF4);
        func_8002C954(player, playerId, sp98);
    }
    temp_var = player->unk_110.unk3C[0];
    if (temp_var >= 0.0f) {
        temp_var = player->unk_110.unk3C[1];
        if (temp_var >= 0.0f) {
            player->unk_046 &= 0xFFDF;
            if (player->unk_256 != 0) {
                player->unk_256++;
                if (player->unk_256 >= 10)
                {
                player->unk_256 = 0;
                }
            }
        }
    }
    if (((!(player->effects & 8)) && (func_802ABDB8(player->unk_110.unk3A) != 0)) && ((player->effects & 0x10000) != 0x10000)) {
        if ((!(player->unk_0CA & 2)) || (!(player->unk_0CA & 8))) {
            func_8008F494(player, playerId);
        }
    } else if (((!(player->effects & 8)) && (func_802ABDB8(player->unk_110.unk3A) == 0)) && (player->effects & 0x10000)) {
        func_8008F5A4(player, playerId);
    }
    player->unk_074 = func_802ABE30(spFC, spF8, spF4, player->unk_110.unk3A);
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && (((gActiveScreenMode == SCREEN_MODE_1P) || (gActiveScreenMode == SCREEN_MODE_2P_SPLITSCREEN_VERTICAL)) || (gActiveScreenMode == SCREEN_MODE_2P_SPLITSCREEN_HORIZONTAL))) {
        func_80029B4C(player, spFC, spF8, spF4);
    } else {
        func_8002A194(player, spFC, spF8, spF4);
    }
    func_8002AE38(player, playerId, posX, posZ, spFC, spF4);

    temp2 = (sp98[0] * sp98[0]) + (sp98[2] * sp98[2]);
    player->unk_22C = player->unk_094;
    player->unk_094 = sqrtf(temp2);

    if ((player->unk_08C <= 0.0f) 
        && (player->unk_094 <= 0.08)
        && (D_8018CE10[playerId].unk_04[0] == 0.0f)
        && (D_8018CE10[playerId].unk_04[2] == 0.0f)) {
        sp98[0] = sp98[0] + (-1 * sp98[0]);
        sp98[2] = sp98[2] + (-1 * sp98[2]);
    } else {
        player->pos[0] = spFC;
        player->pos[2] = spF4;
    }
    player->pos[1] = spF8;
    if ((player->type & PLAYER_HUMAN) && (!(player->type & PLAYER_CPU))) {
        func_8002BB9C(player, &spFC, &spF4, arg2, playerId, sp98);
    }
    player->unk_064[0] = sp178[0];
    player->unk_064[2] = sp178[2];
    player->velocity[0] = sp98[0];
    player->velocity[1] = sp98[1];
    player->velocity[2] = sp98[2];
    D_80165070[playerId][0] = sp98[0];
    D_80165070[playerId][1] = sp98[1];
    D_80165070[playerId][2] = sp98[2];
    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        if (gKartTopSpeedTable[player->characterId] < player->unk_094) {
            temp = gKartTopSpeedTable[player->characterId] / player->unk_094;
            player->velocity[0] *= temp;
            player->velocity[1] *= temp;
            player->velocity[2] *= temp;
            player->unk_094 = gKartTopSpeedTable[player->characterId];
        }
    }
    if ((player->unk_044 & 1) == 1) {
        if (player->unk_094 > 1) {
            temp = 1 / player->unk_094;
            player->velocity[0] *= temp;
            player->velocity[1] *= temp;
            player->velocity[2] *= temp;
            player->unk_094 = 1;
        }
    }
    if (player->unk_110.unk3C[2] >= 500.0f) {
        player->unk_078 = (s16) (((s16) player->unk_078) / 2);
    }
    func_8002C4F8(player, playerId);
}

void func_8002E4C4(Player *player) {
    s32 player_index;

    player_index = get_player_index_for_player(player);
    player->kartHopJerk = 0.0f;
    player->kartHopAcceleration = 0.0f;
    player->kartHopVelocity = 0.0f;
    player->pos[1] = func_802AE1C0(player->pos[0], D_80164510[player_index] + 10.0f, player->pos[2]) + player->boundingBoxSize;
    if (((player->pos[1] - D_80164510[player_index]) > 1200.0f) || ((player->pos[1] - D_80164510[player_index]) < -1200.0f)) {
        player->pos[1] = player->rotY;
    }
    player->velocity[1] = 0.0f;
}

void func_8002E594(Player *player, UNUSED Camera *camera, s8 arg2, s8 arg3) {
    Vec3f spEC = {0.0f, 0.0f, 1.0f};
    Vec3f spE0 = {0.0f, 0.0f, 0.0f};
    Vec3f spD4 = {0.0f, 0.0f, 0.0f};
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 temp_f0_6;
    UNUSED s32 pad;
    f32 posX;
    f32 posY;
    f32 posZ;
    UNUSED s32 pad2[12];
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    UNUSED s32 pad3[4];
    f32 temp;
    Vec3f sp54;
    Vec3f sp48;
    s16 sp46;
    func_8002B830(player, arg3, arg2);
    if ((((((((player->effects & 0x80) == 0x80)
        || ((player->effects & 0x40) == 0x40))
        || ((player->effects & 0x4000) == 0x4000))
        || ((player->effects & 0x80000) == 0x80000))
        || ((player->effects & 0x800000) == 0x800000))
        || ((player->effects & 0x20000) == 0x20000))
        || (player->unk_044 & 0x800)) {
        sp46 = 1;
    } else {
        sp46 = 0;
    }
    func_8002CD48(player, arg3, arg2);
    func_8002AB70(player);
    func_8002FCA8(player, arg3);
    if ((((player->effects & 0x80) == 0x80)
        || ((player->effects & 0x40) == 0x40))
        || ((player->effects & 0x20000) == 0x20000)) {
        sp80 = -1 * (player->unk_064[0]) + (((-player->unk_110.unk60[0]) * player->kartGravity) * 0.1);
        sp7C = (-player->unk_110.unk60[1]) * player->kartGravity;
        sp78 = -1 * (player->unk_064[2]) + (((-player->unk_110.unk60[2]) * player->kartGravity) * 0.1);
    } else {
        sp80 = -1 * player->unk_064[0];
        sp7C = -1 * player->kartGravity;
        sp78 = -1 * player->unk_064[2];
    }
    func_8002C7E4(player, arg3, arg2);
    if (sp46 == 1) {
        calculate_orientation_matrix(player->orientationMatrix, player->unk_058, player->unk_05C, player->unk_060, (s16) ((s32) player->unk_02C[1]));
        calculate_orientation_matrix(player->unk_150, player->unk_058, player->unk_05C, player->unk_060, (s16) ((s32) player->unk_0AE));
    } else {
        calculate_orientation_matrix(player->orientationMatrix, player->unk_058, player->unk_05C, player->unk_060, (s16) ((s32) player->unk_02C[1]));
    }
    spEC[2] = func_80030150(player, arg3);
    if (sp46 == 1) {
        mtxf_translate_vec3f_mat3(spEC, player->unk_150);
    } else {
        mtxf_translate_vec3f_mat3(spEC, player->orientationMatrix);
    }
    sp54[0] = player->velocity[0];
    sp54[1] = player->velocity[1];
    sp54[2] = player->velocity[2];
    if ((player->unk_10C < 3)
        && ((player->unk_256) < 3)
        && ((player->effects & 0x400) != 0x400)
        && ((player->effects & 0x01000000) != 0x01000000)
        && ((player->effects & 0x02000000) != 0x02000000)) {
        sp54[0] += (((((spEC[0] + sp80) + spD4[0])) - (sp54[0] * (0.12 * player->kartFriction))) / 6000) / ((player->unk_20C * 5.0f) + 1.0f);
        sp54[2] += (((((spEC[2] + sp78) + spD4[2])) - (sp54[2] * (0.12 * player->kartFriction))) / 6000) / ((player->unk_20C * 5.0f) + 1.0f);
    } else {
        sp54[0] += ((((f64) (spEC[0] + sp80 + spD4[0]) - (sp54[0] * (0.2 * (f64) player->kartFriction))) / 6000) * 0.08);
        sp54[2] += ((((f64) (spEC[2] + sp78 + spD4[2]) - (sp54[2] * (0.2 * (f64) player->kartFriction))) / 6000) * 0.08);
        
    }
    sp54[1] += ((( ((spEC[1] + sp7C) + spD4[1])) - (sp54[1] * (0.12 * player->kartFriction))) / 6000) / player->unk_DAC;

    if (((player->unk_0CA & 2) == 2) || ((player->unk_0CA & 8) == 8)) {
        sp54[0] = 0.0f;
        sp54[1] = 0.0f;
        sp54[2] = 0.0f;
    }
    posX = player->pos[0];
    posY = player->pos[1];
    posZ = player->pos[2];
        
    player->rotX = player->pos[0];
    player->rotY = player->pos[1];
    player->rotZ = player->pos[2];
        
    spD0 = posX + player->velocity[0] + D_8018CE10[arg3].unk_04[0];
    spCC = posY + player->velocity[1];
    spC8 = posZ + player->velocity[2] + D_8018CE10[arg3].unk_04[2];
    func_8002AAC0(player);
    spCC += player->kartHopVelocity;
    func_802AD950(&player->unk_110, player->boundingBoxSize, spD0, spCC, spC8, player->rotX, player->rotY, player->rotZ);
    player->effects |= 8;
    player->unk_0C2 += 1;
    player->unk_058 = 0.0f;
    player->unk_060 = 0.0f;
    player->unk_05C = 1.0f;
    sp74 = player->unk_110.unk3C[2];
    if (sp74 <= 0.0f) {
        player->effects &= ~2;
        player->effects &= ~8;
        if ((((player->effects & 0x400) != 0x400)
            && ((player->effects & 0x01000000) != 0x01000000))
            && ((player->effects & 0x02000000) != 0x02000000)) {
        if (player->unk_0C2 >= 0x1C) {
            if (player->unk_0C2 >= 0x32) {
                player->unk_0C2 = 0x0032;
            }
            player->unk_DB4.unk18 = 0;
            player->unk_0B6 |= 0x100;
            player->unk_DB4.unkC = 3.0f;
            if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
                func_800CADD0((u8) arg3, ((f32) player->unk_0C2) / 50.0f);
            }
            if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
                player->unk_044 |= 0x100;
            }
        }
        if (((player->unk_0C2 < 0x1C)
            && (player->unk_0C2 >= 0xA))
            && (((player->unk_094 / 18.0f) * 216.0f) >= 20.0f)) {
            player->unk_DB4.unkC = 2.0f;
            player->unk_DB4.unk18 = 0;
            if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
                func_800CADD0((u8) arg3, ((f32) player->unk_0C2) / 50.0f);
            }
            if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
                player->unk_044 |= 0x100;
            }
        }
        player->unk_0C2 = 0;
        } else {
            if (player->unk_0C2 >= 0xA) {
            if (player->unk_0C2 >= 0x32) {
                player->unk_0C2 = 0x0032;
            }
            if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
                func_800CADD0((u8) arg3, ((f32) player->unk_0C2) / 20.0f);
            }
            if (player->unk_0C2 >= 0x28) {
                player->unk_0C2 = 0x0014;
            }
            if ((player->effects & 0x400) == 0x400) {
                player->unk_0C2 /= 6.5;
                player->kartHopJerk = 0.06f;
                player->kartHopAcceleration = 0.0f;
            } else {
                player->unk_0C2 /= 7.5;
                player->kartHopJerk = 0.06f;
                player->kartHopAcceleration = 0.0f;
                if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
                    player->unk_044 |= 0x100;
                }
            }
            } else {
                player->unk_0C2 = 0;
            }
        }
        player->kartHopVelocity = (f32) player->unk_0C2;
    }
    sp74 = player->unk_110.unk3C[2];
    if (sp74 <= 0.0f) {
        func_8003F46C(player, sp48, sp54, spE0, &sp74, &spD0, &spCC, &spC8);
    }
    sp74 = player->unk_110.unk3C[0];
    if (sp74 < 0.0f) {
        func_8003F734(player, sp48, sp54, &sp74, &spD0, &spCC, &spC8);
        func_8002C954(player, arg3, sp54);
        func_80031F48(player, 6.0f);
    }
    sp74 = player->unk_110.unk3C[1];
    if (sp74 < 0.0f) {
        func_8003FBAC(player, sp48, sp54, &sp74, &spD0, &spCC, &spC8);
        func_8002C954(player, arg3, sp54);
        func_80031F48(player, 6.0f);
    }
    sp74 = player->unk_110.unk3C[0];
    if (sp74 >= 0.0f) {
        sp74 = player->unk_110.unk3C[1];
        if (sp74 >= 0.0f) {
            player->unk_046 &= 0xFFDF;
            if (player->unk_256 != 0) {
                player->unk_256++;
                if ((player->unk_256) >= 0xA)
                {
                player->unk_256 = 0;
                }
            }
        }
    }
    if (((func_802ABDB8(player->unk_110.unk3A) != 0) && ((player->effects & 0x10000) != 0x10000)) && (((player->unk_094 / 18.0f) * 216.0f) >= 20.0f)) {
        if ((!(player->unk_0CA & 2)) || (!(player->unk_0CA & 8))) {
            func_8008F494(player, arg3);
        }
    } else if (((!(player->effects & 8)) && (func_802ABDB8(player->unk_110.unk3A) == 0)) && (player->effects & 0x10000)) {
        func_8008F5A4(player, arg3);
    }
    player->unk_074 = func_802ABE30(spD0, spCC, spC8, player->unk_110.unk3A);
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && (((gActiveScreenMode == SCREEN_MODE_1P) || (gActiveScreenMode == SCREEN_MODE_2P_SPLITSCREEN_VERTICAL)) || (gActiveScreenMode == SCREEN_MODE_2P_SPLITSCREEN_HORIZONTAL))) {
        func_80029B4C(player, spD0, spCC, spC8);
    } else {
        func_8002A194(player, spD0, spCC, spC8);
    }
    func_8002AE38(player, arg3, posX, posZ, spD0, spC8);
    temp = (sp54[0] * sp54[0]) + (sp54[2] * sp54[2]);
    player->unk_22C = player->unk_094;
    player->unk_094 = sqrtf(temp);
    if ((((player->effects & 0x400) != 0x400)
        && (player->unk_08C <= 0)
        && (player->unk_094 < 0.13))
        || (((player->effects & 0x400) != 0x400)
        && (player->unk_08C <= 0)
        && (player->unk_094 < 0.20)
        && ((player->effects & 1) == 1))) {
        sp54[0] = sp54[0] + (-1 * sp54[0]);
        sp54[2] = sp54[2] + (-1 * sp54[2]);
    } else {
        player->pos[0] = spD0;
        player->pos[2] = spC8;
    }
    player->pos[1] = spCC;
    player->unk_064[0] = spE0[0];
    player->unk_064[2] = spE0[2];
    player->velocity[0] = sp54[0];
    player->velocity[1] = sp54[1];
    player->velocity[2] = sp54[2];
    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        if (gKartTopSpeedTable[player->characterId] < player->unk_094) {
        temp_f0_6 = gKartTopSpeedTable[player->characterId] / player->unk_094;
        player->velocity[0] *= temp_f0_6;
        player->velocity[1] *= temp_f0_6;
        player->velocity[2] *= temp_f0_6;
        player->unk_094 = gKartTopSpeedTable[player->characterId];
        }
    }
    func_8002C4F8(player, arg3);
}

void control_cpu_movement(Player *player, UNUSED Camera *camera, s8 arg2, s8 arg3) {
    Vec3f spF4 = {0.0f, 0.0f, 1.0f};
    UNUSED Vec3f spE8 = {0.0f, 0.0f, 0.0f};
    Vec3f spDC = {0.0f, 0.0f, 0.0f};
    Vec3f spD0 = {0.0f, 0.0f, 0.0f};
    f32 spCC;
    UNUSED s32 pad;
    f32 spC4;
    UNUSED s32 pad2[15];
    f32 sp84;
    UNUSED s32 pad3;
    f32 sp7C;
    UNUSED s32 pad4[2];
    Vec3f sp68;
    UNUSED f32 pad5[7];
    f32 toSqrt;
    f32 temp_f0_2;
    f32 test;
    player->effects |= 0x1000;
    player->unk_044 |= 0x10;
    test = D_80164510[arg3];
    player->unk_204 = 0;
    player->effects &= ~0x10;
    func_8002B830(player, arg3, arg2);
    func_8002CD48(player, arg3, arg2);
    sp84 = 0 * player->unk_064[0] + spDC[0];
    sp7C = 0 * player->unk_064[2] + spDC[2];
    player->unk_10C = 0;
    player->unk_256 = 0;
    player->effects &= ~0x8000;
    spF4[2] = func_80030150(player, arg3);
    mtxf_translate_vec3f_mat3(spF4, player->orientationMatrix);
    sp68[0] = player->velocity[0];
    sp68[1] = 0;
    sp68[2] = player->velocity[2];
    sp68[0] += (((spF4[0] + sp84) + spD0[0]) - (sp68[0] * (0.12 * player->kartFriction))) / 6000.0;
    sp68[2] += (((spF4[2] + sp7C) + spD0[2]) - (sp68[2] * (0.12 * player->kartFriction))) / 6000.0;
    player->rotX = player->pos[0];
    player->rotY = test;
    player->rotZ = player->pos[2];
    spCC = player->pos[0] + player->velocity[0];
    spC4 = player->pos[2] + player->velocity[2];
    player->unk_0C0 = 0;
    player->kartHopJerk = 0;
    player->kartHopAcceleration = 0;
    player->kartHopVelocity = 0;
    calculate_orientation_matrix(player->orientationMatrix, player->unk_058, player->unk_05C, player->unk_060, player->unk_02C[1]);
    player->unk_0C2 = 0;
    player->effects &= ~2;
    player->effects &= ~8;
    player->slopeAccel = 0;
    player->unk_206 = 0;
    toSqrt = (sp68[0] * sp68[0]) + (sp68[2] * sp68[2]);
    player->unk_22C = player->unk_094;
    player->unk_094 = sqrtf(toSqrt);
    player->pos[0] = spCC;
    player->pos[2] = spC4;
    player->pos[1] = test;
    player->unk_064[0] = 0;
    player->unk_064[2] = 0;
    player->velocity[0] = sp68[0];
    player->velocity[1] = sp68[1];
    player->velocity[2] = sp68[2];
    D_80165070[arg3][0] = sp68[0];
    D_80165070[arg3][1] = sp68[1];
    D_80165070[arg3][2] = sp68[2];
    if (gKartTopSpeedTable[player->characterId] < player->unk_094) {
        temp_f0_2 = gKartTopSpeedTable[player->characterId] / player->unk_094;
        player->velocity[0] *= temp_f0_2;
        player->velocity[1] *= temp_f0_2;
        player->velocity[2] *= temp_f0_2;
        player->unk_094 = gKartTopSpeedTable[player->characterId];
    }
}

void func_8002F730(Player *player, UNUSED Camera *camera, UNUSED s8 arg2, s8 arg3) {
    Vec3f spF4 = {0.0f, 0.0f, 1.0f};
    Vec3f spE8 = {0.0f, 0.0f, 0.0f};
    UNUSED Vec3f spDC = {0.0f, 0.0f, 0.0f};
    Vec3f spD0 = {0.0f, 0.0f, 0.0f};
    f32 spCC;
    f32 spC8;
    f32 spC4;

    f32 spC0;
    f32 sp44;
    f32 spB8;
    f32 temp_f0_2;
    UNUSED s32 pad[11];
    f32 sp84;
    UNUSED s32 pad2;
    f32 sp7C;
    f32 sp78;
    f32 sqrt;
    Vec3f sp68;
    Vec3f sp5C;
    UNUSED s32 pad3[3];

    func_80037BB4(player, spD0);
    sp84 = player->unk_064[0] * 0;
    sp7C = player->unk_064[2] * 0;
    spF4[2] = func_80030150(player, arg3);

    mtxf_translate_vec3f_mat3(spF4, player->orientationMatrix);

    sp68[0] = player->velocity[0];
    sp68[1] = player->velocity[1];
    sp68[2] = player->velocity[2];

    sp68[0] += (((f64) (spF4[0] + sp84) - (sp68[0] * 780.0)) / 6500.0);
    sp68[2] += (((f64) (spF4[2] + sp7C) - (sp68[2] * 780.0)) / 6500.0);
    sp68[1] += (((f64) (spF4[1] + -1100.0f) - (sp68[1] * 780.0)) / 6500.0);

    spC0 = player->pos[0];
    sp44 = player->pos[1];
    spB8 = player->pos[2];


    player->rotX = player->pos[0];
    player->rotY = player->pos[1];
    player->rotZ = player->pos[2];

    spCC = player->velocity[0] + spC0;
    spC8 = player->velocity[1] + sp44;
    spC4 = player->velocity[2] + spB8;

    func_8002AAC0(player);

    spC8 += player->kartHopVelocity;
    func_802AD950(&player->unk_110, player->boundingBoxSize, spCC, spC8, spC4, player->rotX, player->rotY, player->rotZ);
    player->unk_058 = 0.0f;
    player->unk_05C = 1.0f;
    player->unk_060 = 0.0f;
    calculate_orientation_matrix(player->orientationMatrix, 0.0f, 1.0f, 0.0f, (s16) (s32) player->unk_02C[1]);
    player->effects &= ~8;
    sp78 = player->unk_110.unk3C[2];
    if (sp78 <= 0.0f) {
        if(1) {};
        func_8003F46C(player, sp5C, sp68, spE8, &sp78, &spCC, &spC8, &spC4);
    }
    player->unk_074 = func_802ABE30(spCC, spC8, spC4, player->unk_110.unk3A);
    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((gActiveScreenMode == SCREEN_MODE_1P) || (gActiveScreenMode == SCREEN_MODE_2P_SPLITSCREEN_VERTICAL) || (gActiveScreenMode == SCREEN_MODE_2P_SPLITSCREEN_HORIZONTAL))) {
        func_80029B4C(player, spCC, spC8, spC4);
    } else {
        func_8002A194(player, spCC, spC8, spC4);
    }
    func_8002AE38(player, arg3, spC0, spB8, spCC, spC4);
    sqrt = (sp68[0] * sp68[0]) + (sp68[1] * sp68[1]) + (sp68[2] * sp68[2]);
    player->unk_22C = player->unk_094;
    player->unk_094 = sqrtf(sqrt);
    if (((player->unk_08C <= 0.0f) && ((f64) player->unk_094 < 0.13)) || ((player->unk_08C <= 0.0f) && ((f64) player->unk_094 < 0.2) && ((player->effects & 1) == 1))) {
        sp68[0] = sp68[0] + (sp68[0] * -1.0f);
        sp68[2] = sp68[2] + (sp68[2] * -1.0f);
    } else {
        player->pos[0] = spCC;
        player->pos[2] = spC4;
    }
    player->pos[1] = spC8 - 0.018;

    player->unk_064[0] = spE8[0];
    player->unk_064[2] = spE8[2];

    player->velocity[0] = sp68[0];
    player->velocity[1] = sp68[1];
    player->velocity[2] = sp68[2];
    
    D_80165070[arg3][0] = sp68[0];
    D_80165070[arg3][1] = sp68[1];
    D_80165070[arg3][2] = sp68[2];

    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        if (gKartTopSpeedTable[player->characterId] < player->unk_094) {
            temp_f0_2 = gKartTopSpeedTable[player->characterId] / player->unk_094;
            player->velocity[0] *= temp_f0_2;
            player->velocity[1] *= temp_f0_2;
            player->velocity[2] *= temp_f0_2;
            player->unk_094 = gKartTopSpeedTable[player->characterId];
        }
    }
}

void func_8002FCA8(Player *player, s8 arg1) {
    f32 var_f0;
    f32 var_f12;
    s32 temp_lo;
    s32 var_v1;

    var_f0 = 0.0f;
    if ((player->effects & 0x200) != 0x200) {
        if ((s32) player->boundingBoxCorners[3].surfaceType < 0xF) {
            var_f0 += D_800E2A90[player->characterId][player->boundingBoxCorners[3].surfaceType];
        }
        if ((s32) player->boundingBoxCorners[2].surfaceType < 0xF) {
            var_f0 += D_800E2A90[player->characterId][player->boundingBoxCorners[2].surfaceType];
        }
        if ((s32) player->boundingBoxCorners[1].surfaceType < 0xF) {
            var_f0 += D_800E2AB0[player->characterId][player->boundingBoxCorners[1].surfaceType];
        }
        if ((s32) player->boundingBoxCorners[0].surfaceType < 0xF) {
            var_f0 += D_800E2AB0[player->characterId][player->boundingBoxCorners[0].surfaceType];
        }
    }
    if (D_801652C0[arg1] & 4) {
        var_v1 = 2;
    } else {
        var_v1 = 0;
    }
    if ((player->currentSpeed >= 200.0f) && (var_v1 == 2)) {
        temp_lo = (s16) player->unk_0C0 / 182;
        if ((temp_lo > 0xF) || (temp_lo < -0xF)) {
            var_f0 += 1.0;
        }
    }
    if (((player->effects & 0x200000) == 0x200000) && ((player->type & PLAYER_HUMAN) != PLAYER_HUMAN)) {
        var_f0 = -3.0f;
    }

    if (player->unk_088 >= 0.0f) {
        var_f12 = player->unk_088 * var_f0;
    } else {
        var_f12 = -player->unk_088 * var_f0;
    }
    player->unk_208 = player->unk_088 - var_f12;
}

void func_8002FE84(Player *player, f32 arg1) {
    f32 temp_f0_3;
    f32 var_f0;
    s16 temp_lo;
    s32 test;

    if ((player->effects & 0x4000) == 0x4000) {
        player->unk_098 = ((player->currentSpeed * player->currentSpeed) / 25.0f) * 1.1;
        return;
    }
    
    // Huh?
    if (((player->effects & 0xFFFFFFFF) & 8) == 8) {
        player->unk_098 = ((player->currentSpeed * player->currentSpeed) / 25.0f) * 1.1;
        return;
    }

    var_f0 = 0.0f;
    player->unk_098 = arg1;
    temp_lo = player->slopeAccel / 182;
    if ((temp_lo > 0x11) || (temp_lo < -0x11)) {
        var_f0 += (temp_lo * 0.0125) / 1.2;
    } else {
        var_f0 += (temp_lo * 0.025) / 1.2;
    }
    player->unk_098 = arg1 * (1.0f - var_f0);
    if (player->boundingBoxCorners[3].surfaceType == 8) {
        var_f0 += D_800E2E90[player->characterId][player->boundingBoxCorners[3].surfaceType] * 0.7;
    }
    if (player->boundingBoxCorners[2].surfaceType == 8) {
        // The unecessary "* 1.0" here is to force the compiler to save this 0.7 as a separate RO value from the 0.7 just above this comment
        var_f0 += D_800E2E90[player->characterId][player->boundingBoxCorners[2].surfaceType] * (0.7 * 1.0);
    }
    test = player->unk_0C0 / 182;
    if (test < 0) {
        var_f0 += -test * 0.004;
    } else {
        var_f0 +=  test * 0.004;
    }
    player->unk_098 = arg1 * (1.0 + (var_f0 * 0.7));
    if ((player->effects & 0x20) == 0x20) {
        temp_f0_3 = player->currentSpeed + 180.0f;
        player->unk_098 = (temp_f0_3 * temp_f0_3) / 25.0f;
    }
}

f32 func_80030150(Player *player, s8 arg1) {
    f32 var_f0;
    s16 temp_lo;
    f32 var_f2;
    s32 var_v0;

    var_f0 = 0.0f;
    var_f2 = (player->unk_094 / 18.0f) * 216.0f;
    if (var_f2 >= 8.0f) {
        if ((player->effects & 0x200) != 0x200) {
            if ((s32) player->boundingBoxCorners[3].surfaceType >= 0xF) {
                // ???????
                if(1) {}
            } else {
                var_f0 += D_800E2E90[player->characterId][player->boundingBoxCorners[3].surfaceType];
            }
            
            if ((s32) player->boundingBoxCorners[2].surfaceType < 0xF) 
                var_f0 += D_800E2E90[player->characterId][player->boundingBoxCorners[2].surfaceType];
            
            if ((s32) player->boundingBoxCorners[1].surfaceType < 0xF) 
                var_f0 += D_800E2EB0[player->characterId][player->boundingBoxCorners[1].surfaceType];
            
            if ((s32) player->boundingBoxCorners[0].surfaceType < 0xF) 
                var_f0 += D_800E2E90[player->characterId][player->boundingBoxCorners[0].surfaceType];
        }
        if (((player->effects & 8) != 8) && ((player->unk_0CA & 2) != 2)) {
            temp_lo = player->slopeAccel / 182;
            if (var_f2 >= 20.0f) {
                if ((temp_lo > 0x11) || (temp_lo < -0x11)) {
                    var_f0 -= ((temp_lo * 0.0126) / 3.0);
                } else {
                    var_f0 -= ((temp_lo * 0.026) / 3.0);
                }
            } else {
                var_f0 += -0.2;
                if ((player->effects & LIGHTNING_EFFECT) == LIGHTNING_EFFECT) {
                    var_f0 += -0.55;
                }
            }
            if (((player->effects & 0x10) == 0x10) || (player->unk_204 > 0)) {
                var_v0 = (s16) player->unk_0C0 / 182;
                if (var_v0 < 0) {
                    var_f0 += -var_v0 * 0.004;
                } else {
                    var_f0 += var_v0 * 0.004;
                }
            } else {
                var_v0 = (s16) player->unk_0C0 / 182;
                if (var_v0 < 0) {
                    var_f0 += -var_v0 * (0.01 + gKartTurnSpeedReductionTable0[player->characterId]);
                } else {
                    var_f0 += var_v0 * (0.01 + gKartTurnSpeedReductionTable0[player->characterId]);
                }
            }
            if (((player->effects & 0x20000000) == 0x20000000) && (player->unk_228 < 0xA)) {
                if (var_v0 < 0) {
                    var_f0 += -var_v0 * 0.008;
                } else {
                    var_f0 += var_v0 * 0.008;
                }
            }
            if ((player->effects & 0x200) == 0x200) {
                var_f0 += -0.25;
            }
        }
        if ((player->unk_0DE & 1) == 1) {
            var_f0 += 0.3;
        } else {
            if ((player->unk_0DE & 2) == 2) {
                var_f0 += 0.15;
            }
            if (((D_801652A0[arg1] - player->boundingBoxCorners[2].cornerGroundY) >= 3.5) || ((D_801652A0[arg1] - player->boundingBoxCorners[3].cornerGroundY) >= 3.5)) {
                var_f0 += 0.05;
            }
        }
        if ((player->effects & 8) != 0) {
            move_f32_towards(&player->unk_0A0, player->unk_08C * 0.04, 0.15f);
        } else {
            move_f32_towards(&player->unk_0A0, 0.0f, 0.1f);
        }
    } else {
        player->unk_0A0 = 0.0f;
        player->unk_0E8 = 0.0f;
        if (((s16) player->slopeAccel / 182) < 0) {
            var_f0 += -0.85;
            if (player->effects & LIGHTNING_EFFECT) {
                var_f0 += -0.55;
            }
        }
    }
    if ((player->type & PLAYER_HUMAN) != PLAYER_HUMAN) {
        if ((player->effects & 0x200000) == 0x200000) {
            move_f32_towards(&player->unk_0E8, 380.0f, 0.5f);
        } else {
            move_f32_towards(&player->unk_0E8, 0.0f, 0.1f);
        }
    }
    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        if (((player->effects & 0x100) == 0x100) && ((player->effects & 0x10) != 0x10)) {
            move_f32_towards(&player->unk_0E8, 580.0f, 0.2f);
        } else {
            move_f32_towards(&player->unk_0E8, 0.0f, 0.01f);
        }
        if ((player->effects & 0x200000) == 0x200000) {
            move_f32_towards(&player->unk_0E4, 580.0f, 0.01f);
        } else {
            move_f32_towards(&player->unk_0E4, 0.0f, 0.01f);
        }
    }
    move_f32_towards(&player->unk_104, var_f0, gKartTurnSpeedReductionTable1[player->characterId] + 0.05);
    var_f2 = (player->unk_08C + player->unk_0E8 + player->boostPower + player->unk_0E4) - player->unk_0A0;
    if (var_f2 < 0.0f) {
        var_f2 = 0.0f;
    }
    if (((player->unk_0CA & 2) == 2) || ((player->unk_0CA & 8) == 8) || ((player->type & PLAYER_START_SEQUENCE) == PLAYER_START_SEQUENCE)) {
        return (1.0f - player->unk_104) * var_f2;
    }
    if (((player->effects & 0x80) == 0x80) || ((player->effects & 0x40) == 0x40) || ((player->effects & 0x01000000) == 0x01000000) || ((player->effects & 0x02000000) == 0x02000000)) {
        return (1.0f - player->unk_104) * var_f2;
    }
    // Have to `and` the 0x2000 here to force the compiler to reload the immediate
    if (((player->effects & 0x2000) == (0x2000 & 0xFFFFFFFF)) || ((player->effects & 0x100000) == 0x100000) || ((player->effects & 4) == 4)) {
        func_8002FE84(player, player->boostPower + player->unk_08C);
        return player->boostPower + player->unk_08C;
    }
    func_8002FE84(player, var_f2);
    return (1.0f - player->unk_104) * var_f2;
}

void func_80030A34(Player *player) {
    f32 var_f0;
    f32 var_f2;

    if (((player->unk_0CA & 2) != 2) && ((player->unk_0CA & 8) != 8)) {
        if ((((player->unk_094 / 18.0f) * 216.0f) >= 8.0f) && (player->unk_DB4.unkC < 1.0f)) {
            switch (player->unk_0F8) {                    /* irregular */
            case 1:
                if (random_int(0x000AU) != 8) {
                    var_f0 = 0.35f;
                    var_f2 = 0.55f;
                } else {
                    player->unk_07A = 0;
                    player->unk_108 = 0.0f;
                    var_f0 = 0.0f;
                    var_f2 = 0.0f;
                }
                break;
            case 14:
            case 16:
                var_f0 = 0.94f;
                var_f2 = 0.85f;
                break;
            default:
                if(1){}
                var_f0 = 0.46f;
                var_f2 = 0.48f;
                break;
            }
        } else if (random_int(0x000AU) != 8) {
            var_f0 = 0.3f;
            var_f2 = 0.54f;
        } else {
            player->unk_07A = 0;
            player->unk_108 = 0.0f;
            var_f0 = 0.0f;
            var_f2 = 0.0f;
        }
        player->unk_07A += 1;
        player->unk_108 = (player->unk_07A * var_f0) - (0.5 * var_f2 * (player->unk_07A * player->unk_07A));
        if ((player->unk_07A != 0) && (player->unk_108 < 0.0f)) {
            player->unk_07A = 0;
        }
        if (player->unk_108 <= 0.0f) {
            player->unk_108 = 0.0f;
        }
    }
}

// This is likely the function responsible for detecting triple-tap "A" for "fast" acceleration
void func_80030C34(Player *player) {
    s32 var_v0;

    if (player == gPlayerOne) {
        var_v0 = 0;
    }
    if (player == gPlayerTwo) {
        var_v0 = 1;
    }
    if (player == gPlayerThree) {
        var_v0 = 2;
    }
    if (player == gPlayerFour) {
        var_v0 = 3;
    }
    if (player == gPlayerFive) {
        var_v0 = 4;
    }
    if (player == gPlayerSix) {
        var_v0 = 5;
    }
    if (player == gPlayerSeven) {
        var_v0 = 6;
    }
    if (player == gPlayerEight) {
        var_v0 = 7;
    }
    if (gIsPlayerTripleAButtonCombo[var_v0] == FALSE) {
        if (gPlayerIsThrottleActive[var_v0] == 1) {
            if ((D_80165420[var_v0] < 2) || (D_80165420[var_v0] >= 9)) {
                D_80165440[var_v0] = 0;
            }
            D_80165420[var_v0] = 0;
            D_80165400[var_v0] = 0;
        }
        gPlayerIsThrottleActive[var_v0] = 0;
        D_80165420[var_v0]++;
        if (D_80165420[var_v0] >= 9) {
            D_80165420[var_v0] = 9;
        }
        if ((D_80165420[var_v0] >= 2) && (D_80165420[var_v0] < 9)) {
            if (D_80165400[var_v0] == 0) {
                D_80165440[var_v0] += 1;
            }
            D_80165400[var_v0] = 1;
        }
        if (D_80165440[var_v0] == 5) {
            gIsPlayerTripleAButtonCombo[var_v0] = TRUE;
            D_80165480[var_v0] = 0x00000078;
            D_80165440[var_v0] = 0;
            D_80165420[var_v0] = 0;
        }
    } else {
        D_80165480[var_v0]--;
        if (D_80165480[var_v0] <= 0) {
            gIsPlayerTripleAButtonCombo[var_v0] = FALSE;
        }
    }
}

void func_80030E00(Player *player) {
    s32 playerIndex;

    if (player == gPlayerOne) {
        playerIndex = 0;
    }
    if (player == gPlayerTwo) {
        playerIndex = 1;
    }
    if (player == gPlayerThree) {
        playerIndex = 2;
    }
    if (player == gPlayerFour) {
        playerIndex = 3;
    }
    if (player == gPlayerFive) {
        playerIndex = 4;
    }
    if (player == gPlayerSix) {
        playerIndex = 5;
    }
    if (player == gPlayerSeven) {
        playerIndex = 6;
    }
    if (player == gPlayerEight) {
        playerIndex = 7;
    }
    if (gIsPlayerTripleAButtonCombo[playerIndex] == FALSE) {
        if (gPlayerIsThrottleActive[playerIndex] == 0) {
            if ((D_80165420[playerIndex] < 2) || (D_80165420[playerIndex] >= 9)) {
                D_80165440[playerIndex] = 0;
            }
            D_80165420[playerIndex] = 0;
            D_80165400[playerIndex] = 0;
        }
        gPlayerIsThrottleActive[playerIndex] = 1;
        D_80165420[playerIndex]++;
        if (D_80165420[playerIndex] >= 9) {
            D_80165420[playerIndex] = 9;
        }
        if ((D_80165420[playerIndex] >= 2) && (D_80165420[playerIndex] < 9)) {
            if (D_80165400[playerIndex] == 0) {
                D_80165440[playerIndex] += 1;
            }
            D_80165400[playerIndex] = 1;
        }
        if (D_80165440[playerIndex] == 5) {
            gIsPlayerTripleAButtonCombo[playerIndex] = TRUE;
            D_80165480[playerIndex] = 0x00000078;
            D_80165440[playerIndex] = 0;
            D_80165420[playerIndex] = 0;
        }
    } else {
        D_80165480[playerIndex]--;
        if (D_80165480[playerIndex] <= 0) {
            gIsPlayerTripleAButtonCombo[playerIndex] = FALSE;
        }
    }
}

void player_speed(Player *player) {
    s32 player_index;

    player_index = get_player_index_for_player(player);
    if (gIsPlayerTripleAButtonCombo[player_index] == FALSE) {
        if ((0.0                     <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.1))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][0] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.1) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.2))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][1] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.2) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.3))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][2] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.3) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.4))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][3] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.4) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.5))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][4] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.5) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.6))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][5] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.6) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.7))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][6] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.7) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.8))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][7] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.8) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.9))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][8] + (0.05 * (player->slopeAccel / 182));
        }
        if (((player->topSpeed * 0.9) <= player->currentSpeed) && (player->currentSpeed <= (player->topSpeed * 1.0))) {
            player->currentSpeed += gKartAccelerationTables[player->characterId][9] + (0.05 * (player->slopeAccel / 182));
        }
    } else {
        if ((0.0                     <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.1))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][0] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.1) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.2))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][1] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.2) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.3))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][2] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.3) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.4))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][3] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.4) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.5))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][4] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.5) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.6))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][5] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.6) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.7))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][6] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.7) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.8))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][7] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.8) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.9))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][8] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
        if (((player->topSpeed * 0.9) <= player->currentSpeed) && (player->currentSpeed <= (player->topSpeed * 1.0))) {
            player->currentSpeed += (gKartAccelerationTables[player->characterId][9] + (0.05 * (player->slopeAccel / 182))) * gKartTripleABoost[player->characterId];
        }
    }
    if (player->currentSpeed < 0.0f) {
        player->currentSpeed = 0.0f;
    }
    if (player->topSpeed <= player->currentSpeed) {
        player->currentSpeed = player->topSpeed;
    }
    if (!((player->effects & 8)) || ((player->effects & LIGHTNING_EFFECT))) {
        player->unk_08C = (player->currentSpeed * player->currentSpeed) / 25.0f;
    }
    player->unk_044 |= 0x20;
    if ((player->statusEffects * 8) < 0) {
        func_8008F104(player, player_index);
        player->statusEffects &= 0xEFFFFFFF;
    }
}

void func_80031F48(Player *player, f32 arg1) {
    s32 player_index;
    player_index = get_player_index_for_player(player);

    player->currentSpeed -= arg1;
    if (player->currentSpeed <= 0.0f) {
        player->currentSpeed = 0.0f;
    }
    if (player->unk_094 < 0.2) {
        player->unk_08C = 0.0f;
    }
    if (player->topSpeed <= player->currentSpeed) {
        player->currentSpeed = player->topSpeed;
    }
    if ((player->effects & 8) != 8) {
        player->unk_08C = (player->currentSpeed * player->currentSpeed) / 25.0f;
    }
    player->unk_044 &= 0xFFDF;
    if ((player->statusEffects * 8) < 0) {
        func_8008F104(player, player_index);
        player->statusEffects &= 0xEFFFFFFF;
    }
}

void func_80032050(Player *player) {
    s32 var_v0;

    if (player == gPlayerOne) {
        var_v0 = 0;
    }
    if (player == gPlayerTwo) {
        var_v0 = 1;
    }
    if (player == gPlayerThree) {
        var_v0 = 2;
    }
    if (player == gPlayerFour) {
        var_v0 = 3;
    }
    if (player == gPlayerFive) {
        var_v0 = 4;
    }
    if (player == gPlayerSix) {
        var_v0 = 5;
    }
    if (player == gPlayerSeven) {
        var_v0 = 6;
    }
    if (player == gPlayerEight) {
        var_v0 = 7;
    }

    if (D_80165520[var_v0] == 0) {
        if (D_801654A0[var_v0] == 1) {
            if ((D_801654E0[var_v0] < 2) || (D_801654E0[var_v0] >= 9)) {
                D_80165500[var_v0] = 0;
            }
            D_801654E0[var_v0] = 0;
            D_801654C0[var_v0] = 0;
        }
        D_801654A0[var_v0] = 0;
        D_801654E0[var_v0]++;
        if (D_801654E0[var_v0] >= 9) {
            D_801654E0[var_v0] = 9;
        }
        if ((D_801654E0[var_v0] >= 2) && (D_801654E0[var_v0] < 9)) {
            if (D_801654C0[var_v0] == 0) {
                D_80165500[var_v0]++;
            }
            D_801654C0[var_v0] = 1;
        }
        if (D_80165500[var_v0] == 5) {
            D_80165520[var_v0] = 1;
            D_80165540[var_v0] = 0x00000078;
            D_80165500[var_v0] = 0;
            D_801654E0[var_v0] = 0;
        }
    } else {
        D_80165540[var_v0]--;
        if (D_80165540[var_v0] <= 0) {
            D_80165520[var_v0] = 0;
        }
    }
}

void func_8003221C(Player *player) {
    s32 var_v0;

    if (player == gPlayerOne) {
        var_v0 = 0;
    }
    if (player == gPlayerTwo) {
        var_v0 = 1;
    }
    if (player == gPlayerThree) {
        var_v0 = 2;
    }
    if (player == gPlayerFour) {
        var_v0 = 3;
    }
    if (player == gPlayerFive) {
        var_v0 = 4;
    }
    if (player == gPlayerSix) {
        var_v0 = 5;
    }
    if (player == gPlayerSeven) {
        var_v0 = 6;
    }
    if (player == gPlayerEight) {
        var_v0 = 7;
    }

    if (D_80165520[var_v0] == 0) {
        if (D_801654A0[var_v0] == 0) {
            if ((D_801654E0[var_v0] < 2) || (D_801654E0[var_v0] >= 9)) {
                D_80165500[var_v0] = 0;
            }
            D_801654E0[var_v0] = 0;
            D_801654C0[var_v0] = 0;
        }
        D_801654A0[var_v0] = 1;
        D_801654E0[var_v0]++;
        if (D_801654E0[var_v0] >= 9) {
            D_801654E0[var_v0] = 9;
        }
        if ((D_801654E0[var_v0] >= 2) && (D_801654E0[var_v0] < 9)) {
            if (D_801654C0[var_v0] == 0) {
                D_80165500[var_v0]++;
            }
            D_801654C0[var_v0] = 1;
        }
        if (D_80165500[var_v0] == 5) {
            D_80165520[var_v0] = 1;
            D_80165540[var_v0] = 0x00000078;
            D_80165500[var_v0] = 0;
            D_801654E0[var_v0] = 0;
        }
    } else {
        D_80165540[var_v0]--;
        if (D_80165540[var_v0] <= 0) {
            D_80165520[var_v0] = 0;
        }
    }
}

void func_800323E4(Player *player) {
    s32 var_v1;
    f32 test;
    f32 var_f2;

    var_f2 = 0.0f;
    if (player == gPlayerOne) {
        var_v1 = 0;
    }
    if (player == gPlayerTwo) {
        var_v1 = 1;
    }
    if (player == gPlayerThree) {
        var_v1 = 2;
    }
    if (player == gPlayerFour) {
        var_v1 = 3;
    }
    if (player == gPlayerFive) {
        var_v1 = 4;
    }
    if (player == gPlayerSix) {
        var_v1 = 5;
    }
    if (player == gPlayerSeven) {
        var_v1 = 6;
    }
    if (player == gPlayerEight) {
        var_v1 = 7;
    }
    player->effects |= 1;
    // This check will never be true, why is it here?
    if ((player->effects & 0x20) == 0x20) {
        func_80031F48(player, 1.0f);
        player->unk_20C = var_f2;
    } else {
        if ((s32) player->boundingBoxCorners[3].surfaceType < 0xF) {
            var_f2 += D_800E3210[player->characterId][player->boundingBoxCorners[3].surfaceType];
        }
        if ((s32) player->boundingBoxCorners[2].surfaceType < 0xF) {
            var_f2 += D_800E3210[player->characterId][player->boundingBoxCorners[2].surfaceType];
        }
        test = player->unk_22C - player->unk_094;
        if (test <= 0.0f) {
            player->unk_20C = 0.0f;
        } else {
            player->unk_20C += 0.02;
            if (player->unk_20C >= 2.0f) {
                player->unk_20C = 2.0f;
            }
        }
        if (D_80165520[var_v1] == 1) {
            if (player->unk_20C >= 2.0f) {
                func_80031F48(player, (1.0f - var_f2) * 5.0f);
            } else {
                func_80031F48(player, (1.0f - var_f2) * 3.0f);
            }
        } else {
            if (((player->unk_094 / 18.0f) * 216.0f) <= 20.0f) {
                func_80031F48(player, (1.0f - var_f2) * 4.0f);
            }
            if (player->unk_20C >= 2.0f) {
                func_80031F48(player, (1.0f - var_f2) * 2.5);
            } else {
                func_80031F48(player, (1.0f - var_f2) * 1.2);
            }
        }
    }
}

void func_80032700(Player *player) {
    s32 temp_v0;
    s32 var_v0;
    s32 test;

    temp_v0 = get_player_index_for_player(player);
    if ((player->currentSpeed >= 0.0) && (player->currentSpeed < (player->topSpeed * 0.1))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][0] * 3.0;
    }
    if (((player->topSpeed * 0.1) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.2))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][1] * 3.0;
    }
    if (((player->topSpeed * 0.2) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.3))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][2] * 3.0;
    }
    if (((player->topSpeed * 0.3) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.4))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][3] * 3.0;
    }
    if (((player->topSpeed * 0.4) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.5))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][4] * 3.0;
    }
    if (((player->topSpeed * 0.5) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.6))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][5] * 3.0;
    }
    if (((player->topSpeed * 0.6) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.7))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][6] * 2.5;
    }
    if (((player->topSpeed * 0.7) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.8))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][7] * 2.5;
    }
    if (((player->topSpeed * 0.8) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.9))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][8] * 2.5;
    }
    if (((player->topSpeed * 0.9) <= player->currentSpeed) && (player->currentSpeed <= player->topSpeed * 1.0)) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][9] * 2.5;
    }
    if (D_801656F0 == 1) {
        test = gRaceFrameCounter - D_801652E0[temp_v0];
        if (gModeSelection == (s32) 1) {
            var_v0 = 0x14;
        } else {
            var_v0 = 8;
        }
        if ((test < var_v0) && ((player->unk_044 & 0x20) != 0x20)) {
            player->statusEffects |= 0x02000000;
        } else if ((player->topSpeed * 0.9f) <= player->currentSpeed) {
            if ((player->statusEffects & 0x02000000) != 0x02000000) {
                player->statusEffects |= 0x10000000;
                player->statusEffects &= ~0x02000000;
            }
        }
    }
    player->unk_044 |= 0x20;
    player->unk_098 = (player->currentSpeed * player->currentSpeed) / 25.0f;
}

void func_80032CB0(Player *player, f32 arg1) {
    player->currentSpeed -= arg1;
    if (player->currentSpeed <= 0.0f) {
        player->currentSpeed = 0.0f;
    }
    if (player->unk_094 < 0.2) {
        player->unk_08C = 0.0f;
    }
    if (player->topSpeed <= player->currentSpeed) {
        player->currentSpeed = player->topSpeed;
    }
    if ((f64) player->currentSpeed <= (player->topSpeed * 0.7)) {
        player->statusEffects &= ~0x10000000;
    }
    player->statusEffects &= ~0x02000000;
    player->unk_044 &= ~0x0020;
    player->unk_098 = (player->currentSpeed * player->currentSpeed) / 25.0f;
}

void func_80032D94(Player *player) {
    UNUSED s32 player_index;

    player_index = get_player_index_for_player(player);
    if ((0.0                     <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.1))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][0] * 3.2;
    }
    if (((player->topSpeed * 0.1) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.2))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][1] * 3.2;
    }
    if (((player->topSpeed * 0.2) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.3))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][2] * 3.2;
    }
    if (((player->topSpeed * 0.3) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.4))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][3] * 3.2;
    }
    if (((player->topSpeed * 0.4) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.5))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][4] * 3.2;
    }
    if (((player->topSpeed * 0.5) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.6))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][5] * 3.2;
    }
    if (((player->topSpeed * 0.6) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.7))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][6] * 3.2;
    }
    if (((player->topSpeed * 0.7) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.8))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][7] * 2.8;
    }
    if (((player->topSpeed * 0.8) <= player->currentSpeed) && (player->currentSpeed < (player->topSpeed * 0.9))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][8] * 2.8;
    }
    if (((player->topSpeed * 0.9) <= player->currentSpeed) && (player->currentSpeed <= (player->topSpeed * 1.0))) {
        player->currentSpeed += gKartAccelerationTables[player->characterId][9] * 2.8;
    }
    if (player->currentSpeed < 0.0f) {
        player->currentSpeed = 0.0f;
    }
    player->unk_098 = (player->currentSpeed * player->currentSpeed) / 25.0f;
}

void func_80033280(Player *player, f32 arg1) {
    player->currentSpeed -= arg1;
    if (player->currentSpeed <= 0.0f) {
        player->currentSpeed = 0.0f;
    }
    if (player->topSpeed <= player->currentSpeed) {
        player->currentSpeed = player->topSpeed;
    }
    player->unk_098 = (player->currentSpeed * player->currentSpeed) / 25.0f;
}

void func_800332E8(Player *player, s32 arg1) {
    if ((D_80165280[arg1] >= 0.0) && (D_80165280[arg1] < ((f64) player->topSpeed * 0.1))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][0] * 3.2;
    }
    if (((player->topSpeed * 0.1) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.2))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][1] * 3.2;
    }
    if (((player->topSpeed * 0.2) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.3))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][2] * 3.2;
    }
    if (((player->topSpeed * 0.3) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.4))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][3] * 3.2;
    }
    if (((player->topSpeed * 0.4) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.5))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][4] * 3.2;
    }
    if (((player->topSpeed * 0.5) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.6))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][5] * 3.2;
    }
    if (((player->topSpeed * 0.6) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.7))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][6] * 3.2;
    }
    if (((player->topSpeed * 0.7) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.8))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][7] * 2.8;
    }
    if (((player->topSpeed * 0.8) <= D_80165280[arg1]) && (D_80165280[arg1] < (player->topSpeed * 0.9))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][8] * 2.8;
    }
    if (((player->topSpeed * 0.9) <= D_80165280[arg1]) && (D_80165280[arg1] <= (player->topSpeed * 1.0))) {
        D_80165280[arg1] += gKartAccelerationTables[player->characterId][9] * 2.8;
    }
    player->unk_044 |= 0x20;
    if (D_80165280[arg1] < 0.0f) {
        D_80165280[arg1] = 0.0f;
    }
    player->unk_098 = (D_80165280[arg1] * D_80165280[arg1]) / 25.0f;
}

void func_800337CC(Player *player, f32 arg1, s32 arg2) {
    player->unk_044 &= ~0x20;
    D_80165280[arg2] -= arg1;
    if (D_80165280[arg2] <= 0.0f) {
        D_80165280[arg2] = 0.0f;
    }
    if (player->topSpeed <= D_80165280[arg2]) {
        D_80165280[arg2] = player->topSpeed;
    }
    player->unk_098 = (D_80165280[arg2] * D_80165280[arg2]) / 25.0f;
}

void func_80033850(Player *arg0, f32 arg1) {
    arg0->unk_090 += arg1;
    if (arg0->unk_090 >= 0.0f) {
        arg0->unk_090 = 0.0f;
    }
}

void func_80033884(Player *player, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v1;

    if ((*arg1 >= arg4) || (-arg4 >= *arg1)) {        
        temp_v1 = player->unk_200;
        player->unk_200 -= 0x800; 
        if (player->unk_200 >= 0xF0000000) {
            player->unk_200 = temp_v1;
        }
        if (arg5 >= (s32)player->unk_200) {
            player->unk_200 = arg5;
        }

        *arg2 = (arg3 < *arg2) ? * arg2 - player->unk_200 : *arg2 + player->unk_200;

        if (player->unk_090 < ((f32) arg6)) {
            player->unk_090 = (f32) -arg6;
        }
    }
}

UNUSED void func_80033940(Player *player, s32 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u32 temp_v1;
 
    temp_v1 = player->unk_200;
    player->unk_200 -= 0x800;
    if (!(player->unk_200 < 0xF0000000)) {
        player->unk_200 = temp_v1;
    }
    if (arg3 >= (s32)player->unk_200) {
        player->unk_200 = arg3;
    }

    *arg1 = (arg2 < *arg1) ? *arg1 - player->unk_200 : *arg1 + player->unk_200;

    if (player->unk_090 < arg4) {
        player->unk_090 = (f32) -arg4;
    }
}

void func_800339C4(Player *player, s32 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 temp_v0;
    
    temp_v0 = player->unk_200;
    player->unk_200 -= 0x800;
    if (player->unk_200 >= 0xF0000000) {
        player->unk_200 = temp_v0;
    }
    if (arg3 >= (s32)player->unk_200) {
        player->unk_200 = arg3;
    }
    
    *arg1 = (arg2 < *arg1) ? *arg1 - player->unk_200 : *arg1 + player->unk_200;
    
    func_80033850(player, arg4);
}

void func_80033A40(Player *player, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    s32 temp_v1;

    if ((*arg1 >= arg4) || (-arg4 >= *arg1)) {        
        temp_v1 = player->unk_200;
        player->unk_200 -= 0x800; 
        if (player->unk_200 >= 0xF0000000) {
            player->unk_200 = temp_v1;
        }
        if (arg5 >= (s32)player->unk_200) {
            player->unk_200 = arg5;
        }

        *arg2 = (arg3 < *arg2) ? * arg2 - player->unk_200 : *arg2 + player->unk_200;

        func_80033850(player, arg6);
    }
}

void func_80033AE0(Player *player, struct Controller *controller, s8 arg2) {
    s32 sp2E4;
    s32 temp_v0_3;
    UNUSED s32 pad[2];
    UNUSED s16 pad2;
    s16 var_s1_2;
    s32 sp2D0;
    s32 sp2CC;
    s32 sp2C8;
    f32 var_f2_2;
    f32 var_f12 = 0.0f;
    f32 var_f2 = 0;
    UNUSED s32 pad3;
    s32 var_a0;
    f32 sp44[156] = {0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.6, 0.6, 0.6, 0.6, 0.6, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.6, 0.6, 0.6, 0.6, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8};

    if (((((player->effects & 2) != 2) && ((((player->unk_0C0 / 182) <= 6) && ((player->unk_0C0 / 182) >= (-6))) || ((controller->button & R_TRIG) != R_TRIG))) || (((player->unk_094 / 18.0f) * 216.0f) <= 20.0f)) || ((player->effects & 0x8000) == 0x8000))
    {
        func_80036CB4(player);
    }
    if ((player->unk_0C0 / 182) < (-5)) {
        player->unk_044 |= 4;
        player->unk_044 &= 0xFFFD;
        D_801652C0[arg2]++;
    }
    else
        if ((player->unk_0C0 / 182) >= 6)
    {
        player->unk_044 |= 2;
        player->unk_044 &= 0xFFFB;
        D_801652C0[arg2]++;
    }
    else
    {
        player->unk_044 &= 0xFFF9;
        D_801652C0[arg2] = 0;
    }
    if (((player->effects & 2) == 2) || ((player->effects & 0x10) == 0x10))
    {
        player->unk_044 &= 0xFFF9;
    }
    sp2E4 = player->unk_07C;
    temp_v0_3 = func_80038534(controller);
    if (((player->unk_044 & 1) == 1) || ((player->unk_044 & 8) == 8))
    {
        temp_v0_3 = -temp_v0_3;
    }
    player->unk_07C = (temp_v0_3 << 16) & 0xFFFF0000;
    sp2D0 = sp2E4 - player->unk_07C;
    sp2D0 = sp2D0 >> 16;
    player->unk_0FA = (s16) sp2D0;
    if (((sp2D0 >= 0x5A) || (sp2D0 < (-0x59))) && (!(player->unk_044 & 0x4000)))
    {
        if ((((((!(player->effects & 0x10)) && (gCCSelection == 2)) && (gModeSelection != 3)) && (!(player->effects & 8))) && (((player->unk_094 / 18.0f) * 216.0f) >= 40.0f)) && (player->unk_204 == 0))
        {
        player->statusEffects |= 0x80;
        }
    }
    if (((s32) player->boundingBoxCorners[3].surfaceType) < 0xF)
    {
        var_f2 += D_800E3610[player->characterId][player->boundingBoxCorners[3].surfaceType];
    }
    if (((s32) player->boundingBoxCorners[2].surfaceType) < 0xF)
    {
        var_f2 += D_800E3610[player->characterId][player->boundingBoxCorners[2].surfaceType];
    }
    if ((player->effects & 0x20) == 0x20)
    {
        sp2C8 = 10;
        sp2CC = 10;
    }
    else
    {
        if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2))
        {
        var_a0 = 3;
        }
        else
        {
        var_a0 = 0;
        }
        if (((player->unk_094 / 18.0f) * 216.0f) >= 15.0f)
        {
        if ((player->unk_044 & 2) == 2)
        {
            if ((sp2D0 < 36) && (sp2D0 >= 0))
            {
            sp2C8 = (gKartTable800E3650[player->characterId] + 1.0f) * (((f32) (var_a0 + 0xF)) * (1.0f + var_f2));
            sp2CC = (gKartTable800E3650[player->characterId] + 1.0f) * (((f32) (var_a0 + 0xF)) * (1.0f + var_f2));
            }
            else
            {
            sp2C8 = (s32) (((f32) (var_a0 + 5)) * (1.0f + var_f2));
            sp2CC = (s32) (((f32) (var_a0 + 9)) * (1.0f + var_f2));
            }
        }
        else
            if ((player->unk_044 & 4) == 4)
        {
            if ((sp2D0 >= (-0x23)) && (sp2D0 <= 0))
            {
            sp2C8 = (gKartTable800E3650[player->characterId] + 1.0f) * (((f32) (var_a0 + 0xF)) * (1.0f + var_f2));
            sp2CC = (gKartTable800E3650[player->characterId] + 1.0f) * (((f32) (var_a0 + 0xF)) * (1.0f + var_f2));
            }
            else
            {
            sp2C8 = (s32) (((f32) (var_a0 + 5)) * (1.0f + var_f2));
            sp2CC = (s32) (((f32) (var_a0 + 9)) * (1.0f + var_f2));
            }
        }
        else
        {
            sp2C8 = (s32) (((f32) (var_a0 + 3)) * (1.0f + var_f2));
            sp2CC = (s32) (((f32) (var_a0 + 6)) * (1.0f + var_f2));
        }
        }
        else
        {
        sp2C8 = 8;
        sp2CC = 8;
        }
    }
    if ((player->unk_0DE & 1) == 1)
    {
        sp2C8 *= 1.5;
        sp2CC *= 1.5;
    }
    else
    {
        if ((player->unk_0DE & 2) == 2)
        {
        sp2C8 *= 1.2;
        sp2CC *= 1.2;
        }
        if ((((f64) (D_801652A0[arg2] - player->boundingBoxCorners[2].cornerGroundY)) >= 3.5) || (((f64) (D_801652A0[arg2] - player->boundingBoxCorners[3].cornerGroundY)) >= 3.5))
        {
        sp2C8 *= 1.05;
        sp2CC *= 1.05;
        }
    }
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000005A, 0x78000 / sp2C8, 0x000001C2);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000059, 0x76000 / sp2C8, 0x000001B8);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000058, 0x74000 / sp2C8, 0x000001AE);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000057, 0x72000 / sp2C8, 0x000001A4);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000056, 0x70000 / sp2C8, 0x0000019A);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000055, 0x58000 / sp2C8, 0x00000190);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000054, 0x56000 / sp2C8, 0x0000018B);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000053, 0x50000 / sp2C8, 0x00000186);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000052, 0x4F000 / sp2C8, 0x00000186);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000051, 0x4E000 / sp2C8, 0x0000017C);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000050, 0x4D000 / sp2C8, 0x00000172);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000004F, 0x4C000 / sp2C8, 0x00000168);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000004E, 0x4C000 / sp2C8, 0x00000168);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000004D, 0x4B000 / sp2C8, 0x0000015E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000004C, 0x4A000 / sp2C8, 0x00000154);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000004B, 0x49000 / sp2C8, 0x0000014A);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000004A, 0x49000 / sp2C8, 0x0000014A);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000049, 0x49000 / sp2C8, 0x0000014A);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000048, 0x48000 / sp2C8, 0x00000140);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000047, 0x47000 / sp2C8, 0x0000013B);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000046, 0x47000 / sp2C8, 0x0000013B);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000045, 0x46000 / sp2C8, 0x00000131);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000044, 0x46000 / sp2C8, 0x00000131);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000043, 0x45000 / sp2C8, 0x00000118);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000042, 0x46000 / sp2C8, 0x0000010E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000041, 0x45000 / sp2C8, 0x0000010E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000040, 0x44000 / sp2C8, 0x00000104);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000003F, 0x43000 / sp2C8, 0x000000FA);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000003E, 0x43000 / sp2C8, 0x000000FA);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000003D, 0x43000 / sp2C8, 0x000000FA);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000003C, 0x3D000 / sp2C8, 0x000000F5);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000003B, 0x3C000 / sp2C8, 0x000000F5);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000003A, 0x3B000 / sp2C8, 0x000000F5);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000039, 0x3A000 / sp2C8, 0x000000F5);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000038, 0x38000 / sp2C8, 0x000000F5);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000037, 0x38000 / sp2C8, 0x000000E6);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000036, 0x38000 / sp2C8, 0x000000E6);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000035, 0x38000 / sp2C8, 0x000000E6);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000034, 0x38000 / sp2C8, 0x000000E6);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000033, 0x38000 / sp2C8, 0x000000E6);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000032, 0x32000 / sp2C8, 0x000000DC);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000031, 0x32000 / sp2C8, 0x000000DC);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000030, 0x32000 / sp2C8, 0x000000DC);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000002F, 0x32000 / sp2C8, 0x000000DC);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000002E, 0x32000 / sp2C8, 0x000000DC);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000002D, 0x30000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000002C, 0x2E000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000002B, 0x2E000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000002A, 0x2E000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000029, 0x2E000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000028, 0x2E000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000027, 0x2C000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000026, 0x28000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000025, 0x28000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000024, 0x24000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000023, 0x24000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000022, 0x22000 / sp2C8, 0x0000006E);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000020, 0x20000 / sp2C8, 0x00000064);
    func_80033884(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000001F, 0x20000 / sp2C8, 0x00000064);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000001E, 0x1F000 / sp2CC, 0.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000001D, 0x1E000 / sp2CC, 0.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000001C, 0x1D000 / sp2CC, 0.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000001B, 0x1C000 / sp2CC, 0.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000001A, 0x1B000 / sp2CC, 0.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000019, 0x1A000 / sp2CC, 1.0f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000018, 0x19000 / sp2CC, 1.0f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000017, 0x18000 / sp2CC, 1.0f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000016, 0x17000 / sp2CC, 1.0f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000015, 0x16000 / sp2CC, 1.0f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000014, 0x15000 / sp2CC, 1.05f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000013, 0x14000 / sp2CC, 1.05f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000012, 0x13000 / sp2CC, 1.05f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000011, 0x12000 / sp2CC, 1.05f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x00000010, 0x11000 / sp2CC, 1.05f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000000F, 0x10000 / sp2CC, 1.2f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000000E, 0xF000 / sp2CC, 1.2f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000000D, 0xE000 / sp2CC, 1.2f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000000C, 0xD000 / sp2CC, 1.2f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000000B, 0xC000 / sp2CC, 1.2f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0x0000000A, 0xE000 / sp2CC, 1.6f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 9, 0xD000 / sp2CC, 1.6f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 8, 0xC000 / sp2CC, 1.6f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 7, 0xB000 / sp2CC, 1.6f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 6, 0xA000 / sp2CC, 1.6f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 5, 0x9000 / sp2CC, 1.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 4, 0x8000 / sp2CC, 1.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 3, 0x7000 / sp2CC, 1.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 2, 0x6000 / sp2CC, 1.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 1, 0x5000 / sp2CC, 1.9f);
    func_80033A40(player, &sp2D0, &sp2E4, player->unk_07C, 0, 0 / sp2CC, 1.9f);
    if ((player->effects & 0x10) == 0x10)
    {
        var_f2_2 = (f32) (((s32) (sp2E4 >> 16)) / 8);
    }
    else
        if (((player->unk_094 / 18.0f) * 216.0f) <= 25.0f)
    {
        var_f2_2 = (f32) ((sp2E4 >> 16) / 12);
    }
    else
    {
        var_f2_2 = ((f32) (sp2E4 >> 0x10)) / (8.0f + (player->currentSpeed / 50.0f));
    }
    if (var_f2_2 < 0.0f)
    {
        var_f2_2 = -var_f2_2;
    }
    if ((player->effects & 0x20) == 0x20)
    {
        var_f2_2 = var_f2_2 * (sp44[((s16) ((player->unk_094 / 18.0f) * 216.0f)) + 10] * 1.5f);
    }
    else
        if ((player->effects & 0x10) == 0x10)
    {
        var_f2_2 = var_f2_2 * sp44[(s16) ((player->unk_094 / 18.0f) * 216.0f)];
    }
    else
    {
        var_f2_2 = var_f2_2 * (sp44[(s16) ((player->unk_094 / 18.0f) * 216.0f)] * 1.5f);
    }
    player->unk_07C = sp2E4;
    if (player->unk_10C != 0)
    {
        func_8002BD58(player);
    }
    player->effects &= 0xDFFFFFFF;
    if (((s32) player->boundingBoxCorners[3].surfaceType) > 0xE)
    {
        var_f12 = var_f12;
    }
    else
    {
        var_f12 += D_800E3410[player->characterId][player->boundingBoxCorners[3].surfaceType];
    }
    if (((s32) player->boundingBoxCorners[2].surfaceType) < 0xF)
    {
        var_f12 += D_800E3410[player->characterId][player->boundingBoxCorners[2].surfaceType];
    }
    if (((player->effects & 2) != 2) && ((player->effects & 0x10) != 0x10))
    {
        if ((player->effects & 0x20) == 0x20)
        {
        player->unk_078 = (s16) ((s32) (((f32) ((((s32) player->unk_07C) >> 0x10) * 5)) * var_f2_2));
        }
        else
        {
        if ((player->effects & 0x1) != 0x1)
        {
            if (((player->unk_07C >> 16) >= 45) || ((player->unk_07C >> 16) <= (-45)))
            {
            player->unk_078 = ((player->unk_07C >> 16) * (var_f2_2 + (var_f2_2 * var_f12))) * (0.15 + gKartHandlingTable[player->characterId]);
            }
            else
            {
            player->unk_078 = ((player->unk_07C >> 16) * (var_f2_2 + (var_f2_2 * var_f12))) * gKartHandlingTable[player->characterId];
            }
        }
        else
        {
            if ((((player->unk_094 / 18.0f) * 216.0f) >= 0.0f) && (((player->unk_094 / 18.0f) * 216.0f) < 8.0f))
            {
            player->unk_078 = (player->unk_07C >> 16) * (var_f2_2 + (var_f2_2 * var_f12));
            }
            if ((((player->unk_094 / 18.0f) * 216.0f) >= 8.0f) && (((player->unk_094 / 18.0f) * 216.0f) < 65.0f))
            {
            player->unk_078 = (player->unk_07C >> 16) * ((var_f2_2 + 1.5) + (var_f2_2 * var_f12));
            }
            if (((player->unk_094 / 18.0f) * 216.0f) >= 65.0f)
            {
            player->unk_078 = (player->unk_07C >> 16) * ((var_f2_2 + 1.6) + (var_f2_2 * var_f12));
            }
        }
        player->unk_228 = 0;
        if (player->unk_22A < 2) {
            player->unk_22A = 0;
        }
        }
    }
    else
        if (((player->effects & 8) != 8) && ((player->effects & 2) != 2)) {
        if ((((s16) player->unk_0C0) / 182) > 0)
        {
            var_s1_2 = (((s32) (((player->unk_07C >> 0x10) * 0xD) + 0x2B1)) / 106) + 0x28;
            if ((player->unk_07C >> 0x10) < (-0x27)) {
                player->effects = player->effects | 0x20000000;
                if ((player->unk_07C >> 0x10) < (-0x31)) {
                    player->effects |= 0x20000000;
                }
            }
            func_8002A8A4(player, arg2);
        }
        else {
            var_s1_2 = (((s32) (((player->unk_07C >> 0x10) * 0xD) + 0x2B1)) / 106) - 0x35;
            if ((player->unk_07C >> 0x10) >= 0x28) {
                player->effects = player->effects | 0x20000000;
                if ((player->unk_07C >> 0x10) < (-0x31)) {
                    player->effects |= 0x20000000;
                }
            }
            func_8002A8A4(player, arg2);
        }
        if ((((player->unk_094 / 18.0f) * 216.0f) >= 0.0f) && (((player->unk_094 / 18.0f) * 216.0f) < 8.0f)) {
            player->unk_078 = (s16) ((s32) (var_s1_2 * ((var_f2_2 + 2.0f) + (var_f2_2 * var_f12))));
        }
        if ((((player->unk_094 / 18.0f) * 216.0f) >= 8.0f) && (((player->unk_094 / 18.0f) * 216.0f) < 65.0f)) {
            player->unk_078 = var_s1_2 * ((var_f2_2 + 3) + (var_f2_2 * var_f12));
        }
        if (((player->unk_094 / 18.0f) * 216.0f) >= 65.0f) {
            player->unk_078 = var_s1_2 * ((((f64) var_f2_2) + 3.5) + (var_f2_2 * var_f12));
        }
        if ((player->effects & 0x20000000) == 0x20000000) {
            player->unk_078 *= 0.9;
        }
        else {
            player->unk_078 *= 0.65;
        }
    } else {
        var_s1_2 = (s16) (((s32) player->unk_07C) >> 16);
        if (temp_v0_3 == 0) {
            var_s1_2 = 0;
        }
        if (((player->unk_094 / 18.0f) * 216.0f) <= 5.0f) {
            player->unk_078 = (s16) ((s32) (((f32) var_s1_2) * (var_f2_2 + 6.0f)));
        }
        else {
            player->unk_078 = ((s16) var_s1_2) * (var_f2_2 + 1.5f);
        }
    }
    if (gModeSelection == 3) {
        player->unk_078 *= 1.7;
    }
}

void func_8003680C(Player *player, s16 arg1) {
    s32 sp304 = 0;
    UNUSED f32 pad[6];
    f32 var_f0;
    s16 var_v0;
    f32 sp44[168] = {
        0.0f, 0.1f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.7f, 0.7f, 0.7f, 0.7f,
        0.7f, 0.7f, 0.7f, 0.6f, 0.5f, 0.4f, 0.4f, 0.4f,
        0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f,
        0.4f, 0.4f, 0.4f, 0.4f, 0.5f, 0.5f, 0.5f, 0.5f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f,
        0.8f, 0.8f, 0.8f, 0.8f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
        0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f,
    };
    f32 sp24[8] = {
        3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
    };

    if (!((player->effects & 0x80) ||
          (player->effects & 0x40) ||
          (player->effects & 0x400) ||
          (player->effects & 0x10000) ||
          (player->effects & 0x20000) ||
          (player->effects & 0x01000000) ||
          (player->effects & 0x02000000) ||
          (player->effects & 0x04000000))) {
        if (!(((player->unk_094 / 18.0f) * 216.0f) >= 110.0f)) {
            player->effects &= ~0x20000000;
            player->unk_228 = 0;
            if (!(player->effects & 0x80) && !(player->effects & 0x40)) {
                sp304 = (s32) player->unk_07C >> 0x10;
                move_s32_towards(&sp304, (s32) arg1, 0.35f);
                sp304 <<= 0x10;
                if ((player->effects & 0x10) == 0x10) {
                    var_f0 = (sp304 >> 0x10) / 5;
                } else {
                    var_f0 = (f32) (sp304 >> 0x10) / (8.0f + (player->currentSpeed / 50.0f));
                }
                if (var_f0 < 0.0f) {
                    var_f0 = -var_f0;
                }
                if ((player->effects & 0x10) == 0x10) {
                    var_f0 = sp44[(s16) ((player->unk_094 / 18.0f) * 216.0f)] * var_f0;
                } else {
                    var_f0 = sp44[(s16) ((player->unk_094 / 18.0f) * 216.0f)] * sp24[player->characterId] * var_f0;
                }
                player->unk_07C = sp304;
                if (((player->effects & 2) != 2) && ((player->effects & 0x10) != 0x10)) {
                    if ((player->effects & 1) != 1) {
                        player->unk_078 = (player->unk_07C >> 0x10) * var_f0;
                    } else {
                        player->unk_078 = (player->unk_07C >> 0x10) * (var_f0 + 1.5);
                    }
                } else if ((player->effects & 8) != 8) {
                    if (((s16) player->unk_0C0 / 182) > 0) {
                        var_v0 = player->unk_07C >> 0x10;
                    } else {
                        var_v0 = player->unk_07C >> 0x10;
                    }
                    player->unk_078 = var_v0 * (var_f0 + 3.0);
                    player->unk_078 *= 0.8;
                } else {
                    var_v0 = (s16) ((s32) player->unk_07C >> 0x10);
                    if (arg1 == 0) {
                        var_v0 = 0;
                    }
                    player->unk_078 = var_v0 * var_f0;
                }
                if ((((player->effects & 2) != 2) &&
                      (player->unk_0C0 < 0x3D) &&
                      (player->unk_0C0 > -0x3D)) ||
                    (((player->unk_094 / 18.0f) * 216.0f) <= 20.0f) ||
                     ((player->effects & 0x8000) == 0x8000)) {
                    func_80036CB4(player);
                }
            }
        }
    }
}

void func_80036C5C(Player *arg0) {
    if (((arg0->unk_094 / 18.0f) * 216.0f) > 20.0f) {
        arg0->unk_204 = 0;
        arg0->effects |= 0x10;
        arg0->unk_0B6 |= 0x800;
    }
}

void func_80036CB4(Player *player) {
    s32 test;

    if (((player->effects & 0x10) == 0x10) && ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN)) {
        if ((player->unk_0C0 / 182) > 0) {
            test = ((((player->unk_07C >> 0x10) * 0xD) + 0x2B1) / 106) + 0x28;
            player->unk_07C = test << 0x10;
        }
        if ((player->unk_0C0 / 182) < 0) {
            test = ((((player->unk_07C >> 0x10) * 0xD) + 0x2B1) / 106) - 0x35;
            player->unk_07C = test << 0x10;
        }
        player->effects &= ~0x10;
    }
    if (((player->effects & 0x10) == 0x10) && ((player->type & PLAYER_HUMAN) != PLAYER_HUMAN)) {
        player->effects &= ~0x10;
    }
}

void func_80036DB4(Player *player, Vec3f arg1, Vec3f arg2) {
    s16 thing;
    UNUSED s16 pad;
    f32 sp20;
    f32 var_f18;
    s32 temp_t6;

    if (((player->effects & 0x1000) == 0x1000) || ((player->effects & 0x20) == 0x20)) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    } else {
        if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2)) {
            var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) * 3.0f) + (-player->unk_20C * 10.0f);
            sp20 = player->unk_084 * 3.0f;
        } else if (!(player->effects & 0x800) && !(player->unk_044 & 0x4000)) {
            thing = player->unk_0FA;
            if (thing > 0) {
                thing *= -1;
            }
            temp_t6 = player->unk_07C >> 0x10;
            if ((temp_t6 < 0x15) && (temp_t6 >= -0x14)) {
                if (thing < 0x14) {
                    var_f18 = (player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f)) + (-player->currentSpeed * 0.02) + (-player->unk_20C * 50.0f);
                } else {
                    var_f18 = (player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f)) + ((temp_t6 * 0.01) + (-player->currentSpeed * 0.05)) + (-player->unk_20C * 50.0f);
                }
            } else {
                var_f18 = (player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f)) + ((temp_t6 * 0.1) + (-player->currentSpeed * 0.15)) + (-player->unk_20C * 50.0f);
            }
            sp20 = player->unk_084;
        } else {
            var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) * 1.5) + (((player->unk_07C >> 0x10) * 0.1) + (-player->currentSpeed * 0.05)) + (-player->unk_20C * 50.0f);
            sp20 = player->unk_084;
        }
        if ((player->effects & 0x200) == 0x200) {
            if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2)) {
                var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) * 3.0f) + (-player->unk_20C * 10.0f);
                sp20 = player->unk_084 * 3.0f;
            } else {
                var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f);
                sp20 = player->unk_084;
            }
        }
        arg1[0] = (player->unk_090 + var_f18) * player->unk_094;
        arg1[1] = 0.0f;
        arg1[2] = player->unk_094 * sp20;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    }
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];
}

void func_800371F4(Player *player, Vec3f arg1, Vec3f arg2) {
    s16 var_v0;
    f32 sp20;
    f32 var_f18;
    s32 temp_t6;

    if (((player->effects & 0x1000) == 0x1000) || ((player->effects & 0x20) == 0x20)) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    } else {
        if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2)) {
            var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) * 3.0f) + (-player->unk_20C * 50.0f);
            sp20 = player->unk_084 * 3.0f;
        } else if (!(player->effects & 0x800) && !(player->unk_044 & 0x4000)) {
            var_v0 = player->unk_0FA;
            if (var_v0 > 0) {
                var_v0 *= -1;
            }
            temp_t6 = (s32) player->unk_07C >> 0x10;
            if ((temp_t6 < 0x15) && (temp_t6 >= -0x14)) {
                if (var_v0 < 0x14) {
                    var_f18 = (player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f)) + (-player->currentSpeed * 0.02) + (-player->unk_20C * 50.0f);
                } else {
                    var_f18 = ((player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f)) - ((temp_t6 * 0.01) + (player->currentSpeed * 0.05))) + (-player->unk_20C * 50.0f);
                }
            } else {
                var_f18 = ((player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f)) - ((temp_t6 * 0.1) + (player->currentSpeed * 0.15))) + (-player->unk_20C * 50.0f);
            }
            sp20 = player->unk_084;
        } else {
            var_f18 = ((player->unk_208 + ((f64) (-(player->unk_094 / 18.0f) * 216.0f) * 1.5)) - (((player->unk_07C >> 0x10) * 0.1) + (player->currentSpeed * 0.05))) + (-player->unk_20C * 50.0f);
            sp20 = player->unk_084;
        }
        if ((player->effects & 0x200) == 0x200) {
            if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2)) {
                var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) * 3.0f) + (-player->unk_20C * 50.0f);
                sp20 = player->unk_084 * 3.0f;
            } else {
                var_f18 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 3.0f);
                sp20 = player->unk_084;
            }
        }
        arg1[0] = -(player->unk_090 + var_f18) * player->unk_094;
        arg1[1] = 0.0f;
        arg1[2] = player->unk_094 * sp20;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    }
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];
}

void func_80037614(Player *player, Vec3f arg1, Vec3f arg2) {
    f32 var_f12;
    f32 var_f2;

    if (((player->effects & 0x1000) == 0x1000) || ((player->effects & 0x20) == 0x20)) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    } else {
        if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2)) {
            var_f2 = ((-(player->unk_094 / 18.0f) * 216.0f) * 2) + -80.0f;
            var_f12 = -80.0f;
        } else {
            var_f2 = ((-(player->unk_094 / 18.0f) * 216.0f) / 2) + -20.0f;
            var_f12 = -40.0f;
        }
        arg1[0] = (var_f2 + 28.0f) * player->unk_094;
        arg1[1] = 0.0f;
        arg1[2] = var_f12 * player->unk_094;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    }
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];
}

void func_8003777C(Player *player, Vec3f arg1, Vec3f arg2) {
    f32 var_f12;
    f32 var_f2;

    if (((player->effects & 0x1000) == 0x1000) || ((player->effects & 0x20) == 0x20)) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    } else {
        if (((player->effects & 0x10) == 0x10) && ((player->effects & 2) != 2)) {
            var_f2 = ((-(player->unk_094 / 18.0f) * 216.0f) * 2) + -80.0f;
            var_f12 = -80.0f;
        } else {
            var_f2 = ((-(player->unk_094 / 18.0f) * 216.0f) / 2) + -20.0f;
            var_f12 = -40.0f;
        }
        arg1[0] = -(var_f2 + 28.0f) * player->unk_094;
        arg1[1] = 0.0f;
        arg1[2] = var_f12 * player->unk_094;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    }
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];
}

void func_800378E8(Player *player, Vec3f arg1, Vec3f arg2) {
    f32 var_f12;
    f32 var_f2;

    if ((player->effects & 0x20) == 0x20) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    } else {
        if ((player->effects & 0x10) == 0x10) {
            var_f2 = player->unk_208 + (-(player->unk_094 / 18.0f) * 216.0f * 5.0f) + (-player->unk_20C * 10.0f);
            var_f12 = -100.0f;
        } else {
            var_f2 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 40.0f) + (-player->unk_20C * 50.0f);
            var_f12 = player->unk_084;
        }
        arg1[0] = (player->unk_090 + var_f2) * player->unk_094;
        arg1[1] = 0.0f;
        arg1[2] = player->unk_094 * var_f12;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    }
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];
}

void func_80037A4C(Player *player, Vec3f arg1, Vec3f arg2) {
    f32 var_f12;
    f32 var_f2;

    if ((player->effects & 0x20) == 0x20) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    } else {
        if ((player->effects & 0x10) == 0x10) {
            var_f2 = player->unk_208 + (-(player->unk_094 / 18.0f) * 216.0f * 5.0f) + (-player->unk_20C * 50.0f);
            var_f12 = -100.0f;
        } else {
            var_f2 = player->unk_208 + ((-(player->unk_094 / 18.0f) * 216.0f) / 40.0f) + (-player->unk_20C * 50.0f);
            var_f12 = player->unk_084;
        }
        arg1[0] = -(player->unk_090 + var_f2) * player->unk_094;
        arg1[1] = 0.0f;
        arg1[2] = player->unk_094 * var_f12;
        mtxf_translate_vec3f_mat3(arg1, player->orientationMatrix);
    }
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];
}

void func_80037BB4(Player *player, Vec3f arg1) {
    UNUSED s32 pad[3];
    Vec3f sp20;

    if (player->unk_078 == 0) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
    } else {
        if (player->unk_078 < 0) {
            if (((player->effects & 0x20000000) != 0x20000000) || (player->unk_228 >= 0x64)) {
                player->unk_02C[1] += player->unk_078;
            }
            if (!(player->type & PLAYER_CPU)) {
                if (gModeSelection == BATTLE) {
                    func_800378E8(player, sp20, arg1);
                } else {
                    func_80036DB4(player, sp20, arg1);
                }
            } else {
                func_80037614(player, sp20, arg1);
            }
        } else {
            if (((player->effects & 0x20000000) != 0x20000000) || (player->unk_228 >= 0x64)) {
                player->unk_02C[1] += player->unk_078;
            }
            if (!(player->type & PLAYER_CPU)) {
                if (gModeSelection == BATTLE) {
                    func_80037A4C(player, sp20, arg1);
                } else {
                    func_800371F4(player, sp20, arg1);
                }
            } else {
                func_8003777C(player, sp20, arg1);
            }
        }
    }
}

void func_80037CFC(Player *player, struct Controller *controller, s8 arg2) {
    if (((player->effects & 0x80) != 0x80) && 
        ((player->effects & 0x40) != 0x40) && 
        ((player->effects & 0x400) != 0x400) && 
        ((player->effects & 0x4000) != 0x4000) && 
        ((player->effects & 0x01000000) != 0x01000000) && 
        ((player->effects & 0x02000000) != 0x02000000) && ((player->effects & 0x10000) != 0x10000) && 
        ((player->effects & 0x20000) != 0x20000)) {
            if (((player->effects & 0x04000000) != 0x04000000) && 
                ((player->effects & 8) != 8) && 
                ((player->effects & 2) != 2) && 
                ((player->effects & 0x10) != 0x10) && 
                (controller->buttonPressed & R_TRIG)) {
                    func_8002AA50(player);
                    if (((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && ((player->type & PLAYER_INVISIBLE_OR_BOMB) != PLAYER_INVISIBLE_OR_BOMB)) {
                        func_800C9060(arg2, 0x19008000);
                    }
            }
            if ((player->effects & 8) != 8) {
                func_80033AE0(player, controller, arg2);
            } else if (((player->effects & 2) == 2) && (player->unk_110.unk3C[2] <= 5.0f)) {
                func_80033AE0(player, controller, arg2);
            }
            player->effects &= ~1;
            if ((!(player->effects & 0x100000)) && (!(player->effects & 4))) {
                if (((player->unk_094 / 18.0f) * 216.0f) <= 12.0f) {
                    if (controller->button & A_BUTTON) {
                        if (controller->button & B_BUTTON) {
                            player->effects |= 0x20;
                            if ((player->effects & 0x20) != 0x20) {
                                player->currentSpeed += 100.0f;
                            }
                        }
                    }
                }
                if (((player->effects & 0x20) == 0x20) && 
                    (((controller->button & B_BUTTON) == 0) || 
                    (!(controller->button & A_BUTTON)))) {
                        player->effects &= ~0x20;
                }
            }
            if ((player->unk_044 & 1) != 1) {
                if (controller->button & A_BUTTON) {
                    player_speed(player);
                    func_80030E00(player);
                } else {
                    if (gModeSelection == 3)
                    {
                      func_80031F48(player, 2.0f);
                    }
                    else
                    {
                      func_80031F48(player, 1.0f);
                    }
                    func_80030C34(player);
                }
                if (controller->button & B_BUTTON) {
                    func_800323E4(player);
                    func_8003221C(player);
                } else {
                    player->unk_20C = 0.0f;
                    func_80032050(player);
                }
            }
            if ((!(player->effects & 0x100000)) && (!(player->effects & 4))) {
                if (((func_800388B0(controller) < (-0x31)) && 
                    (((player->unk_094 / 18.0f) * 216.0f) <= 5.0f)) && 
                    (controller->button & B_BUTTON)) {
                        player->currentSpeed = 140.0f;
                        player->unk_044 |= 1;
                        player->unk_08C = (player->currentSpeed * player->currentSpeed) / 25.0f;
                        player->unk_20C = 0.0f;
                }
                if ((func_800388B0(controller) >= -0x1D) || (!(controller->button & B_BUTTON))) {
                    if ((player->unk_044 & 1) == 1) {
                        player->unk_044 &= 0xFFFE;
                        player->currentSpeed = 0.0f;
                    }
                }
            }
    } else {
        if ((player->effects & 0x4000) == 0x4000){
            if (controller->button & A_BUTTON) {
                player_speed(player);
            } else {
                func_80031F48(player, 5.0f);
            }
        }
        if (((((player->effects & 0x80) == 0x80) || 
            ((player->effects & 0x40) == 0x40)) || 
            ((player->effects & 0x01000000) == 0x01000000)) || 
            ((player->effects & 0x02000000) == 0x02000000)) {
                if (controller->button & A_BUTTON) {
                    func_80030E00(player);
                    func_800332E8(player, arg2);
                    return;
                }
                func_80030C34(player);
                func_800337CC(player, 5.0f, arg2);
        }
    }
}

void func_800381AC(Player *player, struct Controller *controller, s8 arg2) {
    if (((player->type & PLAYER_EXISTS) == PLAYER_EXISTS) && 
        ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) && 
        ((player->type & PLAYER_CPU) != PLAYER_CPU)) {
            if ((player->type & PLAYER_START_SEQUENCE) != PLAYER_START_SEQUENCE) {
                if (((player->unk_0CA & 2) == 2) || ((player->unk_0CA & 8) == 8)) {
                    if (controller->button & A_BUTTON) {
                        func_80032D94(player);
                    } else {
                        func_80033280(player, 5.0f);
                    }
                } else {
                    func_80037CFC(player, controller, arg2);
                }
                D_80164A89 = 1;
            } else if (D_8018D168 == 1) {
                if (D_801656F0 == 1) {
                    if (D_801652E0[arg2] == 0) {
                        D_801652E0[arg2] = gRaceFrameCounter;
                    }
                }
                if (controller->button & A_BUTTON) {
                    func_80032700(player);
                } else {
                    func_80032CB0(player, 5.0f);
                }
        }
    }
}

void func_800382DC(void) {
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v0_6;

    switch (gActiveScreenMode) {
    case SCREEN_MODE_1P:
        switch (gModeSelection) {
        case 0:
            func_800381AC(gPlayerOne, gControllerOne, 0);
            return;
        case 1:
            if (D_8015F890 != 1) {
                func_800381AC(gPlayerOne, gControllerOne, 0);
                temp_v0_3 = gPlayerTwo->type;
                if (((temp_v0_3 & 0x100) == 0x100) && ((temp_v0_3 & 0x800) != 0x800)) {
                    func_800381AC(gPlayerTwo, gControllerSix, 1);
                }
                temp_v0_4 = gPlayerThree->type;
                if (((temp_v0_4 & 0x100) == 0x100) && ((temp_v0_4 & 0x800) != 0x800)) {
                    func_800381AC(gPlayerThree, gControllerSeven, 2);
                    return;
                }
            } else {
                if ((gPlayerOne->type & 0x800) != 0x800) {
                    func_800381AC(gPlayerOne, gControllerEight, 0);
                }
                temp_v0_5 = gPlayerTwo->type;
                if (((temp_v0_5 & 0x100) == 0x100) && ((temp_v0_5 & 0x800) != 0x800)) {
                    func_800381AC(gPlayerTwo, gControllerSix, 1);
                }
                temp_v0_6 = gPlayerThree->type;
                if (((temp_v0_6 & 0x100) == 0x100) && ((temp_v0_6 & 0x800) != 0x800)) {
                    func_800381AC(gPlayerThree, gControllerSeven, 2);
                    return;
                }
                return;
            }
            break;
        }
        break;
    case SCREEN_MODE_2P_SPLITSCREEN_HORIZONTAL:
    case SCREEN_MODE_2P_SPLITSCREEN_VERTICAL:
        func_800381AC(gPlayerOne, gControllerOne, 0);
        func_800381AC(gPlayerTwo, gControllerTwo, 1);
        return;
    case SCREEN_MODE_3P_4P_SPLITSCREEN:
        func_800381AC(gPlayerOne, gControllerOne, 0);
        func_800381AC(gPlayerTwo, gControllerTwo, 1);
        func_800381AC(gPlayerThree, gControllerThree, 2);
        if (gPlayerCountSelection1 == 4) {
            func_800381AC(gPlayerFour, gControllerFour, 3);
        }
        break;
    }
}

s16 func_80038534(struct Controller *controller) {
    s16 temp_a2;
    s16 var_a3;
    s16 var_t0;
    s16 temp_v0;

    temp_v0 = controller->rawStickX;
    temp_a2 = controller->rawStickY;
    var_a3 = temp_v0;
    var_t0 = temp_a2;

    if (temp_v0 > 0xC) {
        var_t0 = (temp_a2 * 0x000C) / temp_v0;
        var_a3 = 0x000C;
    }
    if (var_a3 < -0xC) {
        var_t0 = (var_t0 * 0x000C) / -var_a3;
        var_a3 = -0x000C;
    }
    if (var_t0 > 0xC) {
        var_a3 = (var_a3 * 0x000C) / var_t0;
        var_t0 = 0x000C;
    }
    if (var_t0 < -0xC) {
        var_a3 = (var_a3 * 0x000C) / -var_t0;
        var_t0 = -0x000C;
    }
    if ((((controller->rawStickX > -0xD) && (controller->rawStickX < 0xD)) && (controller->rawStickY > -0xD)) && (controller->rawStickY < 0xD)) {
        temp_v0 = 0;
        temp_a2 = 0;
    }
    else {
        temp_v0 -= var_a3;
        temp_a2 -= var_t0;
    }
    if (temp_v0 > 0x35) {
        temp_a2 = (temp_a2 * 0x0035) / temp_v0;
        temp_v0 = 0x0035;
    }
    if (temp_v0 < -0x35) {
        temp_a2 = (temp_a2 * 0x0035) / -temp_v0;
        temp_v0 = -0x0035;
    }
    if (temp_a2 > 0x35) {
        temp_v0 = (temp_v0 * 0x0035) / temp_a2;
        temp_a2 = 0x0035;
    }
    if (temp_a2 < -0x35) {
        temp_v0 = (temp_v0 * 0x0035) / -temp_a2;
    }
    return temp_v0;
}

s16 func_800388B0(struct Controller *controller) {
    s16 temp_a2;
    s16 var_a3;
    s16 var_t0;
    s16 temp_v0;

    temp_v0 = controller->rawStickX;
    temp_a2 = controller->rawStickY;
    var_a3 = temp_v0;
    var_t0 = temp_a2;

    if (temp_v0 > 0xC) {
        var_t0 = (temp_a2 * 0x000C) / temp_v0;
        var_a3 = 0x000C;
    }
    if (var_a3 < -0xC) {
        var_t0 = (var_t0 * 0x000C) / -var_a3;
        var_a3 = -0x000C;
    }
    if (var_t0 > 0xC) {
        var_a3 = (var_a3 * 0x000C) / var_t0;
        var_t0 = 0x000C;
    }
    if (var_t0 < -0xC) {
        var_a3 = (var_a3 * 0x000C) / -var_t0;
        var_t0 = -0x000C;
    }
    if ((((controller->rawStickX > -0xD) && (controller->rawStickX < 0xD)) && (controller->rawStickY > -0xD)) && (controller->rawStickY < 0xD)) {
        temp_v0 = 0;
        temp_a2 = 0;
    }
    else {
        temp_v0 -= var_a3;
        temp_a2 -= var_t0;
    }
    if (temp_v0 > 0x35) {
        temp_a2 = (temp_a2 * 0x0035) / temp_v0;
        temp_v0 = 0x0035;
    }
    if (temp_v0 < -0x35) {
        temp_a2 = (temp_a2 * 0x0035) / -temp_v0;
        temp_v0 = -0x0035;
    }
    if (temp_a2 > 0x35) {
        temp_v0 = (temp_v0 * 0x0035) / temp_a2;
        temp_a2 = 0x0035;
    }
    if (temp_a2 < -0x35) {
        temp_v0 = (temp_v0 * 0x0035) / -temp_a2;
        temp_a2 = -0x0035;
    }
    return temp_a2;
}

void func_80038BE4(Player *player, s16 arg1) {
    player->currentSpeed += (f32) arg1;
    if (player->currentSpeed < 0.0f) {
        player->currentSpeed = 0.0f;
    }
    if (player->currentSpeed >= 250.0f) {
        player->currentSpeed = 250.0f;
    }
    player->unk_044 |= 0x20;
    player->unk_08C = (player->currentSpeed * player->currentSpeed) / 25.0f;
}

void func_80038C6C(Player *player, UNUSED Camera *camera, s8 arg2, s8 arg3) {
    Vec3f sp114 = {0.0, 0.0, 1.0};
    Vec3f sp108 = {0.0, 0.0, 0.0};
    Vec3f spFC = {0.0, 0.0, 0.0};
    Vec3f spF0 = {0.0, 0.0, 0.0};
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 sqrt;

    f32 divOptimize;
    UNUSED s32 pad2[10];
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    UNUSED s32 pad3;
    Vec3f sp88;
    Vec3f sp7C;
    UNUSED s32 pad[10];
    
    player->unk_084 = -10.0f;
    player->unk_088 = 28.0f;
    player->topSpeed = 250.0f;
    func_8002B830(player, arg3, arg2);
    func_8002CD48(player, arg3, arg2);
    player->unk_02C[1] += player->unk_078;
    spF0[0] = 0;
    spF0[1] = 0;
    spF0[2] = 0;
    func_8002AB70(player);
    spA4 =  0 * (player->unk_064[0] + spFC[0]);
    spA0 = -1 * player->kartGravity;
    sp9C =  0 * (player->unk_064[2] + spFC[2]);
    sp108[2] = 0;
    sp108[1] = 0;
    sp108[0] = 0;
    mtxf_translate_vec3f_mat3(sp108, player->orientationMatrix);
    spA4 += sp108[0];
    sp9C += sp108[2];
    sp114[2] = player->unk_08C;
    mtxf_translate_vec3f_mat3(sp114, player->orientationMatrix); 
    
    sp88[0] = player->velocity[0];
    sp88[1] = player->velocity[1];
    sp88[2] = player->velocity[2];
    
    sp88[0] += ((((((sp114[0] + spA4) + spF0[0])) - (sp88[0] * (0.12 * (player->kartFriction)))) / 6000.0) / 1);
    sp88[2] += ((((((sp114[2] + sp9C) + spF0[2])) - (sp88[2] * (0.12 * (player->kartFriction)))) / 6000.0) / 1);
    sp88[1] += ((((((sp114[1] + spA0) + spF0[1])) - (sp88[1] * (0.12 * (player->kartFriction)))) / 6000.0) / 1);
    if ((player->unk_044 & 0x10) == 0x10) {
        player->unk_044 &= 0xFFEF;
    }

    posX = player->pos[0];
    posY = player->pos[1];
    posZ = player->pos[2];

    player->rotX = player->pos[0];
    player->rotY = player->pos[1];
    player->rotZ = player->pos[2];

    spEC = posX + player->velocity[0];
    spE8 = posY + player->velocity[1];
    spE4 = posZ + player->velocity[2];
    func_8002AAC0(player);
    spE8 += player->kartHopVelocity;
    spE8 -= 0.02;
    func_802AD950(&player->unk_110, player->boundingBoxSize, spEC, spE8, spE4, player->rotX, player->rotY, player->rotZ);
    player->unk_058 = 0;
    player->unk_060 = 0;
    player->unk_05C = 1.0f;
    calculate_orientation_matrix(player->orientationMatrix, 0, 1.0f, 0, player->unk_02C[1]);
    player->effects |= 8;
    player->unk_0C2 += 1;
    sp98 = player->unk_110.unk3C[2];
    if (sp98 <= 0) {
        player->unk_0C2 = 0;
        player->effects &= ~2;
        player->effects &= ~8;
        player->kartHopVelocity = player->unk_0C2;
    }
    sp98 = player->unk_110.unk3C[2];
    if (sp98 <= 0) {
        func_8003F46C(player, sp7C, sp88, sp108, &sp98, &spEC, &spE8, &spE4);
    }
    sp98 = player->unk_110.unk3C[0];
    if (sp98 < 0) {
        func_8003F734(player, sp7C, sp88, &sp98, &spEC, &spE8, &spE4);
        func_8002C954(player, arg3, sp88);
    }
    sp98 = player->unk_110.unk3C[1];
    if (sp98 < 0) {
        func_8003FBAC(player, sp7C, sp88, &sp98, &spEC, &spE8, &spE4);
        func_8002C954(player, arg3, sp88);
    }
    sp98 = player->unk_110.unk3C[0];
    if (sp98 >= 0) {
        sp98 = player->unk_110.unk3C[1];
        if (sp98 >= 0) {
            player->unk_046 &= 0xFFDF;
        }
    }
    player->unk_074 = func_802ABE30(spEC, spE8, spE4, player->unk_110.unk3A);
    func_80029B4C(player, spEC, spE8, spE4);
    func_8002AE38(player, arg3, posX, posZ, spEC, spE4);
    sqrt = (sp88[0] * sp88[0]) + (sp88[2] * sp88[2]);
    player->unk_22C = player->unk_094;
    player->unk_094 = sqrtf(sqrt);

    player->pos[0] = spEC;
    player->pos[2] = spE4;
    player->pos[1] = spE8;

    player->unk_064[0] = sp108[0];
    player->unk_064[2] = sp108[2];

    player->velocity[0] = sp88[0];
    player->velocity[1] = sp88[1];
    player->velocity[2] = sp88[2];

    D_80165070[arg3][0] = sp88[0];
    D_80165070[arg3][1] = sp88[1];
    D_80165070[arg3][2] = sp88[2];
    
    if ((player->type & PLAYER_HUMAN) == PLAYER_HUMAN) {
        if (gKartTopSpeedTable[player->characterId] < player->unk_094) {
            divOptimize = gKartTopSpeedTable[player->characterId] / player->unk_094;
            player->velocity[0] *= divOptimize;
            player->velocity[1] *= divOptimize;
            player->velocity[2] *= divOptimize;
            player->unk_094 = gKartTopSpeedTable[player->characterId];
        }
    }
    if ((player->unk_044 & 1) == 1){
        if (player->unk_094 > 1.0f){
            player->velocity[0] *= 1.0f / player->unk_094;
            player->velocity[1] *= 1.0f / player->unk_094;
            player->velocity[2] *= 1.0f / player->unk_094;
            player->unk_094 = 1.0f;
        }
    }
    if (player->unk_110.unk3C[2] >= 500.0f) {
        player->unk_078 /= 2;
    }
    func_8002C4F8(player, arg3);
}
