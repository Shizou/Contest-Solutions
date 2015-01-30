#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int r,cnt;
int main() {
	while(scanf("%d",&r) && r != 0){
		cnt = 0;
		for(int x = 1,y = r;x <= r;++x){
			for(int y2 = y;y2 >= 0;--y2){
				if(sqrt(x*x+y2*y2) <= r){
				    cnt+=y2;
				    y=y2;
					break;
				}
			}
		}
		cnt*=4;
		cnt+=4*r+1;
		printf("%d\n",cnt);
	}
	return 0;
}

