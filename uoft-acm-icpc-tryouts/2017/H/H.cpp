#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#define needforspeed ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp4(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define trace1(a) cout << (#a) << ":" << (a);
#define trace2(a,b) trace1(a); cout << " "; trace1(b); cout << endl; 
#define trace3(a,b,c) trace1(a); cout << " "; trace1(b); cout << " "; trace1(c); cout << endl;  
#define trace4(a,b,c,d) trace1(a); cout << " "; trace1(b); cout << " "; trace1(c); cout << " "; trace1(d); cout << endl;  
#define ms(a,b) memset( (a), (b), sizeof(a))
#define Fill(a,b) fill((a), (a)+sizeof(a)/sizeof((a)[0]), (b));
#define Fill2D(a,b) fill(&(a)[0][0], &(a)[0][0]+sizeof(a)/sizeof((a)[0][0]), (b))
#define Fill3D(a,b) fill(&(a)[0][0][0],&(a)[0][0][0]+sizeof(a)/sizeof((a)[0][0][0]), (b))
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN (int)1e9
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define db 0
using namespace std;

int string_to_int(string s);
string int_to_string(int i);
vector<string>split(string s, char delim);
template< class T>
void print_vec(vector<T>vec, bool new_line=false);

int T, R;


int dist(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

double dist2(int x1, int y1, int x2, int y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
    needforspeed;
    while(cin >> T && T!= 0){
        cin >> R;
        vector< pair<int, pair<int,int> > >towers;
        vector< pair<int,int> >roads;
        for(int i = 0;i < T;i++){
            int x,y,p;
            cin >> x >> y >> p;
            towers.pb(mp3(x,y,p));
        }
        for(int i = 0;i < R+1;i++){
            int x,y;
            cin >> x >> y;
            roads.pb(mp(x,y));
        }
        vector< pair<int,int> >out;
        for(int i = 0;i+1 < R+1;i++){
            pair<int,int>cp = roads[i];
            pair<int,int>np= roads[i+1];
            double scale = 0.5/dist(roads[i].xx, roads[i].yy, roads[i+1].xx, roads[i+1].yy);
            pair<int,int> v = mp(roads[i].xx-roads[i+1].xx, roads[i].yy-roads[i+1].yy);
            for(int j = 1;;j++){
                double cscale = scale*j;
                pair<double,double> cv = mp(v[i].xx*cscale, v[i].yy*cscale);
                pair<double,double> point = 

            }

        }
        // for(int i = 0;i < R+1;i++){
        //     int bsignal = -inf;
        //     int it = 0;
        //     for(int j = 0;j < T;j++){
        //         int cdist = dist(roads[i].first, roads[i].second, 
        //                          towers[j].first, towers[j].second.first);
        //         int csignal = round((double)towers[j].second.second/cdist);
        //         if(bsignal < csignal){
        //             bsignal = csignal;
        //             it = j;
        //         }
        //     }
        //     char t = 'A'+it;
        //     pair<int,char> btower = mp(i, t); 
        //     if(out.empty() || out[len(out)-1].second != btower.second){
        //         out.pb(btower);
        //     }
        // }
        for(int j = 0;j < len(out);j++){
            cout << "("  << out[j].first << "," << out[j].second << ") ";
        }
        cout << endl;
        break;
    }
}

template< class T>
void print_vec(vector<T>vec, bool new_line){
    for(int i = 0;i < len(vec);i++){
        cout << vec[i] << ((new_line) ? '\n' : ' ');
    }
    cout << endl;
}

int string_to_int(string s){
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
}

string int_to_string(int i){
    string ret;
    stringstream ss;
    ss << i;
    ss >> ret;
    return ret;
}

vector<string>split(string s, char delim){
    stringstream ss(s);
    vector<string>ret;
    string temp;
    while(getline(ss, temp, delim)){
        ret.push_back(temp);
    }
    return ret;
}
