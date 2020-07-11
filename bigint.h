#pragma once
#include <iostream>
#include <string>
#include <vector>

using std :: string;
using std :: vector;

const int positive = 1;
const int negative = -1;

class Bint
{
    unsigned int siz;
    int sign;
    vector<int> s;

public:
    Bint(int x = 0);
    Bint(long long  x);
    Bint(string x);

    unsigned int size() const;
    int echo_sign() const;
    int operator [] (int i) const;
    int& operator [] (int i);

    Bint operator - (void) ;
};

Bint operator + (const Bint &A,const Bint &B);
Bint operator - (const Bint &A,const Bint &B);
Bint operator * (const Bint &A,const Bint &B);
Bint operator / (const Bint &A,const Bint &B);
Bint operator % (const Bint &A,const Bint &B);

bool operator == (const Bint &A, const Bint &B);
bool operator != (const Bint &A, const Bint &B);
bool operator < (const Bint &A, const Bint &B);
bool operator > (const Bint &A, const Bint &B);
bool operator <= (const Bint &A, const Bint &B);
bool operator >= (const Bint &A, const Bint &B);
