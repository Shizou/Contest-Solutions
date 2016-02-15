#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include<utility>

using namespace std;

string input;

int search(int x){
	int cnt = 1;
	for(int i = x+1;i < input.size();i++){
		if(input[i] == ' ')
            return cnt;
        else
            cnt++;

	}
}

int main(){
    freopen("input.txt","r",stdin);

    int occur=0;
    string word = "";
    vector <string> list;
    vector< pair<int,string> > words;
    vector< pair<int,char> > punc;


    int count = 0;
    unsigned int startPos, endPos, j,prev = 0;
    string currentWord;
    char current = (char)0;
    getline(cin, input);

    // punc??
    // bad i < s = input.size() every loop
    for (int i =0 ; i< input.length(); i++){
        count=0;
        if (input[i]<= 64&& input [i]>=33){
            current = input[i];
            for (int j = 0;j < input.length(); j++){
                if (input[j] == current)
                    count++;
            }
            punc.push_back(make_pair(count,input[i]));

        }
        for (int j = 0; j<input.length(); j++){
            if (input[j] == current)
                input.erase(j,1);
        }
    }

    input.insert(0," ");
   input.insert(input.size(), " ");



    int s = input.size();
    count = 0;
    for(int i = 0;i < s;i++){
        count = 0;
        string str = input.substr(0,search(0));

        for(int j = 0;j < s;j++){
                if(input.substr(j,search(0)) == str){
                    count++;
                }
        }
       words.push_back(make_pair(count,str));
       for(int j = 0;j < s;j++){
                if(input.substr(j,search(0)) == str){
                    input.erase(j,search(0));
                    s = input.size();
                    j = 0;
                }
        }


        s -= str.size();

        if(str == input.substr(0, str.size())){
            input.erase(0,str.size());
            s -= str.size();
        }

       cout << input << endl;

    }
    for(int i = 0;i < words.size();i++){
        cout << words.at(i).first << words.at(i).second << endl;
    }



    fclose(stdin);
    return 0;
}

