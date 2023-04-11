/*
** EPITECH PROJECT, 2023
** menus.c
** File description:
** Display menus
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_menus(renderer_t *renderer, app_t *app)
{
    display_main_menu(renderer, app);
    display_settings(renderer, app);
    display_select_character(renderer, app);
}
