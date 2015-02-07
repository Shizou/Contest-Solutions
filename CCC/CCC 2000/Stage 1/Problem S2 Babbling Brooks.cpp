#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int N,C;
double a,b,r;
vector<double>arr;

int main(){
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> a;
        arr.pb(a);
    }
    while(cin >> C){
        if(C == 99){
            cin >> a >> b;
            a--;
            r = arr[a]-arr[a]*(b/100);
            arr[a]*=(b/100);
            arr.insert(arr.begin()+a+1,r);
        }
        else if(C == 88){
            cin >> a;
            a--;
            arr[a+1]+=arr[a];
            arr.erase(arr.begin()+a);
        }
        else if(C == 77){
            for(int i = 0; i < arr.size();i++)
                printf("%.0f ",arr[i]);
            printf("\n");
            break;
        }
    }
    return 0;
}

