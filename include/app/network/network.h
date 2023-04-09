/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** network
*/

#ifndef NETWORK_H_
    #define NETWORK_H_

    #include "types.h"
    #include "types/character/types.h"

typedef struct s_app app_t;
typedef struct s_renderer renderer_t;
typedef struct s_button button_t;

/**
 * @brief Init network structure
 * @return network_t* The new structure
 */
network_t *network_init(void);

/**
 * @brief Host a new game
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Speicific action button
 * @return int Status of the function
 */
int network_connexion_host(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Join a new game
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Speicific action button
 * @return int Status of the function
 */
int network_connexion_join(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Send new character
 * @param app Application structure
 * @param skin Skin of the character
 */
void network_send_character(app_t *app, skin_textures_t skin);

/**
 * @brief Receive a new character
 * @param app Application structure
 */
void network_receive_character(app_t *app);

/**
 * @brief Handle receive packets
 * @param app Application structure
 */
void network_receive(app_t *app);

#endif /* !NETWORK_H_ */
