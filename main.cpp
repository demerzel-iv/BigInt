#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x ("-341223432432431413243"), y ("2123423");

    cout<<x<<endl;

    cout<<x/y<<endl;

    //cout<<x<<" + "<<y<<" = "<<x+y<<endl;
    //cout<<x<<" - "<<y<<" = "<<x-y<<endl;
    //cout<<x<<" * "<<y<<" = "<<x*y<<endl;


    return 0;
}