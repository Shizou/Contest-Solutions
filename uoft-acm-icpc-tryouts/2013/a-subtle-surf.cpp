#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int D,N,C,T,max_n,t,cnt,a_i;
vector<int>arr;
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&D);
    while(D--){
        scanf("%d%d%d",&N,&C,&T);
        scanf("%d",&a_i);
        max_n = a_i;
        for(int i = 0; i < N-1;i++){
            scanf("%d",&a_i);
            arr.push_back(a_i);
        }
        sort(arr.begin(),arr.end());
        t = 0;
        for(int i = 0; i < arr.size()-1;i++){
            if(arr[i] > max_n && arr[i]-max_n <= C && arr[i+1]-max_n > C){
                t+=T;
                max_n = arr[i];
            }
        }
        if(arr[arr.size()-1]-max_n <= C && arr[arr.size()-1] > max_n){
            t+=T;
            max_n = arr[arr.size()-1];
        }
        printf("%d %d\n",max_n,t);
        arr.clear();
    }
    return 0;
}
