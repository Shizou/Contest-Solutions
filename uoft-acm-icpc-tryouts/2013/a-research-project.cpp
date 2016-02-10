#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int G,N,A;
int main() {
	scanf("%d",&G);
	while(G--){
		scanf("%d",&N);
		vector<int>in;
		while(N-- && scanf("%d",&A))in.push_back(A);
		sort(in.begin(),in.end());
		printf("%d %d\n",in[0],in[in.size()-1]);
	}
	return 0;
}
