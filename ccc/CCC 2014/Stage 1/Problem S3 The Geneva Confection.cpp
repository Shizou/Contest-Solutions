#include<cstdio>
#include<stack>
using namespace std;
stack<int> m;
stack<int> b;
stack<int> l;
int n,c,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){scanf("%d",&c); m.push(c);}
        int p = 1; bool pos = 1;
        while(l.size() != n){
            if(!m.empty() && m.top() == p){
                l.push(p);
                m.pop();
                p++;

            }
            else if(!b.empty() && b.top() == p){
                l.push(p);
                b.pop();
                p++;
            }
            else if(  b.empty() || m.top() < b.top()){
                 b.push(m.top());
                 m.pop();
            }
            else{
                pos = 0;
                break;
            }
        }
        m = stack<int>();
        b = stack<int>();
        l = stack<int>();
        if(pos) printf("Y\n");
        else    printf("N\n");
    }
    return 0;
}
