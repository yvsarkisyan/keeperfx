# I want to add a translation for a campaign #

These instructions assume that:
  * an English version of the campaign file is available
  * the target language is already a supported KeeperFX language (there are official campaign translations)

You will need [POEdit](POEdit.md) (open-source translation tool) to do this.

## Getting the files and tools you need ##

Go to [Language folder in KeeperFX source code tree](http://code.google.com/p/keeperfx/source/browse/#svn%2Ftrunk%2Fkeeperfx%2Flang%253Fstate%253Dopen)  and you will see a list of the language files for the original campaign. Click on the file of the language you wish to use - `‘gtext_xxx.po’` (where `xxx` is the language you wish to translate into). If there's no .po file for your language, then you'll have to create it from .pot file - click `‘gtext_eng.pot’`.

After the file is clicked, you will see its content on the left, and a small toolbar on the right. Right-click on ‘View RAW file’ in that toolbar, and download the file.

Similarly, download the `.pot` file for the campaign you wish to translate. If it is an official campaign within KeeperFX, go to [Language folder in KeeperFX sources](http://code.google.com/p/keeperfx/source/browse/#svn%2Ftrunk%2Fkeeperfx%2Flang) again, expand the folder view on the left hand pane and download the right file. If it is a campaign which isn't shipped with KeeperFX, then you’ll need to have the English template (`.pot` file) from the author(s).

Download [POEdit](POEdit.md) from its [official site](http://www.poedit.net/download.php).

## Preparing initial translation ##

Open the `‘gtext_xxx.po’` file in POEdit. From within the program choose:

`Catalogue -> update from pot file`

and select the .pot file you've downloaded. Accept the changes listed by POEdit.

POEdit will now have highlighted all the campaign specific messages that need the new language scripts. You are now ready to start translating. Save the new `.po` file giving it different name, for example `‘ancntkpr_rus.po’`.

## Translating ##

Translate the highlighted messages into the new language, either all at once, or some at a time.

When the file is completed, you have to send it to KeeperFX developers. You may either create an enhacement proposal in [KeeperFX tracker](https://code.google.com/p/keeperfx/issues/list), or e-mail it to a developer (ie. [Mefistotelis](http://keeper.lubiki.pl/html/contact.php)) for inclusion in the campaign.

## Testing the results ##

If you'll send the translation to developers, you will soon be able to see the results in new [Nightly Builds](http://keeper.lubiki.pl/html/dk_keeperfx_nightly.php). But if you'd like to integrate the changes to the game by yourself, you need to [convert the file to `.dat` format](ConvertPoToDat.md).

## Problems ##

**I can't find the .po file for my language.**

_Your language may be not yet supported by KeeperFX. Create an issue in "Issue tracker" describing the situation._

**I can't find the .pot file for the campaign I want to translate.**

_Some campaigns do not have translations, because they don't have any in-game messages. If you're not sure, you can always raise an issue asking for help._