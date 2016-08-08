/* 
   Author:William Granados
   Date:26/01/16
   Solution:
   since the bounds are low
   we can just use bruteforce
   to find the answer
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a = 1, b = 1, c = 0, ans = 0;
    while(true)
    {
        c = a+b;
        if(c > 4000000)
            break;
        if(c % 2 == 0)
            ans += c;
        a = b;
        b = c;
    }
    cout << ans << endl;
}
