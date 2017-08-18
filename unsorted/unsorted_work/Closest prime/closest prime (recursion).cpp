#include <iostream>
#include <math.h>

using namespace std;

int recurseDown(int x){

        for(int i = 2;i <= sqrt(x);i++){
            if(x%i == 0){
                x = recurseDown(x-1);
            }
        }

        return x;

}
int recurseUp(int x){

        for(int i = 2;i <= sqrt(x);i++){
            if(x%i == 0){
                x = recurseUp(x+1);
            }
        }

        return x;

}

int main(){

    int input, output;
    cout << "Please input number: " << endl;
    cin >> input;

    int prime1 = recurseDown(input-1);
    int prime2 = recurseUp(input+1);

    int difference1 = input - prime1;
    int difference2 = prime2 - input;

    if(difference1 < difference2){
        output = prime1;
    }
    else{
        output = prime2;
    }

    cout << "Clostest and largest prime is: " << output << endl;


    return 0;

}
