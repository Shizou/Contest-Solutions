#include <iostream>
#include <cstdio>
using namespace std;

int N,b;
int main() {
    freopen("pascal.in.9","r",stdin);
	scanf("%d",&N);
	if(N == 1){printf("%d\n",0);return 0;}
	else if(N == 2){printf("%d\n",1);return 0;}
	for(int i = 3; i <= N;i+=2){
        if(N%i == 0){printf("%d\n",N-N/i);break;}
	}
	return 0;
}
