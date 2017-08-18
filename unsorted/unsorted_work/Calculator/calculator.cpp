#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int T,B1,B2,B3;
string N1,N2,operand, buffer;

int base_10(string &tmp,int &base){
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
    cin >> T;
    while(T--){
        cin >> B1 >> N1 >> B2 >> N2 >> operand >> B3;
        int num = base_10(N1,B1);
        int num2 = base_10(N2,B2);
        if(operand == "+")num+=num2;
        else if(operand == "-")num-=num2;
        else if(operand == "*")num*=num2;
        else if(operand == "/")num/=num2;
        cout << base_n(num,B3) << endl;
    }
}
