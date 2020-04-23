/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** process
*/

#include "borwein.h"

static first_track(borwein_t *borwein)
{
    for (int i = 0; i != NDATA; i++) borwein->data[i].data = 0;
    for (int i = 0; i != 10000; i++) {
        borwein->data[FIRST].data = First_n(i / 2, _N);
        borwein->data[SECOND].data = First_n(i / 2 + .25, _N);
        borwein->data[MID].data += borwein->data[FIRST].data;
        borwein->data[TRAP].data += (borwein->data[FIRST].data * 2);
        borwein->data[SIMP].data += (2 * borwein->data[FIRST].data) + (4 * borwein->data[SECOND].data);
    }
}

bool process(borwein_t *borwein)
{
    if (0 < m_atoi(borwein->n)) first_track(borwein);
    else second_track(borwein);
}