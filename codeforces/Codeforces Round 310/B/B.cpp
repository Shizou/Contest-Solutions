#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;


struct trie{
    struct node{
      char c;
      map<char,node*>children;
      node(char _c){
         c = _c;
      }
    }*root;
    int sz;
    trie(){
      sz = 1;
      root = new (node){' '};
    }
    void add(node*nd,string &s,int i){
         if(i == (int)s.size())
            return;
         else if(!nd->children.count(s[i])){
             nd->children[s[i]] = new (node){s[i]};
             sz++;
             add(nd->children[s[i]],s,i+1);
         }else{
             add(nd->children[s[i]],s,i+1);
         }
    }
    int size(){
      return sz;
    }
};

trie T;
string S;

int main(){
    //freopen("B-input.txt","r",stdin);
    needforspeed;
    while(cin >> S)
      T.add(T.root,S,0);
    cout << T.size() << endl;
    return 0;
}