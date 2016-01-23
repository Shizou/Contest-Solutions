#include<iostream>
using namespace std;

int t,n,cnt,temp,o;

int main(){
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> n;
        int a[n];
        cnt = 0;
        for(int j = 0;j < n;j++) cin >> a[j];
        for (int k = 0; k < n ;k++){
            o = 0;
            for (int m = 0; m < n-1;m++){
               if(a[m] > a[m+1]){
                  temp = a[m];
                  a[m]=a[m+1];
                  a[m+1]= temp;
                  cnt++;
                  o++;
              }
            }
            if(o == 0)break;
        }
        printf("Optimal train swapping takes %d swap(s).\n");
    }
    return 0;
}
