#include<bits/stdc++.h>
using namespace std;

int N,M;
int adj[55][55];
bool v[55][55];

int dfs(int r, int c)
{
    int ret = 1;
    v[r][c] = true;
    if((adj[r][c]&(1<<3)) == 0 && r+1 <= M && !v[r+1][c])// south
        ret += dfs(r+1, c);
    if((adj[r][c]&(1<<2)) == 0 && c+1 <= N && !v[r][c+1])// east 
        ret += dfs(r, c+1);
    if((adj[r][c]&(1<<1)) == 0 && r-1 >= 1 && !v[r-1][c])// north 
        ret += dfs(r-1, c);
    if((adj[r][c]&(1<<0)) == 0 && c-1 >= 1 && !v[r][c-1])// north 
        ret += dfs(r, c-1);
    return ret;
}

int main()
{
    freopen("input.txt","r",stdin);
    cin >> N >> M;
    for(int i = 1;i <= M;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            cin >> adj[i][j]; 
        }
    }
    // count all the rooms, and find biggest one
    int rooms = 0;
    int room_size = 0;
    memset(v, false, sizeof(v));
    for(int i = 1;i <= M;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            if(!v[i][j])
            {
                room_size = max(room_size, dfs(i, j));
                rooms++;
            }
        }
    }
    cout << rooms << endl;
    cout << room_size << endl;
    // find size of the largest room creatable by removing a wall
    int room_size_rm = 0;
    int R,C,D;
    for(int i = 1;i <= M;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            //try north wall
            memset(v, false, sizeof(v));
            if((adj[i][j]&(1<<1)) != 0)
            {
                adj[i][j] ^= (1<<1);
                int cur_room_size = dfs(i, j);
                if(cur_room_size > room_size_rm)
                {
                    room_size_rm = cur_room_size;
                    R = i;
                    C = j;
                    D = (1<<1);
                }
                else if(cur_room_size == room_size_rm)
                {
                    if(j < C)// farthest to the west
                    {
                       R = i;
                       C = j;
                       D = (1<<1); 
                    }
                    else if(j == C)
                    {
                        if(i > R)// farthest to the south
                        {
                            R = i;
                            C = j;
                            D = (1<<1);
                        }
                        else if(i == R)
                        {
                            if(D == (1<<2))
                            {
                                R = i;
                                C = j;
                                D = (1<<1);
                            }
                        }
                    }
                }
                adj[i][j] ^= (1<<1);
            }
            //try east wall
            memset(v, false, sizeof(v));
            if((adj[i][j]&(1<<2)) != 0)
            {
                adj[i][j] ^= (1<<2);
                int cur_room_size = dfs(i, j);
                if(cur_room_size > room_size_rm)
                {
                    room_size_rm = cur_room_size;
                    R = i;
                    C = j;
                    D = (1<<2);
                }
                else if(cur_room_size == room_size_rm)
                {
                    if(j < C)// farthest to the west
                    {
                       R = i;
                       C = j;
                       D = (1<<2); 
                    }
                    else if(j == C)
                    {
                        if(i > R)// farthest to the south
                        {
                            R = i;
                            C = j;
                            D = (1<<2);
                        }
                    }
                }
                adj[i][j] ^= (1<<2);
            }
        }
    }
    char dir = (D == 2) ? 'N':'E';
    cout << room_size_rm << endl;
    cout << R << " " << C << " " << dir;
    return 0;
}
