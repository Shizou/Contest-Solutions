#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector< pair< int,int > >r(1000);
int n,in;
int main(){
    freopen("input.txt","r",stdin);
        for(int i = 0;i < 1000;i++)
            r[i].second = i+1;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> in;
            r[in-1].first++;
        }
        sort(r.begin(),r.end());
        if(r[999].first != r[998].first){
            if(r[998].first != r[997].first){
                cout << abs(r[999].second-r[998].second) << endl;
            }
            else{
                int max = abs(r[999].second-r[998].second);
                for(int i = 997;i >= 0;i--){
                    if(r[i].first != r[i+1].first) break;
                    else if(abs(r[999].second-r[i].second) > max){
                            max = abs(r[999].second-r[i].second);
                    }
                }
                cout << max << endl;
            }
        }
        else{
                int max = abs(r[999].second-r[998].second);
                bool a = 0;
                for(int j = 999;j >= 0 && !a;j--){
                    for(int i = 998;i >= 0 && !a;i--){
                        if(r[i].first != r[i+1].first){
                         a = 1;
                         break;
                        }
                        else if(abs(r[j].second-r[i].second) > max){
                                max = abs(r[j].second-r[i].second);
                        }
                    }
                }
                cout << max << endl;

        }



    //fclose(stdin);
    return 0;
}

