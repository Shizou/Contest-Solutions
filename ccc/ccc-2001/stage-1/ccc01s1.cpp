#include <iostream>
#include <cstdio>
#include <map>
using namespace std;


int cnt,tcnt;
string s;
map<char,int>m;

void init(){
	for(char i = 2; i <= '9';i++)
		m[i] = 0;
	m['J'] = 1;
	m['Q'] = 2;
	m['K'] = 3;
	m['A'] = 4;
}
void loop(string ss, int pos,int end){
	printf("%s ",ss.c_str());
	for(int i = pos+1; i < end;i++){
		printf("%c ",s[i]);
		cnt+=m[s[i]];
	}
	if(end-pos==1)cnt+=3;
	if(end-pos==2)cnt+=2;
	if(end-pos==3)cnt+=1;
	printf("%d\n",cnt);
	tcnt+=cnt;
	cnt = 0;
}

int main(){
	init();
	cin >> s;
	printf("Cards Dealt              Points\n");
	int c = s.find('C'), d = s.find('D'), h = s.find('H'), sp = s.find('S');
	loop("Clubs",c,d);
	loop("Diamonds",d,h);
	loop("Hearts",h,sp);
	loop("Spades",sp,s.size());
	printf("			Total %d\n",tcnt);
	return 0;	
}
