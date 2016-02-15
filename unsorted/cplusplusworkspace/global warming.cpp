#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int n,cnt;
int main(){
    while(true){
        cin >> n;
        if(n == 0) break;
        int a[n];
        int b[n];
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n-1;i++)
            b[i] = a[i+1]-a[i];

        int t = 0;
        for(int i = 1;i < n;i++){
            cnt ++;
            if(b[0] == b[i]){
                break;
            }
        }
        int w = 0,ww = 0;
        for(;t < n;t++){
            if(b[w] == b[t])
                ww++;
            else
                break;
            w++;
        }
        if(ww >= 1)
            cout << cnt << endl << endl;
        else
            cout << n << endl << endl;
        //cout << cnt << endl;
        cnt = 0;
    }
}
