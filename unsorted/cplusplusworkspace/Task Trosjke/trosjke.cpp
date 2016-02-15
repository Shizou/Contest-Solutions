#include<iostream>
#include<cstdio>

using namespace std;

int N,cnt;
int dr[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};
string g[100];

int v(int r, int c, int dx, int dy,int d){
    int len = 0;
    while(r >= 0 && c >= 0 && r < N && c < N){
        if(g[r][c] != '.')len++;
        printf("slope : (%d,%d) , position: (%d,%d)\n",dx,dy,r,c);
        r+= dy;
        c+= dx;
    }
    return len;
}
int main(){
    freopen("input.txt","r",stdin);
    cin >> N;
    for(int i = 0; i < N;i++)
        cin >> g[i];

    for(int r = 0; r < N;r++){
        for(int c = 0; c < N;c++){
            if(g[r][c] != '.'){
                // brute force line slopes
                for(int x = 0; x < N;x++){
                    for(int y = 0; y < N;y++){
                        if(!(x == 0 && y == 0)){
                            if(x == 1 && y == 1){
                                int l_int = v(r,c,x,y,0) ;
                                //printf("slope: (%d,%d) intersections: %d\n",x,y,l_int);
                                if(l_int >= 3 || l_int >= 3 || l_int >= 3 || l_int >= 3){
                                    cout << "YOLO" << endl;
                                 //   cnt++;
                                }
                                l_int = v(r,c,x,-y,0) ;
                                //printf("slope: (%d,%d) intersections: %d\n",x,y,l_int);
                                if(l_int >= 3 || l_int >= 3 || l_int >= 3 || l_int >= 3){
                                    cout << "YOLO" << endl;
                                 //   cnt++;
                                }
                                l_int = v(r,c,-x,y,0) ;
                                //printf("slope: (%d,%d) intersections: %d\n",x,y,l_int);
                                if(l_int >= 3 || l_int >= 3 || l_int >= 3 || l_int >= 3){
                                    cout << "YOLO" << endl;
                                 //   cnt++;
                                }
                                l_int = v(r,c,-x,-y,0) ;
                                //printf("slope: (%d,%d) intersections: %d\n",x,y,l_int);
                                if(l_int >= 3 || l_int >= 3 || l_int >= 3 || l_int >= 3){
                                    cout << "YOLO" << endl;
                                 //   cnt++;
                                }

                            }

                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}


