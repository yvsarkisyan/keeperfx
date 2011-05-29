/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file creature_states_pray.h
 *     Header file for creature_states_pray.c.
 * @par Purpose:
 *     Creature state machine functions related to temple.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   KeeperFX Team
 * @date     23 Sep 2009 - 05 Jan 2011
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef DK_CRTRSTATEPRAY_H
#define DK_CRTRSTATEPRAY_H

#include "bflib_basics.h"
#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
#ifdef __cplusplus
#pragma pack(1)
#endif

struct Thing;

#ifdef __cplusplus
#pragma pack()
#endif
/******************************************************************************/
short at_temple(struct Thing *thing);
short praying_in_temple(struct Thing *thing);
long process_temple_function(struct Thing *thing);
short state_cleanup_in_temple(struct Thing *thing);

short cleanup_sacrifice(struct Thing *thing);
short creature_being_sacrificed(struct Thing *thing);
short creature_sacrifice(struct Thing *thing);
short creature_being_summoned(struct Thing *thing);
/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif
