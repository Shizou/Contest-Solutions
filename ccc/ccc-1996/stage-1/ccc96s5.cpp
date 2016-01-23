#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

int n,nn,cnt;
map<int,int> pos;
int main(){
    //freopen("input.txt","r",stdin);
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> nn;
        int s[nn];
        int ss[nn];
        for(int j = 0;j < nn;j++){
            cin >> s[j];
        }
        for(int j = 0;j < nn;j++){
            cin >> ss[j];
        }

        for(int j = nn-1;j > 0;j--){
            if(pos.find(ss[j]) == pos.end()){
                pos[ss[j]] = j;
            }
        }
        for(int k = 0;k < nn;k++){
            if(pos.find(s[k]) != pos.end()){
                 if( pos[s[k]]- k > cnt){
                    cnt = pos[s[k]]- k;
                }
            }
        }
        cout << "The maximum distance is " <<  cnt << endl;
        cnt = 0;
        pos.clear();
    }
}
