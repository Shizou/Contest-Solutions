// https://open.kattis.com/problems/almostunionfind
#include<bits/stdc++.h>
#define DB
using namespace std;

struct DSET{
   set<int>s;
   int sum;
   DSET(){
      sum = 0;
   }
   DSET(int &n){
      s.insert(n);
      sum = 0;
      sum += n;
   }
   void merge(int &n){
       s.insert(n);
       sum+=n;
   }
   void merge(set<int>&ns){
       for(set<int>::iterator it = ns.begin();it!=ns.end();it++){
           s.insert(*it);
           sum += *it;
       }
   }
   void remove(int &n){
       s.erase(n);
       sum -= n;
   }
   int size(){
      return (int)s.size();
   }
   bool count(int &n){
      return s.count(n);
   }
};

int N,M;
map<int,DSET*>m;

int main(){
    #ifdef DB
    freopen("input.txt","r",stdin);
    #endif
    cin >> N >> M;
    for(int i = 1;i <= N;i++)
        m[i] = new (DSET){i};
    for(int i = 0,cmd,p,q;i < M;i++){
        cin >> cmd;
        if(cmd == 1){// join these two sets
           cin >> p >> q;
           if( m[p]->count(q) || m[q]->count(p))
              continue;
           else{
              m[p]->merge(m[q]->s);
              m[q] = m[p];
           }
        }
        if(cmd == 2){// move p into set q
           cin >> p >> q;
           m[p]->remove(p);
           m[q]->merge(p);
           m[p] = m[q];
        }
        if(cmd == 3){// print number of elements in set containing p and sum of that set
           cin >> p;
           cout << m[p]->size() << " " << m[p]->sum << endl;
        }
    }
    return 0;
}
