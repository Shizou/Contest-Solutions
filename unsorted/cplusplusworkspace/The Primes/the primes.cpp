#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#define MAXN 100005
using namespace std;

int S,LH;
vector<int>primes;
set<int>p;
void sieve(){
    vector<bool>v(MAXN,true);
    v[0] = v[1] = false;
	for(int i = 2; i < MAXN;++i){
		if(v[i]){
			if(i >= 10000 && i < 100000){
			    primes.push_back(i);
                p.insert(i);
			}
			for(int j = 2*i; j < MAXN;j+=i)v[j] = false;
		}
	}
}
int first_digit(int x){
    while(x>9)x/=10;
    return x;
}
int main() {
    freopen("input.txt","r",stdin);
    sieve();
    scanf("%d%d",&S,&LH);
    for(int i = 0; i < primes.size();++i){
        if(first_digit(primes[i]) == LH){
            vector<int>box;
            box.push_back(primes[i]);
            for(int j = 0; j < primes.size();++j){
                if(i==j)continue;

            }
        }
    }
	return 0;
}
