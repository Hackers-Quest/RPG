/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load maps
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"
#include "my/include/my.h"

static void maps_load_line_collision(map_t *map, cjson_array_t *array)
{
    cjson_t *line = NULL;
    cjson_array_t *lines = NULL;
    size_t len = 0;

    for (size_t i = 0; i < array->len; i++) {
        line = array->first;
        cjson_get_array(line, &lines);
        map->collision_layer[i] = malloc(sizeof(int) *
        lines->len);
        if (map->collision_layer[i] == NULL)
            return;
        map->collision_layer[i] = cjson_array_to_int_array(lines, &len);
        array->first = array->first->next;
    }
}

static void maps_load_collision(map_t *map, cjson_t *map_config)
{
    cjson_array_t *array = NULL;

    if (!cjson_get_prop_array(map_config, "collision_layer", &array))
        return;
    map->collision_layer = malloc(sizeof(int *) * array->len);
    if (map->collision_layer == NULL)
        return;
    maps_load_line_collision(map, array);
}

static void maps_append_data(map_t *map, cjson_t *map_config)
{
    char *back = cjson_get_prop_string_unsafe(map_config, "back");
    char *front = cjson_get_prop_string_unsafe(map_config, "front");

    map->world = cjson_get_prop_int_unsafe(map_config, "world");
    map->back = sfTexture_createFromFile(back, NULL);
    map->front = sfTexture_createFromFile(front, NULL);
    if (back)
        free(back);
    if (front)
        free(front);
}

static void maps_append(list_t *maps, cjson_t *map_config, int i,
renderer_t *renderer)
{
    node_data_t data;
    node_t *node = NULL;
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return;
    data.map = map;
    node = node_new(data);
    if (!node) {
        free(map);
        return;
    }
    load_screen_add_bar(renderer, 3, "Chargement Ressources. . .",
    my_strcat("Map sol ", nbr_to_str(i)));
    maps_append_data(map, map_config);
    load_screen_add_bar(renderer, 3, "Chargement Ressources. . .",
    my_strcat("Map collisions ", nbr_to_str(i)));
    maps_load_collision(map, map_config);
    list_append(maps, node);
}

void maps_load(list_t *maps, renderer_t *renderer)
{
    cjson_t *maps_config = cjson_parse_file(RESSOURCES_MAPS_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *map = NULL;
    int i = 0;

    if (!maps_config)
        return;
    if (!cjson_get_prop_array(maps_config, "maps", &array)) {
        cjson_free(maps_config);
        return;
    }
    map = array->first;
    while (map) {
        i++;
        maps_append(maps, map, i, renderer);
        map = map->next;
    }
    cjson_free(maps_config);
}
