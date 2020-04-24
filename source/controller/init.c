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
    borwein->data[S].data = _N;
    borwein->data[E].data = _END;
    borwein->data[I].data = _INTER;
    borwein->prc = _PREC;
    borwein->data[R].data = 0;
    borwein->ac = ac;
    return (true);
}