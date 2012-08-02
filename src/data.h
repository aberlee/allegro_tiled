#ifndef _DATA_H
#define _DATA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <glib.h>

struct _ALLEGRO_MAP
{
	int width, height;          // dimensions in tiles
	int tile_width;             // width of each tile in pixels
	int tile_height;            // height of each tile in pixels
    char *orientation;          // "orthogonal" or ... isometric?
    GSList *tilesets;           // list of tilesets
    GSList *layers;             // list of layers
    GSList *object_groups;      // list of object groups
    GSList *objects;            // list of objects
    GHashTable *tiles;          // full list of tiles
    ALLEGRO_BITMAP *backbuffer; // back buffer
};

struct _ALLEGRO_MAP_LAYER
{
	int width;                  // width in tiles
	int height;                 // height in tiles
	int datalen;                // length of the decoded data
	float opacity;              // the layer's opacity
	int visible;                // 0 for hidden, 1 for visible
	char *name;                 // name of the layer
	char *data;                 // decoded data
	ALLEGRO_MAP *map;           // reference to the map
};

struct _ALLEGRO_MAP_TILESET
{
	int firstgid;               // first global id
	int tilewidth;              // width of each tile
	int tileheight;             // height of each tile
	int width, height;          // total dimensions (in pixels)
	char *name;                 // name
	char *source;               // path to this tileset's image source
	ALLEGRO_BITMAP *bitmap;     // image for this tileset
	GSList *tiles;              // list of tiles
};

struct _ALLEGRO_MAP_TILE
{
	int id;                       // the tile id
	ALLEGRO_MAP_TILESET *tileset; // pointer to its tileset
	GHashTable *properties;       // tile properties
	ALLEGRO_BITMAP *bitmap;       // this tile's image
};

struct _ALLEGRO_MAP_OBJECT_GROUP
{
	char *name;
	// color?
	float opacity;
	bool visible;
};

struct _ALLEGRO_MAP_OBJECT
{
	ALLEGRO_MAP_OBJECT_GROUP *group;
	char *name;
	char *type;
	int x, y;
	int width, height;
	bool visible;
	ALLEGRO_BITMAP *bitmap;
	GHashTable *properties;
};

int al_map_get_width(ALLEGRO_MAP *map);
int al_map_get_height(ALLEGRO_MAP *map);
int al_map_get_tile_width(ALLEGRO_MAP *map);
int al_map_get_tile_height(ALLEGRO_MAP *map);

#endif