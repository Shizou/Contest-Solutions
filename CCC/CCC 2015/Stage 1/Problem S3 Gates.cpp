#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

int G,P,cnt;
set<int>A;
set<int>::iterator it;

int main() {
	scanf("%d%d",&G,&P);
	for(int i = 1;i <= G;++i)
		A.insert(i);
	for(int i = 0,g = 0;i < P;i++){
		scanf("%d",&g);
		it = A.lower_bound(g);
        if(A.empty() || *it == 0 || (A.begin() == it && *it > g))
            break;
        else{
            if(*it == g)
                A.erase(it);
            else if(*(--it) < g)
                A.erase(it);
        }
        cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
