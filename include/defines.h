/**
 * @file defines.hh
 * @brief Macro definitions. These can be overriden at build time.
 */

#ifndef ADEQ_MATH_DEFINES_H
#define ADEQ_MATH_DEFINES_H

// this is only for external definition of what the Scalar type expands to. You
// should most likely use the Scalar typedef instead.
// WARNING: ADEQ_SCALAR cannot be expanded into an integer type.
#ifndef ADEQ_SCALAR
#define ADEQ_SCALAR float
#endif // !ADEQ_SCALAR_TYPE

// cache block size
#ifndef ADEQ_BLOCK
#define ADEQ_BLOCK 64
#endif // !ADEQ_BLOCK

#endif // !ADEQ_MATH_DEFINES_H
