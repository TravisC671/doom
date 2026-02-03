#pragma once
#include <stdint.h>

// https://www.gamers.org/dhs/helpdocs/dmsp1666.html

/* 8 byte ascii string */
typedef char string8[8];

struct wad_header
{
    /* ASCII string which must be either "IWAD" or "PWAD"*/
    char wad_type[32];
    /* number of lumps in the wad */
    uint32_t num_lumps;
    /* file offset to the start of the directory */
    uint32_t wad_offset;
};

/* Lump is just data & can be sound data, graphics data, level structure data, etc.*/
struct lump_entry
{
    /* offset of the lump from the start of the file */
    uint32_t lump_offset;
    /* Size of lump in bytes */
    uint32_t lump_size;
    string8 lump_name;
};

struct things
{
    uint8_t x;
    uint8_t y;
    /* From doom specs:
    Angle the thing faces. On the automap, 0 is east, 90 is north, 180
      is west, 270 is south. This value is only used for monsters, player
      starts, deathmatch starts, and teleporter landing spots. Other
      things look the same from all directions. Values are rounded to
      the nearest 45 degree angle, so if the value is 80, it will
      actually face 90 - north.*/
    uint8_t rotation;
    uint8_t type;
    uint8_t options;
};