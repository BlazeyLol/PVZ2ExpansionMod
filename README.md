# **Expansion Mod for PvZ2**

# Credits

* Vi - code assistance
* Brekko/Jay - original repositories
* Snowie - helping me with this

# What is this?

An expanded library for PvZ2 (9.6.1), based on Brekko's ExampleMod. I want it to be fully open sourced and public. My main goal is to softcode and expand vanilla entities via reflection system, which adds new properties to packages. It's currently in development, and no ARM64 version is available at the moment. Stable libraries are available at the `Release` section

# Current Features
* IntegerID backport! - Plant/Zombie types now support id mapping, which will help modders who dont want to constantly update the apk.
* Power Lily softcode - Power Lily gained new properties regarding her collectable
* Piano List softcode in packages
* Mummy Memory from the original Example Mod

# Future Plans
I want to take care of more plants/zombies like grinderhead, bull, camels, ra and tomb raiser.
I am also working on a new Board zoom system, that doesn't require modifying Grid's size.
Map vertical scrolling, custom Game Features and other stuff.

# Build Instructions
Building this repo is the same as building my example mod update. The instructions regarding that [you can find here](https://github.com/BlazeyLol/PVZ2ExampleMod).
This library requires some packages modifications in order to work. You can find example Plant/Zombie types jsons in the Packages directory.
If you want to utilize Power Lily's custom fields, add these to her props:
- CollectableType (string)
- CollectableCount (integer)
- CollectableOffsetY (float)

Arcade's new property is `GridItemType` (string). One important note: DO NOT use a grid item which class isn't `GridItemEightiesArcadeCabinet`, otherwise zombie won't be able to push it. I want to fix it at some point.
