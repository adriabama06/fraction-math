#include "include/fraction-math.hh"

#include <iostream>

FRACTION_MATH_INTEGER absoluteNumber(FRACTION_MATH_INTEGER n)
{
    if(n > 0) {
        return n;
    }

    return n * -1;
}

// Constructors

FractionMath::Fraction::Fraction(FRACTION_MATH_INTEGER numerator, FRACTION_MATH_INTEGER denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}
FractionMath::Fraction::Fraction(FRACTION_MATH_INTEGER &numerator, FRACTION_MATH_INTEGER &denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}
FractionMath::Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 0;
}

// Functions

/**
 * @returns 0 if can't find a reducer else return the max reducer
*/
FRACTION_MATH_INTEGER FractionMath::Fraction::findReducer()
{
    FRACTION_MATH_INTEGER max_div = 0;
    FRACTION_MATH_INTEGER den = absoluteNumber(this->denominator);

    for (FRACTION_MATH_INTEGER div = 2; div <= den; div++)
    {
        if(this->numerator % div == 0 && this->denominator % div == 0)
        {
            max_div = div;
        }
    }

    return max_div;
}

void FractionMath::Fraction::reduce()
{
    FRACTION_MATH_INTEGER max_div = this->findReducer();

    if(max_div == 0) return;

    this->numerator = this->numerator / max_div;
    this->denominator = this->denominator / max_div;
}

// Operators

FractionMath::Fraction operator+(const FractionMath::Fraction &a, const FractionMath::Fraction &b)
{
    FractionMath::Fraction newFraction;

    newFraction.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
    newFraction.denominator = a.denominator * b.denominator;
    
    return newFraction;
}

FractionMath::Fraction operator-(const FractionMath::Fraction &a, const FractionMath::Fraction &b)
{
    FractionMath::Fraction newFraction;

    newFraction.numerator = (a.numerator * b.denominator) - (a.denominator * b.numerator);
    newFraction.denominator = a.denominator * b.denominator;
    
    return newFraction;
}

FractionMath::Fraction operator*(const FractionMath::Fraction& a, const FractionMath::Fraction& b)
{
    FractionMath::Fraction newFraction;

    newFraction.numerator = a.numerator * b.numerator;
    newFraction.denominator = a.denominator * b.denominator;
    
    return newFraction;
}

FractionMath::Fraction operator/(const FractionMath::Fraction& a, const FractionMath::Fraction& b)
{
    FractionMath::Fraction newFraction;

    newFraction.numerator = a.numerator * b.denominator;
    newFraction.denominator = a.denominator * b.numerator;
    
    return newFraction;
}

std::ostream& operator<<(std::ostream& os, const FractionMath::Fraction& fraction)
{
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}