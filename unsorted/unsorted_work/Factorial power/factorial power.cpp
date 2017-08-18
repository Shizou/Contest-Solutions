#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(){
    unsigned int input, total = 1;
    for(int i = 0;i < 5;i++){
        cin >> input;
            for(int j = 1;j <= input;j++){
                total*=j;
            }
        string conversion= static_cast<ostringstream*>( &(ostringstream() << total) )->str();
        printf("The length of %d! is %d\n", input, conversion.size());
        total = 1;

    }

    return 0;
}

