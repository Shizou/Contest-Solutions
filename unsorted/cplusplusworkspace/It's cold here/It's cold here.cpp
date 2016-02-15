#include <iostream>
#include <string>

using namespace std;

int main(){
    string input, top;
    int lowTemp = 100, temp;

        do{
            cin >> input;
            cin >> temp;

            if(temp < lowTemp){
                top = input;
                lowTemp = temp;
            }


        }while(input != "Waterloo");

    cout << top << endl;

    return 0;
}
