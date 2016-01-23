#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 20000
using namespace std;

int N,C,cnt;
vector<int>arr(MAXN),chord,out;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&C);
    for(int i = 0,c; i < C;i++){
        scanf("%d",&c);
        chord.push_back(c);
    }
    sort(chord.begin(),chord.end());
    for(int i = 1; i < chord.size();i++){
        chord[i]-=chord[0];
    }
    chord[0]=0;
    vector<int>cur;
    for(int i = 0; i < N;i++){
        cur.push_back(arr[i]);
        if(i >= C)
            cur.erase(cur.begin());
        if(cur.size() == C){
            vector<int>t = cur;
            sort(t.begin(),t.end());
            for(int j = 1; j < t.size();j++)
                t[j]-=t[0];
            t[0]=0;
            bool pos = true;
            for(int j = 0; j < t.size();j++){
                if(t[j]!=chord[j]){
                    pos = false;
                    break;
                }
            }
            if(pos){
                cnt++;
                out.push_back(i-C+2);
            }
        }
    }
    printf("%d\n",cnt);
    for(int i = 0; i < out.size();i++)
        printf("%d\n",out[i]);

    return 0;
}
