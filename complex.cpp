//
// Created by 1311959 on 29.10.2020.
//

#include "complex.h"
#include <cmath>
complex_num::complex_num(rational_num r, rational_num im) {
  real = r;
  imagine = im;
}
complex_num::complex_num(int real_up, unsigned real_down, int im_up , unsigned int im_down) {
    real = rational_num(real_up,real_down);
    imagine = rational_num(im_up,im_down);
}

complex_num &complex_num::operator=(const complex_num &other) {
  real = other.real;
  imagine = other.imagine;
  return *this;
}

complex_num complex_num::operator+(const complex_num &other) {
  rational_num first = other.real;
  rational_num second = other.imagine;
  return complex_num(first + this->real, second + this->imagine);
}

complex_num complex_num::operator-(const complex_num &other) {
  rational_num first = other.real;
  rational_num second = other.imagine;
  return complex_num(this->real - first , this->imagine- second );
}

complex_num complex_num::operator*(const complex_num &other) {
  rational_num first = this->real * other.real - this->imagine * other.imagine;
  rational_num second = this->real * other.imagine + this->imagine * other.real;
  return complex_num(first, second);
}
complex_num complex_num::operator/(complex_num &other) {
  rational_num
      first = (this->real * other.real + this->imagine * other.imagine) / ((other.real ^ 2) + (other.imagine ^ 2));
  rational_num
      second = (other.real * this->imagine - this->real * other.imagine) / ((other.real ^ 2) + (other.imagine ^ 2));
  return complex_num(first, second);
}

bool operator==(const complex_num &left, const complex_num &right)  {
    return (left.real == right.real && left.imagine == right.imagine);
}
bool operator!=(const complex_num &left, const complex_num &right) {
    return ((!(left.real == right.real)) || (!(left.imagine == right.imagine)));
}

complex_num &complex_num::operator+=(const complex_num &other) {
  this->real = this->real + other.real;
  this->imagine = this->imagine + other.imagine;
  return *this;
}

complex_num &complex_num::operator-=(const complex_num &other) {
  this->real = this->real - other.real;
  this->imagine = this->imagine - other.imagine;
  return *this;
}

complex_num complex_num::operator-() {
  return complex_num(-this->real, -this->imagine);
}

std::ostream &operator<<(std::ostream &out, complex_num num) {
  out << num.real << '+' << num.imagine << 'i';
  return out;
}
complex_num complex_num::operator^(unsigned int n) {
  complex_num result = *this * *this;
  for (int i = 0; i < n - 2; i++) {
    result = result * *this;
  }
  return result;
}
double complex_num::abs() {
  double buf = round(std::sqrt((this->real * this->real).result + (this->imagine * this->imagine).result)* 1000) / 1000;
  return buf;
}
rational_num complex_num::getreal() const {
  return this->real;
}
rational_num complex_num::getimage() const {
  return this->imagine;
}
complex_num &complex_num::setreal(rational_num other) {
  this->real = other;
  return *this;
}
complex_num &complex_num::setimage(rational_num other) {
  this->imagine = other;
  return *this;
}
double complex_num::argv() {
  return round(atan2(this->imagine.result, this->real.result)*1000)/1000;
}