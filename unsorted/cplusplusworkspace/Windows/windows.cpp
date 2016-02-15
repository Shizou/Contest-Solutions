#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define nullptr 0
using namespace std;


struct node{
    pair<int,int>P[2];
    bool real_window;
    node(){}
    node(pair<int,int>p1,pair<int,int>p2){
         P[0] = p1,P[1] = p2;
         real_window = false;
    }
};

const int MAXN = 50000,inf = 0x3f3f3f3f,PRCD_INC =MAXN;
int R,C,N,M,qx,qy;
node tree[4*MAXN];
int  precedence[MAXN];

vector< pair< pair<int,int>, pair<int,int> > >arr;
map< pair< pair<int,int>,pair<int,int> >,int>pt_to_idx;
map<int,int>precd_to_idx;

bool valid(pair<int,int>p,pair<int,int>q){
  return !(p.x == 0 && p.y == 0 && q.x == 0 && q.y == 0);
}

bool contains(pair<int,int>P[2]){
  return qx >= min(P[0].x,P[1].x) && qx <= max(P[0].x,P[1].x) &&
         qy >= min(P[0].y,P[1].y) && qy <= max(P[0].y,P[1].y);
}
void build(int n,int lo,int hi){
     if(lo == hi){
        tree[n].real_window = true;
        tree[n].P[0] = arr[lo].x;
        tree[n].P[1] = arr[lo].y;
     }else{
        build(2*n+1,lo,(lo+hi)/2);
        build(2*n+2,(lo+hi)/2+1,hi);
        if(valid(tree[2*n+1].P[0],tree[2*n+1].P[1]) && valid(tree[2*n+2].P[0],tree[2*n+2].P[1])){ // makes sure we aren't making invalid points like [0,0]-[0,0]
           tree[n].P[0] = tree[2*n+1].P[0];
           tree[n].P[1] = tree[2*n+2].P[1];
        }else{
           if(valid(tree[2*n+1].P[0],tree[2*n+1].P[1]))
              tree[n].P[0] = tree[2*n+1].P[0], tree[n].P[1] = tree[2*n+1].P[1];
           if(valid(tree[2*n+2].P[0],tree[2*n+2].P[1]))
              tree[n].P[0] = tree[2*n+2].P[0], tree[n].P[1] = tree[2*n+2].P[1];
        }

     }
}

// We recurse while the current point is contained within a current segment. If it is not we return a precedence of 0.
// If however we obtain a value of 0 from query(0,0,N-1) then that means that the point is not contained within any segment
// that is within the tree
int query(int n,int lo,int hi){
//    printf("{%d,%d}-%d[%d,%d] -> [%d,%d]-[%d,%d]\n",qx,qy,n,lo,hi,tree[n].P[0].x,tree[n].P[0].y,tree[n].P[1].x,tree[n].P[1].y);

    if(!contains(tree[n].P))// checks whether or not the point is contained by the current segment
       return -inf;
    if(!tree[n].real_window){
      // we return the window which has the greatest precedence in the subsection where the point lies.
      return max(query(2*n+1,lo,(lo+hi)/2),query(2*n+2,(lo+hi)/2+1,hi));
    }else{// this is a real window so we return its precedence. This only occurs when lo == hi
        return precedence[lo];
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    memset(precedence,-inf,sizeof(precedence));
    scanf("%d%d%d",&R,&C,&N);
    for(int i = 1;i <= N;++i){
      pair< pair<int,int>, pair<int,int> >pt;
      scanf("%d%d%d%d",&pt.x.x,&pt.x.y,&pt.y.x,&pt.y.y);
      arr.pb(pt);
      precedence[i-1] = i;
      pt_to_idx[pt] = i;
      precd_to_idx[i] = i-1;
    }
    sort(arr.begin(),arr.end());
    build(0,0,N-1);
    scanf("%d",&M);
    for(int i = 0;i < M;++i){
        scanf("%d%d",&qx,&qy);
        int precd = query(0,0,N-1);
        if(precd == -inf)
           printf("0\n");
        else{
            printf("%d\n",pt_to_idx[arr[precd_to_idx[precd]]]);
            precd_to_idx[precedence[precd_to_idx[precd]]*PRCD_INC] = precd_to_idx[precd];
            precd_to_idx.erase(precd_to_idx[precd]);
            precedence[precd_to_idx[precd]]+=PRCD_INC;
        }
    }
    return 0;
}