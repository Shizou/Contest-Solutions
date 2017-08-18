#include <iostream>
#include <stdio.h>

using namespace std;



int main(){
    int size;
    double temp;
    double mean = 0, median = 0, mode = 0, max= 0, min = 0;
    cin >> size;

    double input[size];

    for(int i = 0;i < size;i++){
        cin >> input[i];
        mean += input[i];
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

    //mean
    mean /= size;
    //median
    if(size%2 != 0)
        median = input[size/2];
    else
        median = (input[size/2-1] + input[size/2])/2;
    //mode
    for(int i = 0;i < size-1;i++)
    {
        if(input[i] == input[i+1]){
            mode = input[i];
            break;
        }
    }
    //maximum
    max = input[size-1];
    //minimum
    min = input[0];

    printf("%.2f\n",mean);
    printf("%.2f\n",median);
    printf("%.2f\n",mode);
    printf("%.2f\n",max);
    printf("%.2f\n",min);


    return 0;
}

