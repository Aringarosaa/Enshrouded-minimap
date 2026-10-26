# Clear View edition

A fork of Shroudweave Minimap 0.5.15 (by Aerox912, original minimap by elxokker)
with additions for readability and colour-blind players. All original features
and settings are unchanged.

## What's added

- **Teammates on the game's compass**: blue markers with their distance, placed
  on the game's own compass at the top of the screen.
- **Optional compass bar** (off by default): N/E/S/W and NE/SE/SW/NW letters,
  your selected waypoint (hollow yellow diamond, or an arrow at the edge when it
  is behind you), teammates (blue triangles) and pings (orange diamonds).
- **Big map** (F7): opens on your current region; press F7 again for all of Embervale,
  once more to close; +/- zoom it while open. Shows you,
  teammates, your waypoint, pings and tombstones, plus every region's
  exploration progress. Regions you have not explored yet stay unnamed ("???").
  You can keep moving while it is open.
- **Exploration progress**: entering a region shows e.g. `Revelwood · 64% explored`.
  Regions: Springlands, Revelwood, Blackmire, Veilwater Basin, Nomad Highlands,
  Kindlewastes, Albaneve Summits and Cinder's Cradle. Borders are approximate
  (drawn from the map); rename regions in `embervale_regions.json`.
- **Coordinate readout and waypoint distance** (off by default) under the compass.
- **Colour-blind friendly marker colours** on the minimap and compass:
  teammates blue, pings orange, waypoint yellow with dark edges, custom pins pink.
  Set `marker_colors` to `original` for the old green/yellow/red markers.
- **Clear View map**: darker shroud, regions told apart by brightness, a darker
  player-arrow outline. Recommended `map_light`: 20.

## Settings (`mods.minimap_mod` in shroudtopia.json)

| Setting | Default | Meaning |
|---|---|---|
| `show_compass_players` | `true` | Teammate markers on the game's compass |
| `game_compass_offset` | `0` | Nudge those markers; pixels at 1080p, positive moves down |
| `game_compass_width_percent` | `100` | Spread of those markers; raise if they drift outward of the game's letters |
| `show_compass` | `false` | Extra compass bar on/off (teammate markers then move to the bar) |
| `big_map_key` | `F7` | Open/close the big map; `none` disables |
| `show_exploration` | `true` | Region-entry notice and percentages (needs `show_fog_of_war`) |
| `show_coordinates` | `false` | Coordinate readout on/off |
| `show_waypoint_distance` | `false` | Waypoint distance on/off |
| `show_height` | `false` | Add height to the coordinates (may be approximate) |
| `marker_colors` | `colorblind` | `colorblind` or `original` |
| `compass_toggle_key` | `F8` | Hide/show the optional compass bar and readout; `none` disables |
| `compass_offset` | `0` | Moves the bar and readout; pixels at 1080p, positive moves down |
| `compass_scale_percent` | `100` | Size of the bar and readout, 50 to 200 |

Changes apply while playing (checked every second).

## Building

GitHub Actions builds the DLL on every push (`.github/workflows/release.yml`).
Download the `Minimap_ClearView-...` artifact from the run's summary page.
