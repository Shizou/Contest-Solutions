#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define swap(x,y)x^=y^=x^=y
#define x first
#define y second
#define LL long long
using namespace std;

const int MAXN = 501;
int R,C,B;
int arr[MAXN][MAXN];


int query(int r1,int c1,int r2,int c2){
    return arr[r2][c2]-arr[r1-1][c2]-arr[r2][c1-1]+arr[r1-1][c1-1];
}

int main(){
    freopen("input.txt","r",stdin);
    needforspeed;
    cin >> C >> R >> B;
    for(int r = 1;r <= R;r++){
        for(int c = 1; c <= C;c++){
            cin >> arr[r][c];
        }
    }
     for(int r = 1;r <= R;++r){
        for(int c = 1;c <= C;c++)
            arr[r][c]+=arr[r][c-1];
        for(int c = 1;c <= C;c++)
            arr[r][c]+=arr[r-1][c];
    }
    if(db){
       for(int r = 1;r <= R;r++){
           for(int c= 1;c <= C;c++){
               cout << query(r,c,r,c) << " ";
           }cout << endl;
       }cout << endl;
    }
    int best = 0;
    for(int r = 1;r <= R;++r){
        for(int c = 1;c <= C;++c){
            int i = R-1,j = C-1,area = (i+1)*C + (j+1)*R - (i+1)*(j+1);
            while(area >= best && !(i < 0 || j < 0)){
                if(db)cout  << r << " " << c << " " << i <<  " " << j << endl;
                if(r+i > R || c+j > C)
                  swap(i,j);
                if(r+i > R || c+j > C){
                  i--;
                  swap(i,j);
                }
                else{
                  int sum1 = query(r,1,r+i,C);
                  int sum2 = query(1,c,R,c+j);
                  int sum3 = query(r,c,r+i,c+j);
                  if(sum1+sum2-sum3 <= B){
                     best = max(best,(i+1)*C + (j+1)*R - (i+1)*(j+1));
                     break;
                  }else{
                    i--;
                  }
                }
                area = (i+1)*C + (j+1)*R - (i+1)*(j+1);
            }
            cout << endl;
        }
    }
    cout << best << endl;
    return 0;
}