#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int N,M,Q,A,B;
int arr[1000];

int main(){
    //freopen("input.txt","r",stdin);
    for(int t = 1;cin >> N;t++){
      for(int i = 0;i < N;i++)
          cin >> arr[i];
      cin >> M;
      cout << "Case " << t << ":" << endl;
      for(int i = 0;i < M;i++){
          cin >> Q;
          A = inf,B = inf;
          for(int a = 0;a < N;a++)
            for(int b = 0;b < N;b++)
                if(arr[a]!=arr[b] && abs(arr[a]+arr[b]-Q) < B)
                   A = arr[a]+arr[b],B = abs(arr[a]+arr[b]-Q);
          cout << "Closest sum to " << Q << " is " << A << "." << endl;
      }
    }
    return 0;
}