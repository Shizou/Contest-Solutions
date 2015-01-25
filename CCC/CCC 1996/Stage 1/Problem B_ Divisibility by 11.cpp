#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;
int n;
string s,ss;
int main(){
    //freopen("input.txt","r",stdin);
    cin >> n;
    getline(cin,s);
    while(n--){
        getline(cin,s); ss = s;
        cout << s << endl;
        for(int i = s.size()-1;i >= 0;i--){
            if(s[i] == '0') {s.erase(i,1); cout << s << endl;}
            else break;
        }
        vector<int>val(s.size());
        for(int i = 0;i < s.size();i++)val[i] = s[i]-'0';

        for(int i = s.size()-1; s.size() > 2;i--){
            int a = val[i-1], b = val[i];
            if(a >= b){
                val[i-1]-=val[i];
                a-=b;
                s[i-1] = '0' + a;
                s.erase(i,1);
                val.pop_back();
                cout << s << endl;
            }
            else if(b > a){
                    while(val[i-1] -  val[i] < 0){
                        for(int j = i-2;j >= 0;j--){
                            if(val[j] > 0){
                                    val[j]--;
                                    val[j+1]+=10;
                                    break;
                            }
                        }
                    }
                    val[i-1]-= val[i];
                    val.pop_back();
                    s.erase(i,1);
                    for(int j = 0;j < s.size();j++)
                        s[j] = '0' + val[j];
                    while(s[0] == '0'){
                        s.erase(0,1);
                        val.erase(val.begin()+1);
                    }
                    cout << s << endl;
            }
            i = s.size();
        }
        int f = atoi(s.c_str()) % 11;

        if(f == 0)cout << "The number " + ss + " is divisible by 11." << endl;
        else      cout << "The number " + ss + " is not divisible by 11." << endl;
        cout << endl;
    }
    //fclose(stdin);
    return 0;
}


