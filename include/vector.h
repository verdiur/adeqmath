#ifndef ADEQ_MATH_VECTOR
#define ADEQ_MATH_VECTOR
#include <math.h>
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
  double_t *data;
  bool valid;
} Vector;

/**
 * @class VectorResult
 * @brief Container for a Vector result. If initialized as invalid, the
 * contained vector is guaranteed to be empty (NULL data pointer, 0-size,
 * invalid).
 */
typedef struct VectorResult {
  Vector vec;
  bool valid;
} VectorResult;

/**
 * @brief Init a new filled vector
 * @param size
 * @param val
 * @return Vector
 */
Vector new_vec(size_t size, double_t val);

/**
 * @brief Create a valid VectorResult. This is equivalent to {vec, true}.
 * @param vec
 * @return valid VectorResult
 */
VectorResult valid_vec_res(Vector vec);

/**
 * @brief Create an invalid VectorResult instance. Useful in cases where an
 * operation is forbidden.
 * @return invalid VectorResult
 */
VectorResult invalid_vec_res();

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

#endif // !ADEQ_MATH_VECTOR
