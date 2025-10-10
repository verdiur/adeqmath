#include "matrix.h"
#include "scalar.h"
#include <math.h>
#include <stdlib.h>


Matrix new_mat(size_t size_x, size_t size_y) {
  Matrix mat;
  mat.size_x = size_x;
  mat.size_y = size_y;
  mat.data = calloc(size_x * size_y, sizeof(Scalar));
  mat.valid = mat.data;
  return mat;
}


Matrix empty_mat() {
  Matrix mat;
  mat.size_x = 0;
  mat.size_y = 0;
  mat.data = NULL;
  mat.valid = false;
  return mat;
}


bool is_mat_empty(Matrix *mat) {
  bool size_check = (mat->size_x == 0 && mat->size_y == 0);
  bool data_check = (mat->data == NULL);
  bool valid_check = (!mat->valid);
  return size_check && data_check && valid_check;
}


bool is_mat_valid(Matrix *mat) { return mat && mat->valid; }


bool free_mat(Matrix *mat) {
  if (!is_mat_valid(mat))
    return false;
  free(mat->data);
  return true;
}


Scalar mat_value_unsafe(Matrix *mat, size_t x, size_t y) {
  return mat->data[y * mat->size_x + x];
}


Scalar mat_value(Matrix *mat, size_t x, size_t y) {
  if (!is_mat_valid(mat))
    return NAN;
  if ((mat->size_x <= x) || (mat->size_y <= y))
    return NAN;
  return mat_value_unsafe(mat, x, y);
}


Scalar *mat_at_unsafe(Matrix *mat, size_t x, size_t y) {
  return &mat->data[y * mat->size_x + x];
}


Scalar *mat_at(Matrix *mat, size_t x, size_t y) {
  if (!is_mat_valid(mat))
    return NULL;
  if ((mat->size_x <= x) || (mat->size_y <= y))
    return NULL;
  return mat_at_unsafe(mat, x, y);
}
