#include <iostream>
#include <math.h>


using namespace std;

int main(){
    int testcases;
    double input,inputTwo;
    double stars;

    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        cin >> input >> inputTwo;
        stars = nearbyint((input/(input+inputTwo))*10);

        for(int j = 0;j < 10;j++){
            if(stars > 0){
                cout << "*";
                stars--;
            }
            else
                cout << ".";

        }
        cout << endl;

    }

}

