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

const int MAXN = (1<<25)+1,inf = 0x3f3f3f3f;
int R,C,T,ID;
int dist[MAXN];

void bfs(){
    queue< pair<int,int> >q;
    q.push(mp(ID,0));
    dist[ID] = 0;
    if(ID == 0)return;
    while(!q.empty())
    {
        int id = q.front().x;
        int d =  q.front().y;
        q.pop();
        for(int r = 0;r < R;r++)
        {
            for(int c = 0;c < C;c++)
            {
                int tid = id;
                tid ^= (1<<(C*r+c)) ;
                if(r-1 >= 0)
                   tid ^= (1<<(C*(r-1)+c));
                if(r+1 < R)
                   tid ^= (1<<(C*(r+1)+c));
                if(c-1 >= 0)
                   tid ^= (1<<(C*r+(c-1)));
                if(c+1 < C)
                  tid ^= (1<<(C*r+(c+1)));
                if(dist[tid] > d+1)
                {
                   dist[tid] = d+1;
                   q.push(mp(tid,d+1));
                   if(tid == 0)break;
                }
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    T = 5;
    while(T--){
        cin >> R >> C;
        ID = 0;
        memset(dist,inf,sizeof(dist));
        for(int r = 0;r < R;r++)
        {
            string s;
            cin >> s;
            for(int c = 0;c < C;c++)
            {
                if(s[c] == '1')
                {
                    ID ^= (1 << (C*r + c));
                }
            }
        }
        bfs();
        if(dist[0] == inf)
           cout << -1 << endl;
        else
           cout << dist[0] << endl;
    }
    return 0;
}
