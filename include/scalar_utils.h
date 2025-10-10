/**
 * @file scalalg.h
 * @brief Some scalar algebra utilities
 */

#ifndef ADEQ_MATH_SCALALG_H
#define ADEQ_MATH_SCALALG_H
#include <stdbool.h>

/**
 * @brief Determine if x is a power of 2
 * @param x
 * @return true if x == 2 ** k
 */
bool is_power_of_two(int x);

int find_power_of_two_exponent(int x);
int unsafe_find_power_of_two_exponent(int x);

#endif // !ADEQ_MATH_SCALALG_H
