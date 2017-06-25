#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>

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

int R, C;
vector<vector<int>> G; 


bool valid_col_move(vector< vector<int> >&grid, int col){
    for(int r = 0;r < R;r++){
        if(grid[r][col] - 1 < 0){
            return false;
        }
    }
    return true;
}

bool valid_row_move(vector< vector<int> >&grid, int row){
    for(int c = 0;c < C;c++){
        if(grid[row][c] - 1 < 0){
            return false;
        }
    }
    return true;
}


bool is_zero_matrix(vector< vector<int> >&grid){
    for(int r = 0;r < R;r++){
        for(int c = 0;c < C;c++){
            if(grid[r][c] != 0){
                return false;
            }
        }
    }
    return true;
}

void print_matrix(vector<vector<int> >&cur_grid){
  for(int r = 0;r < R;r++){
      for(int c = 0;c < C;c++){
          cout << cur_grid[r][c] << " " ;
      }
      cout << endl;
  }
  cout << endl;
}

class my_comp{
    public:
      bool operator()(const vector<vector<int> >&lhs, 
                      const vector<vector<int> >&rhs) const {
          for(int r = 0;r < R;r++){
              for(int c = 0;c < C;c++){
                  if(lhs[r][c] != rhs[r][c]){
                      return lhs[r][c] < rhs[r][c];
                  }
              }
          } 
          return false;
      }
};
                  


int main() {
  needforspeed;
  cin >> R >> C;
  G.resize(R);
  for(int r = 0;r < R;r++){
      G[r].resize(C);
  }
  for(int r = 0;r < R;r++){
      for(int c = 0;c < C;c++){
          int v;
          cin >> v;
          G[r][c] = v;
      }
  }

  vector< pair<char,int> >start;
  set< vector< vector<int> > , my_comp>memo;
  queue< pair< vector< vector<int> >, vector< pair<char, int> > > >q;

  q.push(mp(G, start));
  memo.insert(G);

  while(!q.empty()){
      vector< vector<int> >cur_grid = q.front().first;
      vector< pair<char,int> >cur_start = q.front().second;
      q.pop();
      //print_matrix(cur_grid);
      if(is_zero_matrix(cur_grid)){
          start = cur_start;
          break;
      }
      for(int r = 0;r < R;r++){
          if(valid_row_move(cur_grid, r)){
              vector< vector<int> >new_grid = cur_grid;
              for(int c = 0;c < C;c++){
                  new_grid[r][c]--;
              }
              if(!memo.count(new_grid)){
                  cur_start.pb(mp('r', r+1));
                  q.push(mp(new_grid,cur_start));
                  memo.insert(new_grid);
                  cur_start.pop_back();
              }
          }
      }
      for(int c = 0;c < C;c++){
          if(valid_col_move(cur_grid, c)){
              vector< vector<int> >new_grid = cur_grid;
              for(int r = 0;r < R;r++){
                  new_grid[r][c]--;
              }
              if(!memo.count(cur_grid)){
                  cur_start.pb(mp('c', c+1));
                  q.push(mp(new_grid,cur_start));
                  memo.insert(new_grid);
                  cur_start.pop_back();
              }
          }
      }
  }
  if(len(start) == 0){
      cout << -1 << endl;
  }else {
      cout << len(start) << endl;
      for(int i = len(start)-1;i >= 0;i--){
          cout << (start[i].first == 'r' ? "row ": "col ") << start[i].second << endl;;
      }
  }
  return 0;
}
