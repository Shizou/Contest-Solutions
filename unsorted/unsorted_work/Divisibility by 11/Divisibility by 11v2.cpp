#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>



using namespace std;

string removeTrailingZeroes(string number){
    for(;;){
        cout << number << endl;
        if(number.at(number.size()-1) == '0')
            number.erase(number.size()-1,1);
        else
            break;
    }

    return number;
}


int main(){

    int testcases;
    string number, numberCopy;

    cin >> testcases;

    for(int i = 0;i < testcases; i++)
    {
        cin >> number;
        numberCopy = number;
        number = removeTrailingZeroes(number);


            for(int j = number.size()-1; j > -1 ; j--)
            {
                if(number.size()-1 != 2){
                    string tempValue = number.substr(number.size()-4, 3);
                    string tempValue2 = number.substr(number.size()-1, 1);

                    int value = atoi(tempValue.c_str()) - atoi(tempValue2.c_str());
                    string stringValue = static_cast<ostringstream*>( &(ostringstream() << value) )->str();

                    number.replace(number.size()-4,3, stringValue);
                    number.erase(number.size()-1,1);


                    cout << number << endl;

                }else{

                    string tempValue = number.substr(0, 2);
                    string tempValue2 = number.substr(number.size()-1, 1);

                    int value = atoi(tempValue.c_str()) - atoi(tempValue2.c_str());
                    string stringValue = static_cast<ostringstream*>( &(ostringstream() << value) )->str();

                    number.replace(0,2, stringValue);
                    number.erase(number.size()-1,1);

                    cout << number << "\n" << "The number " << numberCopy;

                    if(value == 11)
                        cout << " is divisible by 11.\n";
                    else
                        cout << " is not divisible by 11.\n";

                        break;

                }

            }
    }



    return 0;
}
