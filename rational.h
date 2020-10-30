//
// Created by 1311959 on 29.10.2020.
//

#ifndef COMPLEX_NUMBERS__RATIONAL_H_
#define COMPLEX_NUMBERS__RATIONAL_H_
#include <iostream>
class rational_num {

 public:
  int up;
  unsigned int down;
  double result;
  rational_num();
  explicit rational_num(int u, unsigned int d);

  rational_num &reduction();

  rational_num &operator=(const rational_num &other);

  rational_num operator+(const rational_num &other) const;

  rational_num operator-(const rational_num &other) const;

  rational_num operator*(const rational_num &other);
  rational_num operator/(const rational_num &other);
  bool operator==(const rational_num &other) const;

  rational_num operator-();

  friend std::ostream &operator<<(std::ostream &out, rational_num &num);
};
#endif //COMPLEX_NUMBERS__RATIONAL_H_
