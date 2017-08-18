#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctype.h>
using namespace std;

string s,ss;
string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector< pair< char, char > >p(27);
int main(){
    //freopen("input.txt","r",stdin);
    int t = 5;
    while(t--){
        getline(cin,s);getline(cin,ss);
        for(int i = 0;i < s.size();i++)s[i] = toupper(s[i]);
        for(int i = 0;i < ss.size();i++)ss[i] = toupper(ss[i]);
        for(int i = 0;i < s.size();i++){if(s[i] == ' '){s.erase(i,1);i--;}}
        s+=a;
        for(int i = 0;i < s.size();i++){
            if(s[i] < 65 || s[i] > 97){
                s.erase(i,1);
                i--;
                continue;
            }
            for(int j = i+1;j < s.size();j++){
                if(s[i] == s[j]){
                    s.erase(j,1);
                    j--;
                }
            }
        }
        for(int i = 0;i < s.size()-1;i++){
            if(i == 0){
                p[ s[i] - 65] = make_pair(s[s.size()-1] , s[i+1]);
                p[ s[s.size()-1] - 65] = make_pair( s[s.size()-2], s[0]);
            }
            else
                p[s[i]-65] = make_pair( s[i-1],s[i+1]);
        }


        for(int i = 0;i < ss.size()-1;i+=2){
            char one = p[ ss[i] - 65].first;
            char two = p[ ss[i+1] - 65].second;
            ss[i] = two;
            ss[i+1] = one;
        }
        for(int i = 0;i < ss.size();i++)   if(ss[i] == 'X') ss[i] = ' ';
        for(int i = 0;i < ss.size()-1;i++) if(ss[i] == 'K' && ss[i+1] == 'S') ss = ss.substr(0,i) + "X" + ss.substr(i+2,ss.size());

        cout << s << endl;
        cout << ss << endl;
    }
    //fclose(stdin);
    return 0;
}
