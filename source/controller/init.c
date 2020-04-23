/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Debian]
** File description:
** init
*/

#include "borwein.h"

bool init(borwein_t *borwein, char *n, const int ac)
{
    if (!(borwein->data = malloc(sizeof(double) * NDATA))) return (false);
    borwein->n = m_strcpy(borwein->n, n);
    borwein->ac = ac;
    return (true);
}