#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
using namespace std;
string convert(string input){
    string conversion = "";

    for(int i = 0;i < input.size();i++){
        conversion += tolower(input[i]);
    }



    return conversion;
}
int main(){
    //freopen("input.txt","r",stdin);
    int testcases;
    string l;
    cin >> testcases;
    getline(cin,l);

    for(int j = 0;j < testcases;j++){
        string lines[4];

        for(int i = 0;i < 4;i++){
            getline(cin,lines[i]);
        }

        int pos = lines[0].find_last_of(" ")+1 , pos2 = lines[1].find_last_of(" ")+1;
        int pos3 = lines[2].find_last_of(" ")+1, pos4 = lines[3].find_last_of(" ")+1;
        string one,two,three,four;

        lines[0] = convert(lines[0]);
        lines[1] = convert(lines[1]);
        lines[2] = convert(lines[2]);
        lines[3] = convert(lines[3]);

        for(int i = pos;i < lines[0].size();i++){
                if(lines[0].at(i) == 'a' || lines[0].at(i) == 'e' || lines[0].at(i) == 'i' || lines[0].at(i) == 'o' || lines[0].at(i) == 'u'){
                    one = lines[0].substr(i,lines[0].size());
                }
        }
        for(int i = pos2;i < lines[1].size();i++){
                if(lines[1].at(i) == 'a' || lines[1].at(i) == 'e' || lines[1].at(i) == 'i' || lines[1].at(i) == 'o' || lines[1].at(i) == 'u'){
                    two = lines[1].substr(i,lines[1].size());
                }
        }
        for(int i = pos3;i < lines[2].size();i++){
                if(lines[2].at(i) == 'a' || lines[2].at(i) == 'e' || lines[2].at(i) == 'i' || lines[2].at(i) == 'o' || lines[2].at(i) == 'u'){
                    three = lines[2].substr(i,lines[2].size());
                }
        }
        for(int i = pos4;i < lines[3].size();i++){
                if(lines[3].at(i) == 'a' || lines[3].at(i) == 'e' || lines[3].at(i) == 'i' || lines[3].at(i) == 'o' || lines[3].at(i) == 'u'){
                    four = lines[3].substr(i,lines[3].size());
                }
        }


        if(one == two && one == three && one == four)
            cout << "perfect" << endl;
        else if(one == two && three == four)
            cout << "even" << endl;
        else if(one == three && two == four)
            cout << "cross" << endl;
        else if(one == four && two == three)
            cout << "shell" << endl;
        else
            cout << "free" << endl;

    }
    //fclose(stdin);
    return 0;
}
