#include <iostream>
#include <cstdio>
#define needforspeed ios_base::sync_with_stdio(false);
#define endl '\n'
#define MAXN 1000000
using namespace std;

int num_sets = 0, root[MAXN+1], RANK[MAXN+1];

int find_root(int x) {
  if (root[x] != x) root[x] = find_root(root[x]);
  return root[x];
}

void make_set(int x) {
  root[x] = x;
  RANK[x] = 0;
  num_sets++;
}

bool is_united(int x, int y) {
  return find_root(x) == find_root(y);
}

void unite(int x, int y) {
  int X = find_root(x), Y = find_root(y);
  if (X == Y) return;
  num_sets--;
  if (RANK[X] < RANK[Y]) root[X] = Y;
  else if (RANK[X] > RANK[Y]) root[Y] = X;
  else RANK[root[Y] = X]++;
}

int N, Q;
int a,b;
char cmd;

int main()
{
    freopen("input.txt", "r", stdin);
    needforspeed;
    cin >> N >> Q;
    for(int i = 0;i < N;i++)
        make_set(i);
    for(int i = 0;i < Q;i++)
    {
    	cin >> cmd >> a >> b;
    	if(cmd == '=')
    	{
    	   unite(a,b);
    	}
    	else
    	{
    	    cout << (is_united(a,b) ? "yes":"no")<< endl;
    	}
    }
    return 0;
}
