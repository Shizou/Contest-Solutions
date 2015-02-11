#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXD = (int)1e4, MAXC = 32,INF = 0x3F3F3F3F;
int D,N,c[MAXC],dist[MAXD];
int main() {
	scanf("%d%d",&D,&N);
	memset(dist,INF,sizeof dist);
	for(int i = 0; i < N;i++)
		scanf("%d",&c[i]);
	dist[0]=0;
	for(int i = 0; i <= D;i++)
		for(int j = 0; j < N;j++)
			dist[i+c[j]] = min(dist[i+c[j]],dist[i]+1);
	if(dist[D]!=INF)
		printf("Roberta wins in %d strokes.\n",dist[D]);
	else
		printf("Roberta acknowledges defeat.\n");
	return 0;
}
