#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

const int MAXD = 1000;
const int SLEEPING = -1,WAITING = 1,BARKING = 0;
int D,F,T;
int state[MAXD];
int wait[MAXD];
int timer[MAXD];
int cnt[MAXD];
bool v[MAXD];

vector<int>adj[MAXD];

void update(int dog){
   for(int i = 0;i < (int)adj[dog].size();i++){
       if(state[adj[dog][i]] == SLEEPING){
          state[adj[dog][i]] = WAITING;
          timer[adj[dog][i]] = wait[adj[dog][i]];
       }
   }
}
int main(){
    freopen("Input/dogs1.in","r",stdin);
    cin >> D;
    for(int i = 0;i < D;i++){
        cin >> wait[i];
    }
    cin >> F;
    for(int i = 0,a,b;i < F;i++){
       cin >> a >> b;
       adj[--a].pb(--b);
    }
    cin >> T;
    memset(state,SLEEPING,sizeof(state));
    memset(timer,SLEEPING,sizeof(timer));
    state[0] = BARKING;
    timer[0] = 0;
    for(int t = 0;t <= T;t++){
       for(int dog = 0;dog < D;dog++){
           if(timer[dog] == 0){
              cnt[dog]++;
              update(dog);
           }
       }
       for(int dog = 0;dog < D;dog++){
           timer[dog]--;
           if(timer[dog] == 0)state[dog] = BARKING;
           if(timer[dog] <  0)state[dog] = SLEEPING;
           if(timer[dog] >  0)state[dog] = WAITING;
       }
    }
    for(int dog = 0;dog < D;dog++)
        cout << cnt[dog] << endl;
    return 0;
}

