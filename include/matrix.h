/**
 * @file matrix.h
 * @brief Matrix struct and associated unary operations
 */

#ifndef ADEQ_MATH_MATRIX_H
#define ADEQ_MATH_MATRIX_H
#include "scalar.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @class Matrix
 * @brief Matrix class
 *
 */
typedef struct Matrix {
  size_t size_x;
  size_t size_y;
  Scalar *data;
  bool valid;
} Matrix;

/**
 * @brief Init a new filled matrix
 * @param size_x
 * @param size_y
 * @param val
 * @return
 */
Matrix new_mat(size_t size_x, size_t size_y);

/**
 * @brief Create an empty matrix. Empty matrices are invalid, and can be used as
 * a fallback return value.
 *
 * @return
 */
Matrix empty_mat();

/**
 * @brief Check if a matrix is empty. This checks all of the fields.
 * @param mat
 * @return true if Matrix is empty
 */
bool is_mat_empty(Matrix *mat);

/**
 * @brief Check if a Matrix instance is valid
 * @param mat
 * @return true if ptr is valid and Vector is valid
 */
bool is_mat_valid(Matrix *mat);

/**
 * @brief Free memory allocated for a Matrix instance
 * @param mat
 * @return
 */
bool free_mat(Matrix *mat);

/**
 * @brief Get value of element of Matrix at position (x, y). This function skips
 * the usual safe checks. Consider useing mat_value() for a safe version.
 *
 * @param mat
 * @param x
 * @param y
 * @return value of element
 */
Scalar mat_value_unsafe(Matrix *mat, size_t x, size_t y);

/**
 * @brief Get value of element of Matrix at position (x, y)
 * @param mat
 * @param x
 * @param y
 * @return value of element
 */
Scalar mat_value(Matrix *mat, size_t x, size_t y);

/**
 * @brief Get pointer to element of Matrix at position (x, y). This function
 * skips the usual safe checks. Consider using mat_at() for a safe version.
 *
 * @param mat
 * @param x
 * @param y
 * @return ptr to element
 */
Scalar *mat_at_unsafe(Matrix *mat, size_t x, size_t y);

/**
 * @brief Get pointer to element of Matrix at position (x, y)
 * @param mat
 * @param x
 * @param y
 * @return ptr to element
 */
Scalar *mat_at(Matrix *mat, size_t x, size_t y);

/* UNARY OPERATIONS ***********************************************************/

#endif // !ADEQ_MATH_MATRIX_H
