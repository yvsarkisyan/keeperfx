# HOW TO PLAY CUSTOM MAPS FROM lubiki.pl IN KEEPERFX #

  1. Download the map from [keeper.lubiki.pl](http://keeper.lubiki.pl/html/dk1_maps.php)
  1. Extract the map to "levels" folder inside KeeperFX.
  1. Open KeeperFX, click "Free play levels" (this option may be called "Deeper Dungeons" in some languages.
  1. Select your map from the list, and play.

# TROUBLESHOOTING #

### **Q:** What does "extract" mean? What are these ZIP files? ###

**A:** These are archives. You can extract them in any archive tool; Windows has a build-in extraction tool, but I recommend using 7z:
http://www.7-zip.org/
Extracting means copying the files stored inside ZIP file into separate files, stored outside of the ZIP.


### **Q:** Where is my KeeperFX levels folder? ###

**A:** I don't know. If you have KeeperFX, you must have extracted (or installed) it somewhere. You've selected a place to extract by yourself. If you can't remember, try looking at "properties" of the shortcut you're using to run KeeperFX.


### **Q:** There's no "Free play levels" nor "Deeper Dungeons" button in the game. ###

**A:** Make sure you're using KeeperFX, not original DK. Also, check if you have the latest version of KeeperFX.


### **Q:** The map does not appear in the "Free play levels" menu. ###

**A:** Make sure the files form ZIP file are inside "levels" folder of your KeeperFX. Make sure they are stored directly there, not in any subfolder. Make sure the file with "LIF" or "LOF" extension is there (ie. "MAP00500.LIF"). If there is a LIF file for your map, the level will appear. On any further problems, try debug version and check if the LOG file shows a reason why your LIF wasn't loaded.


### **Q:** The map is on the list, but when I click on it, empty level is started (there's literally nothing on the level) and I hear that I'm defeated. ###

**A:** This means the LIF file is where it should be, but some of the other map files can't be located. Make sure you have all of them, especially SLB, TNG and TXT files. Make sure that level number inside LIF file (open it with text editor) is correct (corresponds to names of files). Also, make sure the level number is lower than 32767 - only levels up to this number are supported. Finally, make sure you're running KeeperFX in latest version.


### **Q:** Why the enemy keeper isn't doing anything when I'm playing the map? ###

**A:** You've probably downloaded a multiplayer map. In multiplayer maps, enemy keepers are not set up as computers.
You either have to add computer player configuration to the script, or make that map show in multiplayer menu. See the questions below.


### **Q:** How can I change multiplayer map into ordinary "Free play" map? ###

**A:** open the TXT file for your level (ie. "MAP00500.TXT") and add lines to set up existing enemy players as computers:
```
COMPUTER_PLAYER(PLAYER1,0)
COMPUTER_PLAYER(PLAYER2,0)
COMPUTER_PLAYER(PLAYER3,0)
```


### **Q:** How can I make a map show in "Multiplayer" instead of "Free play levels"? ###

**A:** The LIF file can only be used to put a map into "Free play levels". It doesn't have enough options to make a map appear in multiplayer.
So to make it visible there, you must use another file - LOF file. The old LIF file MUST BE DELETED! You cannot have both LIF and LOF for one map - that would confuse the game.
You can create the LOF in any text editor. This is how it should look like:
```
; KeeperFX Level Overview File (LOF)
KIND = MULTI
NAME_TEXT = <Name of the map, the same that was in LIF>
ENSIGN_POS = <x> <y>
ENSIGN_ZOOM = <x> <y>
PLAYERS = <number of keepers>
OPTIONS =
AUTHOR = Anonymous
DESCRIPTION = Map downloaded from keeper.lubiki.pl
DATE = 2010-01-01
```
The coordinates `<`x`>` `<`y`>` are position on the multiplayer land; `<`x`>` is ranged 160..1120, while `<`y`>` is 120..840. Both ENSIGN`_` commands should have identical coordinates. The `<`number of keepers`>` option should include human player, so for example if there's one enemy, value should be "2".
Examples of LOF files can be found in "levels" folder of keeperFX - for example:
```
; KeeperFX Level Overview File (LOF)
KIND = MULTI
NAME_TEXT = DD Multi 10
ENSIGN_POS = 478 520
ENSIGN_ZOOM = 478 520
PLAYERS = 3
OPTIONS =
AUTHOR = Bullfrog
DESCRIPTION = Original Deeper Dungeons multiplayer level
DATE = 1997-09-15
```