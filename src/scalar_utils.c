#include "scalar_utils.h"
#include <math.h>


bool is_power_of_two(int x) {
  bool zero_check = (x != 0);
  bool power_check = ((x & (x - 1)) == 0);
  return zero_check && power_check;
}


int unsafe_find_power_of_two_exponent(int x) {
  int x_copy = x;
  int count;
  // simply counts trailing zeros
  while ((x_copy & 1) == 0) {
    x_copy >>= 1;
    count++;
  }
  return count;
}


int find_power_of_two_exponent(int x) {
  if (!is_power_of_two(x))
    return NAN;
  return unsafe_find_power_of_two_exponent(x);
}
