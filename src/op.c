#include "op.h"
#include "scalar.h"
#include "vector.h"
#include <math.h>


/* Scaling ********************************************************************/


Vector scalesv(Scalar fac, Vector *vec) {
  if (!is_vec_valid(vec))
    return empty_vec();

  Vector res = new_vec(vec->size);
  Scalar *data = vec->data;
  size_t size = vec->size;
  for (size_t i = 0; i < size; i++) {
    res.data[i] = fac * data[i];
  }

  return res;
}


/* Dot Product ****************************************************************/


Scalar dotvv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return NAN;

  size_t lhs_size = lhs->size;
  size_t rhs_size = rhs->size;
  if (lhs_size != rhs_size)
    return NAN;

  Scalar res = 0;
  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  for (size_t i = 0; i < lhs_size; i++) {
    res += lhs_data[i] * rhs_data[i];
  }

  return res;
}

/* Cross Product **************************************************************/


Vector crossvv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return empty_vec();

  if (lhs->size != 3 || rhs->size != 3)
    return empty_vec();

  Vector res = new_vec(3);
  Scalar *lhs_data = lhs->data;
  Scalar *rhs_data = rhs->data;
  res.data[0] = lhs_data[1] * rhs_data[2] - lhs_data[2] * rhs_data[1];
  res.data[1] = lhs_data[2] * rhs_data[0] - lhs_data[0] * rhs_data[2];
  res.data[2] = lhs_data[0] * rhs_data[1] - lhs_data[1] * rhs_data[0];

  return res;
}
