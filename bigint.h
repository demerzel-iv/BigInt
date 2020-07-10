#pragma once
#include <bits/stdc++.h>

class Bint
{
    unsigned int siz;
    int sign;
    int *s;

public:
    Bint(int x=0);
    Bint(long long  x);

    unsigned int size() const;
    int operator [] (int i) const;
    int& operator [] (int i);

    Bint operator - (void) ;
};

Bint operator + (const Bint &A,const Bint &B);
Bint operator - (const Bint &A,const Bint &B);
Bint operator * (const Bint &A,const Bint &B);
Bint operator / (const Bint &A,const Bint &B);
Bint operator % (const Bint &A,const Bint &B);