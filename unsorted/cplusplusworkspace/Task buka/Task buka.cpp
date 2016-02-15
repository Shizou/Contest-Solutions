#include <iostream>
#include <string>

using namespace std;

string multiplication(string a, string b){
    int occurences = 0;

    if(a.size() > b.size()){

        for(int i = a.size()-1;i > -1;i--){
            if(a.at(i) == '0')
                occurences++;
        }
        for(int i = 1;i <= occurences;i++){
            b += "0";
        }

        return b;
    }
    else{

        for(int i = b.size()-1;i > -1;i--){
            if(b.at(i) == '0')
                occurences++;
        }
        for(int i = 1;i <= occurences;i++){
            a += "0";
        }

        return a;
    }


}
string addition(string a, string b){
     if(a.size() < b.size()){
        string temp = a;
        a = b;
        b = temp;
     }
    int position = a.size()-1;


        for(int i = b.size()-1;i > -1;i--){
            if(a.at(position) == '1' && b.at(i) == '1')
                a.at(position) = '2';
            else if(a.at(position) == '0' && b.at(i) == '1')
                a.at(position) = '1';

            position--;
        }
        return a;


}

int main(){
    string a, operand, b;
    cin >> a >> operand >> b;

    if(operand == "*"){
        a = multiplication(a,b);
        cout << a << endl;
    }
    else{
        a = addition(a,b);
        cout << a << endl;
    }

    return 0;
}

