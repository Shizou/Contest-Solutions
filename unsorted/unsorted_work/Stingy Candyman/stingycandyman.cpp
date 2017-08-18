#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,arr[10];
int mb[10];
vector< pair<int,int> > pos_base[10]; // value, orig base
bool global_found = false;


int ld(int a){// largest digit
    int b = 0;
    while(a!=0){
        b=max(b,a%10);
        a/=10;
    }
    return b;
}
int base_n(int a,int b){
    int ans = 0,pwr = 0;
    while(a!=0){
        ans += (a%10)*(int)pow(b,pwr++);
        a/=10;
    }
    return ans;
}
int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b,a%b);
}
void r(vector< pair<int,int> > used){
    int d = used.size();
    if(global_found)return;
    else if(d==N){
        for(int i = 0; i < N;i++)cout << used[i].second << endl;
        global_found = true;
    }
    if(!global_found){
        for(int i = 0; i < pos_base[d].size()-1 && !global_found;i++){
            bool pos = true;
            for(int j = 0; j < used.size();j++){
                if(gcd( used[j].first, pos_base[d][i].first) != 1){
                    pos = false;
                    break;
                }
            }
            if(pos){
                used.push_back(pos_base[d][i]);
                r(used);
                used.pop_back();
            }
        }
    }

}
int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&N);fill(mb,mb+10,2);
    for(int i = 0; i < N;i++)scanf("%d",&arr[i]);
    for(int i = 0; i < N;i++)mb[i] = max(mb[i],ld(arr[i])+1);
    for(int i = 0;i < N;i++){
        for(int j = mb[i];j <= 10;j++){
            pos_base[i].push_back( make_pair(base_n(arr[i],j),j) );
            //pos_base[i].push_back( make_pair(base_n(arr[i],j),j));
        }
    }
    /*for(int i = 0; i < N;i++){
        for(int j = 0; j < pos_base[i].size();j++){
            printf("(%d %d) ",pos_base[i][j].first,pos_base[i][j].second);
        }
        printf("\n");
    }*/
    vector< pair<int,int> > start;
    r(start);
    return 0;
}
