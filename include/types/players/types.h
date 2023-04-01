/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Players types
*/

#ifndef PLAYERS_TYPES_H_
    #define PLAYERS_TYPES_H_

    #include <SFML/Graphics.h>

typedef struct s_list list_t;

/**
 * @brief Structure of a skin
*/
typedef struct s_skin {
    int id;                 //Id of the skin
} skin_t;

/**
 * @brief Structure of a player
*/
typedef struct s_player {
    char *name;             //Name of the player
    int xp;                 //Player exeprience
    sfVector2f position;    //Position of the player
    list_t *inventory;      //Inventory with all objects
    skin_t *skin;           //Representation of the player (visual)
} player_t;

#endif /* !PLAYERS_TYPES_H_ */