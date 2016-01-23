#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N,P,a,b;
int cf,cnt = 1;
vector< pair<int,int> > arr;
int main(){
    scanf("%d%d",&N,&P);
    for(int i = 0; i < N;i++){
        scanf("%d%d",&a,&b);
        if(i == P-1){
            cf = a;
            continue;
        }
        arr.push_back(make_pair(b,a));
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < N-1;i++){
        if(arr[i].first > cf)continue;
        else if(arr[i].second - arr[i].first >= 0){
            cnt++;
            cf += (arr[i].second - arr[i].first);
        }
    }
    printf("%d\n%d\n",cf,cnt);
    return 0;
}

