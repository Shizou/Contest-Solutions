#include<iostream>
#include<sstream>
using namespace std;

stringstream ss;
string xc,yc;
long long x,y,cnt;

int main(){
    stringstream ss;
    cin >> x >> y;
    ss << x;
    ss >> xc;
    ss.clear();
    ss << y;
    ss >> yc;
    ss.clear();
    for(int a = 0;a <= 9;a++){
        for(int b = 0;b <= 9;b++){
            if(a == b)continue;
            for(int len = xc.size(); len <= yc.size();len++){
                string str = "";
                int m = len;
                while(m--)str+= a+'0';
                for(int p = 0;p < len;p++){
                    str[p] = b+'0';
                    ss << str;
                    long long cur = 0;
                    ss >> cur;
                    ss.clear();
                    if(cur >= x && cur <= y && str[0] != '0') cnt++;
                    str[p] = a+'0';
                }
            }
        }
    }
    cout <<  cnt << endl;
    return 0;
}

