#include <iostream>
using namespace std;

int main() {
    int input = 0;
    int repetitions = 0;

    cin >> input;

    while(true){
        if(input != 1)
        repetitions++;

        if(input % 2 != 0 && input != 1){
            input = input * 3;
            input = input + 1;
        }
        else if(input % 2 == 0)
            input/=2;

        if(input == 1)
            break;
    }

    cout << repetitions << "\n";

    return 0;
}
