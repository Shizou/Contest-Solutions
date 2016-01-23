#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

int N,T,P;
bool arr[2000][2000];
int v[2000];
vector< pair<int, pair<int,int> > >c;

bool compare(pair<int, pair<int,int> >l, pair<int,pair<int,int> >r){
	if(l.first > r.first)
		return true;
	else if(l.first == r.first){
		if(l.second.first > r.second.first)
			return true;
		else if(l.second.first == r.second.first)
			return l.second.second < r.second.second;
		else
			return false;
	}
	else
		return false;
}
int main() {
	scanf("%d%d%d",&N,&T,&P);
	for(int i = 0; i < N;i++){
		for(int j = 0; j < T;j++){
			cin >> arr[i][j];
			if(!arr[i][j])v[j]++;
		}
	}
	for(int i = 0; i < N;i++){
		int s = 0, ac = 0;
		for(int j = 0; j < T;j++){
			s+= arr[i][j] ? v[j]:0;
			ac += arr[i][j] ? 1:0;
		}
		c.pb(mp(s,mp(ac,i+1)));
	}
	sort(c.begin(),c.end(),compare);
	for(int i = 0; i < N;i++){
		if(c[i].second.second == P){
			printf("%d %d\n",c[i].first,i+1);
			break;
		}
	}
	return 0;
}
