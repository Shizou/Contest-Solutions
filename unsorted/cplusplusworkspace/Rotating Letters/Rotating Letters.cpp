#include <iostream>
#include <string>

using namespace std;

bool check(string input){
    for(int i = 0;i < input.size();i++){
        if(input.at(i) != 'I' && input.at(i) != 'O'){
            if(input.at(i) != 'S' && input.at(i) != 'H'){
                if(input.at(i) != 'Z' && input.at(i) != 'X'){
                    if(input.at(i) != 'N')
                        return false;
                }
            }
        }
    }

    return true;
}

int main(){
    string input;
    cin >> input;

    if(check(input))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
