#include "Fraction.h"

Fraction::Fraction(int a, int b)
{
  numerator = a;
  denominator = b;

  if (denominator == 0)
  {
    throw "Denominator cannot be zero";
  }

  simplify();
}

Fraction::~Fraction() {}

void Fraction::simplify()
{
  int gcd = 1;
  for (int i = 1; i <= numerator && i <= denominator; i++)
  {
    if (numerator % i == 0 && denominator % i == 0)
    {
      gcd = i;
    }
  }
  numerator /= gcd;
  denominator /= gcd;
}

Fraction Fraction::recripocal()
{
  return Fraction(denominator, numerator);
}

Fraction Fraction::multipliy(int a)
{
  return Fraction(numerator * a, denominator);
}

double Fraction::toDouble()
{
  return (double)numerator / denominator;
}

std::string Fraction::toString()
{
  if (numerator == 0)
  {
    return "0";
  }
  else if (denominator == 1)
  {
    return std::to_string(numerator);
  }
  else
  {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
  }
}