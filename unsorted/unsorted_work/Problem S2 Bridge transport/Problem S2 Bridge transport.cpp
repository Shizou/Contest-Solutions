#include <iostream>

using namespace std;

int check(int*cars){
    for(int i = 0;i < 4;i++){
        if(cars[i] == 0)
            return i;
        if(i == 3)
            return 0;
    }
}
bool checkAvailibility(int*cars){
    for(int i = 0;i < 4;i++){
        if(cars[i] == 0)
            return false;
        if(i == 3)
            return true;
    }
}


int main(){
    int maxweight = 0, currentWeight = 0, n = 0, carpasses = 0;

    cin >> maxweight;
    cin >> n;

    int carsWeight[n];
    int currentCars[4];

    for(int i = 0;i < n;i++){
        cin >> carsWeight[i];
    }
    for(int i = 0;i < n;i++){
        if(currentWeight + carsWeight[i] <= 100){
            currentWeight += carsWeight[i];
            carpasses += 1;
            currentCars[check(currentCars)] = i;
        }
        else if(checkAvailibility(currentCars) && currentWeight - carsWeight[0] + carsWeight[i] <= 100){
            currentWeight -= carsWeight[0];
            carpasses += 1;

            //shift values
            for(int j = 0;j< 3;j++){
                currentCars[j] = j+1;
            }
            currentCars[4] = i;
        }
        else
            break;

    }

    cout << carpasses << endl;

}
