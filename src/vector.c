#include "vector.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

Vector new_vec(size_t size, double_t val) {
  Vector vec;
  vec.size = size;
  vec.data = calloc(val, size * sizeof(double_t));
  vec.valid = vec.data;
  return vec;
}


VectorResult valid_vec_res(Vector vec) {
  VectorResult ret = {vec, true};
  return ret;
}


VectorResult invalid_vec_res() {
  Vector vec;
  vec.size = 0;
  vec.data = NULL;
  vec.valid = false;

  VectorResult ret = {vec, false};
  return ret;
}


bool is_vec_valid(Vector *vec) { return vec && vec->valid; }


bool free_vec(Vector *vec) {
  if (!is_vec_valid(vec))
    return false;
  free(vec->data);
  return true;
}
