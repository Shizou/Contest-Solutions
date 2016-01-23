#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;


string toRoman(int x) {

 string H[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};

 string T[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};

 string O[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

 string ret(x / 1000, 'M');

 return ret + H[(x %= 1000) / 100] + T[x / 10 % 10] + O[x % 10];

}
int romanToInt(string s) {
    map<char, int> roman;
    roman['M'] = 1000;
    roman['D'] = 500;
    roman['C'] = 100;
    roman['L'] = 50;
    roman['X'] = 10;
    roman['V'] = 5;
    roman['I'] = 1;

    int ret = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (roman[s[i]] < roman[s[i+1]])
            ret -= roman[s[i]];
        else
            ret += roman[s[i]];
    }
    ret += roman[s[s.size()-1]];
    return ret;
}
int main(){
    //freopen("input.txt","r",stdin);

    int cases = 0;
    string a = "";
    string b = "";
    string input = "";
    int index = 0;

    cin >> cases;
    getline(cin,input);

    while(cases){
        getline(cin,input);
        for(int i = 0;i < input.size();i++){
            if(input[i] == '+'){
                index = i;
                break;
            }
            a += input[i];
        }
        for(int i = index;i < input.size();i++){
            if(input[i] == '='){
                index = i;
                break;
            }
            else
                b += input[i];
        }

        int sum = romanToInt(a) + romanToInt(b);

        if(sum <= 1000)
           cout << input << toRoman(sum) << endl;
        else
           cout << input << "CONCORDIA CUM VERITATE" << endl;

       a = "";
       b = "";
       input = "";
       cases--;
    }
    //fclose(stdin);
    return 0;
}
