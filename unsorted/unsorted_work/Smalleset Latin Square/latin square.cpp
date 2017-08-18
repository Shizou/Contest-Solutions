#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<set>
using namespace std;
int T,N;
int arr[9][9];
int max_arr[9][9];
set< string > v;

void print_array(int tmp[9][9]){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            printf("%d ",tmp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void update_max(int arr2[9][9]){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(arr2[i][j] > max_arr[i][j]){
                return;
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            max_arr[i][j] = arr2[i][j];
        }
    }
}
bool done(int tmp[9][9]){
    bool v[9]{0};
    for(int i = 0;i < N;i++){
        memset(v, 0, sizeof v);
        for(int j = 0;j < N;j++)
            v[tmp[i][j]-1] = 1;
        for(int j = 0;j < N;j++)
            if(!v[j])return false;
    }
    return true;
}
string con_array(int tmp[9][9]){
    string con = "";
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            con+=(tmp[i][j]+'0');
        }
    }
    return con;
}
void r(int tmp[9][9]){
   // print_array(tmp);
    string test = con_array(tmp);
    if(v.find(test) == v.end()){
        v.insert(test);
    }
    else{
        return;
    }

    if(done(tmp)){
        update_max(tmp);
       // print_array(tmp);
    }
    else{
        for(int i = 1;i < N;i++){
            for(int j = 1;j < N;j++){
                if(tmp[i][j] > 0)continue;
                for(int k = 1;k <= N;k++){
                    tmp[i][j] = k;
                    r(tmp);
                }
                tmp[i][j] = 0;
               //return;
            }
        }
    }

}
void init_max_array(){
     for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            max_arr[i][j] = 10;

        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&T,&N);
    init_max_array();
    for(int i = 0;i < N;i++)
        arr[0][i] = arr[i][0] = i+1;
    r(arr);
    print_array(max_arr);
}

