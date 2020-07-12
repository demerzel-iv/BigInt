#pragma once
#include <iostream>
#include <string>
#include <vector>

using std :: string;
using std :: vector;
using std :: ostream;
using std :: move;

const int positive = 1;
const int negative = -1;

class Bint
{
    int sign;
    vector<int> s;

    void resize(int _siz);
    void fix(int i); //处理第i位的进位
    int& highest(); //最高位的数
    void output(); //for debug

public:
    int size() const;
    int getsign() const;
    
    Bint(int x = 0);
    Bint(long long  x);
    Bint(string x);
    Bint(const Bint &x);
    Bint(Bint &&x);
    
    int operator [] (int i) const;
    int& operator [] (int i);
    friend void format (Bint &A);
    Bint operator += (const Bint &A);
    Bint operator - (void) const ;
    Bint& operator = (const Bint &A);
    Bint& operator = (Bint &&A);

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

    friend Bint abs(const Bint &A);
    friend ostream& operator << (ostream &os,const Bint &A);
    
    friend vector<bool> B_to_bin(Bint A);
    
};

Bint modpow_B(Bint A, Bint B, Bint C); //a^b (mod c)
