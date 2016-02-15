#include <iostream>
#include <string>

using namespace std;

int main(){
    unsigned int max = 2000000000, min = 1, guess = 0;
    string input = "";

    do{
        guess = (min+max)/2;

        cout << guess << endl;
        cout.flush();

        cin >> input;

        if(input == "Lower"){
            max = guess-1;
        }
        else if(input == "Higher"){
            min = guess+1;
        }




    }while(input != "OK");

    return 0;
}
