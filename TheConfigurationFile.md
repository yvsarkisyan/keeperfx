# Introduction #

Editing the configuration file is often a necessity, because with default screen resolution settings the game may not work.

The configuration file keeperfx.cfg can be edited with a normal text editor, such as Notepad or Wordpad. Take care if editing with an editor that supports formatting to save the result as plain text.

# Common Commands #

FRONTEND\_RES
> Allows you to select front-end resolution (used inside
> menu and for playing movies, but not in actual game)
> FRONTEND\_RES=_failsafe-mode movies-mode menu-mode_

INGAME\_RES
> Allows you to select up to five in-game resolutions.
> Resolution has the form of WIDTHxHEIGHTxBPP.
> Standard modes are: 320x200x8, 320x240x8, 512x384x8,
> 640x400x8, 640x480x8, 800x600x8, 1024x768x8,
  1. 80x1024x8, 1600x1200x8. Different modes (ie.
> widescreen) may be used too, if only they are
> supported by your graphics card and video driver.
> You can switch between those resolutions during the
> gameplay by pressing Alt+R. Modes over 640x480 are
> experimental, and not completely stable.
> INGAME\_RES=_mode1 mode2 mode3_ ....

SCREENSHOT
> Selects the format in which screenshots will be written.
> You can choose between BMP and HSI bitmap format.
> SCREENSHOT=_type_

LANGUAGE
> This option is used to select language file, used for
> displaying texts. It also changes language in mentor
> speeches. Note that if the specific campaign doesn't
> have support for your language, the default language
> will be used.