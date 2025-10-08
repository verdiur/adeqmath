#include "scalar.h"


ScalarResult valid_sca_res(double_t scalar) {
  ScalarResult ret = {scalar, true};
  return ret;
}


ScalarResult invalid_sca_res() {
  ScalarResult ret = {0, false};
  return ret;
}
