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
  complex_num(rational_num r, rational_num im); // test done
  complex_num(int real_up, unsigned real_down, int im_up , unsigned int im_down); // test done
  complex_num &operator=(const complex_num &other);   //test done

  complex_num operator+(const complex_num &other); // test done

  complex_num operator-(const complex_num &other); // test done

  complex_num operator*(const complex_num &other);  // test done
  complex_num operator/( complex_num &other);  // test done
  friend bool operator==(const complex_num &left, const complex_num &right); // test done
  friend bool operator!=(const complex_num &left, const complex_num &right); // test done
  complex_num &operator+=(const complex_num &other);  // test done

  complex_num &operator-=(const complex_num &other); // test done

  complex_num operator-(); // test done

  friend std::ostream &operator<<(std::ostream &out, complex_num num); // done
  complex_num operator^(unsigned int n);
  double abs() ; // done
  rational_num getreal() const;  // test done
  rational_num getimage() const; // test done
  complex_num &setreal(rational_num other); // test done
  complex_num &setimage(rational_num other); // test done
  double argv(); // test done
};
#endif //COMPLEX_NUMBERS__COMPLEX_H_
