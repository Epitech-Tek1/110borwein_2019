/*
** EPITECH PROJECT, 2020
** 110borwein_2019 [WSL: Debian]
** File description:
** maths_define
*/

#ifndef MATHS_DEFINE_H_
#define MATHS_DEFINE_H_

#if defined __cplusplus
#define __FLOAT_CAST static_cast<float>
#else
#define __FLOAT_CAST (float)
#endif

#define DIV(dividend, divisor) (m_assert(0 < divisor) \
? __FLOAT_CAST(dividend / divisor) : false)

#endif /* !MATHS_DEFINE_H_ */