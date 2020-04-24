/*
** EPITECH PROJECT, 2020
** 110borwein_2019
** File description:
** m_assert_fail
*/

#include "assert.h"
#include "../../string/include/string.h"

bool m_assert_fail(char const *__restrict__ assertion, char const *__restrict__
file, unsigned line, char const *__restrict__ function)
{
    m_putstr((char *)file, 2);
    m_putstr(": ", 2);
    m_putstr((char *)function, 2);
    m_putstr(":", 2);
    m_putnbr(line, 2);
    m_putstr(": Assertion", 2);
    m_putstr(" '", 2);
    m_putstr((char *)assertion, 2);
    m_putstr("' failed\n", 2);
    return (false);
}