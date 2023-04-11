/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init network structure
*/

#include <stdlib.h>
#include "app/network/types.h"

network_t *network_init(void)
{
    network_t *network = malloc(sizeof(network_t));

    if (!network)
        return NULL;
    network->listener = NULL;
    network->socket = NULL;
    return network;
}
