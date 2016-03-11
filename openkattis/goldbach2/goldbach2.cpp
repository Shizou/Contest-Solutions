#include<bits/stdc++.h>
#define MAXN 32005
#define len(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
using namespace std;

int n;
vector<int>primes;

void sieve()
{
    bool v[MAXN];
    memset(v, true, sizeof(v));
    v[0]=v[1] = false;
    for(int i = 2;i < MAXN;i++)
    {
        if(v[i])
        {
            for(int j = i+i;j < MAXN;j+=i)
            {
                v[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    sieve();
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        set< pair<int,int> >pairs;
        for(int j = 0;j < len(primes);j++)
        {
            if(x-primes[j] >= 0)
            {
                if(binary_search(all(primes), x-primes[j]))
                {
                    int A = min(primes[j], x-primes[j]);
                    int B = max(primes[j], x-primes[j]);
                    if(!pairs.count(make_pair(A,B)))
                        pairs.insert(make_pair(A,B));
                }
            }
        }
        cout << x << " has " << len(pairs) << " representation(s)" << endl;
        for(set< pair<int,int> >::iterator it = pairs.begin();it != pairs.end();it++)
        {
            pair<int,int>p = *it;
            cout << p.first << "+" << p.second << endl;
        }
        cout << endl;
    }
    return 0;
}