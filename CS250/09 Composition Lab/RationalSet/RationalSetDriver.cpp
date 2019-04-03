#include <iostream>
#include "RationalSet.h"

using namespace std;

int main()
{
    RationalSet cRationalSet;

    Rational cTheRational (4, 1);
    Rational cTheRational2 (3, 1);
    cRationalSet.add (cTheRational);
    cRationalSet.add (cTheRational2);
    cRationalSet.print (cout);
    cRationalSet.print (cout);
    return EXIT_SUCCESS;
}

