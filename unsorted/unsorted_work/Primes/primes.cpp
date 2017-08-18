#include <iostream>
#include <cstdio>
#include <vector>
#define MAXD 5000005
using namespace std;

int N,M;
int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d%d",&N,&M);
	vector<bool>v(32000,true), v2(MAXD,true);
	v[0]=v[1]=false;
	if(N == 1)v2[0]=false;
	for(int i = 2; i < 32000;++i){
		if(v[i]){
			for(int j = i*i; j < 32000;j+=i)v[j]=false;
            for(int k = 0; N+k <= M;++k){
                if( (N+k) != i && (N+k)%i == 0){
                    for(int j = k; j < MAXD && N+j <= M;j+=i)v2[j]=false;
                    break;
                }
            }
		}
	}
	for(int i = 0; i < MAXD && N+i <= M;++i){
		if(v2[i])printf("%d\n",N+i);
	}
	return 0;
}
