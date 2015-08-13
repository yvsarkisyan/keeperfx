**Q:** Colors are changed in menu or during gameplay,
but no problem is mentioned in "keeperfx.log".
> A: Select "Run in 256 colors" and "Run in 640x480" in the
> program properties, and change lines in KEEPERFX.CFG
> into those written in next answer.

**Q:** Intro doesn't play. LOG file says:
Error: setup\_game: Can't enter movies screen mode to play intro
> A: The problem is that your drivers can't support 320x200 mode.
> Change the resolution config lines in KEEPERFX.CFG
> into those written in next answer.

**Q:** The game is pixelated/works in low resolution mode only.
Can I make it work in higher resolutions?
> A: To switch resolutions during the game, press Alt+R.
> If the screen blanks, but resolution doesn't change,
> then the video mode used for higher resolution is probably
> not supported by your video card/driver. In that case,
> change the resolution config line in KEEPERFX.CFG into:
> INGAME\_RES=320x200x8 640x480x8
> You may also try other resolutions, but those over 640x480
> may be unstable.

**Q:** Game stops when loading a map. LOG file says:
Error: setup\_screen\_mode: Unable to setup screen resolution
640x400x8 (mode 10)
> A: The problem is that your drivers can't support 640x400 mode.
> Change the [resolution config lines in KEEPERFX.CFG](TheConfigurationFile.md) into:
> FRONTEND\_RES=640x480x8 640x480x8 640x480x8
> INGAME\_RES=640x480x8

**Q:** The game doesn't run. LOG file says:
Error: setup\_strings\_data: Strings file couldn't be loaded
or is too small
> A: Check if there's a language file in 'FXDATA' folder for the
> language which you've selected in KEEPERFX.CFG.

**Q:** Mouse stops/teleports/moves incorrectly during the game.
> A: Try the '-altinput' command line switch.

**Q:** I get a message 'Cannot initialize' when I try to enter network game.
> A: KeeperFX does not support serial cable, modem and IPX multiplayer.
> Use standard, retail version of DK if you wish to play serial or
> modem game. Use standard DK with IPX fix (or DK Gold) if you wish
> to play IPX game. KeeperFX supports only TCP/IP protocol.

**Q:** I'm having problems with TCP/IP multiplayer.
> A: See 'tcp\_readme.txt' for more information about multiplayer.

**Q:** There are no special eye effects when I possess Beetle, Fly,
Dragon, Tentacle etc.!
> A: Lens effect only work if the game detects over 16MB RAM.
> Also, make sure that "fxdata/lenses.cfg" is present and not damaged.

**Q:** After some time of gameplay, many in-game elements stops working.
Creature spells and some keeper spells (ie. Create Imp spell) ain't
working. Same with placing traps/doors, and creating gold piles.
> A: The game has a limit for amount of 'things' - these 'things' are
> all the objects that generate sprites (graphic representations as
> an image). They are limited to 2047, and if all slots are taken,
> it's no longer possible to create spell shots, gold piles or doors.
> Creatures have additional limit - even if there are still free
> 'thing' slots, they are limited to 255.

**Q:** What's the difference between 'keeperfx.exe' and 'keeperfx\_dbg.exe'?
> A: These files are identical except of one thing: 'keeperfx\_dbg.exe'
> writes A LOT of messages into 'keeperfx.log', allowing to trace
> any bugs and problems during the game. Because of the amount of data
> being written, the debug version, 'keeperfx\_dbg.exe', is a few times
> slower than standard version, 'keeperfx.exe'. If you're not planning
> to report any bugs, you should use 'keeperfx.exe'.

**Q:** I've found a cheat menu, but it doesn't work!
> A: The three cheat menus are only partially functional.