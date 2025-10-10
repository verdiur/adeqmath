#include "vector_op.h"
#include "scalar.h"
#include "scalar_utils.h"
#include "vector.h"
#include <math.h>
#include <stddef.h>


/* Sum ************************************************************************/


Vector sum_vv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return empty_vec();
  if (lhs->size != rhs->size)
    return empty_vec();
  return unsafe_sum_vv(lhs, rhs);
}


Vector unsafe_sum_vv(Vector *lhs, Vector *rhs) {
  size_t size = lhs->size;
  Vector sum = new_vec(size);
  if (!is_vec_valid(&sum))
    return empty_vec();

  Scalar *sum_data = sum.data;
  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  for (size_t i = 0; i < size; i++)
    sum_data[i] = lhs_data[i] + rhs_data[i];
  return sum;
}


/* Difference *****************************************************************/


Vector diff_vv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return empty_vec();
  if (lhs->size != rhs->size)
    return empty_vec();
  return unsafe_diff_vv(lhs, rhs);
}


Vector unsafe_diff_vv(Vector *lhs, Vector *rhs) {
  size_t size = lhs->size;
  Vector sum = new_vec(size);
  if (!is_vec_valid(&sum))
    return empty_vec();

  Scalar *sum_data = sum.data;
  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  for (size_t i = 0; i < size; i++)
    sum_data[i] = lhs_data[i] - rhs_data[i];
  return sum;
}


/* Scaling ********************************************************************/


Vector scale_sv(Scalar fac, Vector *vec) {
  if (!is_vec_valid(vec))
    return empty_vec();
  return unsafe_scale_sv(fac, vec);
}


Vector unsafe_scale_sv(Scalar fac, Vector *vec) {
  size_t size = vec->size;
  Vector res = new_vec(size);
  if (!is_vec_valid(&res))
    return empty_vec();

  Scalar *data = vec->data;
  for (size_t i = 0; i < size; i++) {
    res.data[i] = fac * data[i];
  }
  return res;
}


/* Dot Product ****************************************************************/


Scalar dot_vv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return NAN;
  if (lhs->size != rhs->size)
    return NAN;
  return unsafe_dot_vv(lhs, rhs);
}


Scalar unsafe_dot_vv(Vector *lhs, Vector *rhs) {
  size_t lhs_size = lhs->size;
  size_t rhs_size = rhs->size;

  Scalar res = 0;
  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  for (size_t i = 0; i < lhs_size; i++)
    res += lhs_data[i] * rhs_data[i];

  return res;
}


/* Cross Product **************************************************************/


Vector cross_vv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return empty_vec();
  if (lhs->size != 3 || rhs->size != 3)
    return empty_vec();
  return unsafe_cross_vv(lhs, rhs);
}


Vector unsafe_cross_vv(Vector *lhs, Vector *rhs) {
  Vector res = new_vec(3);
  if (!is_vec_valid(&res))
    return empty_vec();

  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  res.data[0] = lhs_data[1] * rhs_data[2] - lhs_data[2] * rhs_data[1];
  res.data[1] = lhs_data[2] * rhs_data[0] - lhs_data[0] * rhs_data[2];
  res.data[2] = lhs_data[0] * rhs_data[1] - lhs_data[1] * rhs_data[0];

  return res;
}


/* L-Norm *********************************************************************/


Scalar lnorm_v(Vector *vec, int order) {
  if (order <= 0)
    return NAN;
  if (!is_vec_valid(vec))
    return NAN;
  return unsafe_lnorm_v(vec, order);
}


Scalar unsafe_lnorm_v(Vector *vec, int order) {
  Scalar res = 0;
  Scalar *data = vec->data;
  size_t size = vec->size;

  for (size_t i = 0; i < size; i++)
    res += pow(data[i], order);

  // we can make it faster if the order is a power of 2
  if (is_power_of_two(order)) {
    int expo = unsafe_find_power_of_two_exponent(order);
    while (expo > 0) {
      res = sqrt(res);
      expo--;
    }
    return res;
  }

  return pow(res, 1 / (double)order);
}


/* L-Distance *****************************************************************/


Scalar ldistance_vv(Vector *lhs, Vector *rhs, int order) {
  if (order <= 0)
    return NAN;
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return NAN;
  if (lhs->size != rhs->size)
    return NAN;
  return unsafe_ldistance_vv(lhs, rhs, order);
}


Scalar unsafe_ldistance_vv(Vector *lhs, Vector *rhs, int order) {
  Scalar res = 0;
  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  size_t size = lhs->size;

  for (size_t i = 0; i < size; i++)
    res += pow(lhs_data[i] - rhs_data[i], order);

  // we can make it faster if the order is a power of 2
  if (is_power_of_two(order)) {
    int expo = unsafe_find_power_of_two_exponent(order);
    while (expo > 0) {
      res = sqrt(res);
      expo--;
    }
    return res;
  }

  return pow(res, 1 / (double)order);
}
