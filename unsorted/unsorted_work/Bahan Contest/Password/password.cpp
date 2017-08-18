#include <iostream>
#include <cstdio>
#include <cctype>
#include <set>
using namespace std;

int T,p;
string in;

bool one_digit(){
    for(int i = 0; i < in.size();i++)
        if(isdigit(in[i]))return true;
    return false;
}
bool one_latin(){
    for(int i = 0; i < in.size();i++)
        if(isalpha(in[i]))return true;
    return false;
}
bool non_digit_non_latin(){
    for(int i = 0; i < in.size();i++)
        if( !(isalpha(in[i]) || isalpha(in[i])) )return true;
    return false;
}
bool one_small_one_big(){
    int cnt = 0;
    for(int i = 0; i < in.size();i++)
        if( isalpha(in[i]) && islower(in[i])){cnt++;break;}
    for(int i = 0; i < in.size();i++)
        if( isalpha(in[i]) && isupper(in[i])){cnt++;break;}
    return cnt == 2;
}
bool all_unique(){
    set<char>used;
    for(int i = 0; i < in.size();i++){
        if(used.find(in[i]) != used.end())return false;
        else  used.insert(in[i]);
    }
    return true;
}
int main() {
    freopen("input.txt","r",stdin);
    //freopen("24.out","w",stdout);
	cin >> T;
	for(int i = 0; i < T;i++){
	    cin >> in;
        if(one_digit())p++;
        if(one_latin())p++;
        if(non_digit_non_latin())p++;
        if(in.size() >= 6)p++;
        if(in.size() > 10)p++;
        if(one_small_one_big())p++;
        if(all_unique())p++;
        printf("Case #%d:\n%s\n",(i+1), (p < 4) ? "weak": ( (p < 6) ? "normal":"strong" ));
        p = 0;
	}
	return 0;
}
