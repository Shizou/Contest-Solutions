#include<stdio.h>
#include<queue>
#include<set>
using namespace std;
int d,n;
bool p = 0;
struct stroke{
    int sum,depth;
};
int main(){
    scanf("%d%d",&d,&n);
    int c[n];
    for(int i = 0;i < n;i++) scanf("%d",&c[i]);
    queue< stroke > q;
    set < int > set;
    q.push( (stroke){0,0} );
    while(!q.empty()){
        int s = q.front().sum;
        int dep = q.front().depth;
        q.pop();
        if(s > d)
            continue;
        if(s == d){
            printf("Roberta wins in %d strokes.\n",dep);
            p = true;
            break;
        }
        for(int i = 0;i < n;i++){
            if(set.find(s+c[i]) == set.end()){
                q.push( (stroke){ (s+c[i]),dep+1} );
                set.insert(s+c[i]);
            }
        }
    }
    if(p == false)
        printf("Roberta acknowledges defeat.\n");
}
