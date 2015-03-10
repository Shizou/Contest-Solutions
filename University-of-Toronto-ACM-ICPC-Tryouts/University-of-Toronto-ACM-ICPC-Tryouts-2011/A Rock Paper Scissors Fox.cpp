#include <iostream>
#include <string>

using namespace std;

int main(){
    int testcases;
    bool foxen = false;
    string input;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        cin >> input;
        if(!foxen){
            if(input == "Rock")
                cout << "Paper\n";

            else if(input == "Scissors")
                cout << "Rock\n";

            else if(input == "Paper")
                cout << "Scissors\n";

            else if(input == "Fox")
                cout << "Foxen\n";

            else if( input == "Foxen")
                foxen = true;
        }
    }
}
