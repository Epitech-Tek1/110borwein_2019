/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** error
*/

#include "borwein.h"

static bool error_synthax(const char *restrict string)
{
    return (!string || !m_isnum(string) || 0 == m_strlen((char *)string)) ?
    (false) : (true);
}

bool error_handling(borwein_t *borwein)
{
    return (!error_synthax || borwein->ac != 2) ? (false) : (true);
}