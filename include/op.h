#ifndef ADEQ_MATH_OP_H
#define ADEQ_MATH_OP_H
#include "scalar.h"
#include <stdint.h>

// fwd
typedef struct Vector Vector;
typedef struct Matrix Matrix; // TODO:

/* SCALE **********************************************************************/

Vector scalesv(Scalar fac, Vector *vec);
Matrix scalesm(Scalar fac, Matrix *mat); // TODO:

/* DOT PRODUCT ****************************************************************/

Scalar dotvv(Vector *lhs, Vector *rhs);

/* CROSS PRODUCT **************************************************************/

Vector crossvv(Vector *lhs, Vector *rhs);

#endif // !ADEQ_MATH_OP_H
