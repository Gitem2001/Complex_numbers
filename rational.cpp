//
// Created by 1311959 on 29.10.2020.
//

#include <numeric>
#include "rational.h"
#include <cmath>

rational_num::rational_num() {
    up = 0;
    down = 1;
    result = 0;
}

rational_num::rational_num(int u, unsigned int d) {
    up = u;
    down = d;
    result = round((double(up)/double(down)) * 1000) / 1000;
}

rational_num &rational_num::reduction() {
    int del = std::gcd(this->up, this->down);
    this->down /= del;
    this->up /=  del;
    result = round((double(up)/double(down)) * 1000) / 1000;
    return *this;
}

rational_num &rational_num::operator=(const rational_num &other) {
    up = other.up;
    down = other.down;
    result = round((double(up)/double(down)) * 1000) / 1000;
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

rational_num rational_num::operator^(unsigned int n) {
    rational_num result = *this * *this;
    for (int i = 0; i < n - 2; i++) {
        result = result * *this;
    }
    return result;
}