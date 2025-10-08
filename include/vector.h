#ifndef ADEQ_MATH_VECTOR_H
#define ADEQ_MATH_VECTOR_H
#include "scalar.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @class Vector
 * @brief Vector class. Vectors are more lightweight than Matrixes. It might be
 * relevant to use them if you are certain you will only perform vector-wise
 * operations. Otherwise use a Matrix.
 *
 */
typedef struct Vector {
  size_t size;
  Scalar *data;
  bool valid;
} Vector;

/**
 * @brief Init a new filled vector
 * @param size
 * @param val
 * @return Vector
 */
Vector new_vec(size_t size, Scalar val);

/**
 * @brief Create an empty vector. Empty vectors are invalid, and can be used as
 * a fallback return value.
 *
 * @return empty Vector instance
 */
Vector empty_vec();

/**
 * @brief Check if a vector is empty. This checks all of the fields.
 * @param vec
 * @return true if Vector is empty
 */
bool is_vec_empty(Vector *vec);

/**
 * @brief Checks if a Vector instance is valid
 * @param vec
 * @return true if ptr is valid and Vector is valid
 */
bool is_vec_valid(Vector *vec);

/**
 * @brief Free memory allocated for a Vector instance
 * @param vec
 * @return true if successful. false if vector is invalid.
 */
bool free_vec(Vector *vec);

#endif // !ADEQ_MATH_VECTOR_H
