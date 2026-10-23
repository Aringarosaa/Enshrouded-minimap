Shroudweave Minimap + Compass (Clear View) 0.5.15-clearview

What it adds: an in-game minimap with world clock and weather, teammates on the
game's compass, coordinates and waypoint distance, and colour-blind friendly
map and marker colours. Client-side only: every player installs it on their own
PC; nothing is needed on the server.

1. Close Enshrouded.
2. Install Shroudtopia (the mod loader) if you don't have it yet:
   https://www.nexusmods.com/enshrouded/mods/143?tab=files
   Use the loader/proxy from Optional Files. Back up any existing shroudtopia.dll
   and winmm.dll, then extract both beside enshrouded.exe.
3. Extract this ZIP into the game folder (the folder with enshrouded.exe), for
   example C:\Program Files (x86)\Steam\steamapps\common\Enshrouded
   You should end up with mods\minimap_mod\minimap_mod.dll.
   Keep only one minimap_mod folder; replace it if you had an older version.
4. Start the game. No settings changes are needed.

Keys: F10 minimap on/off, +/- zoom, F9/F11 smaller/larger,
      F8 compass additions and coordinates on/off.

Optional settings go in shroudtopia.json under mods > minimap_mod.
shroudtopia.example.json shows every setting; CLEAR-VIEW.md explains them.
Do not overwrite other mods' settings when you edit it.

Requires Windows x64 and the Microsoft Visual C++ x64 Redistributable:
https://aka.ms/vc14/vc_redist.x64.exe

To uninstall or roll back: close the game and remove or restore mods\minimap_mod.
Credits: original minimap by elxokker, maintained by Aerox912 (see CREDITS.md).
