/*
** EPITECH PROJECT, 2023
** enemy.c
** File description:
** Enemy attack
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/types.h"
#include "types/players/players.h"
#include "app/core/core.h"
#include "app/core/types.h"
#include "types/list/types.h"
#include "app/app.h"
#include "app/network/network.h"
#include "app/animations/animations.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static void applay_attack(cjson_t *node, app_t *app)
{
    list_t *events = animation_event_new(app);
    char *attack = cjson_get_prop_string_unsafe(node, "title");
    int damage = cjson_get_prop_int_unsafe(node, "damage");

    attack = my_strcat(attack, "\n-");
    attack = my_strcat(attack, nbr_to_str(damage));
    attack = my_strcat(attack, " PV");
    app->player->life -= damage;
    animations_floating_text_add(events, sfWhite, ATTACKS_POSITION,
    my_strdup(attack));
    free(attack);
}

void core_fight_enemy(app_t *app)
{
    cjson_t *config = cjson_parse_file(ATTACKS_NPC_CONFIG);
    cjson_array_t *attacks = cjson_get_array_unsafe(config);
    cjson_t *node = NULL;
    fight_t *fight = app->interaction->data.fight;
    int index_attack = 0;
    size_t attack = 0;
    time_t t;

    srand((unsigned) time(&t));
    index_attack = rand() % fight->npc->enemy->nb_attacks;
    attack = fight->npc->enemy->attacks[index_attack];
    node = attacks->first;
    for (size_t i = 0; i < attack; i++) {
        node = node->next;
    }
    applay_attack(node, app);
    app->interaction->data.fight->state = FT_PLAYER_ATTACK;
    cjson_free(config);
}
