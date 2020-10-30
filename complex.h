//
// Created by 1311959 on 29.10.2020.
//

#ifndef COMPLEX_NUMBERS__COMPLEX_H_
#define COMPLEX_NUMBERS__COMPLEX_H_
#include "rational.h"
class complex_num {
 public:
  rational_num real;
  rational_num imagine;
  complex_num(rational_num r, rational_num im);

  complex_num &operator=(const complex_num &other);

  complex_num operator+(const complex_num &other);

  complex_num operator-(const complex_num &other);

  complex_num operator*(const complex_num &other);

  bool operator==(complex_num &other);

  bool operator!=(const complex_num *other);
  complex_num &operator+=(const complex_num &other);

  complex_num &operator-=(const complex_num &other);

  complex_num operator-();

  friend std::ostream &operator<<(std::ostream &out, complex_num num);
  complex_num operator^(unsigned int n);
  double abs() const;
  rational_num getreal() const;
  rational_num getimage() const;
  complex_num &setreal(rational_num other);
  complex_num &setimage(rational_num other);
  double argv();
};
#endif //COMPLEX_NUMBERS__COMPLEX_H_
