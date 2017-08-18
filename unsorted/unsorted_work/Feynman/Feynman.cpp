#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int in = 0;
    int out = 0;
    cin >> in;
    out+=in*in;

    for(int i = 2;i <= in;i++){
            out+= (in*in)/(i*i);

    }

    cout << out;
    //fclose(stdin);
    return 0;
}

