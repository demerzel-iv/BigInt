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

int Bint :: size() const
{
    return s.size();
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
    if (tem == 0) 
    {
        s.push_back(0);
    }
    while (tem != 0)
    {
        s.push_back((int)(tem%M));
        tem /= M;
    }
}

Bint :: Bint(long long x)
{
    if (x >= 0) sign = positive;
    else sign = negative;
    long long tem;
    if (sign > 0) tem = x;
    else tem = -x;
    while (tem != 0)
    {
        s.push_back((int)(tem%M));
        tem /= M;
    }
}
Bint :: Bint(string x)
{
    int tem1 = x.size();
    int tem2 = tem1;
    sign = 1;
    for (int i = 0; i < tem1; ++i)
    {
        if (i == 0 && x[0] == '-')
        {
            sign = -1;
            --tem2;
        }
        else if (x[i] == '0') --tem2;
        else break;
    }
    if (tem2 == 0) 
    {
        s.push_back(0);
        sign = 1;
    }
    int temr = tem1;
    int teml = tem1;
    string tem_str = "";
    for (int i = tem1 - 1; i >= (tem1 - tem2); --i)
    {
        --teml;
        tem_str += x[i];
        if (i == tem1 - tem2 || (temr - teml) == 7) 
        {
            reverse(tem_str.begin(), tem_str.end());
            s.push_back(stoi(tem_str)); 
            temr = teml;
            tem_str = "";
        } 
    }
}

Bint :: Bint(const Bint &x)
{
    sign = x.sign;
    s.assign(x.s.begin(), x.s.end());
}

Bint :: Bint(Bint &&x)
{
    sign = x.sign;
    s = std::move(x.s); 
}

Bint& Bint :: operator = (const Bint &A)
{
    sign = A.sign;
    s.assign(A.s.begin(), A.s.end());
    return *this;
}

Bint& Bint :: operator = (Bint &&A)
{
    sign = A.sign;
    s = std::move(A.s);
    return *this;
}

void Bint::resize(int _siz)
{
   s.resize(_siz);
}
void Bint::fix(int i)
{
    int a = std::floor(s[i]/10.0);
    s[i+1]+=a;
    s[i]-=a*10;
}
int& Bint::highest()
{
    return s[size()-1];
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
        if (A.getsign() == 1)
        {
            if (A.size() > B.size()) return 0;
            else if (A.size() < B.size()) return 1;
            else 
            {
                for (int i = A.size() - 1; i >= 0; --i)
                {
                    if (A[i] > B[i]) {return 0; break;}
                    else if (A[i] < B[i]) {return 1; break;}
                }
                return 0;
            }
        }
        else 
        {
            if (A.size() > B.size()) return 1;
            else if (A.size() < B.size()) return 0;
            else 
            {
                for (int i = A.size() - 1; i >= 0; --i)
                {
                    if (A[i] > B[i]) {return 1; break;}
                    else if (A[i] < B[i]) {return 0; break;}
                }
                return 0;
            }
        }
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
Bint operator / (const Bint &A,const Bint &B)
{
    if(abs(A)<abs(B)) return Bint(0);

    std::ostringstream oss;
    Bint a=A,tmp,ret;

    for(int i=A.size()-1;i>=B.size()-1;i--)
    {
        //printf("i = %d\n",i);
        //cout<<"a = "<<a<<endl;

        oss.clear();
        oss.str("");

        //printf(" %d : %d\n",A.size()-1,i-B.size());
        for(int j=A.size()-1;
            //printf("%d === %d : %d\n",j,i-B.size(),(j>i-(int)B.size())),
            (j>i-(int)B.size());
                j--) 
        {
            //printf("j = %d\n",j),
            oss<<a[j];
        }
        tmp=Bint(oss.str());

        //cout<<"wtf : "<<oss.str()<<endl;
        //cout<<"tmp = "<<tmp<<endl;

        ret.s.push_back(0);
        while(tmp>=B)
        {
            tmp = tmp-B ,ret.s.back()++;
            //cout<<"tmp = "<<tmp<<", B = "<<B<<endl;
            //getchar();
        }

        for(int j=A.size()-1;j>i-B.size();j--)
            if(j-i+B.size()-1<tmp.size()) a[j]=tmp[j-i+B.size()-1];
            else a[j]=0;
    }

    std::reverse(ret.s.begin(),ret.s.end());
    ret.sign=A.sign*B.sign;

    format(ret);
    return ret;
}
Bint operator%(const Bint &A, const Bint &B)
{
    return A-(A/B)*B;
}

Bint& Bint :: operator += (const Bint &A)
{
    *this = *this + A;
    return *this;
}
Bint& Bint::operator-=(const Bint &A)
{
    *this = *this - A;
    return *this;
}
Bint& Bint::operator *= (const Bint &A)
{
    *this = *this * A;
    return *this;
}
Bint& Bint::operator /= (const Bint &A)
{
    *this = *this / A;
    return *this;
}
Bint& Bint::operator %= (const Bint &A)
{
    *this = *this % A;
    return *this;
}

ostream& operator << (ostream &os, const Bint &A)
{
    if(A.sign==negative) os<<"-";
    for(int i=A.size()-1;i>=0;i--)
    {
        if (i != A.size() - 1)
        {
            for (int j = 0; j < 7 - siz_int(A[i]); ++j)
                cout << '0';
        }
        if (A[i] != 0) cout << A[i];
    }
    return os;
}

vector<bool> B_to_bin(Bint A)
{
    vector<bool> ans;
    while (A != 0)
    {
        if (A % 2 != 0) {ans.push_back(1);}
        else {ans.push_back(0);}
        A /= 2;
    }
    return ans; 
}

Bint pow_B(Bint A, Bint B)
{
    Bint ans(1);
    vector<bool> tem1 = B_to_bin(B);
    /*for (int i = 0; i < tem1.size(); ++i)
    {
        cout << tem1[i];
    }
    cout << endl;*/
    Bint tem2(A);
    if (tem1[0]) ans *= A;
    for (int i = 1; i < tem1.size(); ++i)
    {
        tem2 *= tem2;
        if (tem1[i]) ans *= tem2;
    }
    return ans;
}

Bint bin_to_B(const vector<bool> &A)
{
    Bint ans(0);
    Bint tem(1);
    if (A[0]) ans += 1;
    for (int i = 1; i < A.size(); ++i)
    {
        tem *= 2;
        if (A[i]) ans += tem;
    }
    return ans;
}

Bint modpow_B(Bint A,Bint B, Bint C)
{
    Bint ans(1);
    vector<bool> tem1 = B_to_bin(B);
    Bint tem2(A);
    if (tem1[0]) ans *= A;
    for (int i = 1; i < tem1.size(); ++i)
    {
        tem2 *= tem2;
        tem2 %= C;
        if (tem1[i])
        {
            ans *= tem2;
            ans %= C;
        }
    }
    return ans;
}

void Bint::output()
{
    cout<<"sign : "<<sign << " , ";
    for(int i=0;i<size();i++)
        cout<<s[i]<<" ";
    cout<<endl;
}

Bint abs(const Bint &A)
{
    Bint ret(A);
    if(ret.sign==negative)
        ret.sign=positive;
    return ret;
}

int operator % (const Bint &A,int x)
{
    int ret = 0 ;
    for(int i=A.size()-1;i>=0;i--)
        ret = (ret*10+A[i]) % x;
    return ret * A.sign;
}

int siz_int(int a)
{
    int ans = 0;
    while(a != 0)
    {
        a /= 10;
        ++ans;   
    }
    return ans;
}