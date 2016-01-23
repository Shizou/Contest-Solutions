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

const int MAXN = 1000;
int N;
int arr[MAXN][MAXN];

int main(){
    //freopen("A-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0,x1,y1,x2,y2;i < N;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int r = x1;r <= x2;r++)
            for(int c = y1;c <= y2;c++)
                arr[r][c]++;
    }
    int ans = 0;
    for(int i = 1;i <= 100;i++)
        for(int j = 1;j <= 100;j++)
            ans+=arr[i][j];
    cout << ans << endl;
    return 0;
}