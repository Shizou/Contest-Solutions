#include <iostream>
#include <cstdio>
using namespace std;

int N,pos = 1;
int main(){
	while(cin >> N){
		pos+=N;
		if(pos == 9) pos = 34;
		if(pos == 40)pos = 64;
		if(pos == 67)pos = 86;
		if(pos == 99)pos = 77;
		if(pos == 90)pos = 48;
		if(pos == 54)pos = 19;
		if(pos > 100)pos-=N;
		if(N==0){
			printf("You Quit!\n");
			break;
		}
		else if(pos == 100){
			printf("You are now on square %d\n",pos);
			printf("You Win!\n");
			break;
		}
		else
			printf("You are now on square %d\n",pos);
	}
	return 0;	
}
