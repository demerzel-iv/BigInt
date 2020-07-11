#pragma once
#include <iostream>
#include <string>
#include <vector>

using std :: string;
using std :: vector;
using std :: ostream;

const int positive = 1;
const int negative = -1;

class Bint
{
    unsigned int siz;
    int sign;
    vector<int> s;

    void resize(int _siz);
    void fix(int i); //处理第i位的进位
    int& highest(); //最高位的数
    void output(); //for debug

public:
    Bint(int x = 0);
    Bint(long long  x);
    Bint(string x);

    Bint(const Bint &x);
    Bint(Bint &&x);
    Bint& operator = (const Bint &A);
    Bint& operator = (Bint &&A);

    unsigned int size() const;
    int getsign() const;
    int operator [] (int i) const;
    int& operator [] (int i);

    Bint operator - (void) const ;

    friend void format (Bint &A);

friend bool operator == (const Bint &A, const Bint &B);
friend bool operator != (const Bint &A, const Bint &B);
friend bool operator < (const Bint &A, const Bint &B);
friend bool operator > (const Bint &A, const Bint &B);
friend bool operator <= (const Bint &A, const Bint &B);
friend bool operator >= (const Bint &A, const Bint &B);
friend Bint operator + (const Bint &A,const Bint &B);
friend Bint operator - (const Bint &A,const Bint &B);
friend Bint operator * (const Bint &A,const Bint &B);
friend Bint operator / (const Bint &A,const Bint &B);
friend Bint operator % (const Bint &A,const Bint &B);

friend ostream& operator << (ostream &os,const Bint &A);
};
