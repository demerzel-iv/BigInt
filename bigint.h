#pragma once
#include <iostream>
#include <string>
#include <vector>

const int M = (int)1e7;

using std :: string;
using std :: vector;
using std :: ostream;

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
    Bint operator - (void) const ;
    Bint& operator = (const Bint &A);
    Bint& operator = (Bint &&A);

    Bint& operator += (const Bint &A);
    Bint& operator -= (const Bint &A);
    Bint& operator *= (const Bint &A);
    Bint& operator /= (const Bint &A);
    Bint& operator %= (const Bint &A);

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

    friend int operator % (const Bint &A,int x);

    friend Bint abs(const Bint &A);
    friend ostream& operator << (ostream &os,const Bint &A);
    
    friend vector<bool> B_to_bin(Bint A);
    friend Bint bin_to_B(const vector<bool> &A);
    friend Bint pow_B(Bint A, Bint B);
    friend Bint modpow_B(Bint A, Bint B, Bint C); //a^b (mod c)
};

Bint bin_to_B(const vector<bool> &A);