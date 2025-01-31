/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

bool init(borwein_t *borwein, char *n, const int ac);

bool error_handling(int ac, char *n);

void display(borwein_t *borwein, char *header);

bool process(borwein_t *borwein);

#endif /* !FUNCTION_H_ */