#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x(987), y(21), z(2);
    vector<bool> q = B_to_bin(x);
    for (int i = 0; i <q.size(); ++i)
    {
        cout << q[i];
    }
    cout << endl;
    cout << bin_to_B(q) << endl;
    cout << pow_B(x, y) << endl;
    cout << modpow_B(z, y, x) << endl;
    return 0;
}