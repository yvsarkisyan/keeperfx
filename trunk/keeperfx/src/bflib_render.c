/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet or Dungeon Keeper.
/******************************************************************************/
/** @file bflib_render.c
 *     Rendering the 3D view elements functions.
 * @par Purpose:
 *     Functions for rendering 3D elements.
 * @par Comment:
 *     Go away from here, you bad optimizer! Do not compile this with optimizations.
 * @author   Tomasz Lis
 * @date     20 Mar 2009 - 30 Mar 2009
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "bflib_render.h"

#include "globals.h"
#include "bflib_basics.h"
#include "bflib_memory.h"
#include "bflib_video.h"
#include "bflib_sprite.h"
#include "bflib_vidraw.h"

/******************************************************************************/
TbPixel vec_colour = 112;
unsigned char vec_mode;
unsigned char *LOC_poly_screen;
unsigned char *LOC_vec_map;
unsigned char *render_fade_tables = NULL;
unsigned char *render_ghost = NULL;
unsigned long LOC_vec_screen_width;
unsigned long LOC_vec_window_width;
unsigned long LOC_vec_window_height;
struct PolyPoint polyscans[POLY_SCANS_COUNT];
/******************************************************************************/
