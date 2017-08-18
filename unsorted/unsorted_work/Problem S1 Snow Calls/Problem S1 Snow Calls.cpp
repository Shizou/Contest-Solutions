#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeOccurences(string number, int length, char character){
    string newString;

    for(int i = 0;i < length;i++){

        if(number.at(i) != character)
            newString += number.at(i);

    }

    return newString;

}
string addOccurences(string number, int length, char character){
    string newString;

    for(int i = 0;i < length;i++){
        newString += number.at(i);
        if(i == 2 || i == 5)
        newString += '-';
    }

    return newString;
}
string convertLetters(string number, int length){
    string newString;
    for(int i = 0;i < length;i++){

        if(number.at(i) == 'A' || number.at(i) == 'B' || number.at(i) == 'C')
            newString += '2';
        else if(number.at(i) == 'D' || number.at(i) == 'E' || number.at(i) == 'F')
            newString += '3';
        else if(number.at(i) == 'G' || number.at(i) == 'H' || number.at(i) == 'I')
            newString += '4';
        else if(number.at(i) == 'J' || number.at(i) == 'K' || number.at(i) == 'L')
            newString += '5';
        else if(number.at(i) == 'M' || number.at(i) == 'N' || number.at(i) == 'O')
            newString += '6';
        else if(number.at(i) == 'P' || number.at(i) == 'Q' || number.at(i) == 'R' || number.at(i) == 'S')
            newString += '7';
        else if(number.at(i) == 'T' || number.at(i) == 'U' || number.at(i) == 'V')
            newString += '8';
        else if(number.at(i) == 'W' || number.at(i) == 'X' || number.at(i) == 'Y' || number.at(i) == 'Z')
            newString += '9';
        else
            newString += number.at(i);

        }

    return newString;
}
string shorten(string number){
    string newString;
    for(int i = 0;i < 10;i++){
        newString += number.at(i);
    }
    return newString;
}

int main(){
    int testcases;
    string input,inputConversion;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        cin >> input;
        input = removeOccurences(input, input.size(), '-');

        input = convertLetters(input, input.size());
        input = shorten(input);
        input = addOccurences(input, input.size(), '-');
        cout << input << endl;

    }

}
