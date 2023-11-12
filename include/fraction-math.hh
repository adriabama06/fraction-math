#ifndef FRACTION_MATH_H
#define FRACTION_MATH_H

#include <ostream>
#include <cstdint>

// FMI : FRACTION_MATH_INTEGER
#define FMI signed long

namespace FractionMath
{
    class Fraction
    {
    public:
        FMI numerator;
        FMI denominator;

        Fraction(FMI numerator, FMI denominator);
        Fraction(FMI& numerator, FMI& denominator);
        Fraction();

        template<typename T>
        T getValue()
        {
            return static_cast<T>(this->numerator) / static_cast<T>(this->denominator);
        }
        FMI findReducer();
        void reduce();
    };


    // Namespace functions

    Fraction FindGenerativeFraction(double number);
} // namespace FractionMath


// *** Operators Fraction ***

FractionMath::Fraction operator+(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator-(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator*(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator/(const FractionMath::Fraction& a, const FractionMath::Fraction& b);


// *** Operators Fraction + Number ***

FractionMath::Fraction operator+(const FractionMath::Fraction& a, const int& b);
FractionMath::Fraction operator+(const FractionMath::Fraction& a, const double& b);

FractionMath::Fraction operator-(const FractionMath::Fraction& a, const int& b);
FractionMath::Fraction operator-(const FractionMath::Fraction& a, const double& b);

FractionMath::Fraction operator*(const FractionMath::Fraction& a, const int& b);
FractionMath::Fraction operator*(const FractionMath::Fraction& a, const double& b);

FractionMath::Fraction operator/(const FractionMath::Fraction& a, const int& b);
FractionMath::Fraction operator/(const FractionMath::Fraction& a, const double& b);


std::ostream& operator<<(std::ostream& os, const FractionMath::Fraction& fraction);

#endif
