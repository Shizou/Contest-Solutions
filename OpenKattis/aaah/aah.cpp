#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define DB 1
using namespace std;

string A,B;

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    cin >> A >> B;
    if(len(A) < len(B))
       cout << "no" << endl;
    else
       cout << "go" << endl;
    return 0;
}