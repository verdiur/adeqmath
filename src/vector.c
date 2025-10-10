#include "vector.h"
#include "scalar.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


Vector new_vec(size_t size) {
  Vector vec;
  vec.size = size;
  vec.data = calloc(size, sizeof(Scalar));
  vec.valid = (vec.data != NULL);
  return vec;
}


Vector new_vec_copy(const Vector *other) {
  if (!is_vec_valid(other))
    return empty_vec();

  size_t n = other->size;
  Vector vec = new_vec(n);
  if (!is_vec_valid(&vec))
    return empty_vec();

  memcpy(vec.data, other->data, n * sizeof(Scalar));
  return vec;
}


Vector new_vec_move(Vector *other) {
  if (!is_vec_valid(other))
    return empty_vec();

  size_t n = other->size;
  Vector vec = new_vec(n);
  if (!is_vec_valid(&vec))
    return empty_vec();

  memcpy(vec.data, other->data, n * sizeof(Scalar));
  *other = empty_vec();
  return vec;
}


Vector empty_vec() {
  Vector vec;
  vec.size = 0;
  vec.data = NULL;
  vec.valid = false;
  return vec;
}


bool is_vec_empty(const Vector *vec) {
  bool size_check = (vec->size == 0);
  bool data_check = (vec->data == NULL);
  bool valid_check = (!vec->valid);
  return size_check && data_check && valid_check;
}


bool copy_vec_at_offset(Vector *dst, const Vector *src, size_t offset) {
  if (!is_vec_valid(dst) || !is_vec_valid(src))
    return false;

  size_t dst_size = dst->size;
  size_t src_size = src->size;

  if (dst_size < src_size)
    return false;
  if (offset > dst_size)
    return false;
  if (src_size > dst_size - offset)
    return false;

  memcpy(dst->data + offset, src->data, src_size * sizeof(Scalar));
  return true;
}


bool is_vec_valid(const Vector *vec) { return vec && vec->valid; }


bool free_vec(Vector *vec) {
  if (!is_vec_valid(vec))
    return false;
  free(vec->data);
  *vec = empty_vec();
  return true;
}
