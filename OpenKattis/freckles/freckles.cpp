#include<bits/stdc++.h>
#define DB 1
#define MAXN 1005
using namespace std;

int T,N;
int parent[MAXN];
vector< pair<double,double> >arr;
vector< pair<double,pair<int,int> > >E;

int find(int n){
    if(parent[n] != n)parent[n] = find(parent[n]);
    return parent[n];
}
void merge(int x,int y){
     x = find(x);
     y = find(y);
     if(x < y)
        parent[y] = x;
     else
        parent[x] = y;
}


int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    cin >> T;
    for(int t = 0;T--;t++){
       cin >> N;
       if(t!=0)cout << endl;
       for(int i = 0;i < N;i++){
           double x,y;
           cin >> x >> y;
           arr.push_back(make_pair(x,y));
           parent[i] = i;
       }
       for(int i = 0;i < N;i++){
           for(int j = 0;j < N;j++){
               double w =  (arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)
                      + (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
               E.push_back( make_pair(w,make_pair(i,j)) );
           }
       }
       sort(E.begin(),E.end());
       double ans = 0;
       for(int i = 0;i < (int)E.size();i++){
           pair<double,pair<int,int> >e = E[i];
           double w = e.first;
           int x = find(e.second.first),y = find(e.second.second);
           if(parent[x] != parent[y]){
              merge(x,y);
              ans += sqrt(w);
           }
       }
       cout << setprecision(2) << fixed << ans << endl;
       arr.clear();
       E.clear();
    }
    return 0;
}