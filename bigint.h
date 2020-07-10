#pragma once
#include <iostream>
#include <string>
#include <vector>

using std :: string;
using std :: vector;

const bool positive = 1;
const bool negative = 0;

class Bint
{
    unsigned int siz;
    bool sign;
    vector<int> s;

public:
    Bint(int x = 0);
    Bint(long long  x);
    Bint(string x);

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