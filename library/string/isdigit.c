/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** isdigit
*/

#include "string.h"

bool m_isdigit(const char character)
{
    return ('0' > character || '9' < character) ? (false) : (true);
}