/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet or Dungeon Keeper.
/******************************************************************************/
/** @file bflib_guibtns.c
 *     GUI Buttons support.
 * @par Purpose:
 *     Definition of button, and common routines to handle it.
 * @par Comment:
 *     None.
 * @author   Tomasz Lis
 * @date     25 Nov 2008 - 30 Dec 2008
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "bflib_guibtns.h"

#include <string.h>
#include <stdio.h>

#include "bflib_basics.h"
#include "globals.h"
#include "bflib_sound.h"
#include "bflib_keybrd.h"

#ifdef __cplusplus
extern "C" {
#endif

DLLIMPORT void _DK_do_button_click_actions(struct GuiButton *gbtn, unsigned char *, Gf_Btn_Callback callback);
DLLIMPORT void _DK_do_button_release_actions(struct GuiButton *gbtn, unsigned char *, Gf_Btn_Callback callback);
/******************************************************************************/
// Global variables
char *gui_strings_data;
char *gui_strings[STRINGS_MAX+1];
/******************************************************************************/
// Functions

void do_sound_menu_click(void)
{
  play_non_3d_sample(61);
}

void do_sound_button_click(struct GuiButton *gbtn)
{
  if ((gbtn->id_num >= 1) && (gbtn->id_num <= 5))
      play_non_3d_sample(60);
  else
      play_non_3d_sample(61);
}

void do_button_click_actions(struct GuiButton *gbtn, unsigned char *s, Gf_Btn_Callback callback)
{
  _DK_do_button_click_actions(gbtn, s, callback);
}

void setup_input_field(struct GuiButton *gbtn)
{
  static const char *func_name="setup_input_field";
  char text[INPUT_FIELD_LEN];
  lbInkey = 0;
  memset(backup_input_field, 0, INPUT_FIELD_LEN);
  if (strlen((char *)gbtn->content) < INPUT_FIELD_LEN)
  {
    strcpy(backup_input_field, (char *)gbtn->content);
  } else
  {
    error(func_name, 7873, "backup_input_field too small");
    strncpy(backup_input_field, (char *)gbtn->content, INPUT_FIELD_LEN-1);
    backup_input_field[INPUT_FIELD_LEN-1] = 0;
  }
  sprintf(text,gui_strings[358]); // UNUSED
  if ( !strcmp(text, backup_input_field) )
    *(long *)gbtn->content = 0;
}

/******************************************************************************/
#ifdef __cplusplus
}
#endif