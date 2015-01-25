#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a,b,T;

int to_b(int x, int b){
	return (int)pow(b,0)*(x%10) + (int)pow(b,1)*((x/10)%10) + pow(b,2)*((x/100)%10);
}
int main() {
	scanf("%d",&T);
	for(int i = 0; i < T;i++){
		scanf("%d%d",&a,&b);
		int X = 10, Y = 10;
		while(X<= 15000 && Y <= 15000){
			if(to_b(a,X) > to_b(b,Y))
				Y++;
			else if(to_b(a,X) < to_b(b,Y))
				X++;
			else{
				printf("%d %d\n",X,Y);
				break;
			}
		}
	}
	return 0;
}
