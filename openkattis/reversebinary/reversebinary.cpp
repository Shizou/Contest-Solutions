#include <bits/stdc++.h>
using namespace std;

int N;

int binary(int n){
    vector<int>v;
    while(n!=0){
        v.push_back(n%2);
        n/=2;
    }
    reverse(v.begin(),v.end());
    int ret = 0;
    for(int i = 0,pwr = 0;i < v.size();i++)
        ret += v[i]*pow(2,pwr++);
    return ret;
}
int main() {
    freopen("input.txt","r",stdin);
    cin >> N;
    N = binary(N);
    cout << N << endl;
    return 0;
}