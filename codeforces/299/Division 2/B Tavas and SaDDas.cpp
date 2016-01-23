#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
#define all(x) x.begin(),x.end()
using namespace std;

const int MAXN = (int)1e9;
int n;
vector<long long>arr;
set<long long>v;

int main(){
    //freopen("input.txt","r",stdin);
    cin >> n;
    queue<long long>q;
    q.push(4),q.push(7);
    v.insert(4),v.insert(7);
    arr.push_back(4),arr.push_back(7);
    while(!q.empty()){
       long long x = q.front(),a = x*10+4,b = x*10+7;
       q.pop();
       if(!v.count(a) && a < MAXN){
           v.insert(a);
           q.push(a);
           arr.push_back(a);
       }
       if(!v.count(b) && a < MAXN){
          v.insert(b);
          q.push(b);
          arr.push_back(b);
       }
    }
    sort(all(arr));
    long long idx = lower_bound(all(arr),n)-arr.begin()+1;
    cout << idx << endl;
    return 0;
}