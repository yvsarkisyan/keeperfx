# Correcting A Translation #

You may have played a campaign, and noticed an error, or a poor translation, and want to fix it. You can do this quite easily.

You will need [POEdit](POEdit.md) (open-source translation tool) to do this.

## Getting the files and tools you need ##

Go to [Language folder in KeeperFX source code tree](http://code.google.com/p/keeperfx/source/browse/#svn%2Ftrunk%2Fkeeperfx%2Flang%253Fstate%253Dclosed) and you will see a list of the language files for the original campaign. Expand the menu on the left (click the triangle next to `‘lang’`) and the various KeeperFX campaigns will be visible. Select the campaign, and find and click to show the .po file for the language you wish to correct.

Then right-click on ‘save target as’, and download the file `‘text_xxx.po’` (where xxx is the language you wish to translate into). Also download the English template file, which is usually text\_eng.pot

Download [POEdit](POEdit.md) from its [official site](http://www.poedit.net/download.php).

## Updating translation ##

Start the POEdit software and choose ‘edit a translation’, and when prompted open the `text_xxx.po` file for the language you wish to amend.

You are now able to make changes, but before correcting any translations, go to:

`Catalogue -> update from pot file`

And when prompted, choose the text\_eng.pot file. When complete, this will highlight all pre-existing changes needed for the translation file, as it may have been changed since the first translation.

## Testing the results ##

After you've made a few corrections, you may want to check how the changes look inside the game. This is not trivial, as KeeperFX needs translation to be converted to `.dat` format before use in the game.

If you'll send the translation to developers, you will soon be able to see the results in new [Nightly Builds](http://keeper.lubiki.pl/html/dk_keeperfx_nightly.php). But if you'd like to integrate the changes to the game by yourself, you need to [convert the file to `.dat` format](ConvertPoToDat.md).