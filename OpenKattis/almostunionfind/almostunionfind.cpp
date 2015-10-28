#include<bits/stdc++.h>
#define DBa
#define MAXN (int)1e5+5
using namespace std;

struct dset{
    set<int>s;
    long long sum;
    dset(){sum = 0;}
    dset(int &n){
        s.insert(n);
        sum = n;
    }
    void merge(int &n){
       s.insert(n);
       sum += n;
    }
    void merge(int &p,int &q,vector<dset*>&m){
        for(set<int>::iterator it = m[q]->s.begin();it!=m[q]->s.end();it++){
            s.insert(*it);
            sum += *it;
            if(*it != q)
               m[*it] = m[p];
        }
        m[q] = m[p];
    }
    void remove(int &n){
       s.erase(n);
       sum -= n;
    }
    int size(){
       return (int)s.size();
    }
    int tot_sum(){
       return sum;
    }
    bool contains(int &n){
       return s.count(n);
    }
};

int N,M;
vector<dset*>m(MAXN);

int main(){
    #ifdef DB
    freopen("input.txt","r",stdin);
    #endif
    while(cin >> N >> M){
          for(int i = 1;i <= N;i++)
              m[i] = new (dset){i};
          for(int i = 0,cmd,p,q;i < M;i++){
              cin >> cmd;
              if(cmd == 1){
                 cin >> p >> q;
                 if(m[p]->contains(q))// already in the same set
                    continue;
                 else
                    m[p]->merge(p,q,m);
              }
              if(cmd == 2){
                 cin >> p >> q;
                 if(m[q]->contains(p))
                    continue;
                 else{
                    m[p]->remove(p);
                    m[q]->merge(p);
                    m[p] = m[q];
                 }
              }
              if(cmd == 3){
                 cin >> p;
                 cout << (m[p]->size()) << " " << (m[p]->tot_sum()) << endl;
              }
          }
    }

    return 0;
}

