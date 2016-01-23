#include<bits/stdc++.h>
#define MAXN 200000
using namespace std;

int N;
priority_queue<long long>pq;

int main(){
  //  freopen("input.txt","r",stdin);
    cin >> N;
    for(int i = 0;i < N;i++){
        long long in;
        cin >> in;
        pq.push(in);
    }
    long long out = 0;
    while(!pq.empty()){
         if(pq.size() >= 3){
            pq.pop();
            pq.pop();
            out += pq.top();
            pq.pop();
         }
         else
             pq.pop();
    }
    cout << out << endl;
    return 0;
}