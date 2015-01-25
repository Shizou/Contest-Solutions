#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

string base_2,base_3;
set<int> nums;

int to_dec(int base,string&in){
    int base_10 = 0;
    for(int i = in.size()-1;i >= 0;i--)
        base_10 += (in[i]-'0') * pow(base,in.size()-1-i);
    return base_10;
}

int main(){
    //freopen("input.txt","r",stdin);
    getline(cin,base_2);
    getline(cin,base_3);
    int con1 = to_dec(2,base_2), con2 = to_dec(3,base_3);

    for(int i = 0; i < base_2.size();i++){
        if(base_2[i] == '1'){
            con1 -= 1 << (2,base_2.size()-1-i);
            nums.insert(con1);
            con1 += 1 << (2,base_2.size()-1-i);
        }
        else{
            con1 += 1 << (2,base_2.size()-1-i);
            nums.insert(con1);
            con1 -= 1 << (2,base_2.size()-1-i);
        }
    }
    for(int i = 0;i < base_3.size();i++){
        if(base_3[i] == '2'){
            con2 -= pow(3,base_3.size()-1-i);
            if(nums.find(con2) != nums.end()){
                cout << con2 << endl;
                break;
            }
            con2 += pow(3,base_3.size()-1-i);

            con2 -= 2*pow(3,base_3.size()-1-i);
            if(nums.find(con2) != nums.end()){
                cout << con2 << endl;
                break;
            }
            con2 += 2*pow(3,base_3.size()-1-i);
        }
        else if(base_3[i] == '1'){
            con2 -= pow(3,base_3.size()-1-i);
            if(nums.find(con2) != nums.end()){
                cout << con2 << endl;
                break;
            }
            con2 += pow(3,base_3.size()-1-i);

            con2 += pow(3,base_3.size()-1-i);
            if(nums.find(con2) != nums.end()){
                cout << con2 << endl;
                break;
            }
            con2 -= pow(3,base_3.size()-1-i);
        }
        else{
            con2 += pow(3,base_3.size()-1-i);
            if(nums.find(con2) != nums.end()){
                cout << con2 << endl;
                break;
            }
            con2 -= pow(3,base_3.size()-1-i);

            con2 += 2*pow(3,base_3.size()-1-i);
            if(nums.find(con2) != nums.end()){
                cout << con2 << endl;
                break;
            }
            con2 -= 2*pow(3,base_3.size()-1-i);
        }
    }
    return 0;
}

