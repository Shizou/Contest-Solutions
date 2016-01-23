#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 20
using namespace std;

int N,mw;
vector<bool>v(MAXN,false);
vector<int>w(MAXN);
int sum = 0,size = 0,csum = 0;
bool RMAX = false;

bool check(int x, int y){
	do{
		if(x%10 + y%10 >= 10)return false;
		x/=10,y/=10;
	}while(x > 0 && y > 0);
	return true;
}
void rec(int i){
    mw = max(mw,size);
    if(i >= N)return;
    if(check(csum,w[i])){
        csum+=w[i];
        ++size;
        rec(i+1);
        csum-=w[i];
        --size;
    }
    rec(i+1);
}

int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d",&N);
	for(int i = 0; i < N;++i)
		scanf("%d",&w[i]);
	rec(0);
	printf("%d\n",mw);
	return 0;
}

