#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define nullptr 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;


int N;
bool v[1000];
vector< pair<int,int> >arr;

int right(int it){
  memset(v,false,sizeof(v));
    int ca = 0,state = 0;
    int jt = it;// go right
    v[it] = true;
    int na = 1,nb = 0;
    while(nb != na){
       nb = na;
       if(state == 0)// go right
         for(int i = jt;i < (int)arr.size();i++){
             if(!v[i]){
                v[i] = true;
                ca+= arr[i].y;
                state = 1;
                na++;
                break;
            }
         }
       if(state == 1)// go left
         for(int i = jt;i >= 0;i--){
             if(!v[i]){
                v[i] = true;
                ca+= arr[i].y;
                state = 0;
                na++;
                break;
            }
         }
    }
    return ca;
}
int left(int it){
  memset(v,false,sizeof(v));
    int ca = 0,state = 1;
    int jt = it;// go left
    v[it] = true;
    int na = 1,nb = 0;

    while(nb !=na){
       nb = na;
       if(state == 1)// go left
         for(int i = jt;i >= 0;i--){
             if(!v[i]){
                 v[i] = true;
                ca+= arr[i].y;
                state = 0;
                na++;
                break;
            }
         }
        if(state == 0)// go right
         for(int i = jt;i < (int)arr.size();i++){
             if(!v[i]){
                v[i] = true;
                ca+= arr[i].y;
                state = 1;
                na++;
                break;
            }
         }
        // cout << na <<  " "<< nb << endl;
    }
    return ca;
}
int main(){
    //freopen("A-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++){
      int a,b;cin >> a>> b;
      arr.pb(mp(a,b));
    }
    arr.pb(mp(0,0));
    sort(all(arr));
    int it = 0;
    for(int i = 0;i < (int)arr.size();i++){
      if(arr[i].x == 0 && arr[i].y == 0)it = i;
    }
    int ans = 0;
    ans = max(ans,left(it));
    ans = max(ans,right(it));
    cout << ans << endl;
    return 0;
}

