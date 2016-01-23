#include <iostream>
#include <cstdio>
using namespace std;

int N,M,cnt;
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N;i++){
		scanf("%d",&M);
		cnt = 0;
		for(int i = 1; i < M;i++)
			if(M%i==0)cnt+=i;
		if(cnt < M)
			printf("%d is a deficient number.\n",M);
		else if(cnt == M)
			printf("%d is a perfect number.\n",M);
		else
			printf("%d is an abundant number.\n",M);
	}
	return 0;
}
