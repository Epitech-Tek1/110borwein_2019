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
    char *n;
    int ac;
} borwein_t;

typedef enum {MID = 0, TRAP = 1, SIMP = 2, FIRST = 3, SECOND = 4};

#endif /* !STRUCT_H_ */