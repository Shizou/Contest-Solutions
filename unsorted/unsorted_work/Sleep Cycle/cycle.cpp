#include <iostream>
#include <cstdio>
#define max(a,b) a>b?a:b
using namespace std;

int N,max_len,len,a[1000];
bool down, single_dip;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < N-1;i++){
        len = 1;
        down = true;
        single_dip = true;
        if(a[i] != a[i+1]){
            cout << i << " ";
            for(int j = i+1;j < N;j++){
                cout << j << " ";
                if(down){
                    if( single_dip && a[j] == a[j-1]){
                        single_dip = false;
                        len++;
                    }
                    else if(single_dip && a[j] < a[j-1])
                        len++;
                    else if( !single_dip && a[j] < a[j-1]){
                        len = 0;
                        cout << "TEST" << endl;
                        break;
                    }
                    else if( a[j] > a[j-1]){
                        len++;
                        down = false;
                    }
                }
                else{
                    if(a[j] > a[j-1])
                        len++;
                    else{
                        cout << "TEST2" << endl;
                        break;
                    }
                }
            }
            cout << endl << len<< endl;
            max_len = max(max_len,len);
        }
    }
    printf("%d\n",(max_len >= 3) ? max_len:0);
}
