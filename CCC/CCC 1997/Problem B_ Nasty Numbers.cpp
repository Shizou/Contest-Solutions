#include <stdio.h>
#include <vector>
using namespace std;

int N,in;

vector<bool>v(32005);

int main() {
	scanf("%d",&N);
	for(int t = 0; t < N;t++){
        scanf("%d",&in);
        bool nasty = false;
        vector< pair<int,int> > p;

        for(int i = 1;i <= in;i++){
            for(int j = 1;j <= in;j++){
                if(i*j == in  ){
                    p.push_back( make_pair(i,j));

                }
            }
        }

        for(int i = 0;i < p.size();i++){
            for(int j = 0;j < p.size();j++){
                if(p[i].first - p[i].second == p[j].first + p[j].second){
                    nasty = true;
                    break;
                }
            }
        }
        printf("%d %s\n", in, (nasty) ? "is nasty":"is not nasty");
	}
	return 0;
}
