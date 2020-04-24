/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** process
*/

#include "borwein.h"

static double frac(double s, double v, double r, int i)
{
    if (i > s) return (r);
    if (v != 0) r *= (sin(DIV(v, ((2 * i) + 1))) / DIV(v, ((2 * i) + 1)));
    return (frac(s, v, r, i + 1));
}

static void bor(borwein_t *borwein, int i)
{
    bool tmp = (borwein->data[E].data > 0) ? true : false;
    borwein->data[R].data = 0;

    while ((tmp) ? (++i < borwein->data[I].data) : (--i > borwein->data[I].data))
        borwein->data[R].data += frac(borwein->data[S].data, borwein->data[S].data + i * H, 1, 0);
}

static double simp(borwein_t *borwein, int i)
{
    double result = 0;
    bool tmp = (borwein->data[E].data > 0) ? true : false;

    while ((tmp) ? (++i < borwein->data[I].data) : (--i > borwein->data[I].data))
        result += frac(borwein->data[S].data, (borwein->data[S].data + i * H) + (H / 2), 1, 0);
    return (result);
}

static void midpoint(borwein_t *borwein, char *none)
{
    bor(borwein, borwein->data[S].data - 1);
    borwein->data[R].data *= (borwein->data[E].data - borwein->data[S].data) / borwein->data[I].data;
}

static void trapezoids(borwein_t *borwein, char *none)
{
    bor(borwein, borwein->data[S].data);
    borwein->data[R].data = (
        ((borwein->data[R].data * 2) +
        frac(borwein->data[S].data, borwein->data[S].data, 1, 0) +
        frac(borwein->data[S].data, borwein->data[E].data, 1, 0)) *
        ((borwein->data[E].data - borwein->data[S].data) / (2 * borwein->data[I].data))
    );
}

static void simpson(borwein_t *borwein, char *none)
{
    double tmp = simp(borwein, -1);

    bor(borwein, borwein->data[S].data);
    borwein->data[R].data = (
        ((borwein->data[R].data * 2) + (tmp * 4) +
        frac(borwein->data[S].data, borwein->data[S].data, 1, 0) +
        frac(borwein->data[S].data, borwein->data[E].data, 1, 0)) *
        ((borwein->data[E].data - borwein->data[S].data) / (6 * borwein->data[I].data))
    );
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
    char *header[] = {"Midlepoint:", "Midlepoint:", "Trapezoidal:",
    "Trapezoidal:", "Simpson:", "Simpson:"};

    for (int i = 0; proc_fct[i]; i++) proc_fct[i](borwein, header[i]);
    return (true);
}