#include "vector.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

Vector new_vector(size_t size, double_t val) {
  Vector vec;
  vec.size = size;
  vec.data = calloc(val, size * sizeof(double_t));
  vec.valid = vec.data;
  return vec;
}

bool is_vector_valid(Vector *vec) { return vec && vec->valid; }


bool free_vector(Vector *vec) {
  if (!is_vector_valid(vec))
    return false;
  free(vec->data);
  return true;
}
