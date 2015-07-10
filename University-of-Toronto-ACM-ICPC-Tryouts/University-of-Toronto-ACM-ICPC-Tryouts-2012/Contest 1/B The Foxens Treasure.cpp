#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

const int A = 0, S = 1,MAXT = (int)1e5;
int T,N;
vector< pair<int,pair<int,int> > >foxen;// o,a,s

int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0,a,s,o;i < N;i++){
            cin >> a >> s >> o;
            o%= (a+s);
            foxen.pb(mp( ((o < a) ? o:-(s-(o-a) ) ) ,mp(a,s)));
        }
        bool OK = true;
        for(int i = 0;i < N;i++)
            if(foxen[i].x >= 0)
                OK = false;
        if(OK){
           cout << 0 << endl;
           goto end;
        }
        for(int t = 1;t <= MAXT;t++){
            for(int i = 0;i < N;i++){
                foxen[i].x++;
                if(foxen[i].x == foxen[i].y.x)
                   foxen[i].x = -foxen[i].y.y;
            }
            bool OK = true;
            for(int i = 0;i < N;i++)
                if(foxen[i].x >= 0)
                   OK = false;
            if(OK){
              cout << t << endl;
              goto end;
            }
        }
        cout << "Foxen are too powerful" << endl;
        end:foxen.clear();
    }
    return 0;
}
