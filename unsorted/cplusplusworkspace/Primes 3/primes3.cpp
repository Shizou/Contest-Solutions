#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#define MAXN 7*(int)1e6
using namespace std;

long long T,N;
vector<bool>v(MAXN,true);
vector<int>primes;
set<int>p;

void sieve(){
	v[0]=v[1]=false;
	for(int i = 2;i < sqrt(MAXN);++i){
		if(v[i]){
			for(int j = i*i; j < MAXN;j+=i)v[j]=false;
			primes.push_back(i);
			p.insert(i);
		}
	}
	for(int i = sqrt(MAXN);i < MAXN;++i){
		if(v[i]){
			primes.push_back(i);
			p.insert(i);
		}
	}
}
bool check_prime(){
	for(int i = 0; i < primes.size() && primes[i] <= sqrt(N);++i)
		if(N%primes[i]==0)return false;
	return true;
}
int main() {
    //freopen("input.txt","r",stdin);
	sieve();
	scanf("%d",&T);
	for(int i = 0; i < T;++i){
		scanf("%lld",&N);
		if(p.find(N) != p.end())
			printf("PRIME\n");
		else{
		    if(N < MAXN){
                if(v[N])printf("PRIME\n");
                else printf("NOT\n");
		    }
			else if(check_prime())
				printf("PRIME\n");
			else
				printf("NOT\n");
		}
	}
	return 0;
}
