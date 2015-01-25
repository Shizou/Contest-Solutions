#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,K,a,b;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&K);

    vector<int> stacks = vector<int>(N);
    vector< pair < int, bool > > s;

    for(int i = 0;i < K;i++){
        scanf("%d%d",&a,&b);
        s.push_back( make_pair(a-1,false));
        s.push_back( make_pair(b,true));
    }
    sort(s.begin(),s.end());

    int val = 0;
    int j = 0;
    for(int i = 0;i < N;i++){
        if(j < s.size() && s[j].first == i){
            if(!s[j].second){
                val++;
                j++;
                i--;
                continue;
            }
            else{
                val--;
                j++;
                i--;
                continue;
            }
        }
        stacks[i]+=val;
    }
    sort(stacks.begin(),stacks.end());
    printf("%d\n", stacks[ (N-1)/2]);


    //fclose(stdin);
}
