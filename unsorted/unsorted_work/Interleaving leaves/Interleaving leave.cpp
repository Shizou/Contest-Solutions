#include <iostream>
#include <string>

using namespace std;

int main(){


    int scenarios, length;
    string inputOne, inputTwo, output;

    cin >> scenarios;

    for(int i = 0;i < scenarios;i++){

        cin >> length;
        cin >> inputOne;
        cin >> inputTwo;

        for(int j = length-1;j > -1;j--){
            output += inputTwo.at(j);
            output += inputOne.at(j);
        }

        cout << output << endl;
        output = "";
        inputOne = "";
        inputTwo = "";
    }

    return 0;
}
