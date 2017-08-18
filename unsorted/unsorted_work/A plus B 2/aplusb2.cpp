#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MAXN = (int)1e5+2,POS = 1,NEG = -1;
std::string s1,s2,s3 = "0";

class bigint{
    private:
        char dig[MAXN];
        int end,signbit;

    // constructors
    public:
        bigint();
        bigint(string val);
        bigint(int val);
        bigint(long long val);
        void print();

    // helper methods
    private:
        void add(const bigint &b);
        void sub(const bigint &b);

    // arithmetic operators
    public:
        bigint operator + (const bigint&b);
        bigint operator - (const bigint&b);
        bigint operator * (const bigint&b);
        bigint operator / (const bigint&b);

    // assignment operators
    public:
        void operator += (const bigint&b);
        void operator -= (const bigint&b);
        void operator *= (const bigint&b);
        void operator /= (const bigint&b);
        void operator =  (const bigint&b);

    // boolean operators
    public:
        bool operator <  (const bigint&b)const;
        bool operator >  (const bigint&b)const;
        bool operator >= (const bigint&b)const;
        bool operator <= (const bigint&b)const;
        bool operator != (const bigint&b)const;
        bool operator == (const bigint&b)const;
};

// constructors
bigint::bigint(){
    dig[0] = '0';
    end = 0;
    signbit = POS;
}
bigint::bigint(string val){
    if(val[0] == '-'){
        signbit = -1;
        for(int i = val.size()-1, j = 0;i>=1;i--)
            dig[j++] = val[i];
        end = val.size()-2;
    }
    else{
        signbit = 1;
        for(int i = val.size()-1, j = 0;i>=0;i--)
            dig[j++] = val[i];
        end = val.size()-1;
    }
}
bigint::bigint(int val){
    //cout << val << endl;
    for(long long i = 0,j = val;i < MAXN;i++,j/=10){
        dig[i] = (j%10)+'0';
        end++;
        if(j==0)break;
    }
}
bigint::bigint(long long val){
    for(long long i = 0,j = val;i < MAXN && j != 0;i++,j/=10){
        dig[i] = (j%10)+'0';
        if(j/10 != 0)
            end++;
    }
}

// helper methods
void bigint::add(const bigint &b){
    bigint a(*this);
    // simply increasing magnitude
    int e = max(a.end,b.end),carry = 0;
    for(int i = 0, sum = 0; i <= e+1;i++){
        sum = carry;
        carry = 0;
        if(!isdigit(a.dig[i]) && !isdigit(b.dig[i])&& sum == 0)
            break;
        else{
            if(isdigit(a.dig[i]))
                sum+= a.dig[i]-'0';
            if(isdigit(b.dig[i]))
                sum+= b.dig[i]-'0';
            if(sum >= 10){
                sum%=10;
                carry = 1;
            }
            a.dig[i] = sum+'0';
            a.end=i;
        }
    }
}
void bigint::print(){
    if(signbit==NEG)printf("-");
        for(int i = end;i>=0;i--)
            printf("%c",this->dig[i]);
        printf("\n");
}

void bigint:: operator += (const bigint&b){
    bigint a(*this);
    if(a.signbit == POS && b.signbit == POS){
        a.add(b);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    bigint a(100000),b(1000);
    a+=b;
    a.print();

    return 0;
}
