# Clear View edition

A fork of Shroudweave Minimap 0.5.15 (by Aerox912, original minimap by elxokker)
with additions for readability and colour-blind players. All original features
and settings are unchanged.

## What's added

- **Compass bar** at the top of the screen: N/E/S/W and NE/SE/SW/NW letters,
  your selected waypoint (hollow yellow diamond, or an arrow at the edge when it
  is behind you), teammates (blue triangles) and pings (orange diamonds).
- **Coordinate readout** under the compass: `X` (east) and `Y` (north) in metres,
  optional height.
- **Waypoint distance** next to the coordinates, for example `240 m` or `1.2 km`.
- **Colour-blind friendly marker colours** on the minimap and compass:
  teammates blue, pings orange, waypoint yellow with dark edges, custom pins pink.
  Set `marker_colors` to `original` for the old green/yellow/red markers.
- **Clear View map**: darker shroud, regions told apart by brightness, a darker
  player-arrow outline. Recommended `map_light`: 20.

## Settings (`mods.minimap_mod` in shroudtopia.json)

| Setting | Default | Meaning |
|---|---|---|
| `show_compass` | `true` | Compass bar on/off |
| `show_coordinates` | `true` | Coordinate readout on/off |
| `show_waypoint_distance` | `true` | Waypoint distance on/off |
| `show_height` | `false` | Add height to the coordinates (may be approximate) |
| `marker_colors` | `colorblind` | `colorblind` or `original` |
| `compass_toggle_key` | `F8` | Hide/show compass and readout; `none` disables |
| `compass_offset` | `0` | Pixels at 1080p; positive moves the compass down |
| `compass_scale_percent` | `100` | 50 to 200 |

Changes apply while playing (checked every second).

## Building

GitHub Actions builds the DLL on every push (`.github/workflows/release.yml`).
Download the `Minimap_ClearView-...` artifact from the run's summary page.
