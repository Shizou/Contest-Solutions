#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int T,G,a,b,sa,sb,total;

vector<int>points(4,0);
vector<bool>v[4];

struct state{
    vector<int>pts;
    vector<bool>v[4];
    int rnds;
};
void r(vector<int>pts, vector< bool>v[], int rnds){
    if(rnds == 6){
        bool win = true;
        for(int i = 0;i < 4;i++){
            if(T != i){
                if( !(pts[T] > pts[i]) ){
                    win = false;
                    break;
                }
            }
        }
        if(win)total++;
    }
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(!v[i][j]){
                v[i][j] = v[j][i] = true;

                pts[i]+=3;
                r(pts,v,rnds+1);
                pts[i] -=3;

                pts[j] += 3;
                r(pts,v,rnds+1);
                pts[j] -=3;

                pts[i] += 1;
                pts[j] += 1;
                r(pts,v,rnds+1);
                //v[i][j] = v[j][i] = false;
            }
        }
    }

}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&T,&G);
    T--;
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            v[i].push_back(false);
    for(int i = 0;i < G;i++){
        scanf("%d%d%d%d",&a,&b,&sa,&sb);
        points[a-1] += (sa > sb) ? 3: ( (sa == sb) ? 1:0);
        points[b-1] += (sb > sa) ? 3: ( (sb == sa) ? 1:0);
        v[a-1][b-1] = v[b-1][a-1] =  v[a-1][a-1] = v[b-1][b-1] = true;
    }
    stack< state> s;
    s.push((state){points,{ {v[0]},{v[1]} ,{v[2]}, {v[3]}},G});

    while(!s.empty()){
        vector<int> pts = s.top().pts;
        vector<bool>v[4] = s.top().v;
        int rnds = s.top().rnds;
        s.pop();
        //printf("Round: %d; %d %d %d %d\n", rnds, pts[0],pts[1],pts[2],pts[3]);
            if(rnds == 6){
                bool win = true;
                for(int i = 0;i < 4;i++){
                    if(T != i){
                        if( !(pts[T] > pts[i]) ){
                            win = false;
                            break;
                        }
                    }
                }
                if(win)total++;
                continue;
            }
            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++){
                    if(!v[i][j]){
                        v[i][j] = v[j][i] = true;
                        pts[i]+=3;
                        s.push((state){pts,{ {v[0]},{v[1]} ,{v[2]}, {v[3]}},rnds+1});
                        pts[i] -=3;

                        pts[j] += 3;
                        s.push((state){pts,{ {v[0]},{v[1]} ,{v[2]}, {v[3]}},rnds+1});
                        pts[j] -=3;

                        pts[i] += 1;
                        pts[j] += 1;
                        s.push((state){pts,{ {v[0]},{v[1]} ,{v[2]}, {v[3]}},rnds+1});
                    }
                }
            }

    }
    //r(points,v,G);
    cout << total << endl;
}
