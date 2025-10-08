#include "op.h"
#include "scalar.h"
#include "vector.h"
#include <math.h>


/* Scaling ********************************************************************/


Vector scalesv(Scalar fac, Vector *vec) {
  if (!is_vec_valid(vec))
    return empty_vec();

  Vector res = new_vec(vec->size, 0);
  for (int i = 0; i < vec->size; i++) {
    res.data[i] = fac * vec->data[i];
  }

  return res;
}


/* Dot Product ****************************************************************/


Scalar dotvv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return NAN;

  if (lhs->size != rhs->size)
    return NAN;

  Scalar res = 0;
  for (int i = 0; i < lhs->size; i++) {
    res += lhs->data[i] * rhs->data[i];
  }

  return res;
}

/* Cross Product **************************************************************/


Vector crossvv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return empty_vec();

  if (lhs->size != 3 || rhs->size != 3)
    return empty_vec();

  Vector res = new_vec(3, 0);
  res.data[0] = lhs->data[1] * rhs->data[2] - lhs->data[2] * rhs->data[1];
  res.data[1] = lhs->data[2] * rhs->data[0] - lhs->data[0] * rhs->data[2];
  res.data[2] = lhs->data[0] * rhs->data[1] - lhs->data[1] * rhs->data[0];

  return res;
}
