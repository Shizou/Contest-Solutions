#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 1000000
using namespace std;

int N,K,g,x,best;
vector<int>arr(MAXN);

void print_arr(int index){
	cout << "[ ";
	for(int i = 0; i < index;i++)
		cout << arr[i] << ", ";
	cout << "]" << endl;
}
int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d%d",&N,&K);
	for(int i = 0; i < N;++i){
		scanf("%d%d",&g,&x);x--;
		// normal range
		if(x-K >= 0 && x+K+1 < MAXN){
            arr[x-K]+=g;
            arr[x+K+1]-=g;
		}
		// range cut of at start
		else if(x-K < 0 && x+K+1 < MAXN){
            arr[0]+=g;
            arr[x+K+1]-=g;
		}
		// range cut off at end
		else if(x-K >= 0 && x+K+1 >= MAXN){
            arr[x-K]+=g;
		}
		else if(x-K < 0 && x+K+1 > MAXN){
            arr[0]+=g;
		}
	//	print_arr(20);
	}
	int c = 0;
	for(int i = 0; i < MAXN;i++){
        c+=arr[i];
        arr[i]=c;
        best = max(best,c);
	}
	printf("%d\n",best);
	//print_arr(20);
	return 0;
}

