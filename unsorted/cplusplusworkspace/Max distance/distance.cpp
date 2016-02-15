#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int n,nn,cnt;
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
        for(int j = 0;j < nn;j++){
            for(int k = nn-1;k > j;k--){
                if(s[j] == ss[k]){
                    if(k-j > cnt)
                        cnt = k-j;
                }
            }
        }
        cout << "The maximum distance is " <<  cnt << endl;
        cnt = 0;
    }
    //fclose(stdin);
}
