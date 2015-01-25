#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int testcases; cin >> testcases;
    int sizeOne = 0, sizeTwo = 0, sizeThree = 0;
    string l;
    for(int i = 0;i < testcases;i++){

         cin >> sizeOne >> sizeTwo >> sizeThree;

         getline(cin,l);

         string subject[sizeOne];
         string verbs[sizeTwo];
         string object[sizeThree];

        for(int j = 0;j <sizeOne; j++){
            getline(cin,subject[j]);
        }
        for(int j = 0;j < sizeTwo; j++){
            getline(cin,verbs[j]);
        }
        for(int j = 0;j < sizeThree; j++){
            getline(cin,object[j]);
        }


        for(int j = 0; j < sizeOne; j++)
        {
            for(int k = 0; k < sizeTwo; k++)
            {
                for(int p = 0; p < sizeThree; p++)
                {
                    cout << subject[j] << " "  <<  verbs[k] + " " << object[p] << "." << endl;
                }
            }
        }
         cout << endl;
    }

}

