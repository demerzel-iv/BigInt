#include <iostream>
#include <ctime>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x("10000324234000004324230000004123410000000000423400123400"), y(4324324);
    cout << x << endl;
    //clock_t st_time, ed_time;
    //st_time = clock();
    //cout << modpow_B(x, y, z) << endl;
    //ed_time = clock();
    //cout << (double) (ed_time - st_time) / CLOCKS_PER_SEC << endl;
    return 0;
}