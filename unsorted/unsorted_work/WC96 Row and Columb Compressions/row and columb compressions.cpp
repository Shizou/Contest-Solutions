#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int R,C;
string in,out,s;
char g[10][10];
int main() {
    freopen("input.txt","r",stdin);
	cin >> R >> C;
	cin >> in;
	int cnt = 1,it = 0;
	while(!in.empty()){
		if(isalpha(in[0])){
			while(cnt--)s+=in[0];
			cnt = 1;
		}
		else cnt++;
		in.erase(0,1);
	}
	cout << in << endl;
	cout << s << endl;
	for(int c = 0; c < C;c++)
		for(int r = 0; r < R;r++)
			g[r][c] = s[it++];
	for(int r = 0; r < R;r++){
		for(int c = 0; c < C;c++){
			out+=g[r][c];
			cout << g[r][c];
		}
		cout <<endl;
	}

	/*cout << out << endl;
	cnt = 1;
	while(!out.empty()){
		cnt = 1;
		it = 1;
		while(out.size() != 1 && out[0] == out[it++])cnt++;
		if(cnt == 1)cout << out[0];
		else        cout << cnt << out[0];
		out.erase(0,cnt);
	}
	cout << endl;*/

	return 0;
}
