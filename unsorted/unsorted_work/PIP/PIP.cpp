#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string in;



int main(){
    freopen("input.txt","r",stdin);
    getline(cin,in);
    int s = in.size();

    for(int i = 0;i < s;i++){

        if(in.at(i) == '('){
        }
        else if(in.at(i) == ')'){

        }
        else if(in.at(i) == '+'){
            in.erase(i,1);
            in.insert(i-1,"+");
        }
        else if(in.at(i) == '-'){
            in.erase(i,1);
            in.insert(i-1,"-");
        }
        else if(in.at(i) == '*'){
            in.erase(i,1);
            in.insert(i-1,"*");
        }

    }
    cout << in << endl;
    fclose(stdin);
    return 0;
}
