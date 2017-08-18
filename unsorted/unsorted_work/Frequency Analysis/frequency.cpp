#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int size = 0; cin >> size;
    int e = 0,t = 0,a = 0,o = 0, z= 0, q = 0, x = 0;

    string in[size];
    getline(cin,in[0]);

    for(int i = 0;i < size;i++){
        getline(cin,in[i]);
        for(int j = 0;j < in[i].size();j++){
            if(in[i].at(j) == 'E')
                e++;
            else if(in[i].at(j) == 'T')
                t++;
            else if(in[i].at(j) == 'A')
                a++;
            else if(in[i].at(j) == 'O')
                o++;
            else if(in[i].at(j) == 'Z')
                z++;
            else if(in[i].at(j) == 'Q')
                q++;
            else if(in[i].at(j) == 'X')
                x++;
        }
    }
    bool eng = true;

    if(z > e || z > t || z > a || z > o)
        eng = false;
    if(q > e || q > t || q > a || q > o)
        eng = false;
    if(x > e || x > t || x > a || x > o)
        eng = false;

    if(eng)
        cout << "english" << endl;
    else
        cout << "not" << endl;

    //fclose(stdin);
    return 0;
}

