#include <algorithm>
#include <iostream>
#include <stack>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <numeric>

#define needforspeed ios::sync_with_stdio(0);cin.tie(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp4(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define trace1(a) cout << (a) << endl;
#define trace2(a,b) cout << (a)  << " " << (b) << endl;
#define trace3(a,b,c) cout << (a)  << " " << (b) << " " << (c) << endl;
#define trace4(a,b,c,d) cout << (a)  << " " << (b) << " " << (c) <<  " " << (d) << endl;
#define trace5(a,b,c,d,e) cout << (a)  << " " << (b) << " " << (c) <<  " " << (d) <<  " " << (e) << endl;
#define ms(a,b) memset( (a), (b), sizeof(a))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define wi(x) for(int  (i) = (0); (i) < (x);(i)++)
#define wj(x) for(int  (j) = (0); (j) < (x);(j)++)
#define wk(x) for(int  (k) = (0); (k) < (x);(k)++)
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN (int)1e9
#define inf 0x3f3f3f3f
#define db 0
using namespace std;

int N; 

int main() {
    needforspeed;
    cin >> N;
    int cnt = 0;
    stack< pair<int, int> >stack;
    for(int i = 0, it = 1;i < 2*N;i++){
        string str;
        cin >> str;
        if(str == "add"){
            int num;
            cin >> num;
            stack.push(mp(num,num));
        }
        if(str == "remove"){
            pair<int,int>box_range= stack.top();
            //cout << i << " " << it << " " << box_range.first << " " << box_range.second << endl;
            if(box_range.first == it){
                if(box_range.second == it){
                    stack.pop();
                    it++;
                }else{
                    stack.top().first++;
                    it++;
                }

            }else{
                int low = N, hi = 0;
                cnt++;
                //cout << "reording" << endl;
                while(!stack.empty()){
                    pair<int,int>br = stack.top();
                    stack.pop();
                    low = min(low, min(br.first,br.second));
                    hi = max(hi, max(br.first, br.first));
                }
                stack.push(mp(low+1, hi));
                //cout << low+1 << " " << hi << endl;
                it++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
