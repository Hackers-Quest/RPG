/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quests
*/

#ifndef QUESTS_H_
    #define QUESTS_H_

    #include "app/app.h"
    #include "app/quests/types.h"

/**
 * @brief Get current quest of the application
 * @param app Application object
 * @return quest_t* The quest object
 */
quest_t *core_quest_get(app_t *app);

/**
 * @brief Get current quests object
 * @return quest_t* The quests object
 */
quests_t *core_quests_get(app_t *app);

/**
 * @brief Upgrade quests indexs (next)
 * @param app Application object
 */
void core_quests_upgrade(app_t *app);

/**
 * @brief Handle world quests
 * @param quest Actual quest
 * @param app Application objects
 */
void core_quests_world(quest_t *quest, app_t *app);

/**
 * @brief Handle NPC quests
 * @param quest Actual quest
 * @param app Application objects
 */
void core_quests_npc(quest_t *quest, app_t *app);

#endif /* !QUESTS_H_ */