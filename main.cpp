#include <iostream>
#include "rational.h"
#include "complex.h"
#include "catch_amalgamated.hpp"
#include <fstream>
TEST_CASE("Tests for complex_numbers") {
    SECTION("Contructors for complex_numbers","[constuctors]"){
        rational_num a(5,1);
        rational_num b(6,1);
        complex_num c(a,b);
        complex_num d(5,1,6,1);
        REQUIRE(c == d);
    }
    SECTION("Operators = for complex num", "[=]"){
        complex_num a(10204,15,8664,2);
        complex_num b = a;
        REQUIRE(a==b);
        complex_num c = - b;
        REQUIRE(c == -(a));
    }
    SECTION("Operators +, += for complex num", "[+ +=]" ){
        complex_num a(1403,5,1202,10);
        complex_num b(5604,42,1802,25);
        complex_num c = a+b;
        REQUIRE(c.getreal().result == 414.029);
        REQUIRE(c.getimage().result == 192.28);
        c+=a;  // с положительными
        REQUIRE(c.getreal().result == 694.629);
        REQUIRE(c.getimage().result == 312.48);
        c+=-(a);   // проверка на сложение с отрицательными
        REQUIRE(c.getreal().result == 414.029);
        REQUIRE(c.getimage().result == 192.28);
    }
    SECTION("Operators -, -= for complex num", "[- -=]" ){
        complex_num a(2543,12,5634,78);
        complex_num b(13745,34,17875,24);
        complex_num c = a - b;
        REQUIRE(c.getreal().result == -192.348);
        REQUIRE(c.getimage().result == -672.561);
        c -= (-a); // проверка на сложение с отрицательными
        REQUIRE(c.getreal().result == 19.569);
        REQUIRE(c.getimage().result == -600.33);
    }
    SECTION("Operators * / for complex_num", "[* /]" ){
        complex_num a(12,2,6,1);
        complex_num b(15,3,4,2);
        complex_num c = a * b;
        REQUIRE(c.getreal().result == 18.0);
        REQUIRE(c.getimage().result == 42.0);
        c = a / b;
        REQUIRE(c.getreal().result == 1.448);
        REQUIRE(c.getimage().result == 0.621);
    }
    SECTION("Operators ^ for complex_num", "[^]" ){
        complex_num a(12,2,6,1);
        complex_num b = a^3;
        REQUIRE(b  == a*a*a);
    }
    SECTION("Operator - for complex num", "[-]" ){
        complex_num a(2543,12,5634,78);
        complex_num b = -a;
        REQUIRE(b.real.result == -211.917);
        REQUIRE(b.imagine.result == -72.231);
        complex_num c = -b;
        REQUIRE(c.real.result == 211.917);
        REQUIRE(c.imagine.result == 72.231);
    }
    SECTION("Functions get  for complex_num", "[get]" ){
        complex_num a(2543,12,5634,78);
        REQUIRE(a.getreal().result == 211.917);
        REQUIRE(a.getimage().result == 72.231);
    }
    SECTION("Function abs() for complex_num", "[abs]" ){
        complex_num a(2543,12,5634,78);
        REQUIRE(a.abs() == 223.888);
    }
    SECTION("Function set image, set real for complex_num", "[set]" ){
        complex_num a(7645,3645,678234,23);
        rational_num b (5,1);
        rational_num c (10,1);
        a.setreal(b);
        a.setimage(c);
        REQUIRE(a.real == b);
        REQUIRE(a.imagine == c);
    }
    SECTION("Function argv  for complex_num", "[argv]" ){
        complex_num a(2256,24,45633,1235);
        REQUIRE(a.argv() == 0.375);
    }
    SECTION("Operators <<  for complex_num", "[<<]" ){
        complex_num a(12,1,17,13);
        std::ofstream fout("output.txt");
        fout<<a.imagine.up;
        fout.close();
        std::ifstream fin("output.txt");
        int b= 0;
        fin>>b;
        fin.close();
        REQUIRE( b == 17);
    }
    SECTION("Operators == != for complex_num", "[== !=]" ){
        complex_num a(16,12,4,1);
        complex_num b(12,12,4,1);
        REQUIRE( a == a);
        REQUIRE(a != b);
    }
}


