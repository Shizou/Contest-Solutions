#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#define max(a,b) a > b ? a:b
using namespace std;

int N,v,max_f;
vector<int>in;
vector<int>rng;

bool find(int nm){
    for(int i = 0; i < in.size();i++)
        if(in[i] == nm)return true;
    return false;
}

void del_occr(int nm, vector<int>&vec){
    for(int i = 0; i < vec.size();i++){
        if(vec[i] == nm){
            vec.erase(vec.begin()+i);
            i--;
        }
    }
}

void chk_flow(int nm, vector<int>vec){
    del_occr(nm,vec);
    int cnt = 1;
    for(int i = 0;i < vec.size();i++){
        if(i+1 < vec.size() && vec[i] == vec[i+1])cnt++;
        else{
            max_f = max(max_f,cnt);
            cnt = 1;
        }
    }
}


int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&v);
        if(!find(v))
            rng.push_back(v);
        in.push_back(v);
    }
    for(int i = 0; i < rng.size();i++)
        chk_flow(rng[i],in);

    printf("%d\n",max_f);
}

