#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctype.h>
#include<sstream>
using namespace std;
vector< pair<char,int> > a;
string s;
string ss;
int main(){
    freopen("input.txt","r",stdin);
    for(int i = 65;i <= 90;i++){
        a.push_back(make_pair((char)i,0));
    }
    for(int j = 1; j <= 5;j++){
        getline(cin,s);
            for(int i = 0;i < s.size();i++){
                s[i] = tolower(s[i]);
            }
            for(int i = 0;i < s.size();i++){
            if(s[i] == 'a')
                a[0].second++;
            else if(s[i] == 'b')
                a[1].second++;
            else if(s[i] == 'c')
                a[2].second++;
            else if(s[i] == 'd')
                a[3].second++;
            else if(s[i] == 'e')
                a[4].second++;
            else if(s[i] == 'f')
                a[5].second++;
            else if(s[i] == 'g')
                a[6].second++;
            else if(s[i] == 'h')
                a[7].second++;
            else if(s[i] == 'i')
                a[8].second++;
            else if(s[i] == 'j')
                a[9].second++;
            else if(s[i] == 'k')
                a[10].second++;
            else if(s[i] == 'l')
                a[11].second++;
            else if(s[i] == 'm')
                a[12].second++;
            else if(s[i] == 'n')
                a[13].second++;
            else if(s[i] == 'o')
                a[14].second++;
            else if(s[i] == 'p')
                a[15].second++;
            else if(s[i] == 'q')
                a[16].second++;
            else if(s[i] == 'r')
                a[17].second++;
            else if(s[i] == 's')
                a[18].second++;
            else if(s[i] == 't')
                a[19].second++;
            else if(s[i] == 'u')
                a[20].second++;
            else if(s[i] == 'v')
                a[21].second++;
            else if(s[i] == 'w')
                a[22].second++;
            else if(s[i] == 'x')
                a[23].second++;
            else if(s[i] == 'y')
                a[24].second++;
            else if(s[i] == 'z')
                a[25].second++;
        }
        ss = "";
        for(int i = 0;i < 26;i++){
            if(a[i].second != 0){
                ss+= a[i].first;
                ss+= '-';
                ss+= static_cast<ostringstream*>( &(ostringstream() << a[i].second) )->str();
                ss+=':';
            }
        }
        if(ss[ss.size()-1] == ':')
            ss.erase(ss.size()-1,1);
        cout << ss << endl;
        for(int i = 0;i < 26;i++){
            a[i].second = 0;
        }
    }
    fclose(stdin);
    return 0;
}
