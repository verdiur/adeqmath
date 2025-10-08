#ifndef ADEQ_MATH_OP
#define ADEQ_MATH_OP
#include <math.h>
#include <stdint.h>

// fwd

typedef struct ScalarResult ScalarResult;
typedef struct Vector Vector;
typedef struct VectorResult VectorResult;
typedef struct Matrix Matrix; // TODO:
typedef struct MatrixResult MatrixResult;

VectorResult scalesv(double_t fac, Vector *vec);
MatrixResult scalesm(double_t fac, Matrix *mat); // TODO:

ScalarResult dotvv(Vector *lhs, Vector *rhs);

VectorResult crossvv(Vector *lhs, Vector *rhs);

#endif // !ADEQ_MATH_OP
