/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct data_s
{
    double data;
} data_t;

typedef struct borwein_s
{
    data_t *data;
    int prc;
    int ac;
} borwein_t;

typedef enum list_s {S = 0, E = 1, I = 2, R = 3} list_t;

#endif /* !STRUCT_H_ */