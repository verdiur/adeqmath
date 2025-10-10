/**
 * @file vector.hh
 * @brief Vector struct
 */

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
Vector new_vec(size_t size);

/**
 * @brief Copy initialize from another vector
 * @param other Vector from which to copy data.
 * @return new vector with copied data
 */
Vector new_vec_copy(const Vector *other);

/**
 * @brief Move initialize from another vector
 * @param other Vector from which to move data. Will be emptied.
 * @return new vector with moved data
 */
Vector new_vec_move(Vector *other);

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
bool is_vec_empty(const Vector *vec);

/**
 * @brief Checks if a Vector instance is valid
 * @param vec
 * @return true if ptr is valid and Vector is valid
 */
bool is_vec_valid(const Vector *vec);

/**
 * @brief Copy the contents of a source vector into a destination vector
 * starting from the specified offset. Destination vector must be at least the
 * same size as the source, and the offset + the size of the source vector must
 * not be larger than the size of the destination vector.
 * @param dst
 * @param src
 * @param offset Index of dst from which to start moving the contents of src.
 * @return true if successful
 */
bool copy_vec_at_offset(Vector *dst, const Vector *src, size_t offset);

/**
 * @brief Free memory allocated for a Vector instance
 * @param vec
 * @return true if successful. false if vector is invalid.
 */
bool free_vec(Vector *vec);

#endif // !ADEQ_MATH_VECTOR_H
