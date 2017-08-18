#include <iostream>
#include<cmath>
using namespace std;

int a[] = {5,4,3,2,1,10,9,8,7,6};
int c;
int main(){
    for(int i = 0; i < 10;i++){
        for(int j =0; j < i-1;j++){
            if(a[j] > a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}
