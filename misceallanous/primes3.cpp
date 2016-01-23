#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL T,N;

/*
   This functions calculates (a^b)%c
   @a base
   @b exponent
   @c modulo
*/
LL modulo(LL a, LL b, LL c)
{
    LL x = 1, y = a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x*y)%c;
        }
        y = (y*y)%c;
        b/=2;
    }
    return x%c;
}

/* 
   This functions calculates (a*b)%c
   @a operand 1
   @b operand 2
   @c modulo
*/
LL mulmod(LL a, LL b, LL c)
{
    LL x = 0, y = a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

/*
   This functions performs the Miller-Rabin primality test
   @p number to be tested
   @iteration number of itersations the algorithm should be run
*/
bool miller(LL p, int iteration)
{
    if(p < 2)
    {
        return false;
    }
    if(p != 2 && p%2 == 0)
    {
        return false;
    }
    LL s = p-1;
    while(s % 2 == 0)
    {
        s /= 2;
    }
    for(int i = 0; i < iteration;i++)
    {
        LL a = rand()%(p-1)+1, temp = s;
        LL mod = modulo(a,temp,p);
        while(temp != p-1 && mod != 1 && mod != p-1)
        {
            mod = mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod != p-1 && temp%2 == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    cin >> T;
    while(T-- > 0)
    {
        cin >> N;
        if(miller(N,20))
            cout << "PRIME" << endl;
        else
            cout << "NOT" << endl;
    }
    return 0;
}
