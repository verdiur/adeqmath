#ifndef ADEQ_MATH_VECTOR
#define ADEQ_MATH_VECTOR
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct Vector {
  size_t size;
  double_t *data;
  bool valid;
} Vector;

/**
 * @brief Init a new filled vector
 * @param size
 * @param val
 * @return Vector
 */
Vector new_vector(size_t size, double_t val);

/**
 * @brief Checks if a Vector instance is valid
 * @param vec
 * @return true if ptr is valid and Vector is valid
 */
bool is_vector_valid(Vector *vec);

/**
 * @brief Free memory allocated for a Vector instance
 * @param vec
 * @return true if successful. false if vector is invalid.
 */
bool free_vector(Vector *vec);

#endif // !ADEQ_MATH_VECTOR
