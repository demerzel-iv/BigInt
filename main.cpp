#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x ("43243123123"), y ("3432434"), z("57893213123213");
    Bint a ("119855980179");
    Bint ts("-00000000");
    cout << (ts == 0) << endl;
    cout << modpow_B(x, y, z) << endl;
    return 0;
}