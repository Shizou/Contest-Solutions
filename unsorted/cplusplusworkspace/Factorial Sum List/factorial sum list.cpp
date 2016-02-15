#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


vector<int> list;
int factorial[9];

void defaultFactorials(){
    factorial[0] = 1;
    factorial[1] = 1;
    factorial[2] = 2;
    factorial[3] = 3*2;
    factorial[4] = 4*3*2;
    factorial[5] = 5*4*3*2;
    factorial[6] = 6*5*4*3*2;
    factorial[7] = 7*6*5*4*3*2;
    factorial[8] = 8*7*6*5*4*3*2;
    factorial[9] = 9*8*7*6*5*4*3*2;
}
bool search(int val){
    for(int i = 0;i < list.size();i++){
        if(val == list.at(i))
            return false;
    }
    return true;
}

int main(){
    freopen("input.txt","r",stdin);
    defaultFactorials();

    string input = "25";
    int total = 0;

    //scanf("%s",&input);

    while(true){
        total = 0;
        for(int i = 0;i < input.size();i++){

            if(input.at(i) == '0')
                total += factorial[0];
            else if(input.at(i) == '1')
                total += factorial[1];
            else if(input.at(i) == '2')
                total += factorial[2];
            else if(input.at(i) == '3')
                total += factorial[3];
            else if(input.at(i) == '4')
                total += factorial[4];
            else if(input.at(i) == '5')
                total += factorial[5];
            else if(input.at(i) == '6')
                total += factorial[6];
            else if(input.at(i) == '7')
                total += factorial[7];
            else if(input.at(i) == '8')
                total += factorial[8];
            else if(input.at(i) == '9')
                total += factorial[9];



        }
        input = static_cast<ostringstream*>( &(ostringstream() << total) )->str();
        cout << total << endl;
        list.push_back(total);

        if(search(total))
            break;


    }


    printf("%d\n", list.size());
    fclose(stdin);
    return 0;
}
