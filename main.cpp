#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x ("-3123214214124124398437591097872109709174239241223432432431413243"), y ("21234232398473205056");

    cout<<x<<endl;

    cout<<(x/y)*y + (x%y) <<endl;

    cout<<x/y<<endl;

    //cout<<x<<" + "<<y<<" = "<<x+y<<endl;
    //cout<<x<<" - "<<y<<" = "<<x-y<<endl;
    //cout<<x<<" * "<<y<<" = "<<x*y<<endl;


    return 0;
}