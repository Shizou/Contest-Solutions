#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int X;

vector<int> base_n(int x, int b){
    vector<int>con;
    while(x!=0){
        con.push_back(x%b);
        x/=b;
    }
    reverse(con.begin(),con.end());
    return con;
}
bool palindrome(vector<int>s){
    vector<int>s2 = s;
    reverse(s2.begin(),s2.end());
    for(int i = 0; i < s2.size();i++)if(s2[i]!=s[i])return false;
    return true;
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&X);
    for(int i = 2; i < X;i++){
        if(palindrome(base_n(X,i)))printf("%d\n",i);
    }
    return 0;
}
