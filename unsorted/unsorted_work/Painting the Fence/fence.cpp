#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map < int, int> m;
int x,N,cnt,s;
int dx[] = {-1,1};
char d;
int main() {
    freopen("1.in","r",stdin);
	scanf("%d",&N);
	m[0] = 0;
	for(int i = 0; i < N;i++){
		scanf("%d %c",&s,&d);
		int dir = (d == 'L') ? 0:1;
		for(int j = 0; j < s;j++){
			x+=dx[dir];
			if(m.find(x) == m.end())
				m[x] = 1;
			else if(m[x] != -1){
				m[x]++;
				if(m[x] == 2){
				  //  cout << x << " ";
					cnt++;
					m[x]=-1;
				}
			}

		}

	}
	cout << endl;
	printf("%d\n",cnt);
	return 0;
}
