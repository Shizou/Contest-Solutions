#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

int a,b,qq;
string A,B;

int OK = 0;
int c = 0;

void rec(int cq){
    if(cq == 0){
      if(b+c == a)
         OK++;
    }else{
      c++;
      rec(cq-1);
      c--;

      c--;
      rec(cq-1);
      c++;
    }
}

int main(){
    //freopen("B-input.txt","r",stdin);
    cin >> A >> B;
    for(int i = 0;i < (int)A.size();i++){
        a+=  (A[i] == '+') ? 1: ( (A[i] == '-') ?  -1:0);
    }
    for(int i = 0;i < (int)B.size();i++){
        b+=  (B[i] == '+') ? 1:( (B[i] == '-') ?  -1:0);
        if(B[i] == '?')qq++;
    }
    if(qq != 0){
      rec(qq);
      printf("%.12f\n", OK/pow(2,qq) );
    }else{
      if(a==b)
        printf("%.12f\n", 1.0);
      else
        printf("%.12f\n", 0.0);
    }
    return 0;
}