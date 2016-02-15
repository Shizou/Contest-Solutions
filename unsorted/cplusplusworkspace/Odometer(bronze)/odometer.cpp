#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>

using namespace std;

long long x,y,cnt;
string s;
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&x,&y);
    for(;x <= y;x++){

        vector< pair<int,int> > v;
        stringstream ss;
        bool third_digit = false;

        ss << x;
        ss >> s;
        v.push_back(make_pair(-1,-1));
        v.push_back(make_pair(-1,-1));
        for(int i = 0; i < s.size();i++){
            int dig = s[i]-'0';
            if(v[0].first == -1){
                v[0].first = dig;
                v[0].second = 1;
            }
            else if(v[1].first == -1){
                v[1].first = dig;
                v[1].second = 1;
            }
            else if(v[0].first == dig){
                v[0].second++;
            }
            else if(v[1].first == dig){
                v[1].second++;
            }
            else{
                third_digit = true;
                break;
            }
        }

        if(v[0].first != -1 && v[1].first != -1 && v[0].second > v[1].second && v[1].second == 1 && !third_digit){
            cout << x << endl;
            cnt++;
        }
        else if(v[0].first != -1 && v[1].first != -1 && v[1].second > v[0].second && v[0].second == 1 && !third_digit){
            cout << x << endl;
            cnt++;
        }

    }
    printf("%d\n",cnt);
    return 0;
}
