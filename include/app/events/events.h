/*
** EPITECH PROJECT, 2023
** events.h
** File description:
** Events functions
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <SFML/Graphics.h>
    #include "app/types.h"
    #include "types/renderer/types.h"

/**
 * @brief Handle all events
 * @param window Window of the app
 * @param event The specific event
*/
void event_handler(sfRenderWindow *window, app_t *app, renderer_t *renderer);

/**
 * @brief Close window
 * @param window Window of the app
*/
void event_window_close(sfRenderWindow *window);

/**
 * @brief Detects when a movement key is pressed
 * @param event The event
 * @param app Application structure
*/
void keyboard_press_move(sfEvent event, app_t *app);

/**
 * @brief Detects when a movement key is released
 * @param event The event
 * @param app Application structure
*/
void keyboard_release_move(sfEvent event, app_t *app);

/**
 * @brief Handle events on buttons
 * @param renderer Renderer structure
 * @param app Application structure
 * @param event Event click
*/
void event_components_buttons(renderer_t *renderer, app_t *app, sfEvent event);

/**
 * @brief Handle events on levers
 * @param renderer Renderer structure
 * @param app Application structure
 * @param event Event click
*/
void event_components_levers(renderer_t *renderer, app_t *app, sfEvent event);

/**
 * @brief Handle events on attacks
 * @param renderer Renderer structure
 * @param app Application structure
 * @param event Event click
*/
void event_components_attacks(renderer_t *renderer, app_t *app, sfEvent event);

/*
 * @brief Handler of event close
 * @param window Window of the app
 * @param event The specific event
*/
void event_close(sfRenderWindow *window, sfEvent event);

/**
 * @brief Handler of event text entered
 * @param app Application structure
 * @param event The specific event
 * @param renderer Renderer structure
*/
void event_text_entered(renderer_t *renderer, sfEvent event, app_t *app);

/**
 * @brief Handler of event key entered
 * @param app Application structure
 * @param event The specific event
*/
void event_key_pressed(sfEvent event, app_t *app);

/**
 * @brief Handler of event key released
 * @param app Application structure
 * @param event The specific event
*/
void event_key_released(sfEvent event, renderer_t *renderer, app_t *app);

/**
 * @brief Keyboard E interaction
 * @param event Event structure
 * @param app Application structure
 */
void keyboard_interaction(sfEvent event, renderer_t *renderer, app_t *app);

/**
 * @brief Handler of event mouse button pressed
 * @param app Application structure
 * @param renderer Renderer structure
 * @param event The specific event
*/
void event_mouse_button_pressed(app_t *app, renderer_t *renderer,
sfEvent event);

/**
 * @brief Handler of event mouse button released
 * @param app Application structure
 * @param renderer Renderer structure
 * @param event The specific event
*/
void event_mouse_button_released(app_t *app, renderer_t *renderer,
sfEvent event);

/**
 * @brief Fight interaction start
 * @param interactions Interactions structure
 * @param app App object
 * @param renderer Renderer object
 */
void interaction_fight_start(interactions_t *interactions, app_t *app,
renderer_t *renderer);

/**
 * @brief Fight interaction choice
 * @param interactions Interactions structure
 * @param app App object
 * @param renderer Renderer object
 */
void keyboard_interaction_choice(sfEvent event, app_t *app,
renderer_t *renderer);

/**
 * @brief Dialogs interaction
 * @param app App object
 * @param renderer Renderer object
 */
void keyboard_interaction_dialogs(renderer_t *renderer, app_t *app);

/**
 * @brief Inventory keyboard
 * @param event Event structure
 * @param app App object
 */
void keyboard_inventory(sfEvent event, app_t *app);

#endif /* !EVENTS_H_ */
