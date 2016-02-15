/*Optimized BFS ftw since I can't DP*/
#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;
int n;
char c;
string in;
vector<bool> vis(33554431);
struct path{
    string s;
    int d,id;
};
int dec(string s){
    int d = 0,p = 0;
    for(int i = s.size()-1;i >= 0;i--){if(s[i]== '1') d += 1 << p;p++;}
    return d;
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf(" %c",&c);
        in+=c;
    }
    queue< path >q;
    q.push((path){in,0,dec(in)});
    while(!q.empty()){
        string s = q.front().s;
        int d = q.front().d;
        int id = q.front().id;
        q.pop();
        if(vis[id]) continue;
        vis[id] = 1;
        for(int i = 0;i < n;i++){
            if(i+3 < n){
                /*Checks for four consecutive ones.*/
                if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '1' && s[i+3] == '1' ){
                    s[i] = s[i+1] =  s[i+2]=  s[i+3]= '0';
                    /*Subtracts 2^(n-i-1) from the id used to mark the visited array*/
                    id-= (1 << (n-i-1)) + (1 << (n-(i+1)-1)) + (1 << (n-(i+2)-1)) + (1 << (n-(i+3)-1));
                    /*Same process as above except for any consecutive block that's greater than four lights.*/
                    for(int j = i+4; j < n;j++){
                        if(s[j] == '1'){
                            s[j] = '0';
                            id-= (1 << (n-j-1));
                            i++;
                        }
                        else
                            break;
                    }
                    i+=3;// i is incremented to speed the process up.
                }
            }
        }
        if(id == 0){
            printf("%d\n",d);
            return 0;
        }
        for(int i = 0;i < n;i++){
            if(s[i] == '0'){
                s[i] = '1';
                /*Adds 2^(n-i-1) to the current id to create the id new row of lights*/
                int chq = id + (1 << (n-i-1));
                if(!vis[chq]){
                    q.push( (path){s,d+1,chq});
                }
                s[i] = '0';
            }
        }
    }
    return 0;
}
