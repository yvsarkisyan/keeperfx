# In-game Texts & Language Support #

In KeeperFX, each campaign has a .dat file for each supported language. This contains the in-game messages, which are in 2 variants:

  * Objective. Appears at the bottom of the screen in-game. There is one at the start of the game, and the final one is usually something like _"Success! This Land is Yours. Press Space to proceed to the next realm."_. There are often more posted during the game, each replacing the previous one.

  * Information. Is a text message in a box, very similar to Objective. When triggered, Information is visible via flashing 'i'. You may have several Information messages visible at once - they will not replace each other, but will stack. Each Information has a limited lifespan after it's been read, and will disappear after some time.

Both these message types are sent via the level script file (`map00xxx.txt`), specific to each map. The script calls a message from that language's `.dat` file (e.g. `text_eng.dat`).

In KeeperFX .dat files are generated via

  1. `.pot` files which are template English language files
  1. `.po` files which are translations of that campaign's `.pot` file

KeeperFX uses the `.pot` and `.po` files to generate the language specific `text_xxx.dat` files for each campaign.

As well as in-game messages, the `.dat` file also contains all the other information needed by the game for a specific language. The game produces tooltip messages whenever you point at an object, room, thing, creature etc in the game, and these also come from the `.dat` file. Hence it is wise to use a pre-existing file, usually from the original campaign, and modify that to generate new content.

## Options ##

  * [I want to correct errors in a non-English translated file](CorTran.md)
> Click the above link if you have played KeeperFX and noticed badly translated messages, or missing and/or nonsensical messages, and wish to correct this.
  * [I want to generate a new language file for a campaign](NewTrans.md), where support for that langauge doesn't currently exist.
> Read inside the above link if you have noticed that a particular language (that is supported by KeeperFX currently, i.e. other campaigns have this support) is not supported for a particular campaign. You wish to add this language.
  * [I want to add a new language to KeeperFX](NewLanguage.md)
> Select the above if you want a new langauge added to KeeperFX, one which doesn't currently exist in any campaign.
  * [I want to make changes to the English language template for a campaign](ModifyExistingPot.md)
> Click the link if you have noticed errors in English messages, or want to add more messages to a campaign.
  * [I want to generate in-game messages for an in-progress new campaign](CreateNewPot.md)
> Use the above if you are making a new campaign for KeeperFX and want the format to support multiple languages (either on publication, or in the future).
  * [I want to convert existing `.po` or `.pot` into `.dat` format](ConvertPoToDat.md).
> This will only explain you what to do if you have a `.po` or `.pot` file and want to integrate it into the game.

## Notification ##

For all these types of changes, it is advisable (but not compulsory) to give notice that you intend to make a change / changes. Go to the [KeeperFX Issues](http://code.google.com/p/keeperfx/issues/list) page and click ‘New Issue’ (top left of screen). Choose ‘Enhancement Proposal from User’ from the dropdown menu, and enter the relevant details in the form where you can. Make it clear that you intend to do this work, and are notifying the community of your intent. Press submit when done (you may need to enter a ‘captcha’ code at this stage as a simple security measure)

It is a good idea to do this to prevent duplication of effort (i.e. someone else might do the same work!). Another advantage is that if you embark on a translation, but you can’t complete it, you can upload your latest progress into this site, and someone else can download your latest work and complete it.