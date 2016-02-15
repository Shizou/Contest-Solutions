#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N,R,a,b;

int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d",&N);
	while(N--){
		scanf("%d%d%d",&R,&a,&b);
		int ans = 0;
		for(int i = R;i >= a;i--){
			if(i%a == 0){
				ans += i/a;
				break;
			}
		}
		for(int i = R;i >= b;i--){
			if(i%b == 0){
				ans += i/b;
				break;
			}
		}
		int o = 0;
		for(int i = max(a,b);i <= R;i+=max(a,b)){
			if(i%a == 0 && i%b == 0){
				o = i;
				break;
			}
		}

		for(int i = R;i > o && o != 0;i--){
			if(i%o == 0){
				ans -= i/o;
				break;
			}
		}


		printf("%d\n",ans);
	}
	//fclose(stdin);
	return 0;
}
