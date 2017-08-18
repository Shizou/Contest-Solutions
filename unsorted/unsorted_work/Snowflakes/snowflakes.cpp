#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int N;
int in[6];
string c;
set< string> st;
int main(){
    //freopen("B/B.18.dat","r",stdin);
    scanf("%d",&N);
    for(int i = 0;i < N;++i){
        scanf("%d%d%d%d%d%d",&in[0],&in[1],&in[2],&in[3],&in[4],&in[5]);
        sort(in,in+6);
        c = "";
        for(int j = 0;j < 6;++j)c += static_cast<ostringstream*>( &(ostringstream() << in[j]) )->str();
        if(st.find(c) != st.end()){
            printf("Twin snowflakes found.\n");
            return 0;
        }
        else{
            st.insert(c);
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
