#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10001;
int N,a,b;
int p[MAXN];
vector<int>adj[MAXN];

int main() {
	scanf("%d",&N);
	while(true){
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)break;
		adj[a].push_back(b);
	}
	p[1]=1;
	for(int i = 1; i < N;i++)
		for(int j = 0; j < adj[i].size();j++)
			p[adj[i][j]]+=p[i];
	printf("%d\n",p[N]);
	return 0;
}
