#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int size, temp;
    cin >> size;
    double input[size];
    double median;

    for(int i = 0;i < size;i++){
        cin >> input[i];
    }
      //bubble sort
    for(int i = 0, exchanges = 0;i < size;i++){
        exchanges = 0;
        for(int j = 0;j < size-1 ;j++){
            if(input[j] > input[j+1]){
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
                exchanges++;
            }
        }
        if(exchanges==0)
            break;
    }

    if(size%2 != 0)
       median = input[size/2];
    else
       median = (input[size/2-1] + input[size/2])/2;

    printf("The median on the test is %.1f", median);


}
