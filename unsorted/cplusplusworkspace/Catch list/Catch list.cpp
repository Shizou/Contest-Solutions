#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main(){
    freopen("catch list.txt", "r", stdin);
    //freopen("catch list.txt", "w", stdout);
    vector<string> list;
    string in = "";

    while(in != "end"){
        getline(cin,in);
        if(in != "end")
            list.push_back(in);

    }
    sort(list.begin(),list.end());

    for(int i = 0;i < list.size();i++)
        cout << list.at(i) << endl;


    printf("You only need to catch %d more pokemon!\n", list.size());
    fclose(stdin);
    //fclose(stdout);
    return 0;
}
