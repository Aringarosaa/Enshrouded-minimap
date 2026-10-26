Shroudweave Minimap + Compass (Clear View) - all-in-one package

What it adds: an in-game minimap with world clock and weather, a big map with
exploration progress per region, teammates on the game's compass, and
colour-blind friendly map and marker colours. Client-side only: every player installs it on their own
PC; nothing is needed on the server. The Shroudtopia mod loader is included.

INSTALL
1. Close Enshrouded.
2. In Steam: right-click Enshrouded > Manage > Browse local files.
   This opens the game folder (the one with enshrouded.exe).
3. Extract everything from this ZIP into that folder.
   You should now have, next to enshrouded.exe:
     shroudtopia.dll, winmm.dll, shroudtopia.json, mods\minimap_mod\
4. Start the game. The minimap appears bottom-right.

ALREADY USING OTHER SHROUDTOPIA MODS?
When Windows asks to replace shroudtopia.json, choose Skip, then add the
"minimap_mod" section from shroudtopia.example.json to your own file, so your
other mods keep their settings. If another mod already uses winmm.dll, back up
your files first.

KEYS
F10 minimap on/off   +/- zoom   F9/F11 smaller/larger
F7  big map with exploration progress
F8  optional compass bar / coordinates on/off (both off by default)

SETTINGS
Edit shroudtopia.json (mods > minimap_mod). CLEAR-VIEW.md explains each setting.

If the game does not start or the minimap does not appear, install the
Microsoft Visual C++ x64 Redistributable: https://aka.ms/vc14/vc_redist.x64.exe

UNINSTALL
Close the game and delete shroudtopia.dll, winmm.dll, shroudtopia.json and
mods\minimap_mod from the game folder.

Credits: original minimap by elxokker, maintained by Aerox912 (CREDITS.md).
Shroudtopia by s0T7x / Miguel Oppermann, MIT licence (SHROUDTOPIA-LICENSE.txt).
