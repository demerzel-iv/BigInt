#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x ("982446080941232314213") , y ("-982446080941232314213");

    Bint z ("-0");

    cout<<x+y<<endl;
    cout<<y+x<<endl;
    cout<<z<<endl;
    cout<<(z==0)<<endl;

    return 0;
}