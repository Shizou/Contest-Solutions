#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define inf 0x3f3f3f3f
using namespace std;

typedef pair<double,double> pt;
int N;



double euclidean_distance(pt A,pt B){
    return sqrt((A.xx-B.xx)*(A.xx-B.xx) + (A.yy-B.yy)*(A.yy-B.yy));
}


pair< pt, pt > vertical_sweep(vector< pt >&pts, int &MAXN){
        // variables nessary for the sweep
        pair< pt,pt > ret;
        double min_distance = inf;
        int line_id = 0;
        int x_coordinate[MAXN];
        set<double>vertical_segment[MAXN];

        for(int i = 0;i < MAXN;i++){
            if(i == 0){
               x_coordinate[line_id] = pts[i].xx;
               vertical_segment[line_id].insert(pts[i].yy);
            }
            else{
                pt P = pts[i];
                pt Q = pts[i-1];
                if(P.first == Q.first){// lies on the same segment as the last point

                   if(euclidean_distance(P,Q) < min_distance){
                      ret = pair<pt,pt>(P,Q);
                      min_distance = euclidean_distance(P,Q);
                   }
                   vertical_segment[line_id].insert(P.yy);
                   if(line_id > 0){
                     // binary search for next biggest point and next smallest point o the segment before the current one
                     pt A = pt(x_coordinate[line_id-1], *vertical_segment[line_id-1].upper_bound(P.yy) );
                     pt B = pt(x_coordinate[line_id-1], *(--vertical_segment[line_id-1].upper_bound(P.yy)) );
                     if(euclidean_distance(P,A) < min_distance){
                        ret = pair<pt,pt>(P,A);
                        min_distance = euclidean_distance(P,A);
                     }
                     if(euclidean_distance(P,B) < min_distance){
                        ret = pair<pt,pt>(P,B);
                        min_distance = euclidean_distance(P,B);
                     }
                   }
                   else{
                      // TODO
                   }
                }

            }
        }
        return ret;
}
pair< pt,pt > hortizontal_sweep(vector< pt >&pts, int &MAXN){
      pair< pt,pt > ret;
      return ret;
}

int main(){
    #ifdef DB
    freopen("input.txt","r",stdin);
    #endif
    needforspeed
    while(cin >> N && N != 0){
          vector< pt >pts;
          for(int i = 0;i < N;i++){
              double x,y;
              cin >> x >> y;
              pts.push_back(pt(x,y));
          }
          pair<pt,pt> vert = vertical_sweep(pts,N);
          pair<pt,pt> horz = hortizontal_sweep(pts,N);
    }

    return 0;
}