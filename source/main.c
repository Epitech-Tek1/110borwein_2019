/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Debian]
** File description:
** main
*/

#include "borwein.h"

static bool bor(const int ac, char *const restrict *const restrict av)
{
    borwein_t borwein;

    if (!init(&borwein, av[1], ac)) return (false);
    if (2 == ac && m_strcmp("-h", av[1])) {m_fread("data/describe.txt"); return (0);}
    error_handling(&borwein, av[1]);
    process(&borwein);
    return (true);
}

int main(const int ac, char *const restrict *const restrict av)
{
    return (bor(ac, av)) ? (0) : (84);
}