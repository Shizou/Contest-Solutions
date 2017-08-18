#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct prsn{
    string nm;
    int ads,dst;
};



int N,in1,in2;
bool occ[100];
vector< prsn > ppl;
vector< string > out;
string in0;


int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> in0 >> in1 >> in2;
        occ[in1-1] = true;
        ppl.push_back((prsn){in0,in1-1,in2-1});
    }
    for(int i = 0; i < ppl.size();i++){
        if(!occ[ppl[i].dst]){
            occ[ppl[i].ads] = false;
            occ[ppl[i].dst] = true;
            out.push_back(ppl[i].nm);
            ppl.erase(ppl.begin()+i);
            i = -1;
            continue;
        }
        if(i == ppl.size()-1){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = 0;i < out.size();i++){
        cout << out[i] << endl;
    }
    return 0;
}
