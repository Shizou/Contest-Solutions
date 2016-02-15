#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
using namespace __gnu_pbds;

typedef tree<
  int,
  null_type,
  greater<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
set_t;

int N,X,R,K,n;
char cmd;
unordered_map<int,int>user,score;
set_t s;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0;i < N;++i){
      scanf(" %c",&cmd);
      if(cmd == 'N'){
        scan(X);scan(R);
        user[X] = R;
        score[R] = X;
        s.insert(R);
      }
      else if(cmd == 'M'){
        scan(X);scan(R);
        s.erase(user[X]);
        score.erase(user[X]);
        user[X] = R;
        score[R] = X;
        s.insert(R);
      }else{
        scan(K);
        printf("%d\n",score[*s.find_by_order(K-1)]);
      }
    }
    return 0;
}