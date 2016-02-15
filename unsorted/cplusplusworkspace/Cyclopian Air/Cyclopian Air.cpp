#include <iostream>

using namespace std;

int main(){
    int size, top = 0;
    cin >> size;
    int input[size];

    for(int i  = 0;i < size;i++){
        cin >> input[i];
    }
    for(int i  = 0;i < size-1;i++){
        if(input[i]*input[i+1] > top){
            top = input[i]*input[i+1];
        }

    }

    cout << top << endl;


    return 0;
}
