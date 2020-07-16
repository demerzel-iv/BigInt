#include <iostream>
#include <ctime>
#include "bigint.h"

using std::cout;
using std::endl;

int main()
{
    Bint x("120189730872014711233840359473"), y(4324324);

    Bint z = (41251230);
    cout<<z<<endl;

    cout << x/z<< endl;
    cout << x/41251230 << endl;

    //clock_t st_time, ed_time;
    //st_time = clock();
    //cout << modpow_B(x, y, z) << endl;
    //ed_time = clock();
    //cout << (double) (ed_time - st_time) / CLOCKS_PER_SEC << endl;
    return 0;
}