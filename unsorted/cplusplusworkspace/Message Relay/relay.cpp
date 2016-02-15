#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,cnt;
int adj[1001];
bool v[1001];

int r(int n){
	if(n == 0)
		return 0;
	if(v[n]){
		cnt++;
		return 1;
	}
	v[n] = true;
	return r(adj[n]);
}
int main() {
	scanf("%d",&N);
	for(int i = 1; i <= N;i++)
		scanf("%d",&adj[i]);
	for(int i = 1; i <= N;i++){
		r(i);
		memset(v,0,sizeof v);
	}
	printf("%d\n",N-cnt);
	return 0;
}
