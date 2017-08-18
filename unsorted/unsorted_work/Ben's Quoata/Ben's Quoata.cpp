#include <iostream>

using namespace std;

int main(){
    int input [10];
    int total;

    for(int i = 0;i < 10; i++){
            cin >> input[i];

            if(total + input[i] <= 100)
                total += input[i];
    }
    cout << total << endl;

}
