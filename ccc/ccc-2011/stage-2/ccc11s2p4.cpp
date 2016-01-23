#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define nullptr 0
using namespace std;


int N;
set<int>v;
map<int,int>C;

int main(){
    //freopen("Input/reorg.A.3.in","r",stdin);
    cin >> N;
    for(int i = 0,j = 0;i < N;i++){
       cin >> j;
       if(i == 0)
          v.insert(j);
       else{
          set<int>::iterator it = --v.upper_bound(j);
          if(*v.begin() > j){
             printf("NO\n");
             return 0;
          }
          while(it != v.end()){
            if(C[*it] < 2){
               C[*it]++;
               v.insert(j);
               if(C[*it] == 2)
                  v.erase(it);
               break;
            }
            --it;
          }
          if(!v.count(j)){
             printf("NO\n");
             return 0;
          }
       }
    }
    printf("YES\n");
    return 0;
}

