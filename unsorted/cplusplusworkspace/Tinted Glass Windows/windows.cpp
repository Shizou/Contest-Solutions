#include<stdio.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;

int m,t;
double area;

struct seg{
    int x,y,ex,ey,tf;
};

int main(){
    freopen("input.txt","r",stdin);
        scanf("%d%d",&m,&t);
        vector<seg> points;
        int x1,x2,y1,y2,tf;
        for(int i = 0;i < m;i++){
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&tf);
            points.push_back( (seg){x1,y1,x1,y2,tf});
            points.push_back( (seg){x2,y1,x2,y2,-1*tf});
        }
        // # bubble sort
        for(int i = 0;i < points.size();i++){
            int swap = 0;
            for(int j = 0; j < points.size()-1;j++){
                if( points[j].x > points[j+1].x ){
                    seg tmp = points[j+1];
                    points[j+1] = points[j];
                    points[j] = tmp;
                    swap++;
                }
            }
            if(swap == 0) break;
        }
        int ctf = 0;
        for(int i = 0;i < points.size();i++){
            int bx = points[i].x  ,  by = points[i].y;
            int ex = points[i].ex ,  ey = points[i].ey;
            int tf = points[i].tf ;
            if(tf > 0)ctf+=tf;
            else if(tf < 0){
                if(ctf > t){
                    if(by > points[i-1].y && ey > points[i-1]){


                    }


                }
                else
                    ctf+=tf;
            }
        }
    fclose(stdin);
    return 0;
}
