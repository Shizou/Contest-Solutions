#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

int K;
string a,b,in;
vector< pair<string,string> > arr;

int main(){
    freopen("testdata/input/s2.1.in","r",stdin);
    cin >> K;
    for(int i = 0;i < K;i++){
        cin >> a >> b;
        arr.pb(mp(a,b));
    }
    cin >> in;
    while(!in.empty()){
        for(int i = 0;i < K;i++){
            if(arr[i].y.size() <= in.size()){
                if(arr[i].y == in.substr(0,arr[i].y.size())){
                   cout << arr[i].x;
                   in.erase(0,arr[i].y.size());
                   break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}