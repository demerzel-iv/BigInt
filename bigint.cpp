#include "bigint.h"
#include "poly/polynomial.h"

unsigned int Bint :: size() const
{
    return siz;
}

int Bint :: echo_sign() const
{
    return sign;
}

Bint :: Bint(int x)
{
    if (x >= 0) sign = positive;
    else sign = negative;
    int tem;
    if (sign > 0) tem = x;
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
    if (sign > 0) tem = x;
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

Bint Bint :: operator - (void)
{
    Bint tem = *this;
    tem.sign = -tem.sign;
    return tem;
}

bool operator == (const Bint &A, const Bint &B)
{
    if (A.echo_sign() != B.echo_sign()) return 0;
    if (A.size() != B.size()) return 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] != B[i]) return 0;
    }
    return 1;
}

bool operator != (const Bint &A, const Bint &B)
{
    if (A == B) return 0;
    else return 1;    
}

bool operator < (const Bint &A, const Bint &B)
{
    if (A.echo_sign() > B.echo_sign()) return 0;
    else if (A.echo_sign() < B.echo_sign()) return 1;
    else 
    {
        bool tem;
        if (A.size() > B.size()) tem = 0;
        else if (A.size() < B.size()) tem = 1;
        else 
        {
            for (int i = A.size() - 1; i >= 0; --i)
            {
                if (A[i] > B[i]) {tem = 0; break;}
                else if (A[i] < B[i]) {tem = 1;break;}
            }
        }
        if (A.echo_sign() >0) return tem;
        else return !tem;
    }
}

bool operator > (const Bint &A, const Bint &B)
{
    if (A == B || A < B) return 0;
    else return 1;
}

bool operator <= (const Bint &A, const Bint &B)
{
    if (A >B) return 0;
    else return 1;
}

bool operator >= (const Bint &A, const Bint &B)
{
    if (A < B) return 0;
    else return 1;
}
