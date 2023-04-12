/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** items
*/

#ifndef ITEMS_H_
    #define ITEMS_H_

    #include "app/items/types.h"
    #include "types/list/list.h"
    #include "cjson/include/cjson.h"


/**
 * @brief Load all items of game
 * @return Loaded items
 */
list_t *items_load(void);

/**
 * @brief Load item from config
 * @param config Configuration of item
 * @param item Item in which import config
 * @return Status of loading success
 */
bool item_load(cjson_t *config, item_t **item);

#endif /* !ITEMS_H_ */
