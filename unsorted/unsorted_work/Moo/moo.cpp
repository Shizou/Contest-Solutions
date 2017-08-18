#include <cstdio>
#include <vector>
using namespace std;

vector<bool>moo(3,false);
vector<bool>before;
int N;
int main() {
    freopen("input.txt","r",stdin);
	scanf("%d",&N);
	moo[0] = true;
	before = moo;
	for(int i = 0;i < 16;i++){
		moo.push_back(false);
		moo.insert(moo.begin(),before.begin(),before.end());
		moo.insert(moo.end(),before.begin(),before.end());
		before = moo;
	}
	printf("%d\n",moo.size());
	printf("%s", (moo[N-1]) ? "m":"o");
	return 0;
}

