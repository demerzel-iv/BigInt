#include <iostream>
#include "bigint.h"
#include "poly/polynomial.h"

using std::cout;
using std::endl;

int main()
{
    Bint x ("432423"), y ("3"), z("578979");
    Bint a ("119855980179");
    vector<bool> tem = B_to_bin(y);
    cout << x * x << endl;
    cout << (x * x) % z << endl;
    cout << x * ((x * x) % z) << endl;
    cout << (x * ((x * x) % z)) % z << endl;
    cout << modpow_B(x, y, z) <<endl;
    cout << a % z << endl;
    cout << a / z << endl;
    return 0;
}