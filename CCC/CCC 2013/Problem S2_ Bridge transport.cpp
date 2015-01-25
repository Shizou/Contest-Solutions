#include<cstdio>
#include<vector>
#include<fstream>
using namespace std;
int b[4];
int mW,cW;
int n,cnt,cI;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&mW,&n);
    vector<int> c;
    for(int i = 0;i< n;i++){
        scanf("%d",&cI);
        c.push_back(cI);
    }
    for(int i = 0;i < n;i++){
         if(b[0] == 0){
             b[0] = c[i];
         }
         else{
             b[3] = b[2];
             b[2] = b[1];
             b[1] = b[0];
             b[0] = c[i];
         }
         if(b[0]+b[1]+b[2]+b[3] <= mW)
             cnt++;
         else
             break;
     }
    printf("%d\n",cnt);
    return 0;
}
