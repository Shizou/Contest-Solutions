#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define MAXN (int)1e5
#define mp make_pair
using namespace std;

int N,sr,sc,er,ec,r,c,d;
vector<bool>v[MAXN];
int main(){
	scanf("%d",&N);
	for(int i = 0,vi; i < N;++i){
		scanf("%d",&vi);
		v[i] = vector<bool>(vi,false);
	}
	scanf("%d%d%d%d",&sr,&sc,&er,&ec);
	sr--;sc--;er--;ec--;
	queue< pair<int, pair<int,int> > > q;
	q.push(mp(0,mp(sr,sc)));
	while(!q.empty()){
		d = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();
		if(v[r][c])continue;
		else	   v[r][c] = true;
		if(r == er && c == ec){
			printf("%d\n",d);
			break;
		}
		// right
		if(c+1 < v[r].size() && !v[r][c+1])
			q.push(mp(d+1,mp(r,c+1)));
		else if(c+1 == v[r].size() && r+1 < N && !v[r+1][0])
			q.push(mp(d+1,mp(r+1,0)));
		// left
		if(c-1 >= 0 && !v[r][c-1])
			q.push(mp(d+1,mp(r,c-1)));
		else if(c-1 < 0 && r-1 >= 0 && !v[r-1][v[r-1].size()-1])
			q.push(mp(d+1,mp(r-1,v[r-1].size()-1)));
		// up
		if(r-1 >= 0 && c < v[r-1].size() && !v[r-1][c])
			q.push(mp(d+1,mp(r-1,c)));
		else if(r-1 >= 0 && c >= v[r-1].size() && !v[r-1][v[r-1].size()-1])
			q.push(mp(d+1,mp(r-1,v[r-1].size()-1)));
		// down
		if(r+1 < N && c < v[r+1].size() && !v[r+1][c])
			q.push(mp(d+1,mp(r+1,c)));
		else if(r+1 < N && c >= v[r+1].size() && !v[r+1][v[r+1].size()-1])
			q.push(mp(d+1,mp(r+1,v[r+1].size()-1)));

	}
	return 0;
}

