#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;

    int whitespaces = 0;

    for(int k = 0;k < 5;k++){
        cin >> input;
        for(int i = 0;i < input.size();i++){

            for(int j = 0;j < input.size()-1-i;j++){
                cout << " ";
            }
            cout << input.at(i);


            if(i > 0)
                whitespaces +=2;

            for(int j = 0;j < whitespaces-1 ;j++){
                cout << " ";
            }
            if(i != 0)
                cout << input.at(i);

            cout << endl;
        }

        for(int i = input.size()-2;i > -1;i--){

            for(int j = 0;j < input.size()-1-i;j++){
                cout << " ";
            }
            cout << input.at(i);

            whitespaces -=2;

            for(int j = 0;j < whitespaces-1 ;j++){
                cout << " ";
            }
            if(i != 0)
                cout << input.at(i);


            cout << endl;
        }

    }


    return 0;
}
