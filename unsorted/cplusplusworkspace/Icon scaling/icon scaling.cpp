#include <iostream>
#include <string>

using namespace std;

int main(){
    int scale,temp;
    cin >> scale;

     temp = scale;
     string lineOne = "*x*";
     string lineTwo = " xx";
     string lineThree = "* *";
    for(int k = 0;k < scale;k++){
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < scale;j++){
                cout << lineOne.at(i);
            }


        }
        cout << endl;
    }


    for(int k = 0;k < scale;k++){
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < scale;j++){
                cout << lineTwo.at(i);
            }


        }
        cout << endl;
    }

    for(int k = 0;k < scale;k++){
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < scale;j++){
                cout << lineThree.at(i);
            }


        }
        cout << endl;
    }



    return 0;
}
