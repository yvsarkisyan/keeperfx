# Modifying English language template #

While .po file have a great tool to create, update and edit them, the .pot files do not have such editor. The best way is to open them in your favourite text editor and make changes there.

Remember to use simple text editor, which will not support text formatting, and will not break syntax of the .pot file. Notepad or MadEdit are both a good choice; don't use Ms Word.

## Testing the results ##

After you've made a few corrections, you may want to check how the changes look inside the game. This is not trivial, as KeeperFX needs translation to be converted to `.dat` format before use in the game.

If you'll send the translation to developers, you will soon be able to see the results in new [Nightly Builds](http://keeper.lubiki.pl/html/dk_keeperfx_nightly.php). But if you'd like to integrate the changes to the game by yourself, you need to [convert the file to `.dat` format](ConvertPoToDat.md).