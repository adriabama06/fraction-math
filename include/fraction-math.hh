#ifndef FRACTION_MATH_H
#define FRACTION_MATH_H

#include <ostream>
#include <cstdint>

#define FRACTION_MATH_INTEGER signed long

namespace FractionMath
{
    class Fraction
    {
    public:
        FRACTION_MATH_INTEGER numerator;
        FRACTION_MATH_INTEGER denominator;

        Fraction(FRACTION_MATH_INTEGER numerator, FRACTION_MATH_INTEGER denominator);
        Fraction(FRACTION_MATH_INTEGER& numerator, FRACTION_MATH_INTEGER& denominator);
        Fraction();

        template<typename T>
        T getValue()
        {
            return static_cast<T>(this->numerator) / static_cast<T>(this->denominator);
        }
        FRACTION_MATH_INTEGER findReducer();
        void reduce();
    };
} // namespace FractionMath

FractionMath::Fraction operator+(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator-(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator*(const FractionMath::Fraction& a, const FractionMath::Fraction& b);
FractionMath::Fraction operator/(const FractionMath::Fraction& a, const FractionMath::Fraction& b);

std::ostream& operator<<(std::ostream& os, const FractionMath::Fraction& fraction);

#endif
