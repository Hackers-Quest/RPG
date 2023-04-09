/*
** EPITECH PROJECT, 2023
** state.c
** File description:
** Check if app is on a speicific state
*/

#include <stdio.h>
#include <stdbool.h>
#include "app/types.h"
#include "types/renderer/types.h"

int states_help(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) button;
    (void) renderer;
    app->state = ST_HELP_1;
    return 0;
}
