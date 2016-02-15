#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define Fill2D(a,b) fill(&(a)[0][0], &(a)[0][0]+sizeof(a)/sizeof((a)[0][0]), (b))

using namespace std;

int R,C,min_spot = 1<<23;
vector< pair<int,int> >pos_loc[3];
char g[50][50];
bool v[50][50];

void print_grid(){
    for(int r = 0; r < R;r++){
        for(int c = 0; c < C;c++){
            printf("%c",g[r][c]);
        }
        printf("\n");
    }
}
void flood(int r, int c,int i,char id){
    if(r<0||c<0||r>R-1||c>C-1||v[r][c])return;
    if(g[r][c] == '.'){
        // disregard putting locations that are out of the exerior of anything but the first spot, I was too lazy to readjust my code
        pos_loc[i].push_back(make_pair(r,c));
        return;
    }
    if(g[r][c] == 'X'){
        v[r][c]=true;
        g[r][c]=id;
        flood(r+1,c,i,id);
        flood(r-1,c,i,id);
        flood(r,c+1,i,id);
        flood(r,c-1,i,id);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&R,&C);
    for(int r = 0; r < R;r++)
        for(int c = 0; c < C;c++)
            scanf(" %c",&g[r][c]);

    int it = 0;
    for(int r = 0; r < R;r++){
        for(int c = 0; c < C;c++){
            if(!v[r][c] && g[r][c] == 'X'){
                flood(r,c,it,it+'0');
                it++;
            }
        }
    }
    // try bfs bewtween spots and then remove duplicate locations
    print_grid();
    printf("%d\n",min_spot);
    return 0;
}
