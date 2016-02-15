#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

string input;
vector< pair<int,string> > words;
vector< pair<int,char> > punc;

int space(int i, string str){
    int cnt = 1;
    i++;
    for(;i < str.size();i++){
        if(str.at(i) == ' ')
           return cnt;

        cnt++;
    }

    return 1;
}
string wu(string str){
    return str.erase(0,1);
}
int main(){
   // freopen("input.txt","r",stdin);
    getline(cin,input);

    int f = 0;
    int c = ' ';
    int s = input.size();

    //punctuation
    for(int i = 0;i < s;i++){
        c = (int)input.at(i);

        if( (c >= 65 && c <= 90) || c == 32)
            continue;
        else{
            for(int j = i;j < s;j++){
                if(input.at(i) == input.at(j)){
                    f++;
                }
            }
            punc.push_back(make_pair(f,input.at(i)));
            for(int j = i+1;j < s;j++){
                if(input.at(i) == input.at(j)){
                    input.erase(j,1);
                }
                 s = input.size();
            }
            input.erase(i,1);
            s--;
            f = 0;
        }

    }
    input.insert(0, " ");

    if(input.at(input.size() == '.'))
        input.insert(input.size(), " ");
    else
        input.insert(input.size()-1, " ");

    // words
    for(int i = 0;i < s;i++){
        string str = input.substr(0, space(0,input));

        for(int j = 0;j < s;j++){
            if(input.at(j) == ' '){
                if(str == input.substr(j, space(j,input))){
                    f++;
                }
            }
        }
        words.push_back(make_pair(f,wu(str)));

        for(int j = 0;j < s;j++){
            if(input.at(j) == ' '){
                if(str == input.substr(j, space(j,input))){
                    input.erase(j,str.size());
                    s = input.size();
                }
            }
        }
        f = 0;
        i = 0;
        s -= str.size();
        if(str == input.substr(0, str.size())){
            input.erase(0,str.size());
            s -= str.size();
        }

    }

    for(int i = 0;i < words.size();i++){
        cout << words.at(i).first << words.at(i).second;
    }

    for(int i = 0;i < punc.size();i++){
        cout << punc.at(i).first << punc.at(i).second;
    }
    cout << endl;

   // fclose(stdin);
    return 0;
}
