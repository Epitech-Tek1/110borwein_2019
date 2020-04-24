/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** process
*/

#include "borwein.h"

static double _function_tmp(double s, double v, double r, int i)
{
    if (s < i) return (r);
    if (0 != v) r *= V(v, i);
    return (_function_tmp(s, v, r, i++));
}

static void bor(borwein_t *borwein, int i)
{
    int tmp = (0 < borwein->data[E].data) ? true : false;

    while (i < borwein->data[I].data) {
        i = (tmp) ? (i + 1) : (i - 1);
        borwein->data[R].data += _function_tmp(borwein->data[S].data, borwein->data[S].data + i * H, 0, 0);
    }
}

static void midpoint(borwein_t *borwein)
{
    bor(borwein, borwein->data[S].data - 1);
    borwein->data[R].data *= (borwein->data[E].data - borwein->data[S].data) / borwein->data[I].data;
}

static void trapezoids(borwein_t *borwein)
{
    
}

static void simpson(borwein_t *borwein)
{
    
}

static void (*proc_fct[])(borwein_t *, char *) =
{
    midpoint,
    display,
    trapezoids,
    display,
    simpson,
    display
};

bool process(borwein_t *borwein)
{
    char *header[] = {"Midlepoint:", "Trapezoidal:", "Simpson:"};

    printf("test\n");
    for (int i = 0, n = 0; proc_fct[i]; i++, n += (i % 2 == 0) ? 0 : 1) {
        printf("%d) %d\n", i, n);
        proc_fct[i](borwein, header[n]);
    }
    return (true);
}