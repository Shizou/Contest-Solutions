#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define MAXN (int)2000
#define inf 0x3f3f3f3f
using namespace std;

const int N = 12;
int P;
int it = 0;
int arr[12];


int find_max(int i,int j){
    int ret = 0;
    for(int it = i;it <= j;it++){
       ret = max(ret,arr[it]);
    }
    return ret;
}
int find_min(int i,int j){
    int ret = find_max(i,j);
    for(int it = i;it <= j;it++){
       ret = min(ret,arr[it]);
    }
    return ret;
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    cin >> P;
    while(P--){
       cin >> it;
       for(int i = 0;i < 12;i++){
           cin >> arr[i];
           if(DB)cout << arr[i] << " ";
       }if(DB)cout << endl;
       int cnt = 0;
       for(int i = 0;i < N;i++){
           for(int j = 0;j < N;j++){
               if(j < i)continue;
               if(i-1 >= 0 && j+1 < N){
                  int a = arr[i-1];
                  int b = arr[j+1];
                  int c = find_min(i,j);
                  if(c > a && c > b)cnt++;
               }
           }
       }
       cout << it << " " << cnt << endl;
    }
    return 0;
}