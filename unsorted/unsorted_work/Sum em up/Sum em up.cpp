#include <iostream>

using namespace std;

int main(){
    int a,b,temp;
    int total = 0;

    for(int j = 0;j < 5;j++){
        cin >> a >> b;

        if(a > b){
            temp = a;
            a = b;
            b = temp;
        }

            for(int i = a;i <= b;i++){
                if(i < b){
                    cout << i << "+" ;
                }
                else{
                    cout << i << "=" ;
                }

                total += i;
            }

        cout << total << endl;
        total = 0;
    }
    return 0;
}
