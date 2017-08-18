#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int T,G,a,b,sa,sb,total;

vector<int>points(4,0);
set<string> past_games;
string games = "------";

bool done(string &gms){
    for(int i = 0; i < 6;i++)if(gms[i] == '-')return false;
    return true;
}
bool max_t(vector<int>&scores){
    for(int i = 0; i < 4;i++)
        if(T != i && scores[T] <= scores[i]) return false;
    return true;
}
void update(string gms,int i,vector<int>&scores){
}
void r(string gms,vector<int>scores){
    if(past_games.find(gms) != past_games.end())return;

    if(done(gms) && max_t(scores))
        total++;
    for(int i = 0;i < 6;i++){
        if(gms[i] == '-'){
            if(i == 0){
                gms[i] = 'W';
                scores[0]+=3;
                r(gms,scores);
                scores[0]-=3;

                gms[i] = 'T';
                scores[0]++;
                scores[1]++;
                r(gms,scores);
                scores[0]--;
                scores[1]--;

                gms[i] = 'L';
                scores[1]+=3;
                r(gms,scores);
                scores[1]-=3;
            }
            else if(i == 1){
                gms[i] = 'W';
                scores[0]+=3;
                r(gms,scores);
                scores[0]-=3;

                gms[i] = 'T';
                scores[0]++;
                scores[2]++;
                r(gms,scores);
                scores[0]--;
                scores[2]--;

                gms[i] = 'L';
                scores[2]+=3;
                r(gms,scores);
                scores[2]-=3;
            }
            else if(i == 2){
                gms[i] = 'W';
                scores[0]+=3;
                r(gms,scores);
                scores[0]-=3;

                gms[i] = 'T';
                scores[0]++;
                scores[3]++;
                r(gms,scores);
                scores[0]--;
                scores[3]--;

                gms[i] = 'L';
                scores[3]+=3;
                r(gms,scores);
                scores[3]-=3;
            }
            else if(i == 3){
                gms[i] = 'W';
                scores[1]+=3;
                r(gms,scores);
                scores[1]-=3;

                gms[i] = 'T';
                scores[1]++;
                scores[2]++;
                r(gms,scores);
                scores[1]--;
                scores[2]--;

                gms[i] = 'L';
                scores[2]+=3;
                r(gms,scores);
                scores[2]-=3;
            }
            else if(i == 4){
                gms[i] = 'W';
                scores[1]+=3;
                r(gms,scores);
                scores[1]-=3;

                gms[i] = 'T';
                scores[1]++;
                scores[3]++;
                r(gms,scores);
                scores[1]--;
                scores[3]--;

                gms[i] = 'L';
                scores[3]+=3;
                r(gms,scores);
                scores[3]-=3;
            }
            else if(i == 5){
                gms[i] = 'W';
                scores[2]+=3;
                r(gms,scores);
                scores[2]-=3;

                gms[i] = 'T';
                scores[2]++;
                scores[3]++;
                r(gms,scores);
                scores[2]--;
                scores[3]--;

                gms[i] = 'L';
                scores[3]+=3;
                r(gms,scores);
                scores[3]-=3;
            }
        }
    }
    past_games.insert(gms);
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&T,&G);
    T--;
    for(int i = 0;i < G;i++){
        scanf("%d%d%d%d",&a,&b,&sa,&sb);
        points[a-1] += (sa > sb) ? 3: ( (sa == sb) ? 1:0);
        points[b-1] += (sb > sa) ? 3: ( (sb == sa) ? 1:0);
        if(a == 1 && b == 2)
            games[0] = (sa > sb) ? 'W' : ( (sa == sb) ? 'T':'L');
        else if(a == 1 && b == 3)
            games[1] = (sa > sb) ? 'W' : ( (sa == sb) ? 'T':'L');
        else if(a == 1 && b == 4)
            games[2] = (sa > sb) ? 'W' : ( (sa == sb) ? 'T':'L');
        else if(a == 2 && b == 3)
            games[3] = (sa > sb) ? 'W' : ( (sa == sb) ? 'T':'L');
        else if(a == 2 && b == 4)
            games[4] = (sa > sb) ? 'W' : ( (sa == sb) ? 'T':'L');
        else if(a == 3 && b == 4)
            games[5] = (sa > sb) ? 'W' : ( (sa == sb) ? 'T':'L');
    }
    r(games,points);
    cout << total << endl;
    return 0;
}
