#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int R,C,cR,cC,stp;
bool v[100][100];
int ss[100][100];

vector< pair<int,int> > corners;

void update(int r, int c){
	for(int i = 0; i < cR;i++)
		for(int j = 0; j < cC;j++)
			v[r+i][c+j] = true;
}
void update_corners(){
    int r = cR,c = cC ,r1 = cR ,c1 = C-cC-1 ;
    while( abs(r-r1) + abs(c - c1) != 1 && abs(r-r1) + abs(c - c1) != 0){
        corners.push_back( make_pair(r,c));
        corners.push_back( make_pair(r1,c1));
        r++;c++;
        r1++;c1--;
    }
    corners.push_back( make_pair(r,c));
    corners.push_back( make_pair(r1,c1));
    r = R-cR-1,c = cC, r1 = R-cR-1,c1 = C-cC-1;
    while( abs(r-r1) + abs(c - c1) != 1 && abs(r-r1) + abs(c - c1) != 0){
        corners.push_back( make_pair(r,c));
        corners.push_back( make_pair(r1,c1));
        r--;c++;
        r1--;c1--;
    }
    corners.push_back( make_pair(r,c));
    corners.push_back( make_pair(r1,c1));
}
bool find_corner(int r, int c){
    for(int i = 0; i < corners.size();i++)
        if(corners[i].first == r && corners[i].second == c)
            return true;

    return false;
}
void print_array(){
	for(int i = 0; i < R;i++){
		for(int j = 0; j < C;j++){
			printf("%s ", v[i][j] ? "1":"0");
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d%d%d%d%d",&C,&R,&cC,&cR,&stp);
	update(0,0);
	update(0,C-cC);
	update(R-cR,0);
	update(R-cR,C-cC);
	int r = 0,c = cC;
	int state = 1;
	// up = 0, right = 1, down = 2, left = 3
	//print_array();
    update_corners();
    int tmp_stp = 0;
	while(tmp_stp < stp){
	    //printf("step: %d (r: %d, c: %d) ... state : %d\n",tmp_stp,r,c,state);
        ss[r][c]++;
	    if(v[r][c] || ss[r][c] > 5){
            tmp_stp++;
            continue;
	    }
		if(state == 1){//right
			if(c+1 > C-1 || v[r][c+1]){
				state = 2;
				v[r][c] = false;
			}
			else{
				v[r][c] = true;
				c++;
				tmp_stp++;
			}
		}
		else if(state == 2){//down
            if(find_corner(r,c)){
                state = 3;
                v[r][c] = false;
            }
            else if(r+1 > R-1 || v[r+1][c]){
                state = 3;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                r++;
                tmp_stp++;
            }
		}
		else if(state == 3){//right
            if(c+1 > C-1 || v[r][c+1]){
                state = 4;
				v[r][c] = false;
            }
            else{
				v[r][c] = true;
				c++;
				tmp_stp++;
			}
        }
        else if(state == 4){//down
           if(r+1 > R-1 || v[r+1][c]){
                state = 5;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                r++;
                tmp_stp++;
            }
        }
        else if(state == 5){//left
            if(find_corner(r,c)){
                state = 6;
                v[r][c] = false;
            }
            else if(c-1 < 0 || v[r][c-1]){
                state = 6;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                c--;
                tmp_stp++;
            }
        }
        else if(state == 6){//down
            if(r+1 > R-1 || v[r+1][c]){
                state = 7;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                r++;
                tmp_stp++;
            }
        }
        else if(state == 7){// left
            if(c-1 < 0 || v[r][c-1]){
                state = 8;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                c--;
                tmp_stp++;
            }
        }
        else if(state == 8){// up
            if(find_corner(r,c)){
                state = 9;
                v[r][c] = false;
            }
            else if(r-1 < 0 || v[r-1][c]){
                state = 9;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                r--;
                tmp_stp++;
            }
        }
        else if(state == 9){// left
            if(c-1 < 0 || v[r][c-1]){
                state = 10;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                c--;
                tmp_stp++;
            }
        }
        else if(state == 10){// up
            if(r-1 < 0 || v[r-1][c]){
                state = 11;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                r--;
                tmp_stp++;
            }
        }
        else if(state == 11){// right
            if(find_corner(r,c)){
                state = 12;
				v[r][c] = false;
            }
            else if(c+1 > C-1 || v[r][c+1]){
                state = 12;
				v[r][c] = false;
            }
            else{
				v[r][c] = true;
				c++;
				tmp_stp++;
			}
        }
        else if(state == 12){// up
            if(r-1 < 0 || v[r-1][c]){
                state = 1;
                v[r][c] = false;
            }
            else{
                v[r][c] = true;
                r--;
                tmp_stp++;
            }
        }
	}
	//print_array();
	printf("%d\n%d\n",c+1,r+1);
	return 0;
}
