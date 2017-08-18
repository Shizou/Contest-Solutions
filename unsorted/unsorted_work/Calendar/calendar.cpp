#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int a = 7,b = 31;
    cin >> a >> b;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    for(int i = 1;i < a;i++){
        cout << "    ";
    }
    for(int i = 1;i <= b;i++){
        if(a < 7){
            printf("%3d ",i);
            a++;
        }
        else{
            printf("%3d\n",i);
            a = 1;
        }

    }

    return 0;
}
