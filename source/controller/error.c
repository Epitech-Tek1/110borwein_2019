/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** error
*/

#include "borwein.h"

static bool error_synthax(const char *restrict string)
{
    return (
        (!m_assert(string)) || (!m_assert(m_isnum(string))) ||
        (!m_assert(0 != m_strlen((char *)string)))
    ) ? (false) : (true);
}

bool error_handling(int ac, char *n)
{
    return (!error_synthax(n) || ac != 2) ? (false) : (true);
}