# Adding new language #

KeeperFX supports many languages - all of them are mentioned in README file. If the language you want to add is within that list, then it is supported - you should look at [how to generate a new language file for a campaign](NewTrans.md).

If the language isn't supported, it requires some programming to add the support. Go to the [KeeperFX Issues](http://code.google.com/p/keeperfx/issues/list) page and click ‘New Issue’ (top left of screen). Choose ‘Enhancement Proposal from User’ from the dropdown menu, and enter the relevant details in the form where you can. Ask if someone is willing to add the new language. If there are national characters in that language, or it has other rules which seem relevant, state them in the description.

Sooner or later, a programmer will read your issue and answer it. In the meantime, you may start translating the game, you just won't be able to test your changes until the support is added. Read [how to generate a new language file](NewTrans.md) for details.

If you think some national characters won't be available in KeeperFX, you should still use them inside your translation - if the char will be missing, automated tools will replace characters with closest english equivalent. This way, when the character will be added to KeeperFX bitmap fonts, the translation won't need any fixing.