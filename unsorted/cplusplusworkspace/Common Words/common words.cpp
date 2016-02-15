#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
#define mp make_pair
#define pb push_back
using namespace std;


int N,M,K;
bool found;
string s;
vector< pair<int,string> >w;

string nt(int x){
    switch(x){
        case 0: return "th";
        case 1: return "st";
        case 2: return "rd";
        case 3: return "rd";
        default: return "th";
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> N;
    while(N--){
        cin >> M >> K;
        for(int i = 0;i < M;i++){
            cin >> s;
            cout << s << endl;
            found = false;
            for(int j = 0;j < (int)w.size();j++)
                if(w[j].second == s)
                    w[j].first++,found = true;
            if(!found)
                w.pb(mp(1,s));
        }
        sort(w.begin(),w.end(),greater< pair<int,string> >());
        if(K%100 >= 11 && K%100 <= 19)
           printf("%dth most common word(s):\n",K);
        else
           printf("%d%s most common word(s):\n",K,nt(K%10).c_str());
        int rk = 1,sc = (w.size() != 0) ? w[0].first:-1;
        //cout << w.size() << endl;
        for(int i = 0;i < (int)w.size();i++){
            if(w[i].first == sc && rk == K)
               printf("%s\n",w[i].second.c_str());
            else if(w[i].first < sc)
               rk++,sc = w[i].first,i--;
        }printf("\n");
       // cout << rk << endl;
        //for(int i = 0;i < (int)w.size();i++)printf("%d: %s\n",w[i].first,w[i].second.c_str());
        w.clear();
    }
}
