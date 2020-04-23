/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Debian]
** File description:
** main
*/

#include "borwein.h"

static bool (*process[])(void *t) =
{
    error_handling,
    process
};

static bool bor(const int ac, char *const restrict *const restrict av)
{
    borwein_t borwein;

    if (!init(&borwein, m_atoi(av[1]), ac)) return (false);
    for (int i = 0; process[i]; i++)
        if (!process[i](NULL)) return (false);
    return (true);
}

int main(const int ac, char *const restrict *const restrict av)
{
    return (bor(ac, av)) ? (0) : (84);
}