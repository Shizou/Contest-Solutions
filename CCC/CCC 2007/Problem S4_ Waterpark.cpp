#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> s[10000];
int n,a,b,slides;
int main(){
    cin >> n;
    int p[n+1];
    memset(p,0,sizeof p);
    while(1){cin >> a >> b; if(a == 0) break; s[a].push_back(b);}
    p[1] = 1;
    for(int x = 1;x < n ;x++){
        for(int y = 0;y < s[x].size();y++){
            p[s[x][y]] += p[x];
        }
    }
    cout << p[n] << endl;
}

