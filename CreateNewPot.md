# Making new levels with future translation in mind #

While making levels, you do not necessarily want to start with all messages in .pot files. It is much more convenient to keep all the messages inside your level script file. Later, when your campaign is almost ready, you can easily export all strings to .pot file, in a partially automated way.

So, it is best to use `QUICK_INFORMATION()` and `QUICK_OBJECTIVE()` for displaying messages while creating levels. Just remember to use `QUICK_*()` commands for all the messages - don't mix them with `DISPLAY_*()`, as that would make automating .pot file generation much harder.

# Creating new translation template #

To make a new translation template, it is best to start with an existing .pot file from another campaign, like [the one from Burdened Imp campaign](https://code.google.com/p/keeperfx/source/browse/trunk/keeperfx/lang/burdnimp/text_eng.pot).

Open the file in any text editor (ie. Notepad under Ms Windows) and replace strings with the ones from `QUICK_*()` commands in your script. Keep string 0 (marked `guitext:0`) intact - it's a message shown after winning a level. Use strings 1..200 for your objectives and infos, then strings 202..225 for your level names - that would keep the convention used in other levels. Group unused message numbers under the "Moo" string - there shouldn't be missing string other that `guitext:201` (and leave this one missing - it is by purpose an empty string). Note that this part of work can be automated - see the next chapter for details.

After the .pot file is ready, comment out all the `QUICK_*()` commands in your scripts and insert `DISPLAY_*()` commands below, using the same message numbers you've assigned to each string in .pot file with `guitext:`.

To convert .pot file to .dat, follow [conversion instructions](ConvertPoToDat.md).

# Automating extraction of strings to translate #

There is a [script in KeeperFX code repository](https://code.google.com/p/keeperfx/source/browse/#svn%2Ftrunk%2Fkeeperfx%2Ftools%2Fcampgn2pot) which allows fast generation of .pot file based on `QUICK_INFORMATION()` and `QUICK_OBJECTIVE()` commands within levels.

After your levels are ready, run this script under Unix shell (ie. any Linux distribution, or on Windows with MinGW installed). This will create a .pot file automatically. You will still have to do a few modifications to it - it will contain only strings from your levels, so will lack some of the strings for spells, rooms, creatures etc. You may copy and paste that missing part at end of file from any other campaign .pot file.

If you don't know how to use that script, ask a programmer to do so - ie. by creating a request in KeeperFX issue tracker, and attaching an archive with all your levels to it.

After .pot file is ready, you still have to replace `QUICK_*()` commands with `DISPLAY_*()` in all your scripts - that part is not automated.

## Testing the results ##

After you've made a few strings, you may want to check how the changes look inside the game. This is not trivial, as KeeperFX needs translation to be converted to `.dat` format before use in the game.

If the translation is to be added to official KeeperFX builds, then send it to developers, and you will soon be able to see the results in new [Nightly Builds](http://keeper.lubiki.pl/html/dk_keeperfx_nightly.php). But if you'd like to integrate the changes to the game by yourself, you need to [convert the file to `.dat` format](ConvertPoToDat.md).