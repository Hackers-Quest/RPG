/*
** EPITECH PROJECT, 2023
** append.c
** File description:
** Append a new button to a list of buttons
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/components/types.h"
#include "types/list/types.h"
#include "types/list/list.h"

lever_t *levers_append(list_t *list, sfVector2f position,
app_states_t app_state)
{
    node_data_t data;
    lever_t *lever = malloc(sizeof(lever_t));

    if (!lever)
        return NULL;
    data.lever = lever;
    lever->position = position;
    lever->scale = 1.0;
    lever->state = ST_LV_OFF;
    lever->app_state = app_state;
    list_append(list, node_new(data));
    return lever;
}
