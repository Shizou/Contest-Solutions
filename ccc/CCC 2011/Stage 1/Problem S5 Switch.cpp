#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

int N,ID;
char C;
bool v[(1<<25)+1];

int main(){
    freopen("Input/s5.9.in","r",stdin);
    scanf("%d",&N);
    for(int i = 0;i < N;i++){
        scanf(" %c",&C);
        if(C == '1')
           ID |= 1<<(i);
    }
    queue< pair<int,int> >q;
    q.push(mp(0,ID));
    while(!q.empty()){
        int d = q.front().x;
        int id = q.front().y;
        q.pop();
        for(int i = 0;i < N;i++){
            if(i+3 < N){
                /*Checks for 4 consecutive ones.*/
                if( (id >> (i) & 1) && (id >> (i+1) & 1) && (id >> (i+2) & 1) && (id >> (i+3) & 1) ){
                     for(int j = i;j < N;j++){
                         if( (id >> (j) & 1) )
                            id ^= 1<<(j);
                         else
                            break;
                     }
                }
            }
        }
        if(id == 0){
            printf("%d\n",d);
            return 0;
        }
        for(int i = 0,bit = 0;i < N;i++){
            bit = (id>>i)&1;
            if( bit == 0 ){
                id ^= 1<<(i);
                if(!v[id]){
                    v[id] = true;
                    q.push(mp(d+1,id));
                }
                id ^= 1<<(i);
            }
        }
    }
    return 0;
}
