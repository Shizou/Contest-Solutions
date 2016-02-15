#include <iostream>
#include <string>

using namespace std;

int main(){
    int testcases; cin >> testcases;
    int tCount = 0, sCount = 0;
    string input = "";

        cin.sync();
        cin.clear();

        for(int i = 0;i < testcases;i++){
            getline(cin,input);

                    for(int j = 0;j < input.size();j++){

                        if(input.at(j) == 't' || input.at(j) == 'T')
                            tCount++;
                        else if(input.at(j) == 's' || input.at(j) == 'S')
                            sCount++;

                    }
            input = "";

        }

        if(tCount > sCount)
            cout << "English" << endl;
        else if(sCount > tCount)
            cout << "French" << endl;
        else if(sCount == tCount)
            cout << "French" << endl;


    return 0;
}
