#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x ("-1239283452197432"), y ("-9081239218397914");

    cout<<x<<" + "<<y<<" = "<<x+y<<endl;
    cout<<x<<" - "<<y<<" = "<<x-y<<endl;
    cout<<x<<" * "<<y<<" = "<<x*y<<endl;

    return 0;
}