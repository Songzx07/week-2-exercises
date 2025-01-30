#pragma once
#include <string>

class Fraction
{
public:
  Fraction(int a, int b);

  ~Fraction();

  Fraction recripocal();

  Fraction multipliy(int a);

  double toDouble();

  std::string toString();

  int getNumerator();

  int getDenominator();

private:
  int numerator;
  int denominator;
  void simplify();
};