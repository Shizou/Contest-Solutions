#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
using namespace std;


// Dinic's blocking flow algorithm
// Running time:
// * general networks: O(|V|^2 |E|)
// * unit capacity networks: O(E min(V^(2/3), E^(1/2)))
// * bipartite matching networks: O(E sqrt(V))

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  // N = number of vertices
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  // Add an edge to initially empty network. from, to are 0-based
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  // Call this to get the max flow. s, t are 0-based.
  // Note, you can only call this once.
  // To obtain the actual flow values, look at all edges with
  // capacity > 0 (zero capacity edges are residual edges).

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};


pair<int,int>interect_hallway(tuple<int,int,int,int>h1, tuple<int,int,int,int>h2){
    // coords for first hallway
    int x1 = get<0>(h1), y1 = get<1>(h1);
    int x2 = get<3>(h1), y2 = get<3>(h1);
    // coords for second hallway
    int x3 = get<0>(h2), y3 = get<1>(h2);
    int x4 = get<3>(h2), y4 = get<3>(h2);
    // figuring out orientation for hall 1
    bool h1_is_vert = x1==x2;
    bool h1_is_horz = y1==y2;
    // figuring out orientation for hall 2
    bool h2_is_vert = x3==x4;
    bool h2_is_horz = y3==y4;
    pair<int,int>no_intersect = make_pair(-1,-1);
    // Parallel hallways will never overlap.
    if((h1_is_vert && h2_is_vert) || (h1_is_horz && h2_is_horz)) {
        return no_intersect;
    }else{
        if(h1_is_vert && h2_is_horz){
            if(x1 >= x3){

            }

        }
        if(h1_is_horz && h2_is_horz);

    }
}

int N;
vector< tuple<int,int,int,int> >hallways;

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        hallways.push_back(make_tuple(x1, y1,x2,y2));
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            

        }
    }
    return 0;
}
