#include <iostream>

using namespace std;

int main(){
    int testcases; cin >> testcases;

    int array[testcases];
    string names[testcases];

    for(int i = 0;i < testcases;i++){
        cin >> names[i];
        cin >> array[i];

    }

    int temp;
    string tempName;

    for(int i=0,exchanges = 0;i<testcases;i++){
        for(int j=0,exchange=0;j<testcases;j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                tempName = names[j];

                array[j] = array[j+1];
                names[j] = names[j+1];

                array[j+1] = temp;
                names[j+1] = tempName;

                exchange++;

            }
            exchanges = exchange;
        }

        if(exchanges==0)
            break;
    }
    cout << endl;

    for(int i = testcases-1;i > -1;i--)
        cout << testcases - i << " "<< names[i] << endl;


    }






