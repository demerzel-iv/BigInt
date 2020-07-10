#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    poly A = {1,2,3};
    poly B = {1,4,3};

    cout<<(A^2)<<endl;
    cout<<A*B<<endl;

    Bint x (123);

    cout<<x.size()<<endl;

    return 0;
}