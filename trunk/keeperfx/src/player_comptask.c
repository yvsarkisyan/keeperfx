/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file player_comptask.c
 *     Computer player definitions and activities.
 * @par Purpose:
 *     Defines a computer player control variables and events/checks/processes
 *      functions.
 * @par Comment:
 *     None.
 * @author   Tomasz Lis
 * @date     10 Mar 2009 - 20 Mar 2009
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "player_computer.h"

#include <limits.h>
#include <string.h>

#include "globals.h"
#include "bflib_basics.h"
#include "bflib_fileio.h"
#include "bflib_dernc.h"
#include "bflib_memory.h"
#include "bflib_sound.h"
#include "bflib_math.h"

#include "config.h"
#include "config_creature.h"
#include "config_terrain.h"
#include "creature_states.h"
#include "magic.h"
#include "thing_traps.h"
#include "player_instances.h"

#include "dungeon_data.h"
#include "map_blocks.h"
#include "slab_data.h"
#include "power_hand.h"
#include "game_legacy.h"

#include "keeperfx.hpp"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
struct TrapDoorSelling {
    long category;
    long model;
};

struct MoveToRoom {
    char kind;
    long priority;
};

/******************************************************************************/
long task_dig_room_passage(struct Computer2 *comp, struct ComputerTask *ctask);
long task_dig_room(struct Computer2 *comp, struct ComputerTask *ctask);
long task_check_room_dug(struct Computer2 *comp, struct ComputerTask *ctask);
long task_place_room(struct Computer2 *comp, struct ComputerTask *ctask);
long task_dig_to_entrance(struct Computer2 *comp, struct ComputerTask *ctask);
long task_dig_to_gold(struct Computer2 *comp, struct ComputerTask *ctask);
long task_dig_to_attack(struct Computer2 *comp, struct ComputerTask *ctask);
long task_magic_call_to_arms(struct Computer2 *comp, struct ComputerTask *ctask);
long task_pickup_for_attack(struct Computer2 *comp, struct ComputerTask *ctask);
long task_move_creature_to_room(struct Computer2 *comp, struct ComputerTask *ctask);
long task_move_creature_to_pos(struct Computer2 *comp, struct ComputerTask *ctask);
long task_move_creatures_to_defend(struct Computer2 *comp, struct ComputerTask *ctask);
long task_slap_imps(struct Computer2 *comp, struct ComputerTask *ctask);
long task_dig_to_neutral(struct Computer2 *comp, struct ComputerTask *ctask);
long task_magic_speed_up(struct Computer2 *comp, struct ComputerTask *ctask);
long task_wait_for_bridge(struct Computer2 *comp, struct ComputerTask *ctask);
long task_attack_magic(struct Computer2 *comp, struct ComputerTask *ctask);
long task_sell_traps_and_doors(struct Computer2 *comp, struct ComputerTask *ctask);
long add_to_trap_location(struct Computer2 *, struct Coord3d *);
long find_next_gold(struct Computer2 *, struct ComputerTask *);
long check_for_gold(long simulation, long digflags, long l3);
int search_spiral(struct Coord3d *pos, int owner, int i3, long (*cb)(long, long, long));
/******************************************************************************/
const struct TaskFunctions task_function[] = {
    {NULL, NULL},
    {"COMPUTER_DIG_ROOM_PASSAGE", task_dig_room_passage},
    {"COMPUTER_DIG_ROOM",         task_dig_room},
    {"COMPUTER_CHECK_ROOM_DUG",   task_check_room_dug},
    {"COMPUTER_PLACE_ROOM",       task_place_room},
    {"COMPUTER_DIG_TO_ENTRANCE",  task_dig_to_entrance},
    {"COMPUTER_DIG_TO_GOLD",      task_dig_to_gold},
    {"COMPUTER_DIG_TO_ATTACK",    task_dig_to_attack},
    {"COMPUTER_MAGIC_CALL_TO_ARMS", task_magic_call_to_arms},
    {"COMPUTER_PICKUP_FOR_ATTACK", task_pickup_for_attack},
    {"COMPUTER_MOVE_CREATURE_TO_ROOM", task_move_creature_to_room},
    {"COMPUTER_MOVE_CREATURE_TO_POS", task_move_creature_to_pos},
    {"COMPUTER_MOVE_CREATURES_TO_DEFEND", task_move_creatures_to_defend},
    {"COMPUTER_SLAP_IMPS",        task_slap_imps},
    {"COMPUTER_DIG_TO_NEUTRAL",   task_dig_to_neutral},
    {"COMPUTER_MAGIC_SPEED_UP",   task_magic_speed_up},
    {"COMPUTER_WAIT_FOR_BRIDGE",  task_wait_for_bridge},
    {"COMPUTER_ATTACK_MAGIC",     task_attack_magic},
    {"COMPUTER_SELL_TRAPS_AND_DOORS", task_sell_traps_and_doors},
};

const struct TrapDoorSelling trapdoor_sell[] = {
    {TDSC_Door, 4},
    {TDSC_Trap, 1},
    {TDSC_Trap, 6},
    {TDSC_Door, 3},
    {TDSC_Trap, 5},
    {TDSC_Trap, 4},
    {TDSC_Door, 2},
    {TDSC_Trap, 3},
    {TDSC_Door, 1},
    {TDSC_Trap, 2},
    {TDSC_EndList, 0},
};

const struct MoveToRoom move_to_room[] = {
    {RoK_TRAINING,  40},
    {RoK_LIBRARY,   35},
    {RoK_WORKSHOP,  32},
    {RoK_SCAVENGER, 20},
    {RoK_NONE,       0},
};
/******************************************************************************/
DLLIMPORT long _DK_task_dig_room_passage(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_dig_room(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_check_room_dug(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_place_room(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_dig_to_entrance(struct Computer2 *comp, struct ComputerTask *ctask);
//DLLIMPORT long _DK_task_dig_to_gold(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_dig_to_attack(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_magic_call_to_arms(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_pickup_for_attack(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_move_creature_to_room(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_move_creature_to_pos(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_move_creatures_to_defend(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_slap_imps(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_dig_to_neutral(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_magic_speed_up(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_wait_for_bridge(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_attack_magic(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT long _DK_task_sell_traps_and_doors(struct Computer2 *comp, struct ComputerTask *ctask);
DLLIMPORT struct ComputerTask *_DK_get_task_in_progress(struct Computer2 *comp, long stl_y);
DLLIMPORT struct ComputerTask *_DK_get_free_task(struct Computer2 *comp, long stl_y);
DLLIMPORT short _DK_fake_dump_held_creatures_on_map(struct Computer2 *comp, struct Thing *thing, struct Coord3d *pos);
DLLIMPORT long _DK_fake_place_thing_in_power_hand(struct Computer2 *comp, struct Thing *thing, struct Coord3d *pos);
DLLIMPORT struct Thing *_DK_find_creature_to_be_placed_in_room(struct Computer2 *comp, struct Room **roomp);
DLLIMPORT short _DK_game_action(char stl_x, unsigned short stl_y, unsigned short plyr_idx, unsigned short a4,
 unsigned short a5, unsigned short a6, unsigned short a7);
DLLIMPORT short _DK_tool_dig_to_pos2(struct Computer2 *, struct ComputerDig *, long, long);
DLLIMPORT long _DK_add_to_trap_location(struct Computer2 *, struct Coord3d *);
//DLLIMPORT long _DK_find_next_gold(struct Computer2 *, struct ComputerTask *);
DLLIMPORT long _DK_check_for_gold(long simulation, long digflags, long l3);
DLLIMPORT int _DK_search_spiral(struct Coord3d *pos, int owner, int i3, long (*cb)(long, long, long));
DLLIMPORT long _DK_dig_to_position(signed char stl_x, unsigned short stl_y, unsigned short plyr_idx, unsigned char a4, unsigned char a5);
DLLIMPORT short _DK_get_hug_side(struct ComputerDig * cdig, unsigned short stl_y, unsigned short plyr_idx, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7);
/******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************/
struct ComputerTask *get_computer_task(long idx)
{
    if ((idx < 1) || (idx >= COMPUTER_TASKS_COUNT))
    {
        return &game.computer_task[0];
    } else
    {
        return &game.computer_task[idx];
    }
}

TbBool computer_task_invalid(struct ComputerTask *ctask)
{
    if (ctask <= &game.computer_task[0])
        return true;
    return false;
}

/** Removes task from Computer2 structure and marks it as unused.
 *
 * @param comp Computer from which task is removed.
 * @param ctask Task to be removed from the computer tasks list.
 * @return
 */
TbBool remove_task(struct Computer2 *comp, struct ComputerTask *ctask)
{
    struct ComputerTask *nxctask;
    long i;
    i = comp->task_idx;
    if (get_computer_task(i) == ctask)
    {
        //Removing first task in list
        comp->task_idx = ctask->next_task;
        ctask->next_task = 0;
        set_flag_byte(&ctask->flags, 0x01, false);
        return true;
    }
    nxctask = get_computer_task(i);
    while (!computer_task_invalid(nxctask))
    {
        i = nxctask->next_task;
        if (&game.computer_task[i] == ctask)
        {
          nxctask->next_task = ctask->next_task;
          ctask->next_task = 0;
          set_flag_byte(&ctask->flags, 0x01, false);
          return true;
        }
        nxctask = get_computer_task(i);
    }
    return false;
}

TbResult game_action(PlayerNumber plyr_idx, unsigned short gaction, unsigned short alevel,
    MapSubtlCoord stl_x, MapSubtlCoord stl_y, unsigned short param1, unsigned short param2)
{
    struct Dungeon *dungeon;
    MapSlabCoord slb_x,slb_y;
    struct Thing *thing;
    long i,k;
    struct SlabMap *slb;
    struct Room *room;
    struct Coord3d pos;
    SYNCDBG(9,"Starting action %d",(int)gaction);
    //return _DK_game_action(plyr_idx, gaction, alevel, stl_x, stl_y, param1, param2);
    if (subtile_has_slab(stl_x, stl_y)) {
        slb_x = subtile_slab_fast(stl_x);
        slb_y = subtile_slab_fast(stl_y);
    } else {
        slb_x = -1;
        slb_y = -1;
    }
    dungeon = get_players_num_dungeon(plyr_idx);
    if (dungeon_invalid(dungeon)) {
      return Lb_FAIL;
    }
    switch (gaction)
    {
    case GA_Unk01:
        break;
    case GA_UsePwrHandPick:
        thing = thing_get(param1);
        if (!is_power_available(plyr_idx, PwrK_HAND))
            break;
        if (!place_thing_in_power_hand(thing, plyr_idx))
          return Lb_FAIL;
        return Lb_SUCCESS;
    case GA_UsePwrHandDrop:
        // Note that we can drop things even if we have no hand power
        if (!dump_held_things_on_map(plyr_idx, stl_x, stl_y, 0))
            return Lb_FAIL;
        return Lb_SUCCESS;
    case GA_UseMkDigger:
        return magic_use_available_power_on_subtile(plyr_idx, PwrK_MKDIGGER, alevel, stl_x, stl_y, CastAllow_Unrevealed);
    case GA_UseSlap:
        return magic_use_available_power_on_subtile(plyr_idx, PwrK_SLAP, alevel, stl_x, stl_y, CastAllow_Unrevealed);
    case GA_UsePwrSight:
        return magic_use_available_power_on_subtile(plyr_idx, PwrK_SIGHT, alevel, stl_x, stl_y, CastAllow_Unrevealed);
    case GA_UsePwrObey:
        return magic_use_available_power_on_level(plyr_idx, PwrK_OBEY, alevel);
    case GA_UsePwrHealCrtr:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_HEALCRTR, alevel, stl_x, stl_y, thing);
    case GA_UsePwrCall2Arms:
        return magic_use_available_power_on_subtile(plyr_idx, PwrK_CALL2ARMS, alevel, stl_x, stl_y, CastAllow_Unrevealed);
    case GA_UsePwrCaveIn:
        return magic_use_available_power_on_subtile(plyr_idx, PwrK_CAVEIN, alevel, stl_x, stl_y, CastAllow_Unrevealed);
    case GA_StopPwrCall2Arms:
        turn_off_call_to_arms(plyr_idx);
        return Lb_SUCCESS;
    case GA_Unk12:
        dungeon->field_88C[0] = 0;
        return Lb_SUCCESS;
    case GA_Unk13:
    case GA_Unk14:
        slb = get_slabmap_block(slb_x, slb_y);
        if ((slb->kind == SlbT_LAVA) || (slb->kind == SlbT_WATER))
        {
            place_slab_type_on_map(SlbT_PATH, stl_x, stl_y, plyr_idx, 0);
            do_slab_efficiency_alteration(slb_x, slb_y);
            i = 1;
        } else
        {
            i = tag_blocks_for_digging_in_rectangle_around(slab_subtile(slb_x,0), slab_subtile(slb_y,0), plyr_idx) > 0;
        }
        return i;
    case GA_Unk15:
    case GA_Unk16:
        room = player_build_room_at(stl_x, stl_y, plyr_idx, param2);
        if (room_is_invalid(room))
            break;
        return room->index;
    case GA_SetTendencies:
        dungeon->creature_tendencies = param1;
        return 1;
    case GA_PlaceTrap:
        if (dungeon->trap_amount[param1] == 0)
            break;
        pos.x.stl.pos = 128;
        pos.x.stl.num = slab_subtile_center(slb_x);
        pos.y.stl.pos = 128;
        pos.y.stl.num = slab_subtile_center(slb_y);
        pos.z.val = 0;
        pos.z.val = get_floor_height_at(&pos);
        thing = create_trap(&pos, param1, plyr_idx);
        if (remove_workshop_item(plyr_idx, TCls_Trap, param1))
          dungeon->lvstats.traps_used++;
        dungeon->camera_deviate_jump = 192;
        if (is_my_player_number(plyr_idx))
            play_non_3d_sample(117);
        return 1;
    case GA_PlaceDoor:
        k = tag_cursor_blocks_place_door(plyr_idx, stl_x, stl_y);
        i = packet_place_door(stl_x, stl_y, plyr_idx, param1, k);
        return i;
    case GA_UsePwrLightning:
        return magic_use_available_power_on_subtile(plyr_idx, PwrK_LIGHTNING, alevel, stl_x, stl_y, CastAllow_Normal);
    case GA_UsePwrSpeedUp:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_SPEEDCRTR, alevel, stl_x, stl_y, thing);
    case GA_UsePwrArmour:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_PROTECT, alevel, stl_x, stl_y, thing);
    case GA_UsePwrConceal:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_CONCEAL, alevel, stl_x, stl_y, thing);
    case GA_UsePwrHoldAudnc:
        return magic_use_available_power_on_level(plyr_idx, PwrK_HOLDAUDNC, alevel);
    case GA_UsePwrDisease:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_DISEASE, alevel, stl_x, stl_y, thing);
    case GA_UsePwrChicken:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_CHICKEN, alevel, stl_x, stl_y, thing);
    case GA_UsePwrSlap:
        thing = thing_get(param1);
        return magic_use_available_power_on_thing(plyr_idx, PwrK_SLAP, alevel, stl_x, stl_y, thing);
    default:
        ERRORLOG("Unknown game action %d", (int)gaction);
        break;
    }
    return 0;
}

TbResult try_game_action(struct Computer2 *comp, PlayerNumber plyr_idx, unsigned short gaction, unsigned short alevel,
    MapSubtlCoord stl_x, MapSubtlCoord stl_y, unsigned short param1, unsigned short param2)
{
  TbResult result;
  result = game_action(plyr_idx, gaction, alevel, stl_x, stl_y, param1, param2);
  if (result > 0)
    comp->tasks_did--;
  SYNCDBG(19,"Returning %d",(int)result);
  return result;
}

struct ComputerTask *get_task_in_progress(struct Computer2 *comp, long a2)
{
    return _DK_get_task_in_progress(comp, a2);
}

struct ComputerTask *get_free_task(struct Computer2 *comp, long a2)
{
    return _DK_get_free_task(comp, a2);
}

short fake_dump_held_creatures_on_map(struct Computer2 *comp, struct Thing *thing, struct Coord3d *pos)
{
    return _DK_fake_dump_held_creatures_on_map(comp, thing, pos);
}

long fake_place_thing_in_power_hand(struct Computer2 *comp, struct Thing *thing, struct Coord3d *pos)
{
    SYNCDBG(9,"Starting");
    return _DK_fake_place_thing_in_power_hand(comp, thing, pos);
}

TbBool worker_needed_in_dungeons_room_kind(const struct Dungeon *dungeon, long rkind)
{
    long i;
    switch (rkind)
    {
    case RoK_LIBRARY:
        if (dungeon->field_F78 < 0)
            return false;
        return true;
    case RoK_TRAINING:
        if (2 * dungeon->field_14B8 >= dungeon->total_money_owned)
            return false;
        return true;
    case RoK_WORKSHOP:
        for (i = 1; i < TRAP_TYPES_COUNT; i++)
        {
            if ((dungeon->trap_buildable[i]) && (dungeon->trap_amount[i] == 0))
            {
              break;
            }
        }
        if (i == TRAP_TYPES_COUNT)
            return false;
        return true;
    default:
        return true;
    }
}

TbBool person_will_do_job_for_room(const struct Thing *thing, const struct Room *room)
{
    struct CreatureStats *crstat;
    crstat = creature_stats_get_from_thing(thing);
    return (get_job_for_room(room->kind, true) & crstat->jobs_not_do) == 0;
}

TbBool person_will_do_job_for_room_kind(const struct Thing *thing, RoomKind rkind)
{
    struct CreatureStats *crstat;
    crstat = creature_stats_get_from_thing(thing);
    return (get_job_for_room(rkind, true) & crstat->jobs_not_do) == 0;
}

struct Room *get_room_to_place_creature(const struct Computer2 *comp, const struct Thing *thing)
{
  const struct Dungeon *dungeon;
  long chosen_priority;
  struct Room *chosen_room;
  struct Room *room;
  long total_spare_cap;
  long i,k,rkind;

    dungeon = comp->dungeon;

    chosen_room = NULL;
    chosen_priority = LONG_MIN;
    for (k=0; move_to_room[k].kind != RoK_NONE; k++)
    {
        rkind = move_to_room[k].kind;
        if (person_will_do_job_for_room_kind(thing,rkind))
        {
            if (!worker_needed_in_dungeons_room_kind(dungeon,rkind))
                continue;
        }
        // Find specific room which meets capacity demands
        i = dungeon->room_kind[rkind];
        room = find_room_with_most_spare_capacity_starting_with(i,&total_spare_cap);
        if (room_is_invalid(room))
            continue;
        if (chosen_priority < total_spare_cap * move_to_room[k].priority)
        {
            chosen_priority = total_spare_cap * move_to_room[k].priority;
            chosen_room = room;
        }
    }
  return chosen_room;
}

struct Thing *find_creature_to_be_placed_in_room(struct Computer2 *comp, struct Room **roomp)
{
    Thing_Maximizer_Filter filter;
    struct CompoundFilterParam param;
    struct Dungeon *dungeon;
    struct Thing *thing;
    struct Room *room;
    SYNCDBG(9,"Starting");
    dungeon = comp->dungeon;
    if (dungeon_invalid(dungeon))
    {
        ERRORLOG("Invalid dungeon in computer player.");
        return INVALID_THING;
    }
    //return _DK_find_creature_to_be_placed_in_room(comp, roomp);
    param.ptr1 = (void *)comp;
    filter = player_list_creature_filter_needs_to_be_placed_in_room;
    thing = get_player_list_creature_with_filter(dungeon->creatr_list_start, filter, &param);
    if (thing_is_invalid(thing))
        return INVALID_THING;
    room = get_room_of_given_kind_for_thing(thing,dungeon,param.num2);
    if (room_is_invalid(room))
        return INVALID_THING;
    *roomp = room;
    return thing;
}

long task_dig_room_passage(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_dig_room_passage(comp,ctask);
}

long task_dig_room(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_dig_room(comp,ctask);
}

long task_check_room_dug(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_check_room_dug(comp,ctask);
}

long task_place_room(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_place_room(comp,ctask);
}

long task_dig_to_entrance(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_dig_to_entrance(comp,ctask);
}

long dig_to_position(signed char plyr_idx, unsigned short stl_x, unsigned short stl_y, int start_side, TbBool revside)
{
    long i,n,nchange;
    //return _DK_dig_to_position(a1, a2, a3, start_side, revside);
    if (revside) {
      nchange = 1;
    } else {
      nchange = 3;
    }
    n = (start_side + 4 - nchange) & 3;
    for (i=0; i < 4; i++)
    {
        struct SlabAttr *slbattr;
        struct SlabMap *slb;
        struct Map *mapblk;
        int delta_x,delta_y;
        SubtlCodedCoords stl_num;
        delta_x = small_around[n].delta_x;
        delta_y = small_around[n].delta_y;
        slb = get_slabmap_for_subtile(stl_x + 3*delta_x, stl_y + 3*delta_y);
        slbattr = get_slab_attrs(slb);
        if (slbattr->is_unknflg14 != 0)
        {
            if (slb->kind != SlbT_GEMS)
            {
                stl_num = get_subtile_number(stl_x + 3*delta_x, stl_y + 3*delta_y);
                mapblk = get_map_block_at_pos(stl_num);
                if ( ((mapblk->flags & MapFlg_Unkn20) == 0) || (slabmap_owner(slb) == plyr_idx) ) {
                    return stl_num;
                }
            }
        }
        if ( ((slbattr->flags & (SlbAtFlg_Unk20|SlbAtFlg_Unk08|SlbAtFlg_Unk01)) == 0) && (slb->kind != SlbT_LAVA) ) {
            stl_num = get_subtile_number(stl_x + 3*delta_x, stl_y + 3*delta_y);
            return stl_num;
        }
        n = (n + nchange) & 3;
    }
    return -1;
}

short get_hug_side(struct ComputerDig * cdig, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7)
{
    return _DK_get_hug_side(cdig, a2, a3, a4, a5, a6, a7);
}

/**
 * Checks if given room kind is available for building by computer player.
 * @param comp Computer player.
 * @param rkind Room kind.
 * @return Gives 0 if the room isn't available, 1 if it's available and 4 if it's researchable.
 */
long computer_check_room_available(struct Computer2 * comp, long rkind)
{
    struct Dungeon *dungeon;
    dungeon = comp->dungeon;
    if ((rkind < 1) || (rkind >= ROOM_TYPES_COUNT)) {
        return 0;
    }
    if (!dungeon->room_resrchable[rkind])
        return 0;
    if (!dungeon->room_buildable[rkind])
        return 4;
    return 1;
}

TbBool xy_walkable(MapSubtlCoord stl_x, MapSubtlCoord stl_y, int plyr_idx)
{
    struct SlabAttr *slbattr;
    struct SlabMap *slb;
    slb = get_slabmap_for_subtile(stl_x, stl_y);
    slbattr = get_slab_attrs(slb);
    if ( (slabmap_owner(slb) == plyr_idx) || (plyr_idx == -1) )
    {
        if ( ((slbattr->flags & SlbAtFlg_Unk10) == 0) && (slb->kind != SlbT_LAVA) )
            return true;
        if ((slbattr->flags & SlbAtFlg_Unk02) != 0)
            return true;
    }
    return false;
}

/*struct ComputerTask * able_to_build_room(struct Computer2 *comp, struct Coord3d *pos, unsigned short a3, long a4, long a5, long a6, long a7)
{
}*/

long check_for_buildable(long stl_x, long stl_y, long plyr_idx)
{
    struct SlabAttr *slbattr;
    struct SlabMap *slb;
    SubtlCodedCoords stl_num;
    struct Map *mapblk;
    long i;
    slb = get_slabmap_for_subtile(stl_x, stl_y);
    slbattr = get_slab_attrs(slb);
    if (slb->kind == SlbT_GEMS) {
        return 1;
    }
    if (slbattr->category == SlbAtCtg_RoomInterior) {
        return -1;
    }
    if ((slbattr->flags & SlbAtFlg_Unk02) != 0) {
        return -1;
    }
    if ( ((slbattr->flags & (SlbAtFlg_Unk20|SlbAtFlg_Unk08|SlbAtFlg_Unk01)) != 0) || (slb->kind == SlbT_LAVA) )
        i = 1;
    else
        i = 0;
    if ( (i < 1) || (slb->kind == SlbT_WATER) ) {
        return -1;
    }
    stl_num = get_subtile_number(stl_slab_center_subtile(stl_x),stl_slab_center_subtile(stl_y));
    if (find_from_task_list(plyr_idx, stl_num) >= 0) {
        return -1;
    }
    if ((slbattr->flags & SlbAtFlg_Unk01) != 0) {
        return -1;
    }
    if ( (slb->kind == SlbT_LAVA) || (slb->kind == SlbT_WATER) ) {
        return 1;
    }
    if ( (slbattr->is_unknflg14 == 0) || (slb->kind == SlbT_GEMS) ) {
        return 1;
    }
    mapblk = get_map_block_at_pos(stl_num);
    return ((mapblk->flags & MapFlg_Unkn20) != 0) && (slabmap_owner(slb) != plyr_idx);
}

/** Retrieves index for small_around[] array which leads to the area closer to given destination.
 *  It uses a bit of randomness when angles are too straight, so it may happen that result for same points will vary.
 *
 * @param curr_x Current position x coord.
 * @param curr_y Current position y coord.
 * @param dest_x Destination position x coord.
 * @param dest_y Destination position y coord.
 * @return Index closer to destination.
 */
unsigned int small_around_index_towards_destination(long curr_x,long curr_y,long dest_x,long dest_y)
{
    long i,n;
    i = LbArcTanAngle(dest_x - curr_x, dest_y - curr_y);
    // Check the angle - we're a bit afraid of angles which are pi/4 multiplications
    if ((i & 0xFF) != 0)
    {
        // Just compute the index
        n = (i + LbFPMath_PI/4) >> 9;
    } else
    {
        //Special case - the angle is exact multiplication of pi/4
        // Add some variant factor to make it little off this value.
        // this should give better results because tangens values are rounded up or down.
        //TODO: maybe it would be even better to get previous around_index as parameter - this way we could avoid taking same path without random factors.
        n = (i + LbFPMath_PI/4 + ACTION_RANDOM(3) - 1) >> 9;
    }
    SYNCDBG(18,"Vector (%ld,%ld) returned ArcTan=%ld, around (%d,%d)",dest_x - curr_x, dest_y - curr_y,i,(int)small_around[n].delta_x,(int)small_around[n].delta_y);
    return n & 3;
}

/**
 * Tool function to do (or simulate) computer player digging.
 * @param comp Computer player which is doing the task.
 * @param cdig The ComputerDig structure to be changed. Should be dummy if simulating.
 * @param simulation Indicates if we're simulating or doing the real thing.
 * @param digflags These are not really flags, but should be change into flags when all calls to this func are rewritten. Use values from ToolDigFlags enum.
 * @return
 */
short tool_dig_to_pos2(struct Computer2 * comp, struct ComputerDig * cdig, TbBool simulation, unsigned short digflags)
{
    struct Dungeon *dungeon;
    struct SlabAttr *slbattr;
    struct SlabMap *slb;
    struct Map *mapblk;
    MapSubtlCoord gldstl_x,gldstl_y;
    MapSlabCoord gldslb_x,gldslb_y;
    MapSubtlCoord digstl_x,digstl_y;
    MapSlabCoord digslb_x,digslb_y;
    long counter1,around_index;
    long i;
    unsigned long k;
    //SYNCDBG(4,"Starting");
    //return _DK_tool_dig_to_pos2(comp, cdig, l1, l2);
    dungeon = comp->dungeon;
    cdig->field_54++;
    if (cdig->field_54 >= 356) {
        WARNLOG("ComputerDig calls count (%d) exceeds limit",(int)cdig->field_54);
        return -2;
    }
    gldstl_x = 3 * (cdig->pos_gold.x.stl.num / 3);
    gldstl_y = 3 * (cdig->pos_gold.y.stl.num / 3);
    around_index = small_around_index_towards_destination(gldstl_x,gldstl_y,cdig->pos_14.x.stl.num,cdig->pos_14.y.stl.num);
    if ( get_2d_distance(&cdig->pos_gold, &cdig->pos_14) <= cdig->distance )
    {
        SYNCDBG(4,"Starting small distance digging");
        counter1 = 0;
        k = 0;
        while ( 1 )
        {
            gldslb_x = gldstl_x / 3;
            gldslb_y = gldstl_y / 3;
            slb = get_slabmap_block(gldslb_x, gldslb_y);
            slbattr = get_slab_attrs(slb);
            if ( ((slbattr->flags & (SlbAtFlg_Unk20|SlbAtFlg_Unk08|SlbAtFlg_Unk01)) != 0) || (slb->kind == SlbT_LAVA) )
                i = 1;
            else
                i = 0;
            if ( (i != 0) && (slb->kind != SlbT_WATER) )
            {
                i = get_subtile_number_at_slab_center(gldslb_x,gldslb_y);
                if (find_from_task_list(dungeon->owner, i) < 0) {
                    break;
                }
            }
            if ( (slb->kind == SlbT_WATER) || (slb->kind == SlbT_LAVA) )
            {
              if ((digflags & ToolDig_AllowLiquidWBridge) != 0)
                  break;
              if (computer_check_room_available(comp, RoK_BRIDGE) != 1)
                  break;
            }

            slb = get_slabmap_block(gldslb_x, gldslb_y);
            if ( (slabmap_owner(slb) != dungeon->owner) && (slab_kind_is_door(slb->kind)) )
                break;
            cdig->pos_20.x.stl.num = gldstl_x;
            cdig->pos_20.y.stl.num = gldstl_y;
            if ( (cdig->pos_14.x.stl.num/3 == gldslb_x) && (cdig->pos_14.y.stl.num/3 == gldslb_y) ) {
                SYNCDBG(15,"Positions are equal at slab (%d,%d)",(int)gldslb_x,(int)gldslb_y);
                return -1;
            }
            around_index = small_around_index_towards_destination(gldstl_x,gldstl_y,cdig->pos_14.x.stl.num,cdig->pos_14.y.stl.num);
            gldstl_x += 3 * small_around[around_index].delta_x;
            gldstl_y += 3 * small_around[around_index].delta_y;
            k++;
            if (k > map_tiles_x*map_tiles_y)
            {
                ERRORLOG("Infinite loop while finding path to dig gold");
                return -1;
            }
        }
        slb = get_slabmap_block(gldslb_x, gldslb_y);
        if ( (slb->kind == SlbT_WATER) || (slb->kind == SlbT_LAVA) )
        {
            if ( (computer_check_room_available(comp, RoK_BRIDGE) == 1) ) {
                cdig->pos_20.x.stl.num = gldstl_x;
                cdig->pos_20.y.stl.num = gldstl_y;
                SYNCDBG(15,"Have bridge, so going through liquid subtile (%d,%d)",(int)gldstl_x,(int)gldstl_y);
                return -5;
            }
        }
        long counter2;
        for (counter2 = cdig->field_2C; counter2 > 0; counter2--)
        {
            gldslb_x = gldstl_x / 3;
            gldslb_y = gldstl_y / 3;
            slb = get_slabmap_block(gldslb_x, gldslb_y);
            mapblk = get_map_block_at(gldstl_x, gldstl_y);
            slbattr = get_slab_attrs(slb);
            if ( (slbattr->is_unknflg14 == 0) || (slb->kind == SlbT_GEMS)
              || (((mapblk->flags & MapFlg_Unkn20) != 0) && (slabmap_owner(slb) != dungeon->owner)) )
            {
                if ( ((slbattr->flags & SlbAtFlg_Unk01) == 0) || (digflags == 0) )
                    break;
            }
            if ( !simulation )
            {
                if (try_game_action(comp, dungeon->owner, GA_Unk14, 0, gldstl_x, gldstl_y, 1, 1) <= 0)
                  break;
              if (digflags != 0)
              {
                if ((slbattr->flags & SlbAtFlg_Unk01) != 0)
                  cdig->field_58++;
              }
            }
            counter1++;
            cdig->pos_20.x.stl.num = gldstl_x;
            cdig->pos_20.y.stl.num = gldstl_y;
            if ( (cdig->pos_14.x.stl.num/3 == gldslb_x) && (cdig->pos_14.y.stl.num/3 == gldslb_y) ) {
                SYNCDBG(15,"Positions are equal at slab (%d,%d)",(int)gldslb_x,(int)gldslb_y);
                return -1;
            }
            around_index = small_around_index_towards_destination(gldstl_x,gldstl_y,cdig->pos_14.x.stl.num,cdig->pos_14.y.stl.num);
            gldstl_x += 3 * small_around[around_index].delta_x;
            gldstl_y += 3 * small_around[around_index].delta_y;
        }
        if ( (cdig->pos_14.x.stl.num / 3 == gldslb_x) && (cdig->pos_14.y.stl.num / 3 == gldslb_y) )
        {
            cdig->pos_20.x.stl.num = gldstl_x;
            cdig->pos_20.y.stl.num = gldstl_y;
            SYNCDBG(15,"Positions are equal at slab (%d,%d)",(int)gldslb_x,(int)gldslb_y);
            return -1;
        } else
        if (counter1 > 0)
        {
            cdig->pos_gold.x.stl.num = gldstl_x;
            cdig->pos_gold.y.stl.num = gldstl_y;
            cdig->distance = get_2d_distance(&cdig->pos_20, &cdig->pos_14);
            SYNCDBG(15,"Going through subtile (%d,%d)",(int)gldstl_x,(int)gldstl_y);
            return 0;
        } else
        {
            if (comp->field_C == counter2)
            {
                gldstl_x -= 3 * (MapSubtlCoord)small_around[around_index].delta_x;
                gldstl_y -= 3 * (MapSubtlCoord)small_around[around_index].delta_y;
                cdig->pos_gold.x.val = subtile_coord(gldstl_x,0);
                cdig->pos_gold.y.val = subtile_coord(gldstl_y,0);
                cdig->pos_gold.z.val = 0;
                cdig->pos_E.x.val = cdig->pos_gold.x.val;
                cdig->pos_E.y.val = cdig->pos_gold.y.val;
                cdig->pos_E.z.val = cdig->pos_gold.z.val;
            }
            if ( (cdig->pos_20.x.val == 0) && (cdig->pos_20.y.val == 0) && (cdig->pos_20.z.val == 0) )
            {
                cdig->pos_20.x.val = cdig->pos_E.x.val;
                cdig->pos_20.y.val = cdig->pos_E.y.val;
                cdig->pos_20.z.val = cdig->pos_E.z.val;
            }
            cdig->field_48++;
            if ( (cdig->field_48 > 10) && (cdig->field_4C == gldstl_x) && (cdig->field_50 == gldstl_y) ) {
                SYNCDBG(15,"Positions are equal at subtile (%d,%d)",(int)gldstl_x,(int)gldstl_y);
                return -2;
            }
            cdig->field_4C = gldstl_x;
            cdig->field_50 = gldstl_y;
            cdig->distance = get_2d_distance(&cdig->pos_20, &cdig->pos_14);
            cdig->field_2A = get_hug_side(cdig, cdig->pos_20.x.stl.num, cdig->pos_20.y.stl.num,
                               cdig->pos_14.x.stl.num, cdig->pos_14.y.stl.num, around_index, dungeon->owner);
            i = dig_to_position(dungeon->owner, cdig->pos_20.x.stl.num, cdig->pos_20.y.stl.num,
                    (around_index + (cdig->field_2A < 1 ? 3 : 1)) & 3, cdig->field_2A);
            if (i == -1) {
                SYNCDBG(15,"Preparing digging to subtile (%d,%d) failed",(int)cdig->pos_20.x.stl.num,(int)cdig->pos_20.y.stl.num);
                return -2;
            }
            digstl_x = stl_num_decode_x(i);
            digstl_y = stl_num_decode_y(i);
            digslb_x = digstl_x / 3;
            digslb_y = digstl_y / 3;
            slb = get_slabmap_block(digslb_x, digslb_y);
            if ( ((slb->kind == SlbT_WATER) || (slb->kind == SlbT_LAVA)) && (computer_check_room_available(comp, RoK_BRIDGE) == 1) )
            {
                cdig->pos_20.y.stl.num = digstl_y;
                cdig->pos_20.x.stl.num = digstl_x;
                SYNCDBG(15,"Have bridge, so going through liquid subtile (%d,%d)",(int)gldstl_x,(int)gldstl_y);
                return -5;
            }
            cdig->direction_around = small_around_index_towards_destination(cdig->pos_20.x.stl.num,cdig->pos_20.x.stl.num,digstl_x,digstl_y);
            slbattr = get_slab_attrs(slb);
            if ( (slbattr->is_unknflg14 != 0) && (slb->kind != SlbT_GEMS) )
            {
                mapblk = get_map_block_at(digstl_x, digstl_y);
                if ( ((mapblk->flags & MapFlg_Unkn20) == 0) || (slabmap_owner(slb) == dungeon->owner) ) {
                    SYNCDBG(15,"Cannot go through subtile (%d,%d)",(int)digstl_x,(int)digstl_y);
                    return -2;
                }
            }
            i = get_subtile_number(stl_slab_center_subtile(digstl_x),stl_slab_center_subtile(digstl_y));
            if ( (find_from_task_list(dungeon->owner, i) < 0) && (!simulation) )
            {
                if (try_game_action(comp, dungeon->owner, GA_Unk14, 0, digstl_x, digstl_y, 1, 1) <= 0) {
                    SYNCDBG(15,"Game action failed at subtile (%d,%d)",(int)digstl_x,(int)digstl_y);
                    return -2;
                }
            }
        }
    } else
    {
        SYNCDBG(4,"Starting long distance digging");
        i = dig_to_position(dungeon->owner, gldstl_x, gldstl_y, cdig->direction_around, cdig->field_2A);
        if (i == -1) {
            return -2;
        }
        digstl_x = stl_num_decode_x(i);
        digstl_y = stl_num_decode_y(i);
        digslb_x = digstl_x / 3;
        digslb_y = digstl_y / 3;
        slb = get_slabmap_block(digslb_x, digslb_y);
        slbattr = get_slab_attrs(slb);
        if ( (slbattr->is_unknflg14 != 0) && (slb->kind != SlbT_GEMS) )
        {
            mapblk = get_map_block_at(digstl_x, digstl_y);
            if ( ((mapblk->flags & MapFlg_Unkn20) == 0) || (slabmap_owner(slb) == dungeon->owner) )
            {
                i = get_subtile_number_at_slab_center(digslb_x,digslb_y);
                if ( (find_from_task_list(dungeon->owner, i) < 0) && (simulation == 0) )
                {
                    if (try_game_action(comp, dungeon->owner, GA_Unk14, 0, digstl_x, digstl_y, 1, 1) <= 0) {
                        return -2;
                    }
                }
            }
        }
        cdig->direction_around = small_around_index_towards_destination(cdig->pos_20.x.stl.num,cdig->pos_20.x.stl.num,digstl_x,digstl_y);
    }
    cdig->pos_20.x.stl.num = digstl_x;
    cdig->pos_20.y.stl.num = digstl_y;
    if ( (cdig->pos_14.x.stl.num/3 == digslb_x) && (cdig->pos_14.y.stl.num/3 == digslb_y) )
    {
        return -1;
    }
    cdig->pos_gold.x.stl.num = digstl_x;
    cdig->pos_gold.y.stl.num = digstl_y;
    return 0;
}

long add_to_trap_location(struct Computer2 * comp, struct Coord3d * coord)
{
    struct Coord3d * location;
    long i;
    SYNCDBG(6,"Starting");
    //return _DK_add_to_trap_location(comp, coord);
    for (i=0; i < COMPUTER_TRAP_LOC_COUNT; i++)
    {
        location = &comp->trap_locations[i];
        if ( (location->x.val == 0) && (location->y.val == 0) ) {
            location->x.val = coord->x.val;
            location->y.val = coord->y.val;
            location->z.val = coord->z.val;
            return true;
        }
    }
    SYNCDBG(7,"No free location");
    return false;
}

long check_for_gold(long stl_x, long stl_y, long plyr_idx)
{
    struct SlabMap *slb;
    struct SlabAttr *slbattr;
    SubtlCodedCoords stl_num;
    SYNCDBG(5,"Starting");
    //return _DK_check_for_gold(l1, l2, l3);
    stl_num = get_subtile_number(stl_x+1,stl_y+1);
    slb = get_slabmap_for_subtile(stl_x,stl_y);
    slbattr = get_slab_attrs(slb);
    if ((slbattr->flags & SlbAtFlg_Unk01) != 0) {
        return (find_from_task_list(plyr_idx, stl_num) < 0);
    }
    return 0;
}

int search_spiral(struct Coord3d *pos, int owner, int i3, long (*cb)(long, long, long))
{
    SYNCDBG(7,"Starting");
    long retval = _DK_search_spiral(pos, owner, i3, cb);
    SYNCDBG(8,"Finished");

    return retval;
}

long find_next_gold(struct Computer2 * comp, struct ComputerTask * ctask)
{
    SYNCDBG(5,"Starting");
    //return _DK_find_next_gold(comp, ctask);

    memcpy(&ctask->dig.pos_14, &ctask->dig.pos_20, sizeof(struct Coord3d));

    if (search_spiral(&ctask->dig.pos_14, comp->dungeon->owner, 25, check_for_gold) == 25) {
        return 0;
    }

    memcpy(&ctask->dig.pos_gold, &ctask->dig.pos_20, sizeof(struct Coord3d));
    ctask->dig.distance = LONG_MAX;
    ctask->dig.field_54 = 0;

    struct ComputerDig cdig;
    memcpy(&cdig, &ctask->dig, sizeof(struct ComputerDig));

    long retval;
    do
    {
        retval = tool_dig_to_pos2(comp, &cdig, 1, 0);
        SYNCDBG(5,"retval=%d, dig.distance=%d, dig.field_54=%d",
            retval, cdig.distance, cdig.field_54);
    } while (retval == 0);

    SYNCDBG(6,"Finished");
    if ((retval != -1) && (retval != -5)) {
        return 0;
    } else {
        return 1;
    }
}

long task_dig_to_gold(struct Computer2 *comp, struct ComputerTask *ctask)
{
    long i;
    SYNCDBG(2,"Starting");
    //return _DK_task_dig_to_gold(comp,ctask);
    struct Dungeon* dungeon = comp->dungeon;

    i = dungeon->total_area * comp->field_1C / 100;
    if ( (dungeon->digger_stack_length > 0) && (dungeon->digger_stack_length >= i) )
    {
        SYNCDBG(6,"Did nothing");
        return 0;
    }

    if (ctask->dig.field_58 >= ctask->long_86)
    {
        struct SlabMap* slb = get_slabmap_for_subtile(ctask->dig.pos_20.x.stl.num, ctask->dig.pos_20.y.stl.num);

        if ((get_slab_attrs(slb)->flags & 0x01) != 0)
        {
            ctask->field_60--;
            if (ctask->field_60 > 0) {
                SYNCDBG(6,"Did nothing");
                return 0;
            }
        }
        ctask->dig.field_58 = 0;
    }

    long retval = tool_dig_to_pos2(comp, &ctask->dig, 0, 1);

    if ((ctask->flags & 0x04) != 0)
    {
        set_flag_byte(&ctask->flags, 0x04, false);
        add_to_trap_location(comp, &ctask->dig.pos_20);
    }

    if (ctask->dig.field_58 >= ctask->long_86)
    {
        ctask->field_60 = 700 / comp->field_18;
    }

    if (retval == -5)
    {
        ctask->ottype = ctask->ttype;
        ctask->ttype = CTT_WaitForBridge;

        SYNCDBG(6,"Waiting for bridge");
        return 4;
    }

    if ((retval < -3) || (retval > -1))
    {
        SYNCDBG(6,"Finished, code %d",(int)retval);
        return retval;
    }

    if (find_next_gold(comp, ctask) != 0)
    {
        SYNCDBG(7,"Next slab found");
        return 0;
    }

    struct GoldLookup* gold_lookup = get_gold_lookup(ctask->gold_lookup_idx);

    unsigned short gldstl_x = gold_lookup->x_stl_num;
    unsigned short gldstl_y = gold_lookup->y_stl_num;

    unsigned short ctgstl_x = ctask->dig.pos_gold.x.stl.num;
    unsigned short ctgstl_y = ctask->dig.pos_gold.y.stl.num;

    // While destination isn't reached, continue finding slabs to mark
    if ((gldstl_x != ctgstl_x) || (gldstl_y != ctgstl_y))
    {
        ctask->dig.pos_20.x.stl.num = gldstl_x;
        ctask->dig.pos_20.y.stl.num = gldstl_y;

        ctask->dig.pos_gold.x.stl.num = gldstl_x;
        ctask->dig.pos_gold.y.stl.num = gldstl_y;

        if (find_next_gold(comp, ctask) != 0) // || (retval < -3) -- Already returned
        {
            SYNCDBG(7,"Next slab found");
            return retval;
        }
    }

    // move to next task or return to enclosing task or return to try again later
    if ((retval == -3) || (retval == -2))
    {
        gold_lookup = &game.gold_lookup[ctask->gold_lookup_idx];
        set_flag_byte(&gold_lookup->plyrfield_1[dungeon->owner], 0x02, true);
        remove_task(comp, ctask);
    } else
    if (retval == -1) // unnecessary check as retval < -3 and retval > -1 did return before
    {
        remove_task(comp, ctask);
    }

    SYNCDBG(5,"Task finished");
    return retval;
}

long task_dig_to_attack(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_dig_to_attack(comp,ctask);
}

long task_magic_call_to_arms(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_magic_call_to_arms(comp,ctask);
}

long task_pickup_for_attack(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_pickup_for_attack(comp,ctask);
}

long task_move_creature_to_room(struct Computer2 *comp, struct ComputerTask *ctask)
{
    struct Thing *thing;
    struct Room *room;
    struct Coord3d pos;
    long i;
    SYNCDBG(9,"Starting");
    //return _DK_task_move_creature_to_room(comp,ctask);
    room = INVALID_ROOM;
    thing = thing_get(comp->field_14C8);
    if (!thing_is_invalid(thing))
    {
      room = room_get(ctask->word_80);
      pos.x.val = room->central_stl_x << 8;
      pos.y.val = room->central_stl_y << 8;
      pos.z.val = 256;
      if (fake_dump_held_creatures_on_map(comp, thing, &pos) > 0)
        return 2;
      remove_task(comp, ctask);
      return 0;
    }
    i = ctask->field_7C;
    ctask->field_7C--;
    if (i <= 0)
    {
      remove_task(comp, ctask);
      return 1;
    }
    thing = find_creature_to_be_placed_in_room(comp, &room);
    if (!thing_is_invalid(thing))
    {
        //TODO CREATURE_AI try to make sure the creature will do proper activity in the room
        //     ie. select a room tile which is far from CTA and enemies
        //TODO CREATURE_AI don't place creatures at center of a temple/portal if we don't want to get rid of them
        //TODO CREATURE_AI make sure to place creatures at "active" portal tile if we do want them to leave
        ctask->word_80 = room->index;
        pos.x.val = room->central_stl_x << 8;
        pos.y.val = room->central_stl_y << 8;
        pos.z.val = 256;
        if ( fake_place_thing_in_power_hand(comp, thing, &pos) )
          return 2;
        remove_task(comp, ctask);
        return 0;
      }
      remove_task(comp, ctask);
      return 0;
}

long task_move_creature_to_pos(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_move_creature_to_pos(comp,ctask);
}

long task_move_creatures_to_defend(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_move_creatures_to_defend(comp,ctask);
}

long task_slap_imps(struct Computer2 *comp, struct ComputerTask *ctask)
{
    struct Dungeon *dungeon;
    SYNCDBG(9,"Starting");
    //return _DK_task_slap_imps(comp,ctask);
    dungeon = comp->dungeon;
    ctask->field_7C--;
    if (ctask->field_7C >= 0)
    {
        struct Thing *thing;
        struct CreatureControl *cctrl;
        long i;
        unsigned long k;
        k = 0;
        i = dungeon->digger_list_start;
        while (i > 0)
        {
            thing = thing_get(i);
            if (thing_is_invalid(thing))
                break;
            cctrl = creature_control_get_from_thing(thing);
            i = cctrl->players_next_creature_idx;
            // Per-thing code
            if (!thing_is_picked_up(thing) && !thing_affected_by_spell(thing, SplK_Speed))
            {
                if (cctrl->field_21 == 0)
                {
                    long state_type;
                    state_type = get_creature_state_type(thing);
                    if (state_type == 1)
                    {
                        if (try_game_action(comp, dungeon->owner, 0x1Cu, 0, 0, 0, thing->index, 0) > 0)
                        {
                            return 2;
                        }
                    }
                }
            }
            // Per-thing code ends
            k++;
            if (k > THINGS_COUNT)
            {
                ERRORLOG("Infinite loop detected when sweeping things list");
                break;
            }
        }
    }
    remove_task(comp, ctask);
    return 0;
}

long task_dig_to_neutral(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_dig_to_neutral(comp,ctask);
}

long task_magic_speed_up(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_magic_speed_up(comp,ctask);
}

long task_wait_for_bridge(struct Computer2 *comp, struct ComputerTask *ctask)
{
    SYNCDBG(9,"Starting");
    return _DK_task_wait_for_bridge(comp,ctask);
}

long task_attack_magic(struct Computer2 *comp, struct ComputerTask *ctask)
{
    struct Dungeon *dungeon;
    struct Thing *thing;
    long i;
    SYNCDBG(9,"Starting");
    //return _DK_task_attack_magic(comp,ctask);
    dungeon = comp->dungeon;
    thing = thing_get(ctask->word_76);
    if (thing_is_invalid(thing))
    {
        return 1;
    }
    i = ctask->field_7C;
    ctask->field_7C--;
    if ((i <= 0) || (thing->health <= 0))
    {
        remove_task(comp, ctask);
        return 1;
    }
    if (computer_able_to_use_magic(comp, ctask->long_86, ctask->field_70, 1) != 1)
      return 4;
    i = try_game_action(comp, dungeon->owner, ctask->field_80, ctask->field_70,
        thing->mappos.x.stl.num, thing->mappos.y.stl.num, ctask->word_76, 0);
    if (i <= 0)
      return 4;
    return 2;
}

long task_sell_traps_and_doors(struct Computer2 *comp, struct ComputerTask *ctask)
{
    struct Dungeon *dungeon;
    const struct TrapDoorSelling *tdsell;
    TbBool item_sold;
    long value,model;
    long i;
    SYNCDBG(19,"Starting");
    //return _DK_task_sell_traps_and_doors(comp,ctask);
    dungeon = comp->dungeon;
    if (dungeon_invalid(dungeon))
    {
        ERRORLOG("Invalid dungeon in computer player.");
        return 0;
    }
    if ((ctask->field_7C >= ctask->long_76) && (ctask->field_80 >= dungeon->total_money_owned))
    {
        i = 0;
        value = 0;
        item_sold = false;
        for (i=0; i < sizeof(trapdoor_sell)/sizeof(trapdoor_sell[0]); i++)
        {
            tdsell = &trapdoor_sell[ctask->long_86];
            switch (tdsell->category)
            {
            case TDSC_Door:
                model = tdsell->model;
                if ((model < 0) || (model >= DOOR_TYPES_COUNT))
                {
                    ERRORLOG("Internal error - invalid model %d in slot %d",(int)model,(int)i);
                    break;
                }
                if (dungeon->door_amount[model] > 0)
                {
                  item_sold = true;
                  value = game.doors_config[model].selling_value;
                  if (remove_workshop_item(dungeon->owner, TCls_Door, model))
                  {
                    remove_workshop_object_from_player(dungeon->owner, door_to_object[model]);
                  }
                  SYNCDBG(9,"Door model %d sold for %d gold",(int)model,(int)value);
                }
                break;
            case TDSC_Trap:
                model = tdsell->model;
                if ((model < 0) || (model >= TRAP_TYPES_COUNT))
                {
                    ERRORLOG("Internal error - invalid model %d in slot %d",(int)model,(int)i);
                    break;
                }
                if (dungeon->trap_amount[model] > 0)
                {
                    item_sold = true;
                    value = game.traps_config[model].selling_value;
                    if (remove_workshop_item(dungeon->owner, TCls_Trap, model))
                    {
                        remove_workshop_object_from_player(dungeon->owner, trap_to_object[model]);
                    }
                    SYNCDBG(9,"Trap model %ld sold for %ld gold",model,value);
                }
                break;
            default:
                ERRORLOG("Unknown SELL_ITEM type");
                break;
            }
            ctask->long_86++;
            if (trapdoor_sell[ctask->long_86].category == TDSC_EndList)
                ctask->long_86 = 0;
            if (item_sold)
            {
                ctask->field_70--;
                if (ctask->field_70 > 0)
                {
                  ctask->long_76 += value;
                  dungeon->offmap_money_owned += value;
                  dungeon->total_money_owned += value;
                  return 1;
                }
                remove_task(comp, ctask);
                return 1;
            }
        }
    }
    SYNCDBG(9,"Couldn't sell anything, aborting.");
    remove_task(comp, ctask);
    return 0;
}

TbBool create_task_move_creatures_to_defend(struct Computer2 *comp, struct Coord3d *pos, long creatrs_num, unsigned long evflags)
{
    struct ComputerTask *ctask;
    SYNCDBG(7,"Starting");
    ctask = get_free_task(comp, 1);
    if (ctask == NULL)
        return false;
    ctask->ttype = CTT_MoveCreaturesToDefend;
    ctask->pos_76.x.val = pos->x.val;
    ctask->pos_76.y.val = pos->y.val;
    ctask->pos_76.z.val = pos->z.val;
    ctask->field_7C = creatrs_num;
    ctask->field_70 = evflags;
    ctask->field_A = game.play_gameturn;
    ctask->field_5C = game.play_gameturn;
    ctask->field_60 = comp->field_34;
    return true;
}

TbBool create_task_magic_call_to_arms(struct Computer2 *comp, struct Coord3d *pos, long creatrs_num)
{
    struct ComputerTask *ctask;
    SYNCDBG(7,"Starting");
    ctask = get_free_task(comp, 1);
    if (ctask == NULL)
        return false;
    ctask->ttype = CTT_MagicCallToArms;
    ctask->field_1 = 0;
    ctask->pos_76.x.val = pos->x.val;
    ctask->pos_76.y.val = pos->y.val;
    ctask->pos_76.z.val = pos->z.val;
    ctask->field_7C = creatrs_num;
    ctask->field_A = game.play_gameturn;
    ctask->field_60 = 25;
    ctask->field_5C = game.play_gameturn - 25;
    ctask->field_8E = 2500;
    return true;
}

TbBool create_task_sell_traps_and_doors(struct Computer2 *comp, long value)
{
    struct ComputerTask *ctask;
    SYNCDBG(7,"Starting");
    ctask = get_free_task(comp, 1);
    if (ctask == NULL)
        return false;
    ctask->ttype = CTT_SellTrapsAndDoors;
    ctask->field_70 = 0;
    ctask->field_A = game.play_gameturn;
    ctask->field_5C = game.play_gameturn;
    ctask->field_60 = 1;
    ctask->field_70 = 5;
    ctask->long_76 = 0;
    ctask->field_7C = value;
    ctask->field_80 = value;
    ctask->long_86 = 0;
    return true;
}

TbBool create_task_move_creature_to_pos(struct Computer2 *comp, struct Thing *thing, long a2, long a3)
{
    struct ComputerTask *ctask;
    SYNCDBG(7,"Starting");
    ctask = get_free_task(comp, 0);
    if (ctask == NULL)
        return false;
    ctask->ttype = CTT_MoveCreatureToPos;
    ctask->word_86 = a2 << 8;
    ctask->word_88 = a3 << 8;
    ctask->word_76 = thing->index;
    ctask->word_80 = 0;
    ctask->field_A = game.play_gameturn;
    return true;
}

long process_tasks(struct Computer2 *comp)
{
    struct ComputerTask *ctask;
    long ndone;
    long i,n;
    unsigned long k;
    //return _DK_process_tasks(comp);
    ndone = 0;
    k = 0;
    i = comp->task_idx;
    while (i != 0)
    {
        if ((i < 0) || (i >= COMPUTER_TASKS_COUNT))
        {
          ERRORLOG("Jump to invalid computer task %ld detected",i);
          break;
        }
        if (comp->tasks_did <= 0)
            break;
        ctask = &game.computer_task[i];
        i = ctask->next_task;
        if ((ctask->flags & 0x01) != 0)
        {
            n = ctask->ttype;
            if ((n > 0) && (n < sizeof(task_function)/sizeof(task_function[0])))
            {
                SYNCDBG(12,"Computer Task Type %d",(int)n);
                task_function[n].func(comp, ctask);
                ndone++;
            } else
            {
                ERRORLOG("Bad Computer Task Type %d",(int)n);
            }
        }
        k++;
        if (k > COMPUTER_TASKS_COUNT)
        {
          ERRORLOG("Infinite loop detected when sweeping computer tasks");
          break;
        }
    }
    return ndone;
}
/******************************************************************************/