#include <bits/stdc++.h>
#include<unordered_map>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define LL long long
using namespace std;

int N;
vector< pair<int,int> > arr;
unordered_map< int,unordered_map<int,int> >tree;

void update(int r,int c,int v){
   for(int i = r;i <= 100000;i+=lb(i))
       for(int j = c;j <= 100000;j+=lb(j))
           if(!(i == r && j == c))
              tree[i][j]+=v;

}
int query(int r,int c){
     int sum = 0;
     for(int i = r;i > 0;i-=lb(i))
         for(int j = c;j > 0;j-=lb(j))
             sum+=tree[i][j];
     return sum;
}
int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0,x,y;i < N;i++){
        cin >> x >> y;x++,y++;
        update(x,y,1);
        arr.pb(mp(x,y));
    }
    for(int i = 0;i < N;i++){
        cout << query(arr[i].x,arr[i].y) << endl;
    }
    return 0;
}