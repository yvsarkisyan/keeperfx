# Introduction #

KeeperFX is an extensive mod for Dungeon Keeper.

It is written by fans and not supported by original developer.
It contains some of original Dungeon Keeper data, but many files
are also modified or remade.

# Installation of KeeperFX CCP #

You need original Dungeon Keeper CD (or CD image) to perform
complete installation.

Please note that there are two types of releases: complete
version and patch. You need a complete version to play the game;
a patch is only an additional feature, which you can use by
overwriting some files from complete version with new ones.
Even with complete version, you still need original Dungeon
Keeper CD to prepare the game for playing.

To install KeeperFX CCP, you have to unpack the archive to
your desired target location, and then run "launcher.exe".
The Launcher utility will allow you to select source folder
from which original DK files will be taken. To select the
"keeper" folder and start copying files, press "Install" button.

You must select the "keeper" folder from the CD content list.
Selecting root folder of your CD, or selecting installation
folder on disk, won't be enough.

If you wish to change language, click "Settings" in the launcher
and select it from list. Remember to save your changes. You may
also edit "keeperfx.cfg" by hand, using text editor.

Press the correct button inside Launcher to start the game.
For information about running the game executable directly,
see 'running KeeperFX' section. If something doesn't work,
see the 'troubleshooting' section.

## Supported DK releases to install from: ##

Here you can find a list of releases which you can use to get
files required by KeeperFX:
  * Dungeon Keeper, english release
  * Dungeon Keeper, multilingual release
  * Dungeon Keeper Gold, english release
  * Dungeon Keeper Gold, multilingual release
  * Dungeon Keeper from GOG.com (the CD image "game.gog")
Remember that KeeperFX needs the original CD, or mounted
CD image. The files installed on disk by original DK setup
are not enough. Also, you must select the "keeper" folder from
the CD content list. Selecting root folder of your CD, or
selecting installation folder on disk, won't be enough.

# Available languages #

The following languages are currently functional:
```
 ENG ITA FRE SPA DUT GER POL SWE JAP RUS
```
The following languages are partially functional:
```
 CHI CHT
```
Note that some campaigns may not support your language.
In this case, default language will be used inside this
campaign.

# Available screen resolutions #

To change available screen modes, edit "keeperfx.cfg".
Screen mode can be in a form `WIDTHxHEIGHTxBPP` which defines
> fullscreen mode, or `WIDTHxHEIGHTwBPP`, which defines windowed
> mode. When defining windowed mode, the BPP should be equal to
> the colour depth on your desktop. It is not recommended to
> mix fullscreen and windowed modes in one config file.
There are two lines which define resolutions: 'FRONTEND\_RES='
> should have exactly 3 parameters and is used in the menu,
> while 'INGAME\_RES=' can have 1-5 parameters, which define
> list of resolutions to switch between in the actual game.
Most stable modes are 640x400 and 640x480. Higher resolutions
> may be sometimes unstable, especially in possession.

# Running KeeperFX #

To start the game, run "keeperfx.exe". If you want to report
any errors you encounter, you may run "keeperfx\_hvlog.exe"
instead. This will run a "heavylog version", which writes a lot
of information into "keeperfx.log". In case of the game hanging
on suddenly disappearing, you may send a last few lines of the
generated LOG to the author with your description of the bug.

Note that "keeperfx\_hvlog.exe" requires a lot more CPU than
standard version, and may be slow even on new computers.
Also, the generated LOG file may be very large, and after
a few hours of play it will have several hundreds megabytes.
This is why you should use standard "keeperfx.exe" if you're
not planning reporting any errors.

Both versions will recognize all [command line options](CommandLineOptions.md).