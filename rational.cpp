//
// Created by 1311959 on 29.10.2020.
//

#include <numeric>
#include "rational.h"

rational_num::rational_num() {
  up = 0;
  down = 1;
  result = 0;
}

rational_num::rational_num(int u, unsigned int d) {
  up = u;
  down = d;
  result = up / down;
}

rational_num &rational_num::reduction() {
  int del = std::gcd(this->up, this->down);
  this->down /= del;
  this->up /= del;
  result = up / down;
  return *this;
}

rational_num &rational_num::operator=(const rational_num &other) {
  up = other.up;
  down = other.down;
  result = up / down;
  return *this;
}

rational_num rational_num::operator+(const rational_num &other) const {
  unsigned res_down = this->down * other.down;
  int res_up = this->up * other.down + this->down * other.up;
  return rational_num(res_up, res_down);
}

rational_num rational_num::operator-(const rational_num &other) const {
  unsigned res_down = this->down * other.down;
  int res_up = this->up * other.down - this->down * other.up;
  return rational_num(res_up, res_down);
}

rational_num rational_num::operator*(const rational_num &other) {
  unsigned res_down = this->down * other.down;
  int res_up = this->up * other.up;
  return rational_num(res_up, res_down);
}
rational_num rational_num::operator/(const rational_num &other) {
  unsigned res_down = this->down * other.up;
  int res_up = this->up * other.down;
  return rational_num(res_up, res_down);
}
bool rational_num::operator==(const rational_num &other) const {
  return (this->result == other.result);
}

rational_num rational_num::operator-() {
  return rational_num(-this->up, down);
}

std::ostream &operator<<(std::ostream &out, rational_num &num) {
  out << num.up << '/' << num.down;
  return out;
}
};