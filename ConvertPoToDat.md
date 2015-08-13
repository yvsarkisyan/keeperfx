# Converting `.po` or `.pot` file into `.dat` format #

KeeperFX cannot read `.po` or `.pot` files directly. These formats are used to help with translations, but then have to be converted into a format which the game engine supports, which is `.dat`.

You don't really have to deal with that - if you will send the new `.po` or `.pot` to be included in new KeeperFX builds, it will be converted automatically and included in the next nighty build. To send the file to KeeperFX developers, you may either create an enhacement proposal in [KeeperFX tracker](https://code.google.com/p/keeperfx/issues/list), or e-mail it to a developer (ie [Mefistotelis](http://keeper.lubiki.pl/html/contact.php)) for inclusion in the campaign.

Still, if you'd like to test your translation by yourself, here's how to do the conversion:

## Conversion utility ##

To convert .po or .pot file to .dat, get [KeeperFX tools](http://keeper.lubiki.pl/html/dk_keeperfx_devel.php#tools) (or compile them from KeeperFX source code), and use [`po2ngdat` command line utility](https://code.google.com/p/keeperfx/source/browse/trunk/keeperfx/tools/po2ngdat/docs/po2ngdat_readme.txt) which can do the conversion.

## Using the `.dat` file in the game ##

If you've made the `.dat` file which fixes existing one, just find it in the KeeperFX folders and replace with new version.

If this is a new file, then you must enable it in a campaign `.cfg` file and place it into the same folder where other translations for this campaign are.