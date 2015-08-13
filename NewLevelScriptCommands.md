# Introduction #

Level script commands that have a new or different meaning in KeeperFX can be found here.

This page can be treated as an addendrum to the [script commands reference](http://keeper.lubiki.pl/dk1_docs/dk_scripting_ref.htm).

# Details #

## `ADD_GOLD_TO_PLAYER` ##
> Allows to add some off-map gold as a reward to a player.
> Example:
```
ADD_GOLD_TO_PLAYER(PLAYER0,5000)
```

## `ALLY_PLAYERS` ##
> Marks two players as allied, or ends the alliance. The
> difference to original DK is that this command takes 3
> parameters - 2 are players, and third one is 1 if the
> alliance is being created, and 0 if it is being broken.
> Note that computer players will not break the alliance
> by themselves, but human player may do so. So this command
> is mostly for controlling the computer players behaviour.
> Example:
```
ALLY_PLAYERS(PLAYER1,PLAYER2,1)
```
> Note: if you enable KeeperFX commands with `LEVEL_VERSION`,
> old `ALLY_PLAYERS` commands (without the extra parameter)
> will no longer work. Add a '1' to fix this.

## `BONUS_LEVEL_TIME` ##
> Sets time to be displayed on "bonus timer" - on-screen
> time field, used mostly for bonus levels.
> Like in original DK, this command accepts one parameter
> - number of game turns to start the countdown from.
> But now this command can be used to show bonus timer in
> any level. Setting game turns to 0 will hide the timer.
> Example:
```
BONUS_LEVEL_TIME(12000)
```

## `CREATURE_AVAILABLE` ##
> Tells the game whether a creature of specific kind can
> come through that player's Portal. Parameters of this
> command are changed to original, an now look like this:
```
  CREATURE_AVAILABLE(​[player],​[creature],​[can be attracted],​[amount forced])
```
> where:

> `[can be attracted]` - If set to 1, it is possible to attract
> > the creature, either by rooms or by forced attraction.
> > (so it works like 4th parameter in original command).


> `[amount forced]` - Amount of creatures of that kind which
> > can be force-attracted (attracted even if player doesn't
> > have rooms required by that creature). Originally
> > there was no possibility to skip attraction conditions.

## `DISPLAY_INFORMATION` ##
Displays one of the text messages from language-specific strings banks in an Information Box. Each Information Box stacks over previous messages, and can be removed by right clicking. It disappears automatically some time after has been read.
```
  DISPLAY_INFORMATION(​[a],​[place])
```

> where:

> `[a]` - The number of the message, assigned to it in .po or .pot translation file.

> `[place]` - Location where the view should be centered if the player clicks on the "zoom to" icon on the Message Panel. It can now have the following values:
  * `PLAYERx` - zoom to player's dungeon heart
  * positive integer - zoom to Action Point of given number
  * negative integer - zoom to Hero Gate of given number
  * `ALL_PLAYERS` - zoom button will be inactive

## `DISPLAY_OBJECTIVE` ##
Displays one of the text messages from language-specific strings banks in an Objective Box. Each Objective Box replaces previous one, and cannot be removed from the messages list. It removes itself only after level is won or lost.
```
  DISPLAY_OBJECTIVE(​[a],​[place])
```
> where:

> `[a]` - The number of the message, assigned to it in .po or .pot translation file.

> `[place]` - Location where the view should be centered if the player clicks on the "zoom to" icon on the Message Panel. It can have the same values as in `DISPLAY_INFORMATION` command above.

## `DRAWFROM` ##
> Is not a command itself but may replace a parameter of most other commands.
> Replaces the old RANDOM() command.
```
   DRAWFROM(a,b,c,d,e,f,g,h)
```
> It draws at random one value or number from up to eight parameters. Examples:
```
    REM Human player will have random start gold between 10000 and 15000
    START_MONEY(PLAYER0,DRAWFROM(10000,11000,12000,13000,14000,15000))
	
    REM One bug type creature will be added to pool
    ADD_CREATURE_TO_POOL(DRAWFROM(FLY,BUG,SPIDER),5)
	
    REM Add one of three predefined Hero parties to Hero gate 6 or 9
    ADD_PARTY_TO_LEVEL(PLAYER0,DRAWFROM(thugs,fiends,dudes),DRAWFROM(-6,-9),1)
```
> It is also possible to draw a value from a range of numbers using a tilde(~). Example:
```
    REM Spawn a BUG at a random time at the start or near the end of the level
    IF(PLAYER0,TIMER1 >= DRAWFROM(0~12000,72000~108000))
        ADD_CREATURE_TO_LEVEL(PLAYER_GOOD,BUG,-1,1,1,500)
    ENDIF
```
> Ranges can be combined with values. The '~' is a separate parameter. Example:
```
   DRAWFROM(1~4,6,8~11,13)
```
> A range cannot be used for hero gates, action points or any non-consecutive values.

> The command shouldn't be used in multiplayer
> maps, as it will lead to synchronization problems.
> Value represented by `DRAWFROM` is selected at start of a map,
> and never changes during the gameplay.

## `IF` ##

> This is used to test the differences between two values (`[name]` and `[a]`). If those two values agree with the comparison, the script will continue. If the two values do not agree with the comparison, the script will find the next `ENDIF` and continue from there. New option values have been added to this command, and some original options were changed:

```
  IF(​[player],​[name]​[comparison]​[a])
```
> where:

> `[name]` -  The name of a variable, timer, flag, creature, room, trap or door.
  * Checking variable returns its value at the moment. Variables are:

| **name** | **description** |
|:---------|:----------------|
| MONEY    | The amount of money the player has |
| GAME\_TURN | The current game turn (player independent) |
| TOTAL\_DIGGERS | The number of special diggers (Imps) that player has got |
| TOTAL\_CREATURES | The number of creatures that player has got |
| EVIL\_CREATURES | The number of evil creatures that player has got |
| GOOD\_CREATURES | The number of heroes that player has got |
| TOTAL\_RESEARCH | The amount of research points that player has got (see manipulating research section for more information) |
| TOTAL\_DOORS | The amount of doors that player has got |
| TOTAL\_AREA | The amount of tiles that player owns |
| TOTAL\_CREATURES\_LEFT | The amount of creatures that have left that player's dungeon because they were annoyed |
| CREATURES\_ANNOYED | The number of creatures annoyed in that player's dungeon |
| BATTLES\_WON | The number of battles won by that player |
| BATTLES\_LOST | The number of battles lost by that player |
| ROOMS\_DESTROYED | The number of rooms belonging to the player which were sold or destroyed |
| SPELLS\_STOLEN | The number of spells stolen from that player |
| TIMES\_BROKEN\_INTO | The number of times that players walls have been breached |
| DUNGEON\_DESTROYED | Whether that players Dungeon Heart has been destroyed (0 if still active, 1 if destroyed) |
| CREATURES\_SCAVENGED\_LOST | Number of creatures lost by that player due to scavenging |
| CREATURES\_SCAVENGED\_GAINED | Number of creatures gained by that player through scavenging |
| ALL\_DUNGEONS\_DESTROYED | Whether all the players Dungeon Hearts has been destroyed (0 if still active, 1 if destroyed) (player independent) |
| DOORS\_DESTROYED | The number of doors belonging to the player which were sold or destroyed |
| TOTAL\_GOLD\_MINED | Total amount of gold mined by the player |
| GOLD\_POTS\_STOLEN | Number of gold pots that were stolen from the player |
| BREAK\_IN | Amount of break-ins |

  * Checking creature returns how many creatures of that kind a player owns. It doesn't matter if the player can controls them, or they're in custody.
  * Checking room returns how many slabs of that room the player owns.
  * Checking trap or door availability returns amount of deployed traps and doors owned by that player.
  * Checking TIMERx or FLAGx returns its current value.

> `[player]` - The player’s name, e.g. PLAYER1. if ALL\_PLAYERS is used, then the condition has to be met for all of the players in order for the commands inside to be executed.

## `IF_AVAILABLE` ##
> Checks availability of an item for the player. New option values have been added to this command:
```
  IF_AVAILABLE(​[player],​[name]​[comparison]​[a])
```
> where:

> `[name]` -  The name of a creature, room, spell, trap or door.
  * Checking creature availability returns how many creatures of that kind can come from portal to that player. The check includes creature pool, players creature limit and whether attraction criteria are met.
  * Checking room availability returns whether the room can be built by a player. Cost of the room is not considered.
  * Checking spell availability returns whether the spell can be casted by a player. Cost of the spell is not considered.
  * Checking trap or door availability returns amount of traps and doors a player has stored, either in workshop or in off-map storage.

## `IF_CONTROLS` ##
> Allows to execute commands based on the items a player controls.
```
  IF_CONTROLS(​[player],​[name]​[comparison]​[a])
```
> where:

> `[name]` -  The name of a creature. Returns how many creatures of given kind the player owns, excluding these under enemy control (in custody). Also accepts TOTAL\_CREATURES, TOTAL\_DIGGERS, EVIL\_CREATURES and GOOD\_CREATURES.

## `KILL_CREATURE` ##
> Kills given amount of creatures based on given criteria.

```
  KILL_CREATURE(​[player],​[creature],​[criteria],​[count])
```
> where:

> `[player]` - The player who owns creatures to be affected.

> `[creature]` - Creature model to be searched.

> `[criteria]` - Creature selection criteria.
| **criterium** | **description** |
|:--------------|:----------------|
| MOST\_EXPERIENCED | Highest level creature |
| MOST\_EXP\_WANDERING | Highest level idle creature |
| MOST\_EXP\_WORKING | Highest level working creature |
| MOST\_EXP\_FIGHTING | Highest level creature in combat |
| LEAST\_EXPERIENCED | Lowest level creature|
| LEAST\_EXP\_WANDERING | Lowest level idle creature |
| LEAST\_EXP\_WORKING | Lowest level working creature |
| LEAST\_EXP\_FIGHTING |Lowest level creature in combat |
| NEAR\_OWN\_HEART | Creature close to friendly dungeon heart |
| NEAR\_ENEMY\_HEART | Creature close to enemy dungeon heart |
| ON\_ENEMY\_GROUND | Creature on enemy tile |

> `[count]` - Amount of creatures affected.

## `LEVEL_VERSION` ##
> Lets the game know if the level was designed specially for
> KeeperFX. To use new script commands, you must start the
> script with `LEVEL_VERSION(1)`. Without it, the new commands
> will not work properly, and the game will try to emulate old
> behavior of commands which were modified.

## `PLAY_MESSAGE` ##
> Allows to play any `SOUND` or `SPEECH` from the game. Messages can be found <a href='https://code.google.com/p/keeperfx/source/browse/trunk/keeperfx/lang/speech_eng.pot'>here</a>.
> Example:
```
PLAY_MESSAGE(PLAYER0,SPEECH,107)
```

## `QUICK_INFORMATION` ##
Works like `DISPLAY_INFORMATION`, but instead of using a string from translations, allows to type it directly.
```
  QUICK_INFORMATION(​[a],​["message"],[place])
```
> where:

> `[a]` -  Message slot selection. There are 50 quick message slots, and each message you're making should use a different one. Using one message slot twice will lead to the first message being lost.

> `["message"]` -  The message string to be shown in a box. Message
> length may be up to 1024 characters.

> `[place]` - Location where the view should be centered if the player clicks on the "zoom to" icon on the Message Panel. It can have the same values as in `DISPLAY_INFORMATION` command.

## `QUICK_OBJECTIVE` ##
Works like `DISPLAY_OBJECTIVE`, but instead of using a string from translations, allows to type it directly.
```
  QUICK_OBJECTIVE(​[a],​["message"],[place])
```
Parameters have the same meaning as in `QUICK_INFORMATION` command.

## `QUICK_INFORMATION_WITH_POS`, `QUICK_OBJECTIVE_WITH_POS` ##
> Accepts additional XY coordinates of the zoom place.

## `SET_CREATURE_TENDENCIES` ##
> Allows to set tendencies: `IMPRISON` and `FLEE`, for a player's
> creatures. Example:
```
SET_CREATURE_TENDENCIES(PLAYER2,FLEE,1)
```
> Note that a player must have prison when `IMPRISON` command
> is triggered; otherwise it won't make any change.

## `SET_CREATURE_FEAR_WOUNDED` ##
> Replacements for `SET_CREATURE_FEAR`. The value taken by this
> function is a percentage (0..100) and defines health drop
> required for the creature to escape from combat. A special
> value of 101 makes creature avoid any combat other than with
> one creature of the same kind.
> Example:
```
    REM Make Imp escape combat only when his health drops below half
    SET_CREATURE_FEAR_WOUNDED(IMP,50)
```

## `SET_CREATURE_FEAR_STRONGER` ##
> Allows to define how many times stronger the enemy has to be
> for our creature to escape from combat. The value is in %.
> Example:
```
    REM Make Avatar fear any other creature which is twice as strong as him
    SET_CREATURE_FEAR_STRONGER(AVATAR,200)
```

## `REVEAL_MAP_RECT` ##
> Reveals rectangular map area for given player. Requires
> coordinates of area center point, and rectangle dimensions.
> Numbers are scaled in subtiles (range is 1..254).
> Example:
```
    REVEAL_MAP_RECT(PLAYER0,132,96,13,11)
```

## `REVEAL_MAP_LOCATION` ##
> Reveals square area of subtiles around given location.
> Location meaning is identical to the one in `DISPLAY_OBJECTIVE`.
> For example, to reveal Hero Gate no.1:
```
  REVEAL_MAP_LOCATION(PLAYER0,-1,11)
```

## `RESEARCH` ##
> Changes amount of research points needed to discover an item
> in library. It doesn't affect research order, only amount
> of points. If the item never was in research list, it's added
> at end. Example:
```
    RESEARCH(PLAYER1,MAGIC,POWER_CHICKEN,10000)
```

## `RESEARCH_ORDER` ##
> When this command is first called, the research list for
> specified players is cleared. Using it you may create
> a research list from beginning. Note that if you won't place
> an item on the list, it will not be possible to research it.
> So if you're using this command, you must add all items
> available on the level to the research list. Example:
```
   RESEARCH_ORDER(ALL_PLAYERS,ROOM,SCAVENGER,50000)
   [...] - more RESEARCH_ORDER commands should follow.
```

## `RANDOM` ##
> The RANDOM() function of original DK has been replaced by `DRAWFROM`.
> This command is currently unimplemented - use DRAWFROM instead.

> It is ment to be a function used in same way as DRAWFROM, but selecting
> value each time during gameplay instead of doing it once at start of the level.