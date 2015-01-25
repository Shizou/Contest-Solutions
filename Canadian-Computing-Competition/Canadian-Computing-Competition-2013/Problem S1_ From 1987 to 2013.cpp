#include <iostream>
#include <sstream>
using namespace std;

bool check(int number){
    string conversion = static_cast<ostringstream*>( &(ostringstream() << number) )->str();
    for(int i = 0; i < conversion.length() ;i++){
        for(int j = i+1;j < conversion.length();j++){
            if(conversion.at(i) == conversion.at(j))
                return false;
        }
    }
    return true;
}
int main(){
    int input, answer;
    cin >> input;
    for(int i = input+1;;i++){
        if(check(i)){
        input = i;
        break;
        }

    }
    cout << input;
}
