#include <iostream>
#include <cstdio>
#include<vector>
#define max(a,b) a>b?a:b
using namespace std;
int N,max_n;
int a[4];

void r(int sum, int cnt,string v){
    cout << sum << " " << cnt << endl;
    if(cnt == 4 && sum <= 24){
        //cout << sum << endl;
	    max_n = max(max_n,sum);
		return;
	}
	for(int i = 0;i < 4;i++){
	    if(v[i] == '-'){
	        v[i] = ' ';
            r(sum+a[i],cnt+1,v);
            r(sum-a[i],cnt+1,v);
            r(sum*a[i],cnt+1,v);
            if(sum != 0){
                if(sum%a[i] == 0)
                    r(sum/a[i],cnt+1,v);
            }
            else
                r(sum/a[i],cnt+1,v);
            v[i] = '-';
	    }
	}
}
int main() {
    freopen("input.txt","r",stdin);
	scanf("%d",&N);
	for(int i = 0;i < N;i++){
	   for(int j = 0; j < 4;j++)
			scanf("%d",&a[j]);
		for(int j = 0; j < 4;j++){
		    string v = "----";
		    v[j] = ' ';
            r(a[j],1,v);
            v[j] = '-';
		}
		printf("%d\n",max_n);
		max_n = 0;
		//break;
	}
	return 0;
}
