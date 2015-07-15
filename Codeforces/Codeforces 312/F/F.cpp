#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define nullptr 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

int N,E;
int arr[1001];
int cnt[4];
vector< pair<int,int> >swap;

int main(){
    freopen("F-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    return 0;
}

