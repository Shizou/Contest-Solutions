#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXH 500005
using namespace std;

int N,H,hi,cnt = 1;
vector<int>h(MAXH,0);
vector< pair<int, bool> > e;
void print_arr(){
	for(int i = 1; i <= H;i++)cout << h[i] << " ";
	cout << endl;
}
int main() {
    freopen("input.txt","r",stdin);
	scanf("%d%d",&N,&H);
	for(int i = 1; i <= N;++i){
		scanf("%d",&hi);
		if(i%2 == 0){
		    e.push_back(make_pair(1,true));
		    e.push_back(make_pair(hi+1,false));
		    //h[1]++;
		 //   h[hi+1]--;
		//	for(int j = 1; hi--;++j)h[j]++;
		}
		else{
		    e.push_back(make_pair(H-hi,true));
		    e.push_back(make_pair(H+1,false));
		 // //  h[H-hi]++;
		   // h[H+1]--;
		//	for(int j = H; hi--;--j)h[j]++;
		}
		//print_arr();
	}
	print_arr();
	sort(e.begin(),e.end());
    int c = 0;
    int j = 0;
    for(int i = 1; i <= H;i++){
        c+=h[i];
        h[i] = c;
        if(e[j].second){
            c++;
        }
    }
	//print_arr();
	/*sort(h.begin()+1, h.begin()+H+1);
	//print_arr();
	for(int i = 2; i <= H && h[i] == h[1];++i)cnt++;
	printf("%d %d\n",h[1],cnt);
*/
	return 0;
}
