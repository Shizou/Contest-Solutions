#include <iostream>

using namespace std;

int main(){

    double AB = 0, BC = 0, AC = 0;
    double DE = 0, EF = 0, DF = 0;

    cin >> AB >> BC >> AC >> DE >> EF >> DF;

    if(AB == DE){
        cout << "D";
    }
    else if(AB == EF){
        cout << "E";
    }
    else if(AB == DF ){
        cout << "F";
    }

    if(BC == DE){
        cout << "D";
    }
    else if(BC == EF){
        cout << "E";
    }
    else if(BC == DF ){
        cout << "F";
    }

    if(AC == DE){
        cout << "D";
    }
    else if(AC == EF){
        cout << "E";
    }
    else if(AC == DF ){
        cout << "F";
    }


    return 0;
}
