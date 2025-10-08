#include "op.h"
#include "scalar.h"
#include "vector.h"
#include <math.h>


/* Scaling ********************************************************************/


VectorResult scalesv(double_t fac, Vector *vec) {
  if (!is_vec_valid(vec))
    return invalid_vec_res();

  Vector res = new_vec(vec->size, 0);
  for (int i = 0; i < vec->size; i++) {
    res.data[i] = fac * vec->data[i];
  }

  return valid_vec_res(res);
}


/* Dot Product ****************************************************************/


ScalarResult dotvv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return invalid_sca_res();

  if (lhs->size != rhs->size)
    return invalid_sca_res();

  double_t res = 0;
  for (int i = 0; i < lhs->size; i++) {
    res += lhs->data[i] * rhs->data[i];
  }

  return valid_sca_res(res);
}

/* Cross Product **************************************************************/


VectorResult crossvv(Vector *lhs, Vector *rhs) {
  if (!is_vec_valid(lhs) || !is_vec_valid(rhs))
    return invalid_vec_res();

  if (lhs->size != 3 || rhs->size != 3)
    return invalid_vec_res();

  Vector res = new_vec(3, 0);
  res.data[0] = lhs->data[1] * rhs->data[2] - lhs->data[2] * rhs->data[1];
  res.data[1] = lhs->data[2] * rhs->data[0] - lhs->data[0] * rhs->data[2];
  res.data[2] = lhs->data[0] * rhs->data[1] - lhs->data[1] * rhs->data[0];

  return valid_vec_res(res);
}
