#include <iostream>
#include <ctime>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x(987), y(21), z(1027);
    clock_t st_time, ed_time;
    st_time = clock();
    //cout << modpow_B(x, y, z) << endl;
    Bint a(974169), b(1027);
    cout << (a >= b) << endl;
    cout << a/b << endl;
    cout << a%b << endl;
    ed_time = clock();
    cout << (double) (ed_time - st_time) / CLOCKS_PER_SEC << endl;
    return 0;
}