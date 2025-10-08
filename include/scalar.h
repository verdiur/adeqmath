#ifndef ADEQ_MATH_SCALAR
#define ADEQ_MATH_SCALAR
#include <math.h>
#include <stdbool.h>

/**
 * @class ScalarResult
 * @brief Container for a scalar result. If initialized as invalid, the
 * contained scalar is guaranteed to be zero-initialized.
 *
 */
typedef struct ScalarResult {
  double_t scalar;
  bool valid;
} ScalarResult;

/**
 * @brief Create a valid ScalarResult instance.
 * @return valid ScalarResult
 */
ScalarResult valid_sca_res(double_t scalar);

/**
 * @brief Create an invalid ScalarResult instance.
 * @return invalid ScalarResult
 */
ScalarResult invalid_sca_res();

#endif // !ADEQ_MATH_SCALAR
