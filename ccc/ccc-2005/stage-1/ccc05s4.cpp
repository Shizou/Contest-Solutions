#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define nullptr 0
#define pb push_back
using namespace std;

struct node{
    string s;
    node* p;
    vector<node*>c;
    public:
        node(string ss,node*pp){
            s = ss;
            p = pp;
        }
};

int T,N,D;
string arr[1000];
node*root;

void rec(node*cur,int d){
    D = max(D,d);
    for(int i = 0; i < cur->c.size();i++)
        rec(cur->c[i],d+1);
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> T;
    while(T--){
        cin >> N;D = 0;
        for(int i = 0; i < N;i++)
            cin >> arr[i];
        root = new node(arr[N-1],nullptr);
        node*cur= root;// current
        for(int i = N-2; i >= 0;i--){
            if(cur->p != nullptr && cur->p->s == arr[i]){
                cur = cur->p;
            }else{
                cur->c.pb(new node(arr[i],cur));
                cur = cur->c[cur->c.size()-1];
            }
        }
        rec(root,0);
        printf("%d\n",N*10-D*20);
    }
    return 0;
}

