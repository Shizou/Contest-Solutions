#include <stdio.h>
using namespace std;

int A,B,C,x,y,cost;
int g[100];

int main() {
    scanf("%d%d%d",&A,&B,&C);
	for(int i = 0; i < 3;i++){
		scanf("%d%d",&x,&y);
		for(int j = x-1;j < y-1;j++)
			g[j]++;
	}
	for(int i = 0;i < 100;i++)
		cost+= (g[i] == 1) ? A: ((g[i] == 2) ? 2*B: ((g[i] == 3) ? 3*C:0));

	printf("%d\n",cost);
	return 0;
}
