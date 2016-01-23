#include<iostream>
#include<cstdio>
using namespace std;

int l_b,ans;

int main(){
    string s = "  ";
    while(scanf("%c",&s[1]) && s[1] != '\n'){
        if(s == "((")
            l_b++;
        else if(s == "))")
            ans+=l_b;
        s[0] = s[1];
    }
    printf("%d\n",ans);
}

