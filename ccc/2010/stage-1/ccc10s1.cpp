#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

int N;
int R,S,D;
string nm;
vector< pair< pair<string,int>, pair<int,int> > >arr;

bool compare(pair< pair<string,int>, pair<int,int> >lft, pair< pair<string,int>, pair<int,int> > rht){
     int s1 = 2*lft.x.y+3*lft.y.x+lft.y.y;
     int s2 = 2*rht.x.y+3*rht.y.x+rht.y.y;
     if(s1 == s2)
        return lft.x.x < rht.x.x;
     else
       return s1 > s2;
}

int main(){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> nm >> R >> S >> D;
        arr.pb(mp(mp(nm,R),mp(S,D)));
    }
    sort(all(arr),compare);
    if( (int)arr.size() >= 2)
        cout << arr[0].x.x << endl << arr[1].x.x << endl;
    if( (int)arr.size() == 1)
        cout << arr[0].x.x;
    return 0;
}
