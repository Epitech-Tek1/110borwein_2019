/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Debian]
** File description:
** display
*/

#include "borwein.h"

void display(borwein_t *borwein, char *header)
{
    printf("%s\n", header);
    printf("I0 = %.*f\n", borwein->prc, borwein->data[R].data);
    printf("diff = %.*f\n", borwein->prc, borwein->data[R].data - M_PI / 2);
}