# Changelog #
Version: 0.4.6

  * Prepared trap placing algorithm for future improvements.
  * Increased computer player priority of training and research and decreased one for manufacture.
  * Modified picking up imps for mining to not use imps which are already mining or returning gold.
  * Rewritten chicken growing cycle and movement function.
  * Modified computer player to not create processes for dungeons without heart.
  * Fixed computer player moving creatures to continue when player has no gold.
  * Introduced command line parameter to enable the computer player chat.
  * Fixed clearing creatures kept in custody in enemy POWER\_HAND when owners heart is destroyed.
  * Rewritten tagging a block for digging.
  * Started work computer player on moving imps to mine when low on gold.
  * Some unifications in computer player gold management code.
  * Modifed doing nothing state for heroes to allow getting back to assigned job.
  * Modified imps so that they count amount of jobs of given kind they did in a row.
  * Divided digging a corridor to sub-fubctions. Made a function which finds a place to drop imp for room digging.
  * Modified destroying dungeon heart if the player has two hearts on map.
  * Changed lightning trap to not hit allies.
  * Made CTA so suppress basic needs other than heal\_critical.
  * Unified the way creatures are affected by CTA. Modified doing nothing state to recognize CTA.
  * Switched the use of hit\_type into hit\_targets in some places.
  * Modified creature idle state to not go for lair during CTA.
  * Modified fear calculations. Heroes are no longer scared when low of health, but will still fear much stronger enemies.
  * Introdiced power castability option for casting on natural terrain. Merged two flag enumerations.
  * Allowed picking up gold from neutral ground. Also did some renaming.
  * Modified POWER\_HAND castability to allow picking gold only on own territory.
  * Added checking child powers availability when casting parent power.
  * Introduced config parameter to mark that a power is part of another power.
  * Added some new config options to keeper powers.
  * Modified code related to powers to mostly use new config struct and ignore old one.
  * Added possibility to hear dungeon heart beat by enemy creatures.
  * Modified line of sight function to check whether left part or right part is visible.
  * Modified creatures with owner who lost to no longer join another player when near dungeon heart.
  * Renamed RANDOM to DRAWFROM in new script commands.
  * Made warnings about excessive parameters in script commands.
  * Improved error reporting during script lines parsing.
  * Rewritten changing owner of creatures whewn unowned and near to dungeon heart.
  * Finished the completely new, much more complex implementation of RANDOM command.
  * Work in progress on more complex RANDOM script command.
  * Modified way of processing lines of config files. Moved RANDOM support to higher level.
  * Prepared for changing implementation of RANDOM command.
  * Made Special Diggers to not be counted to GOOD\_CREATURES and EVIL\_CREATURES amounts.
  * Implemented GOOD\_CREATURES and EVIL\_CREATURES variables in IF\_CONTROLS command.
  * Improved counting active diggers.
  * Added GoldPerHoard to config files.
  * Some unifications in processing lists of player creatures.
  * Commented CTA casting routine by comp. player.
  * Rewritten disabling CTA. Also made picked up creatures to be released from CTA.
  * Added two new script variables - EVIL\_CREATURES and GOOD\_CREATURES.
  * Decreased flight altitude recovering speed to 1/8 of creature movement speed.
  * Modified flying creatures height to slowly decrease any acceleration.
  * Made QUICK\_INFORMATION message flash when unread.
  * Fixed classic bug of keeping creatures in hand while heart is destroyed.
  * Modified destroying enemy ground to influence ownership of gold on that ground.
  * Rewritten growing food in hatchery.
  * Rewritten some of player zooming.
  * Rewritten some combat-related code.
  * Rewritten some code related to lairs.
  * Fixed invalid memory access when exiting torture screen while a door is opened.
  * Fixed killing multiple creatures by KILL\_CREATURE() script command.
  * Rewritten function used to move spells and traps when a room is being sold.
  * Rewritten computer player digging passage for new room.
  * Rewritten some of creature movement during combat.
  * Rewritten 2 combat-related functions.
  * Started work on Dungeon Keeper Independent Level Layout converter.
  * Rewritten checking unconverted drop place, and some of sacrificing.
  * Rewritten eat, fart and destroy wall instances.
  * Removed some of dependencies on specific reature model. Also resized array which breaks saved game compatibility.
  * Modified computer room building to stop if gold amount falls below 1000. Added property which disables this limit for specific rooms.
  * Fixed computer player to be able to stop build tasks when the room is no longer available. Also improved data structures initialization.
  * Fixed grouping creatures while possessing during barracking.
  * A few style changes. Also disabled screen capture keys on high score input.
  * Modified computer player dropping gold to treasury so that the gold is correctly added to wealth.
  * Modified drawing land view zoom to not draw central pixel twice. Also made exit on SDL initialization failure.
  * Completely replaced the view panning in land view screen.
  * Removed possible invalid write in land view screen.
  * Fixed a mistake in computer player pickup code.
  * Modified land view screen to zoom out from an ensign little towards the next ensign.
  * Updated attempting job in room to correctly support special temple terrain.
  * Unified hand dropping functions for human and computer player.
  * Made a few code unifications which shouldn't affect gameplay.
  * Fixed picking up gold by computer player. Also made unifications in power hand code.
  * Rewritten and updated drawing creatures in power hand.
  * Made important unifications in power hand pickup code. Made imps ignore dead bodies on enemy territory.
  * Rewritten checking if an imp will soon be working at given coordinates.
  * Rewritten shot collision code.
  * Modified Must Obey to allow assigning not-do jobs. Added classic bug to allow original behaviour. Also some unificatons in powers.
  * Modified bounding coordinates in land view screen to be more accurate. Also shifted exp level sprite for creatures in hand.
  * Extended collision detection between things to disallow passing through things which have very high velocities.
  * Rewritten drawing lightning power. Also fixed initiating tagged blocks and high score input.
  * Rewritten updating tunneller trail positions.
  * Rewritten GUI update function on creature instance selection.
  * Rewritten re-initiating tagged block flags.
  * Rewritten drawing lightning spell.
  * Rewritten creature standing on corpses code.
  * Fixed recently introduced issue with must obey spell.
  * Unified some of keeper powers code. Modified powers in cheat list to be free.
  * Fixed fighting with doors to not stop after one shot.
  * Updated room building to check possibility to build in unified way.
  * Rewritten some of imp reinforcing code.
  * Added flag DESTROYED\_ON\_ROOM\_PLACE to objects.
  * Rewritten creation of flame breath effects, and a few smaller functions.
  * Rewritten affecting things by wind spell.
  * Added utility functions to help with updating things near given map location.
  * Fixed shifted ceiling issue.
  * Rewritten selecting instance for door and object fight.
  * Placed more of keeper power properties inside config files.
  * Rewritten some of initial map exploration for players.
  * Modified shot collision to destroy both shots.
  * Started replacing hit target selection algorithm, to be based on flags instead of integer type.
  * Increased Dragon armour.
  * Defined HitTargetFlags which are supposed to replace HitType.
  * Modified wibble generation algorithm to produce same values as original game.
  * Replaced some checks by unified functions.
  * Increased size of creature health flower by one pixel.
  * Rewritten choosing lightning trap target.
  * Modified health flowers to scale with half the zoom rate. Also fixed creature tendency buttons to be always refreshed on tendency switch.
  * Fixed digging gold in possession to update counters; also did some updates in logging.
  * Nefred Horny, as he became too powerfull after last dexterity change.
  * Fixed typo in all creature config files.
  * Rewritten processing creatures in power hand. Made slap effect to wear off while in hand.
  * Modified followers positions selection to skip toxic tiles which leader can't step on.
  * Rewritten removing creature from group. Modified functionality to always keep highest level creature as leader.
  * Rewritten placing columns on changed slab.
  * Modified scaling of room ensigns to take similar height in high resolutions.
  * Modified party leader selection to be based not only on experience but also on score.
  * Rewritten creature eating code.
  * Updated campaign creation doc.
  * Modified fast speed parties to update followers positions more often, and slow speed parties to update them less frequently.
  * Unifications in the area of chosing thing to pick.
  * A few fixes which may affect a bug in trap crates handling.
  * Rewritten resetting creatures in room.
  * Modified imps to go to owners territory before toking.
  * Unified checking spell, trap and special pickability by diggers.
  * Modified room building to not auto-claim things not owned by the player - diggers have to move them.
  * Rewritten tagging place for room.
  * Modified wandering points selection to chose wander destinations more carefully. Also improved logging.
  * Modified lair fight to skip unconscious creatures. Also gave better names to some flags and variables.
  * Updated killing creature to not add target to resurrect list if it is being reborn.
  * Improved RANDOM() implementation to not crash on wrong parameters. Also removed few tries of accessing dungeon struct by non-existing players.
  * Updated trap triggers to not react on creatures kept in custody.
  * Removed excessive logging. Also minor update to scavenging.
  * Improved the creature being scavenged behavior so victim won't follow creatures he hates.
  * Made querying creature to not break its scavenging. Unified creature controlled checks.
  * Prepared functions to be later used for objects in room.
  * Updated BONUS\_LEVEL\_TIME() command to set timer from the game turn of trigger.
  * Moved some object properties to config files. Spellbooks put on rooms are no longer claimed with them.
  * Rewritten affecting creatures by alarm trap.
  * Updated Twin Keepers objectives to use strings from PO/POT files. Patch by Dayokay.
  * Rewritten counting and repositioning bodies in graveyard.
  * Moved a lot of traps and doors data into config files.
  * Rewritten affecting all players creatures by spells and killing all players chickens.
  * Rewritten creating effects around thing.
  * Rewritten disease function when creature is sick.
  * Rewritten computer player dig for attack task.
  * Rewritten some of computer players call to arms handling.
  * Rewritten treasure room integrating gold piles into gold hoards.
  * Modified computer player to not create two tasks which require power hand at the same time.
  * Rewritten waiting for wage behind closed doors. Also updated treasury handling and gold storing code.
  * Rewritten adding gold to hoard in treasury.
  * Improved room-related messages to use one, unified function.
  * Added more room config parameters. Modified placing items in rooms to check storage capacity instead of all used capacity.
  * Moved some of room parameters to terrain config file.
  * Fixed diggers to stop digging gems if there's a large enough gold pile near it.
  * Unified two of computer attack routines. Also fixed mistake in map collides code.
  * Modified room destroying code to disallow doing it on allies.
  * Rewritten the use of Make Safe special.
  * Fixed a mistake in dungeon area recalculation pointed out by Jelle Raaijmakers.
  * Rewritten revealing area by sight of evil.
  * Updated messages template for Twin Keepers campaign.
  * Rewritten hold audience spell use.
  * Rewritten decreasing creature health.
  * Fixed counting creatures which are joining the dungeon.
  * Rewritten creature grouping code. Fixed parties following tunnellers.
  * Rewritten adding leader to a party.
  * Rewritten eating code, and selecting best dungeon for tunnelling.
  * Modified changing health of all creatures to not use player-based listing.
  * Modified separation between GUI strings and Campaign strings to use the same function for string retrieval.
  * Unified health computation for rooms. Fixed health shown in room info ensign to show full health.
  * Fixed resurrect creature menu scroll when amount of creatures exactly fills the screen.
  * Moved dungeon special tooltips to config file. Also did some renaming.
  * Modified POWER\_HAND so that player can pick up creatures only when has that power.
  * Modified font drawing code to allow line breaking anywhere if there's no space in a long string.
  * Modified some places to use constant names instead of hardcoded values.
  * Implemented a few more creature statistics.
  * Moved relation between a spellbook and keeper power to config files.
  * Added spellbook to be used for possess spell.
  * Improved flight height code to take ceiling into account.
  * Modified posessing with shift to use standard arrow cursor when cannot possess the target.
  * Modified spell drawing for possession and casting over battle message to only use spell cursor when spell is available.
  * Config files update - reverted dexterity to original values and decreased change on the value with creature level.
  * Config files update - scaled down amount of damage to boulder, and reverted research values and manufacture levels to original DK.
  * Rewritten some of patrolling code.
  * Rewritten filling points in various view modes.
  * Modified possession to be only available when player has the spell.
  * Rewritten filling points in possession mode.
  * Fixed a triangle leak possibility on overflow.
  * Implemented per-campaign outro movie; also started work on intro movie.
  * Rewritten finding random rooms.
  * Rewritten generating creature from entrance.
  * Rewritten object sacrificing code.
  * Rewritten finding render gamut in isometric view and possession.
  * Rewritten drawing scaled textures in map zoom box.
  * Rewritten and fixed map fading.
  * Improved scaling of creature status clouds.
  * Updated reading magic config file to use effect names.
  * Modified moving to lair and temple to use random destination position.
  * Fixed multibyte font support in spell price.
  * Rewritten gold hoards management.
  * Implemented more of moving laying gold to treasury by computer player. Fixed cases of uninitialized variables.
  * Updates in scavenging and picking up. Also did some renaming.
  * Modified hero stealing code to be sure creatures from level are taken first.
  * Made instant re-computing of generation times after each SET\_GENERATE\_SPEED() script command.
  * Modified GUI scale factor to be right for 16:9 aspect ratio. Also removed some more references to original functions.
  * Improved checking whether creature can take gold or eat by dropping things on it.
  * Rewritten food eating code.
  * Fixed flying creatures to be able to adjust altitude. Updated default flight altitude.
  * Some unifications in Special Diggers tasks code.
  * Orig. campaign - allowed computer player to imprison enemies.
  * Orig. campaign - modified lv20 script to kill the first AVATAR if it's imprisoned.
  * Updated scripts to 2 original campaign levels.
  * Made ForceVisibility larger for some instances.
  * Fixed implementation of SET\_CREATURE\_FEAR\_STRONGER() script command.
  * Modified IF\_CONTROLS() script command to accept total amounts.
  * Fixed updating creature health during gameplay.
  * Fixed problem with minimap area being unclickable when minimap is not visible.
  * Updated creature health computation to better handle invalid values in config files.
  * Added more creature selection criteria to script commands.
  * Updated searching creature by job.
  * Implemented more of KILL\_CREATURE() command.
  * Level scripts - modified IF\_AVAILABLE() to accept creature, and added new IF\_CONTROLS() command.
  * Modified creature health computation to use pre-computed values more often.
  * Modified imp behavior to keep better balance between job and toking when low on health.
  * Added basic scroll bar clicking ability to all 4 lists in front end menus.
  * Rewritten leader obeying creature state.
  * Fixed parchment map zoom box to not move in parts when at bottom of the map.
  * Rewritten hero stealing code.
  * Rewritten finding nearest room with spare capacity.
  * Added infinite loop detection in some pathfinding functions.
  * Fixed creature statistics panel to show correct information and tooltips. Added new tooltips to english translation.
  * Decoupled spell damage from melee damage.
  * Improved armour computation.
  * Added the ability to normalize RMS while converting SFX files. Land descriptions are converted too.
  * Rewritten calculating intersection in pathfinding.
  * Pathfinding - rewritten retrieving waypoints from regions.
  * CqArctic campaign - modified script based ondarkkingkongman's patch.
  * Modified high score writing to keep information about beaten levels, overwriting duplicate entries if neccessary.
  * Fixed problem with invalid memory reads due to inprecise scaling of mouse pointer.
  * Fixed centering numbers in creature panel.
  * Modified dumping things from hand to violently drop them all only when heart is being destroyed.
  * Progressed the implementation of moving gold to treasury.
  * Fixed the network game problem with screen coords being transmitted instead of map coordinates.
  * Fixed centering on traps and doors when icon is right-clicked.
  * Rewritten drawing room ensign.
  * Fixed transfer creature and resurrect creature screens scaling.
  * Modified computer player code to drop picked up creatures on heart when intended drop fails.
  * Fixed drawing zoom box on minimap to show creature levels, and correctly centered sprites.
  * Fixed HitType of Grenade to allow it to affect objects, ie. move gold pots.
  * Updated context for some translations, and updated all languages to new english template.
  * Implemented mouse pointer scaling capabilities.
  * Added scaling to drawing ornated GUI window background.
  * Rewritten scaling in-game messages and compass on minimap.
  * Made rescaling of zoom window in full screen map.
  * Made rescaling network game screen.
  * Made scaling of swipes used is possession.
  * Implemented scaling of text in level list and services list.
  * Implemented rescaling of window frame in land view screen.
  * Fixed slider buttons support to deal with other buttons behind.
  * Added reset if wallhug navigation is damaged during tunneling.
  * Fixed problem with special crates being continuously rearranged in library.
  * Fixed possible problem with creature state being blocked at changing to/from chicken.
  * Rewritten drawing timer in bonus levels.
  * Rewritten almost all of GUI and minimap related functions.
  * Improved dropping trap and door crates, and spells, into appropriate rooms.
  * Created config parameter for toking health gain.
  * Rewritten drawing room info when room to place is selected.
  * Rewritten casting cave-in spell.
  * Rewritten updating creature models list for activities GUI list.
  * Updated manufacturing - if the workshop is missing place for crate, workers will take a break from manufacturing.
  * Rewritten picking up crates when digger is dropped at them.
  * Updated all translations from english template.
  * Updated room related messages to be more unified and match the situation.
  * Rewritten finding spellbook at drop site.
  * Added "room unreachable" messages in more cases - when treasury, prison or graveyard cannot be navigated to.
  * Updates and fixes to translations.
  * Finished integratingOGG music support made by Lukas Niemeier.
  * Fixed color ghost offsets in pannel minimap (reinforced walls and gold color).

Version: 0.4.5
  * Rewritten drawing the pannel minimap.
  * Rewritten a lot of network GUI routines.
  * Rewritten a few functions related to traps and shots.
  * Rewritten some of moods and needs processing. Allowed diggers to have moods and needs if their config file permits that.
  * Made creatures unable to teleport just after a battle.
  * Improved recognition between KINKY\_TORTURE and PAINFUL\_TORTURE jobs.
  * Rewritten payday processing.
  * Fixed restoring Flight spell state when creature is being dropped, or ends other state which prevented it from flying.
  * Started renaming 'job stress' to 'going postal'. Also rewritten some of scavenging.
  * Introduced ONE\_OF\_KIND creature property, for Avatar.
  * Introduced NO\_HAND\_PURGE\_ON\_DEFEAT classic bug.
  * Creature job first initialization remade to be configurable in creature.cfg.
  * Moved creature unconscious time to config file.
  * Changed concept behind job assigning to be based on job selection, not on room selection.
  * Work around for issues with multiplayer level number in level selection screen. The number is exchanged as 8-bit int, which should be correctly fixed when possible.
  * Unifications in creature jobs system. Also added definitions of a few more jobs.
  * Fixed directory listing to correctly use MS Windows API.
  * Fix for loading damaged saved game during another game.
  * Updated attraction score computations to include scores from all 3 rooms required to attract.
  * Updated Chinese translation.
  * Rewritten keeper powers update function.
  * Removed area of effect damage from lightning creature spell.
  * Modified ForceVisibility option to be in game turns.
  * Rewritten code of destroying a room with CTA. Modified it to get more random order of destroyed tiles.
  * Made new "room unreachable" event for lair.
  * Updated events when a spellbook or dungeon special is discovered or stolen.
  * Neutral boulder traps will now activate for any creatures other than neutral.
  * Moved several creatures from "United Kingdom" level to being triggered by script.
  * Added classic latin as recognized language.
  * Added friendly fire on area damage as config parameter.
  * Updated gold pots scaling algorithm. Pots are now generally smaller, and those with lots of gold are growing slower than small ones.
  * Rewritten boulder trap activation check. Spectators can no longer trigger boulder traps.
  * Added config option to select whether neutral creatures can be scavenged.
  * Fixed problem with creature strength not being increased with experience.
  * Armageddon no longer teleports neutrals by default.
  * Added rules option to disable affecting neutral creatures by armageddon.
  * Progressed the implementation of going through locked doors property.
  * Rewritten drawing plane of engine columns in isometric and clueo mode.
  * Added two new creature properties - FEMALE and INSECT.
  * Retwritten some GUI functions and creation of creature own name.
  * Added SDL\_mixer to pre-compiled libraries and to linking process. The library isn't used yet.
  * Rewritten the check if a creature can move directly to a place.
  * Rewritten the function which destroys creature lair.
  * Modified uses of apply\_damage\_to\_thing() so that the function is always informed about the type of damage being inflicted.
  * Rewritten and highly modified poison gas effect affecting creatures.
  * Made some improvements to creature movement system. Creatures will now reset their routes after being teleported.
  * Added fixing travel speed if the next travel point returned by ariadne is too far.
  * Rewritten and fixed picking up creatures based only on their job and not their model.
  * Removed some of references to manual from english translation.
  * Modified area damage to be applied on detonation of every shot.
  * Fixed problem with line of sight computation which caused word of power trap to not do any damage.
  * Started integrating OGG music support made by Lukas Niemeier.
  * Added Czech characters to European conversion table.
  * Made more advanced scaling of parchment view.
  * Renamed spells to start with SPELL_and shots to start with SHOT_.
  * Traps placed on strange terrain are now destroyed when depleted.
  * Added support of off-map traps and off-map doors.
  * Selling traps change - only get a refund if armed trap was sold.
  * Made computer player cancel any defend drops while his heart is ongoing destruction.
  * Introduced types of damage, ie. physical, magical, electric, combustion.
  * Rewritten some code related to gold and paydays.
  * Updated language names to meet ISO 639-2 standard. Japanese is now JPN.
  * Rewritten a lot of code related to workshop selling, to fix a bug in counting workshop items which are being sold.
  * Added states which cannot be blocked by spells - currently there's one, the being dropped state.
  * Modified battle event support to ignore the event if there are no enemies nearby.
  * Modified battle events to properly react on heart being attacked.
  * Added a new state which allows to attack doors and enemies while moving to attack room.
  * Rewritten door collision detection.
  * Rewritten some code around creature fights with doors.
  * Some minor updates to polish translations.
  * Fixed problem with magic door being recognized as sacrificial ground.
  * Updated russian fonts to be correctly included in multilingual font files.
  * Fixed problem with finding a creature dragging given thing.
  * Made kinky torture to not remove creature control.
  * Fixed problem with imps escaping from creatures behind doors.
  * Removed possible infinite loop in pathfinding, and enabled some rewritten routines.
  * Rewritten dungeon devastation when heart is destroyed.
  * Some serious changes in line of sight computation.
  * Computer players can now sell traps where they intend to place room.
  * Fixed imps transporting enemy creatures to drop them when enemy is defeated.
  * Fixed some possible problems related to creatures attack.
  * Rewritten some functions related to fight with doors and objects.
  * Forced creatures to become visible when dying or losing consciousness.
  * Fixed inconsistency in resetting states of creatures working in a room taken over.
  * Updated leaving or dying function (for defeated player creatures) to not wake unconscious creatures.
  * Rewritten some code related to dragging unconscious creatures.
  * Added regaining comp control when creature is called to arms.
  * Updated computer player gold digging code.
  * Updated room building code to prevent placing rooms on slabs with traps.
  * Fixed lava trap activation on room area to not break list of room slabs.
  * Added cleaning combat when computer player picks up creature.
  * Updated computer player digging path routine.
  * Updated Ancient Keeper translations, and added German translation.

Version: 0.4.4
  * Added auto-generating possession swipe sprites.
  * Update to foe identification algorithm; creatures being dropped can no longer be treated as enemies.
  * Fixed problem with battles not being dissolved.
  * Modified creatures with high fear to no longer start combat when invisible.
  * Modified imps to be less interested in dead bodies laying near living enemies.
  * Teleporting creatures are now a little more interested in staying in combat.
  * Unified coordinates computation and added scaling to parchment map screen.
  * Rewritten drawing things on round minimap.
  * Fixed the problem with backward move into negative Y direction.
  * Fixed problem with bitmap font while recording a movie which lasts several levels.
  * Changed the way trap-to-crate and door-to-crate association is stored.
  * Fixed mistake in code which caused creatures which are doing nothing to wander the dungeon.
  * Replaced the non-existing GROUP job with BARRACK for skeletons.
  * Rewritten drawing of list of things in hand.
  * Allowed computer player to move creatures to lair if they don't have one yet.
  * Rewritten large part of computer player room building code.
  * Updated ComputerTask structure - created unions which store task-specific parameters for each task.
  * Forced computer player to drop things from his "fake hand" when it's being disabled or defeated.
  * Created a function which fills dungeon position using room coordinates if no soul container is present.
  * Divided the map event 'fight' into two distinct events - friendly fight and enemy fight.
  * Rewritten computer player digging room. Modified checking if the room has been dug.
  * Changed order of land view narrations, and the folder where narrations are stored.
  * Modified workshop job to be stronger used when gold is low.
  * Rewritten computing ceiling height above set of subtiles.
  * Rewritten some of computer player CTA casting code.
  * Rewritten generation of map fade ghost color file.
  * Improved room expansion to never create long, narrow rooms.
  * Rewritten computer player selecting best digging path to entrance.
  * Added support of computer player selling deployed doors.
  * Completely changed the way of tracking amount of traps and doors available to be placed.
  * Fixed computer player expanding rooms to not include slabs with traps on.
  * Implemented selling placed traps by computer player when out of money.
  * Rewritten computer player placing bridge on dig path.
  * Rewritten some of computer player attack code and hatred computation.
  * Modified gold throwing code to never create too many pots, and to distribute the gold equally amongst pots.
  * Computer player now can use temple to heal disease, and puts much higher priority to training his creatures.
  * Fixed spell casting and slapping by computer player. Computer is now aware that imps may die when slapped.
  * Improved checking creature job availability when moving creatures by computer player.
  * Computer player will now less likely put his creatures to work in rooms with enemies.
  * Updated casting keeper powers on things - a specific thing is now selected based on castability settings.
  * Fixed computer player to stop dropping creatures in rooms which are in their not\_do\_job list.
  * Modified CREATURE\_AVAILABLE command to allow force-attracting creatures.
  * Fixed selection of random wandering position while exploring the dungeon.
  * Rewritten computer player digging to entrance. Made unifications to other digging operations.
  * Added checking for spell availability before they're used.
  * Rewritten computer player picking up imps in danger.
  * Several unifications in manufacture system and objects data.
  * Rewritten some functions related to computer player casting SoE.
  * Rewritten computer player casting spells on attackers.
  * Rewritten computer player casting speed spell on fighters.
  * Rewritten some of the sulking code.
  * Fixed distinction between AP number and AP index.
  * Original Campaign - fixed Mistle script to give the player only 3 boulder traps.
  * Rewritten drawing trap buttons; also renamed some variables.
  * Japanese DKMaps8 pack - Added messages to first map.
  * Rewritten a few functions related to battles and unconscious creatures.
  * Modified tunnelers ant tunneler parties to use the same method for storing spawn place and tunnel target.
  * Updated all .po translations of campaigns with their associated .pot template files.
  * Updated spell descriptions in translations and resaved them with POEdit.
  * Fixed unconscious creatures to no longer be attacked due to job stress.
  * Added possibility to load per-campaign creature.cfg file.
  * Added stats increase with experience as config parameters. Added different default values for Ancient Keeper.
  * Rewritten Anger Job selection.
  * Rewritten some of "persuade" anger job.
  * Rewritten some of Mad Killing code; updated mood routine to not allow mad creature to stop being angry.
  * Original Campaign - Updates to scripts of some more Deeper Dungeon levels.
  * Fixed creatures in livid state - they now stop working when very angry, as they should.
  * Original Campaign - reviewed and updated scripts for all levels.
  * Original Campaign - fixed bonus levels to use correct text messages.
  * Updated some more of multiplayer levels script files; only irrelevant changes.
  * Updated some of script files, mostly from multiplayer levels, but also from original campaign.
  * Generated .pot translation templates for 3 campaigns - pstunded, questfth, twinkprs.
  * Prepared translation files for "Conquest of the Arctic" campaign.
  * Documented some tools. Added a script which helps in creating .pot files for translations.
  * Rewritten traps creation routines.
  * Rewritten destroying a door.
  * Rewritten some of freezing prisoners code.
  * Fixed a mistake in trap placing conditions.
  * Rewritten computer player digging routine.
  * Rewritten some of picking up things code.
  * Rewritten searching for interesting neutral places by computer player.
  * Improved high score table input.
  * Rewritten color matching function which finds best color index for given RGB values.
  * Rewritten some of working in barracks and placing traps code.
  * Divided computer player door placement function to make it more clear.
  * Rewritten computer player search for enemy entrances and placing doors around rooms.
  * Some unifications in functions relatedto moving in rooms.
  * Rewritten a torture-related function.
  * Renamed job TEMPLE to TEMPLE\_PRAY.
  * Fixed bug with not being able to manufacture resulting in not being able to pray.
  * Fixed problem with sell button being shown incorrectly when mouse button is kept down on it.
  * Minor renaming which affect quite lot of files.
  * Rewritten a missing part of FLI files creation; also updated memory management routines.
  * Activated some of rewritten sound handling code.
  * Rewritten some GUI-related routines.
  * Fixed some potential problems with config files parsing.
  * Fixed problem with invalid value casting causing long wait in creature doing nothing state.
  * PngPal2Raw - Finished support of JTY files, fixed for better error handling.

Version: 0.4.3
  * Rewritten some of creature tunneling code and position computation when tunneling.
  * Rewritten some of heroes attacking rooms and dropping gold code.
  * Rewritten moving creatures in workshop.
  * Rewritten the function which controls sending creatures to rooms, moved options to config files.
  * Rewritten the function which controls creature behaviour while it's idle.
  * Rewritten waiting for combat (random jumps) code.
  * Rewritten the function which creates Action Points.
  * Added spaces to Japanese translation.
  * Updated the function which defines game keys to accept ALT modifier.
  * Rewritten "define keys" screen.
  * Rewritten drawing the creatures list in Transfer Creature special.
  * Fixed a possible crash while drawing a sprite with very large scale.
  * Rewritten the function which controls revealing terrain by a creature.
  * Updated power hand pickability code. Added function which checks if a creature is dying.
  * Fixed problem with floating spirit spell being inactive and controlling floating spirit.
  * Rewritten some functions related to computer player tasks.
  * Rewritten some of creature manufacture task code.
  * Rewritten creating a creature at dungeon heart.
  * Allowed turning alliances on and off.
  * Rewritten selecting imps for pickup by computer player.
  * Rewritten selecting creatures for defensive drop by computer player.
  * Upgraded the code used for killing creatures. Created cases when not adding to resurrect list.
  * Rewritten a bit more of computer checks code; fixed a coding mistake which caused a crash.
  * Improved damage projection. Also, made better Dexterity and Defence explanation in config files.
  * Rewritten some of keeper sprites loading and handling code.
  * Fixed tunneller being unwilling to attack sometimes.
  * Fixed the problem with fairies being stucked in the ceiling. They will now lower the flight.
  * Replaced binary cubes config file with text one.
  * Modified some config files to make the game more similar to original DK.
  * Introduced per-campaign config files for Ancient Keeper. Also removed unused credits file.
  * Modified checking if creature will attack another to make sure creatures in prison won't be attacked.
  * Fixed the problem with computer player not building new room if it already has such room with low capacity.
  * Modified fear computation to prevent excessive fluctuation of behavior.
  * Fixed problem with digging gems consuming most all of computer player workforce.
  * Rewritten some of computer player moving creatures code.
  * Improved searching for a hatchery when creature is hungry.
  * Rewritten several computer player routines related to room building.
  * Added automatic creation of a few RAW files from PNGs.
  * Rewritten some of computer building rooms code.
  * Rewritten searching for food. Added another condition of "no food" event.
  * Own creatures fight is no longer causing casting CTA and moving creatures by computer.
  * Combat with unconscious creature is no longer a valid combat.
  * Rewritten creature moving routine and some of prettying code.
  * Workaround for allowing to spawn special workers with fly ability.
  * Rewritten loading frontend sprites. Modified general sprites loading function.
  * Updated spanish language, and building of graphics files.
  * Updated building of GUI DAT/TAB files. Also removed casting Destroy Walls on rock.
  * Modified config to allow casting speed spell on creatures held in custody.
  * Rewritten part of creature fighting code.
  * Rewritten two important functions in pathfinding.
  * Rewritten some creature instance callbacks.
  * Launchwx - Removed a few unused or auto-generated files from KeeperFX installation
  * PngPal2Raw - created loading of TXT animation lists for JSPR(JTY) format support.

Version: 0.4.2
  * Launcher updated with additional options
  * More graphics data files are created from PNGs
  * Made Slap spell do be added to a player by default
  * Created new options for preserving classic bugs
  * Fixed invisible mouse cursor when leaving multiplayer game
  * Fixed fading while traveling through the menu
  * Fixed error in defensive spells code
  * Also increased WIND instance reload time
  * Rewritten creature hatchery search while hungry
  * Improved accuracy of angle-to-position calculation
  * Unified computing whether a thing can be affected by a creature spell
  * Rewritten the Destroy Walls spell
  * Removed the possibility of ice explosion death for creatures which do not bleed
  * Added more config options in rules file
  * Improved adding re-arm tasks to imp queue
  * Rewritten engine perspective rotation
  * Retwritten movement while working in temple
  * Rewritten some data structures related to possession swipe effects
  * Fixed not allowing 2 trap boxes on same subtile
  * Increased the push effect caused by explosion
  * Reduced explosion range for friendly creatures to 1/3 of normal range
  * Rewritten spell casting from within battles list message
  * Rewritten and unified magic cast checking
  * Moved some job properties to config files
  * Rewritten footstep sounds playing
  * Rewritten functions which draw scaled sprites
  * Rewritten some of checking for imp jobs
  * Fixed and re-enabled the new pathfinding code
  * Rewritten some imps tasks which make use of pathfinding routines

Version: 0.4.1
  * Updates to land view screen
  * Integrated Post Undead Keeper campaign
  * Integrated Conquest of the Arctic campaign
  * Fixed a problem with making non-existing player an ally
  * Improved line of sight computing
  * Many updates to digger tasks code
  * Remade magic maintenance
  * Introduced a new way of determining where a spell can be casted
  * Hero player isn't allowed to be set up as computer player
  * Integrated Undead Keeper campaign
  * Remade dungeon heart fight selection
  * Fixed the problem with computer player placing traps at invalid places
  * Rewritten displaying the heart flower and anger level above a creature
  * Rewritten a part of computer player tasks code
  * Fixed the definition of keeping creature in enemy custody
  * Any player now automatically drops all things in hand while his heart is exploding.
  * Fixed issues with spell being in Library at start of a level
  * Rewritten lot of code around room maintenance
  * Introduced tools which allow to easily create land views from PNG files (Png2bestPal,PngPal2raw)
  * Introduced tools to translate campaigns with use of .po/.pot files (Po2ngdat)
  * Prepared .po/.pot files for all the campaigns which have national messages
  * Rewritten and modified some lightning-related routines
  * Rewritten the function which computes amount of hate computer player has towards other players
  * Rewritten large part of scavenging code
  * Rewritten some code related to needs of creatures
  * Moved some of room and slab properties into terrain config file
  * Rewritten line of sight computation
  * Some modifications to fighting doors
  * Rewritten part of color tables generation
  * Rewritten part of temple summoning code
  * Rewritten and unified the way of searching for things around given coordinates
  * Fixed playing level intro/victory speech multiple times
  * Creatures are now picked by level only with CTRL, and normally they're picked unordered
  * Rewritten hero tunnelling code
  * Statistics screen will now show asian languages correctly
  * Fixed error with invalid screen showing after playing some of DD levels
  * Association between lair object and creature is now moved to config file
  * Added new creature properties
  * Rewritten dropping creature from hand
  * Improved config files for objects and for magic
  * Updated clipping of map coordinates
  * Rewritten the function which handles trap update
  * Updated functions used for updating positions of things
  * Rewritten putting traps by computer player
  * Rewritten the function used for claiming enemy rooms
  * Improved WOP trap to use the same explosion routine as WOP spell
  * Prepared a mechanism to preserve some of classic DK bugs
  * Replaced fear computation algorithm, introduced 3 factors related to fear
  * Rewritten a lair creation routine
  * Rewritten the research process routine
  * Rewritten and improved large part of battle mechanics.
  * Fixed problem with line pitch setting for some rare video modes
  * Rewritten a few routines related to gold gathering
  * Integrated The Destiny of Ninja campaign
  * Fixed truncated water drip effect
  * Fixed multiplayer landview to use ENSIGN\_ZOOM
  * Fixed one of rendering routines to be more stable in high resolutions
  * Rewritten spawning heroes
  * Fixed error with drawing creature who is being sacrificed
  * Fixed max zoom problem in very high resolutions
  * Rewritten the keeper sprite drawing function
  * Rewritten creation of shot hit effects

Version: 0.4.0a
  * Renamed 'debug version' to 'heavylog version'
  * Allowed making 'debug' version which is really with debug info

Version: 0.4.0
  * Prepared game launcher with installation function
  * Updated some internal mechanisms, ie. columns finding
  * Made small revolution in the zooming system
  * Rewritten the green/red cube (map volume box) drawing
  * Fixed engine window center to be on screen center
  * Introduced new config file - creature states config
  * Improved room efficiency calculation
  * Rewritten a few more routines related to workshop
  * Fixed the sound emitter cleanup code
  * Rewritten revealing map due to torture
  * 
Version: 0.3.9a
  * Updated compound eye effect for high resolution
  * Fixed the problem with Dungeon Heart background sound
  * Updated reading keyboard in front view, also named some constants
  * Fixed creature death kind "ice explosion" when creature is frozen
  * Fixed shadows and lights affecting things
  * Fixed distance computing required for certain shots to hit target
  * Fixed imps to continue their jobs after they finish a part of it

Version: 0.3.9
  * Fixed the v0.3.8c bug with freeze on computer digging for gold
  * Updated frontend menus code, some changes in network related menus
  * Updated creature statistics in Ancient Keeper
  * Disabled another pathfinding routine
  * Rewritten picking up trap box to fill trap
  * Rewritten routine which draws things on the parchment map screen
  * Added zombie players; uninitialized players are initied as zombies
  * Rewritten dead bodies rotting code
  * Rewritten searching for dead bodies by imps

Version: 0.3.8c
  * Fixed the v0.38b bug with computer keeper not digging for gold
  * Rewritten some of imps and workshop related code
  * Rewritten some of imp tasks code and gold counter

Version: 0.3.8b
  * Updated scripts for some maps
  * Fixed killing a creature which has an armour spell casted on
  * Improved some debugging messages
  * Rewritten some of entrance generation code
  * Fixed bug in hero attacking creature code
  * Fixed losing things due to lights overflow
  * Rewritten shot reaching its target
  * Added boulder immunity to creature config files

Version: 0.3.8a
  * Added mouse sensitivity modification option
  * Fixed crash on invalid movies video mode
  * Fixed problem with creatures standing next to lair
  * Fixed error in the new rooms merging algorithm
  * Linked with MinGW libraries as static
  * Fixed problem with no price when selling traps
  * Changed tunneler "relax" sprite to the one with sleeping

Version: 0.38
  * Switched video support library to SDL
  * Fixed duplicates level when using Multiply special
  * Created some 64-bit math, similarly to original code
  * New pathfinding code has been disabled (needs debugging)
  * Dutch land introductions were added to 3 campaigns
  * New graphic modes - any colour depth is now supported
  * New graphic modes - windowed mode is now supported
  * Rewritten more of creature state machine
  * Added more options to CFG files
  * Experimental TCP/IP multiplayer support

Version: 0.37c
  * Fixed dungeon heart blinking if under mouse
  * It is now easier to target a creature for pick up
  * Fixed disappearing in-game speeches
  * Computer player config is reloaded on saved game loading
  * Fixed possible hang when computer player moves creatures
  * Added new creature property, "NEVER\_CHICKENS"
  * Rewritten more of pathfinding
  * Rewritten creature training code
  * Renamed and rescaled "PartnerTraining" (was "RealTraining")
  * Fixed linked list storing creatures who work in a room
  * Updated room selling code

Version: 0.37b
  * Fixed crash on freeing swipe sprites at end of mission
  * Fixed SEEK\_THE\_ENEMY job (Hellhound)
  * Fixed crash when zooming in isometric (non rotable) view
  * Fixed Imps aimless walking around bug
  * Fixed invalid celebration sprite bug
  * Video modes in config file are no longer pre-defined

Version: 0.37a
  * Fixed gems appearance bug
  * Fixed selling bug
  * Fixed per-campaign creatures config bug

Version: 0.37
  * Rewritten computer tasks list
  * Added palette stealing protection to video driver
  * Rewritten some of creature fighting code
  * Rewritten enemy seeking code for heroes
  * Fixed green volume box height in clueo (low walls) mode
  * Rewritten gold stealing code
  * Remade some creature spells code
  * Remade some of imps AI code
  * Remade and fixed some of Ariadne pathfinding system
  * Campaign list is now sorted
  * Imp tasks selection rewritten
  * Creature sprite indexes are now in .CFG files
  * Campaigns can now have their own creature config files

Version: 0.36
  * Rewritten some of room sound playing
  * Modified saved games format (old saves won't work anymore)
  * Saved game can now be loaded even if loading campaign file fails
  * Improved handling of player index errors
  * Improved BONUS\_LEVEL\_TIME() script command
  * Remade part of creature states system

Version: 0.35
  * Rewritten shot throwing code (for both melee combat and spells)
  * Rewritten some of Dungeon Heart behaviour
  * Programming IDE switched to Eclipse for C++
  * New Makefile and project structure - easier to recompile
  * Rewritten and fixed Word of Power damage code
  * Rewritten missing function for new way of storing bonus levels
  * Rewritten more of eye lenses code, updated lenses config file
  * Eye lenses now supported in all resolutions
  * Rewritten part of scavenging code
  * Rewritten part of the polygon rendering code

Version: 0.34
  * Some fixups in CPU Identification code
  * Fixed Imps sacrifice code
  * Text drawing functions remade
  * Fixed CTRL+Arrows keys support
  * Fixed transfer creature bug
  * New way of storing bonus levels availability
  * Fixed spell cursors when playing player > 0
  * Fixed sacrifices when playing player > 0
  * Asian languages support reached alpha stage
  * Shift+M key now works in high scores screen
  * Fixed incorrect memory write on creature suicide

Version: 0.33
  * Rewritten creature killing code
  * Improved creature config files
  * Tooltip drawing code improved
  * Remade another part of network support
  * Improved logging system
  * Creature states are now defined outside DLL
  * Fixed checking for gold bug (gold digging by computer)
  * Changed Video and Mouse driver - EXPERIMENTAL
  * Added '-altinput' command line parameter
  * Rewritten digging and claiming effects
  * Rewritten part of imp tasks management
  * Rewritten and extended creature sacrifice recipes
  * Censorship no longer bounded to german language

Version: 0.32
  * Added CPU identification
  * Rewritten part of spell casting code
  * Rewritten some of 'Transfer creature' code
  * Rewritten some possession-related code
  * RANDOM can now be used instead of most values in script
  * Remade part of 'player instances' code
  * More cheat options, like 'Everything is free', now works
  * Created .LOF Level Overview Files, levels.txt no longer used
  * Started replacing network support

Version: 0.31
  * Fixed disappearing creatures in zoom box
  * Updated zoom level for various resolutions
  * Rewritten even more of Hand Of Evil support
  * Rewritten heap support for sound and speech samples
  * Replaced CREATURE.TXT with multiple .CFG files.
  * Rewritten network GUI functions
  * Changed RESEARCH and added RESEARCH\_ORDER commands

Version: 0.30
  * Fixed Hand Of Evil support code
  * Added range to 'REVEAL\_MAP\_LOCATION'
  * Campaign files improved (file locations, options)
  * Some more unification in accessing array elements
  * Rewritten some network support functions
  * Rewritten credits screen, added credits file

Version: 0.29
  * Added new script command, 'REVEAL\_MAP\_RECT'
  * Added new script command, 'REVEAL\_MAP\_LOCATION'
  * Hand of Evil code has been rewritten
  * Fixed memory leak in keeper AI module
  * Fixed problem with 'IF\_AVAILABLE' command
  * Added support of multiple campaigns (not tested)

Version: 0.28b
  * Rewritten more of script support, warnings added
  * Added new script command, 'PLAY\_MESSAGE'
  * Added new script command, 'ADD\_GOLD\_TO\_PLAYER'
  * Added new script command, 'SET\_CREATURE\_TENDENCIES'
  * Finished work on QUICK script commands support
  * Fixed spells visibility in zoom box of map view
  * DISPLAY\_INFORMATION now requires two parameters (added zoom location)
  * QUICK\_INFORMATION now requires three parameters (added zoom location)
  * When selling multiple traps on same tile, total cost is displayed
  * Text file is now selected based on language setting in "keeperfx.cfg"
  * Fixed room selling (v0.28a)
  * Fixed wage and luck value displayed in creature info panel (v0.28a)
  * Fixed typing mistake in hero party objectives (v0.28b)
  * Fixed ALL\_DUNGEONS\_DESTROYED implementation error (v0.28b)

Version: 0.27a
  * Rewritten most of the world view screen
  * Allowed map numbers over 255
  * Fixed mistake in function create\_room
  * All levels are available when whole campaign is passed
  * Campaign configuration file improved
  * LIF files support adopted from Deeper Dungeons
  * Free level selection screen adopted from Deeper Dungeons
  * New High Scores support code
  * Strings (text.dat) replaced with those from DD (dd1text.dat)
  * Script command QUICK\_OBJECTIVE is now supported
  * Compiled under new MinGW environment
  * Some functions of Cheat Mode are now functional
  * Continue file creation code unified and improved
  * Started work on support of QUICK\_INFORMATION command
  * Fixed mistake in trap manufacture code (v0.27a)

Version: 0.26
  * Rewritten minimap control code, fixed for 640x480
  * Smarter WLB flags regeneration
  * Rewritten part of 'player instances' code
  * Better memory cleaning after a level is finished
  * Bonus levels are preserved in 'Continue game'
  * Transferred creature is preserved (for one use only)
  * Fixed disappearing menu content problem
  * Fixed ending statistics when finishing loaded game
  * Computer player config file created

Version: 0.25
  * Fixed information button blinking
  * Rewritten part of the rendering engine
  * Fixed mouse cursor shift and scrolling at 640x480
  * Added options to save and load replay (packet file)
  * Alt+X can now be used to quit the game
  * Files created by the game are no longer read-only
  * Rewritten loading of map files

Version: 0.24
  * Rewritten level script analysis
  * Added warning and error messages on script loading
  * Allowed longer messages in script
  * Patched DISPLAY\_INFORMATION\_WITH\_POS
  * Fixed problem with CFG file location
  * Rewritten 'landscape affecting creature'
  * Added comments to CFG file

Version: 0.23a
  * Fixed time counter sound in bonus levels
  * Fixed bad memory read in creatures tab code
  * Created a campaign file which stores level numbers
  * More error-safe config file support
  * More inputs left when lost (screnshot, minimap zoom, etc.)
  * Renamed campaign file to load properly (the .23a release)

Version: 0.22
  * Reworked more of the packets processing system
  * Prepared screen resolution ring
  * Fixed problem with floating spirit on lost level
  * Screenshots now work not only in game, but also in menu
  * Improved quality of in-game map screen
  * Fixed a 'sudden speedup' problem when playing > 50 minutes

Version: 0.21
  * Video compression improved for high resolution
  * Added command line option to change player in skirmish
  * Added function of writing screenshots in BMP format
  * Reworked part of the packets processing system
  * Config file separated from original DK

Version: 0.20
  * Message will show if a command line option is wrong
  * Updated delay function to not use 'hlt' command
  * Fixed object tooltips to show when mouse is on something
  * Fixed load slots counting error from v0.19
  * Rewritten GUI initialization arrays
  * Rewritten and fixed movie recording
  * Allowed to record movie in high resolution

Version: 0.19
  * Rewritten GUI events system
  * Rewritten some easter eggs
  * Fixed music support problem from v0.18
  * Game will try to continue if can't enter low-res mode
  * Compiled using new version of GCC

Version: 0.18
  * Rewritten frontend state control and menu speed
  * Added high resolution loading screen
  * Renewed video playing code and fading

Version: 0.17
  * Rewritten main loop and game speed control
  * Fixed screen object destructor
  * Rewritten part of mouse support
  * Made exit possibility when playing with '-level' option

Version: 0.16
  * Finished logging module and log file creation

Version: 0.15
  * Reworked the main initiation function
  * Added introduction screen by Madkill

Version: 0.14
  * Added some command line options from Beta
  * Reworked moon phase calculation

Version: 0.13
  * LbBullfrogMain() reworked
  * Command line parameters reworked and fixed a bit

Version: 0.11
  * Managed to make the DLL working (at last!)