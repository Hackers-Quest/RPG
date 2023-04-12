/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef ITEMS_TYPES_H_
    #define ITEMS_TYPES_H_

    #include <SFML/Graphics.h>

    #define ITEMS_CONFIG "configs/items.json"

typedef enum e_item_type {
    IVT_CONSUMABLE,
    IVT_EQUIPEMENT
} item_type_t;

typedef struct s_item {
    item_type_t type;
    unsigned int id;
    char *label;
    int xp;
    int life;
    int speed;
    int intelligence;
    float price;
    sfIntRect rect;
} item_t;

#endif /* !ITEMS_TYPES_H_ */
