/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** isnum
*/

#include "string.h"

bool m_isnum(const char *restrict string)
{
    for (int i = 0; string[i]; i++)
        if (m_isdigit(string[i])) return (false);
    return (true);
}