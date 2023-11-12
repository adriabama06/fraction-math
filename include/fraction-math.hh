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
} // namespace FractionMath

FractionMath::Fraction operator+(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator-(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator*(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator/(const FractionMath::Fraction& a, const FractionMath::Fraction& b);

std::ostream& operator<<(std::ostream& os, const FractionMath::Fraction& fraction);

#endif
