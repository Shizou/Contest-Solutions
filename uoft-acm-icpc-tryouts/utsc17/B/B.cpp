#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstring>
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
#define inf 2500000005LL
#define db 1
using namespace std;

int string_to_int(string s);
string int_to_string(int i);
vector<string>split(string s, char delim);
template< class T>
void print_vec(vector<T>vec, bool new_line=false);

int n,m,f,s,t;
long long dist[50005][2]; // distance, tickets used 0 or 1

vector< pair<int, pair<int,int> > >adj[50005]; // dest city, cost, special or not

int dijkstra(){
    #define NO_TICKET 0
    #define TICKET 1
    priority_queue< pair<int, pair<int,int> > >pq; // current cost, tickets left, node
    pq.push(mp3(-0, -1, s));
    Fill2D(dist, inf);
    dist[s][0] = dist[s][1]  = 0;

    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_tickets = -pq.top().second.first;
        int cur_node = pq.top().second.second;
        pq.pop();
        for(int i = 0;i < len(adj[cur_node]);i++){
            pair<int, pair<int,int> >edge = adj[cur_node][i];
            int next_node = edge.first;
            int weight = edge.second.first;
            bool special = edge.second.second == 1;
            // special ticket and we still have 1 ticket left, so we try to 
            // to use it now
            if(special && cur_tickets == 1 && dist[next_node][cur_tickets-1] > cur_cost + weight){
                dist[next_node][cur_tickets-1] = cur_cost + weight;
                pq.push(mp3(-dist[next_node][cur_tickets-1], -(cur_tickets-1), next_node));
            }
            // could be executed on a special edge but this is the general case for non-special nodes 
            if(dist[next_node][cur_tickets] > cur_cost + weight){
                dist[next_node][cur_tickets] = cur_cost + weight;
                pq.push(mp3(-dist[next_node][cur_tickets], -cur_tickets, next_node));
            }
        }
    }
    #undef NO_TICKET
    #undef TICKET
    return min(dist[t][0], dist[t][1]);
}

int main() {
    needforspeed;
    cin >> n >> m >> f >> s >> t;
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb(mp3(b,c,0));
        adj[b].pb(mp3(a,c,0));
    }
    for(int i = 0;i < f;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(mp3(b,0,1));
    }
    cout << dijkstra() << endl;
    return 0;
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
