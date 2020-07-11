#include "bigint.h"
#include "poly/polynomial.h"

void format(Bint &A)
{
    for(int i=0;i<A.size()-1;i++) A.fix(i);

    while(A.highest() == 0 && A.size()>1)
        A.resize(A.size()-1);

    if(A.highest() < 0) 
    {
        A.sign *= -1;
        for(int i=0;i<A.size();i++)
            A[i]*=-1;
        format(A);
    }
    else 
    {
        int ind = A.size();
        while(A.highest() >= 10)
        {
            A.resize(ind+1);
            A.fix(ind-1);
            ind++;
        }
    }
}

unsigned int Bint :: size() const
{
    return siz;
}

int Bint::getsign() const
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

Bint :: Bint(const Bint &x)
{
    sign = x.sign;
    siz = x.siz;
    s.assign(x.s.begin(), x.s.end());
}

Bint :: Bint(Bint &&x)
{
    sign = x.sign;
    siz = x.siz;
    s = x.s;    
}

Bint& Bint :: operator = (const Bint &A)
{
    sign = A.sign;
    siz = A.siz;
    s.assign(A.s.begin(), A.s.end());
    return *this;
}

Bint& Bint :: operator = (Bint &&A)
{
    sign = A.sign;
    siz = A.siz;
    s = A.s;
    return *this;
}

void Bint::resize(int _siz)
{
   s.resize(siz = _siz);
}
void Bint::fix(int i)
{
    int a = std::floor(s[i]/10.0);
    s[i+1]+=a;
    s[i]-=a*10;
}
int& Bint::highest()
{
    return s[siz-1];
}

int Bint :: operator [] (int i) const
{
    return i<size()?s[i]:0;
}
int& Bint :: operator [] (int i)
{
    return s[i];
}

bool operator == (const Bint &A, const Bint &B)
{
    if (A.getsign() != B.getsign()) return 0;
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
    if (A.getsign() > B.getsign()) return 0;
    else if (A.getsign() < B.getsign()) return 1;
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
        if (A.getsign() >0) return tem;
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
Bint Bint::operator - (void) const
{
    Bint ret = *this;
    ret.sign *= -1;
    return ret;
}
Bint operator + (const Bint &A,const Bint &B)
{
    Bint ret;
    ret.resize(std::max(A.size(),B.size()));
    for(int i=0;i<ret.size();i++)
        ret[i]=A.sign*A[i]+B.sign*B[i];

    format(ret);
    return ret;
}
Bint operator - (const Bint &A,const Bint &B)
{
    return A+(-B);
}
Bint operator * (const Bint &A,const Bint &B)
{
    poly pA (A.s.begin(),A.s.end());
    poly pB (B.s.begin(),B.s.end());

    poly C = pA * pB;

    Bint ret;
    ret.resize(C.size());
    for(int i=0;i<ret.size();i++)
        ret[i]=C[i].getvalue()->getValueInt();
    ret.sign = A.sign * B.sign;
    format(ret);
    return ret;
}
ostream& operator << (ostream &os, const Bint &A)
{
    if(A.sign==negative) os<<"-";
    
    for(int i=A.size()-1;i>=0;i--)
        os<<A[i];

    return os;
}

void Bint::output()
{
    cout<<"sign : "<<sign << " , ";
    for(int i=0;i<siz;i++)
        cout<<s[i]<<" ";
    cout<<endl;
}
