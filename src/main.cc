#include "include/fraction-math.hh"

#include <iostream>

using namespace std;

int main()
{
    FractionMath::Fraction x(54, -90);

    cout << x << endl;
    cout << "Reducer: " << x.findReducer() << endl;
    x.reduce();
    cout << x << endl;
}