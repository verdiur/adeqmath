#include "vector.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


Vector new_vec(size_t size) {
  Vector vec;
  vec.size = size;
  vec.data = calloc(size, sizeof(double_t));
  vec.valid = vec.data;
  return vec;
}


Vector empty_vec() {
  Vector vec;
  vec.size = 0;
  vec.data = NULL;
  vec.valid = false;
  return vec;
}


bool is_vec_empty(Vector *vec) {
  bool size_check = (vec->size == 0);
  bool data_check = (vec->data == NULL);
  bool valid_check = (!vec->valid);
  return size_check && data_check && valid_check;
}


bool is_vec_valid(Vector *vec) { return vec && vec->valid; }


bool free_vec(Vector *vec) {
  if (!is_vec_valid(vec))
    return false;
  free(vec->data);
  return true;
}
