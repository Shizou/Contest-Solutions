#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int A,B;
vector<int> f(1000005);
vector<bool>v(1000005,true);
void sieve(){
	v[0] = false;
    v[1] = false;
    for(int i = 2;i <= 1000000;++i){
        if(v[i]){
            for(int j = i;j < v.size();j+=i){
                v[j] = 0;
                f[j]++;
            }
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
	sieve();
	scanf("%d%d",&A,&B);
    for(;A<=B;A++){
        printf("%d\n",f[A]);
    }
	return 0;
}
