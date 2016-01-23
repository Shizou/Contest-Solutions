#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define nullptr 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define xx first
#define yy second
#define LL long long
using namespace std;


struct node{
    int lc;
    char c;
    bool end;
    map<char,node*>m;
    node(char _c,bool _end,int _lc){
        c   = _c;
        end = _end;
        lc = _lc;
    }
};
struct trie{

    node*root;
    int it,cc;
    string chain;

    trie(){root = new (node){' ',false,0};}

    void insert(node*n,string&s){
        if(it == (int)s.size())
           return;
        else if(!n->m.count(s[it])){

            if(it == (int)s.size()-1)
               n->m[s[it]] = new (node){s[it],true,++cc};
            else
               n->m[s[it]] = new (node){s[it],false,cc};
            insert(n->m[s[it++]],s);
            n->lc = max(n->lc,n->m[s[--it]]->lc);
        }
        else{
            if(n->m[s[it]]->end)cc++;
            insert(n->m[s[it++]],s);
            n->lc = max(n->lc,n->m[s[--it]]->lc);
        }
    }
    void print(){
        node*current = root;
        int children = 1;
        while(children > 0){
            children = 0;
            for(char c = 'a';c <= 'z';c++){
                if(current->m.count(c)){
                    children++;
                    if(current->m[c]->lc == root->lc){
                        chain+= current->m[c]->c;
                        if(current->m[c]->end == true)
                           cout << chain << endl;
                        current = current->m[c];
                        break;
                    }
                }
            }
        }

    }
};

trie T;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    while(cin >> s){
        T.it = 0,T.cc = 0;
        T.insert(T.root,s);
    }
    T.print();
    return 0;
}

