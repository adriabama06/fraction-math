#include "include/fraction-math.hh"

#include <iostream>

FMI absoluteNumber(FMI n)
{
    if(n > 0) {
        return n;
    }

    return n * -1;
}

// Constructors

FractionMath::Fraction::Fraction(FMI numerator, FMI denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}
FractionMath::Fraction::Fraction(FMI &numerator, FMI &denominator)
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
FMI FractionMath::Fraction::findReducer()
{
    FMI max_div = 0;
    FMI den = absoluteNumber(this->denominator);

    for (FMI div = 2; div <= den; div++)
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
    FMI max_div = this->findReducer();

    if(max_div == 0) return;

    this->numerator = this->numerator / max_div;
    this->denominator = this->denominator / max_div;
}

// Namespace functions

FractionMath::Fraction FractionMath::FindGenerativeFraction(double number)
{
    Fraction fract(1, 1);

    for (FMI i = 1; fract.getValue<double>() != number; i *= 10)
    {
        fract.numerator = number * i;
        fract.denominator = i;
    }
    
    return fract;
}

// Operators Fraction

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

// Operators Fraction + Number

FractionMath::Fraction operator+(const FractionMath::Fraction& a, const int& b)
{
    return a + FractionMath::Fraction(b, 1);
}
FractionMath::Fraction operator+(const FractionMath::Fraction& a, const double& b)
{
    return a + FractionMath::FindGenerativeFraction(b);
}


FractionMath::Fraction operator-(const FractionMath::Fraction& a, const int& b)
{
    return a - FractionMath::Fraction(b, 1);
}
FractionMath::Fraction operator-(const FractionMath::Fraction& a, const double& b)
{
    return a - FractionMath::FindGenerativeFraction(b);
}


FractionMath::Fraction operator*(const FractionMath::Fraction& a, const int& b)
{
    return a * FractionMath::Fraction(b, 1);
}
FractionMath::Fraction operator*(const FractionMath::Fraction& a, const double& b)
{
    return a * FractionMath::FindGenerativeFraction(b);
}


FractionMath::Fraction operator/(const FractionMath::Fraction& a, const int& b)
{
    return a / FractionMath::Fraction(b, 1);
}
FractionMath::Fraction operator/(const FractionMath::Fraction& a, const double& b)
{
    return a / FractionMath::FindGenerativeFraction(b);
}