#include "bigint.h"

unsigned int Bint :: size() const
{
    return siz;
}

Bint :: Bint(int x)
{
    if (x >= 0) sign = positive;
    else sign = negative;
    int tem;
    if (sign) tem = x;
    else tem = -x;
    siz = 0;
    while (tem != 0)
    {
        s.push_back((int)(tem%10));
        tem /= 10;
        ++siz;
    }
}

Bint :: Bint(long long x)
{
    if (x >= 0) sign = positive;
    else sign = negative;
    long long tem;
    if (sign) tem = x;
    else tem = -x;
    siz = 0;
    while (tem != 0)
    {
        s.push_back((int)(tem%10));
        tem /= 10;
        ++siz;
    }
}
Bint :: Bint(string x)
{
    int tem = x.size();
    if (x[0] == '-')
    {
        sign = negative;
        siz = tem - 1;
    }
    else 
    {
        sign = positive;
        siz = tem;
    }
    for (int i = tem - 1; i >= (int)(tem - siz); --i)
    {
        s.push_back((x[i] - '0'));
    }
}

int Bint :: operator [] (int i) const
{
    return s[i];
}

int& Bint :: operator [] (int i)
{
    return s[i];
}