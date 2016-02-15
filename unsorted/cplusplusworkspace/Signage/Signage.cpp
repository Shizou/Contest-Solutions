#include <iostream>
#include <string>

using namespace std;
int n;
string wrds[6];
string sgn[5];
void init(){
    wrds[0] = "WELCOME";
    wrds[1] = "TO";
    wrds[2] = "CCC";
    wrds[3] = "GOOD";
    wrds[4] = "LUCK";
    wrds[5] = "TODAY";
}
int next(int j, string s){
    for(;j < s.size();j++){
        if(s[j] != '.')
            return j;
    }
    return 0;
}
int main(){
    int n; cin >> n;
    init();
    bool f = 0;
    int cnt = 0;
    int l = 0;
    for(int i = 0;i < 5;i++){
        f = 0;
        for(int j = 0;j < 6;j++){
            if(wrds[j] != ""){
                if(wrds[j].size() + sgn[i].size() <= n){
                    sgn[i]+= wrds[j] + '.';
                    wrds[j] = "";
                    cnt++;
                }
                if(cnt == 6){
                    l = i+1;
                    break;
                }
            }

        }

        if(cnt == 6){
            l = i+1;
            break;
        }
    }
    for(int i = 0;i < l;i++){
        sgn[i].erase(sgn[i].size()-1,1);
    }
    for(int i = 0;i < l;i++){
        while(sgn[i].size() != n){
            for(int j = 0;j < n;j++){
                if(sgn[i].size() == n)
                    break;
                if(sgn[i][j] == '.'){
                    sgn[i].insert(j,".");
                    j = next(j,sgn[i]);
                }
                if(sgn[i].find(".") == string::npos){
                    sgn[i].insert(sgn[i].size(),".");
                    j++;
                }
            }
        }
    }
    for(int i = 0;i < l;i++)
        cout << sgn[i] << endl;


    return 0;
}
