#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct car{
	int d,m,v;
};
bool compare(car left, car right){return left.d > right.d;}

int N,V,D,T;
vector<car>cr;
bool crash = false;

int main() {
    freopen("input.txt","r",stdin);
	scanf("%d%d%d%d",&N,&V,&D,&T);
    for(int i = 0; i < N;i++)cr.push_back( (car){D*i,0,0});
    sort(cr.begin(),cr.end(),compare);
    cr[0].v = V;
    int t_int = 0;
    for(int t = 1;!crash;t++){

        for(int i = 0; i < N;i++){// moving cars
            cr[i].d+=cr[i].v;
            cr[i].m+=abs(cr[i].v);
            if(i != 0 && cr[i].d > cr[i-1].d){
                crash = true;
                break;
            }
        }
        if(t%5 == 0){
            t_int++;

            break;
        }

    }
	return 0;
}
