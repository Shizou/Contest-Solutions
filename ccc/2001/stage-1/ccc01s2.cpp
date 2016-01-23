#include <iostream>
#include <sstream>
#define to_s(N) static_cast<ostringstream*>( &(ostringstream() << N) )->str()
using namespace std;

int A,B;
int g[1000][1000];
int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
const int U = 0, R = 1, D = 2, L = 3;
string out[1000];
int new_d(int d){
	switch(d){
		case D:return R;
		case U:return L;
		case L:return D;
		case R:return U;
	}
}

int main() {
	cin >> A >> B;
	
	int dir_cnt[] = {3,2,2,3};
	int r = 250,c = 250, d = 2,s = 0;
	while(A <= B){
		g[r][c]=A;
		s++;
		if(s == dir_cnt[d]){
			dir_cnt[d]+=2;
			d = new_d(d);
			s = 1;
		}
		r+=dr[d];
		c+=dc[d];
		A++;
	}
	int len = 0;
	for(int r = 0; r < 1000;r++){
		for(int c = 0; c < 1000;c++){
			if(g[r][c] != 0)
				out[r]+= to_s(g[r][c]) + " ";
		}
		int len2 = out[r].size();
		len = max(len,len2);
	}
	for(int r = 0; r < 1000;r++){
		if(out[r]!=""){
			if(out[r].size()!=len){
				while(out[r].size()!=len){
					out[r].insert(0," ");
				}
			} 
		}
	}
	for(int r = 0; r < 1000;r++){
		if(out[r]!="")cout << out[r] << endl;
	}
	return 0;
}
