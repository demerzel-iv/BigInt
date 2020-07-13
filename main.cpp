#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x(32);

    cout<<x%2<<endl;

    return 0;
}