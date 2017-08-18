#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int a,b,c,d,N,area;
bool active[10];
bool segment_pair;

struct line_segmentX{
    int x1,y1,x2,y2,id;
    bool beg;
    bool operator <(const line_segmentX& rhs) const{
        return (x1 < rhs.x1) ? true : false;
    }
};
struct line_segmentY{
    int x1,y1,x2,y2,id;
    bool beg;
    bool operator <(const line_segmentY& rhs) const{
        return (y1 < rhs.y1) ? true : false;
    }
};

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    vector< line_segmentX > segmentsX;
    vector< line_segmentY > segmentsY;
    for(int i = 0; i < N;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        segmentsX.push_back((line_segmentX){a,b,a,d,i,true});
        segmentsX.push_back((line_segmentX){c,b,c,d,i,false});

        segmentsY.push_back((line_segmentY){a,b,c,b,i,true});
        segmentsY.push_back((line_segmentY){a,d,c,d,i,false});
    }
    sort(segmentsX.begin(),segmentsX.end());
    printf("X-Linesweep\n");
    for(int i = 0; i < segmentsX.size();i++){
        printf("(X1: %d Y1:%d) (X2: %d Y2: %d) %s\n", segmentsX[i].x1,segmentsX[i].y1,segmentsX[i].x2,segmentsX[i].y2, (segmentsX[i].beg) ? "BEG":"END" );
    }
    active[segmentsX[0].id] = true;
    /*line_segment temp;
    for(int i = 1;i < N;i++){
        if(segments[i].beg)
            active[segments[i].id] = true;
        else
            active[segments[i].id] = false;

        int dx = segments[i].x1 - segments[i-1].x1;

        for(int j = 0;j < N;j++){
            if(!active[j])continue;
            if(!segment_pair){
                segment_pair = true;
            }
        }
    }*/


}
