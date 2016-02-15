#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#define nullptr 0
#define MAXN 1000
using namespace std;

int T,N;
set<string>used;
string arr[MAXN];

struct node{
    string v;
    node* l;
    node* r;
    public:
        node(string vv){
            v = vv;
        }
};

class tree{
    node* root;
    public:
        tree(){root = nullptr;}
        void insert(string s){
            if(root == nullptr){
                root = new node(s);
                return;
            }else{
                queue<node*>q;
                q.push(root);
                while(!q.empty()){
                    node* c = q.front();
                    q.pop();
                    cout << c->v << endl;
                    printf("hi");
                    if(c->l == nullptr){
                        c->l = new node(s);
                        break;
                    }
                    else if(c->r == nullptr){
                        c->r = new node(s);
                        break;
                    }zxzxzxzxzxzxzxzxzx
                    if(c->l != nullptr)q.push(c->l);
                    if(c->r != nullptr)q.push(c->r);
                }
            }
        }
};

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&T,&N);
    for(int i = 0; i < N;i++){
        cin >> arr[i];
    }
    tree TT;
    for(int i = N-1; i >= 0;i--){
        cout << i << " ";
        if(used.find(arr[i]) == used.end()){
            TT.insert(arr[i]);
            used.insert(arr[i]);
        }
        cout << endl;
        //break;
    }
    return 0;
}
