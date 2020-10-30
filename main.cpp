#include <iostream>
#include <numeric>
#include <cmath>
#include <string>
#include "rational.h"
#include "complex.h"
int main() {
  rational_num a(4, 3);
  rational_num b(2, 3);
  complex_num c(a, b);
  rational_num d(1, 2);
  rational_num z(2, 2);
  complex_num s(d, z);
  std::cout << c + s;
  return 0;
}
