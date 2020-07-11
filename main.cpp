#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x("-00000123456");
    cout << x << endl;
//  cout << modpow_B(x, y, z);
    return 0;
}