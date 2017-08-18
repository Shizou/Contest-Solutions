#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;

string in1,in2;
int b1,b2,b3;

int base_10(string &tmp,int base){
    int ans = 0,pwr = 0;
    for(int i = tmp.size()-1;i >=0;i--){
        ans += (tmp[i]-'0')*(int)pow(base,pwr++);
    }
    return ans;
}
string base_n(int &tmp, int base){
    string ans = "";
    while(tmp != 0){
        ans += ((tmp%base)+'0');
        tmp = (tmp-(tmp%base))/base;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n = 5;
    while(n--){
        cin >> in1 >> b1 >> b3;
        //cout << in2 << b1 << b3 << endl;
        int ans =  base_10(in1,b1);
        cout << base_n(ans,b3) << endl;
    }
}
