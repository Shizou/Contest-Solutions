#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int n,a,b,cnt;
char c;
bool d;
int main(){
    //freopen("input.txt","r",stdin);
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d%c%d",&a,&c,&b);
        d = 0;
        while(true){
          if(d){
            if(a == 1 && b == 2){
                a = 4;
                b = 1;
            }
            else if(a == 4 && b == 2){
                a = 8;
                b = 1;
            }
            else if(a == 8 && b == 4){
                break;
            }
            else if(b == 4){
                a++;
                b = 1;
            }
            else
                b++;
          }
          else
            d = 1;
            cnt++;
        }
        cout << cnt << endl;
        cnt = 0;
    }
    //fclose(stdin);
    return 0;
}
