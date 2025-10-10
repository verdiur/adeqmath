#ifndef ADEQ_MATH_VECTOR_OP_H
#define ADEQ_MATH_VECTOR_OP_H
#include "scalar.h"


// fwd
typedef struct Vector Vector;
typedef struct Matrix Matrix;


/**
 * @brief Calculate sum of two vectors of same size
 * @param lhs
 * @param rhs
 * @return sum
 */
Vector sum_vv(Vector *lhs, Vector *rhs);
// @brief unsafe vector sum
Vector unsafe_sum_vv(Vector *lhs, Vector *rhs);


/**
 * @brief Calculate difference of two vectors of same size
 * @param lhs
 * @param rhs
 * @return difference
 */
Vector diff_vv(Vector *lhs, Vector *rhs);
// @brief unsafe vector difference
Vector unsafe_diff_vv(Vector *lhs, Vector *rhs);


/**
 * @brief Calculate scaled vector
 * @param fac
 * @param vec
 * @return scaled vector
 */
Vector scale_sv(Scalar fac, Vector *vec);
// @brief unsafe scaled vector
Vector unsafe_scale_sv(Scalar fac, Vector *vec);


/**
 * @brief Calculate dot product of vectors
 * @param lhs
 * @param rhs
 * @return dot product
 */
Scalar dot_vv(Vector *lhs, Vector *rhs);
// @brief unsafe vector dot product
Scalar unsafe_dot_vv(Vector *lhs, Vector *rhs);


/**
 * @brief Calculate cross product of vectors. Undefined for vectors with size
 * != 3.
 * @param lhs
 * @param rhs
 * @return cross product
 */
Vector cross_vv(Vector *lhs, Vector *rhs);
// @brief unsafe vector cross product
Vector unsafe_cross_vv(Vector *lhs, Vector *rhs);


/**
 * @brief Calculate L-norm of a vector
 *
 * @param vec
 * @param order Order of the L-norm. The function is undefined for `[-inf, 0]`.
 * An order of 2 corresponds to an euclidean norm.
 * @return L-norm of the vector
 */
Scalar lnorm_v(Vector *vec, int order);
// @brief unsafe vector L-norm
Scalar unsafe_lnorm_v(Vector *vec, int order);


/**
 * @brief Calculate L-distance between two vectors. Undefined for vectors of
 * different sizes.
 * @param lhs
 * @param rhs
 * @param order Order of the L-distance. The function is undefined for `[-inf,
 * 0]`. An order of 2 corresponds to an euclidean distance.
 * @return L-distance of the vector
 */
Scalar ldistance_vv(Vector *lhs, Vector *rhs, int order);
// @brief unsafe vector L-distance
Scalar unsafe_ldistance_vv(Vector *lhs, Vector *rhs, int order);


#endif // !ADEQ_MATH_VECTOR_OP_H
