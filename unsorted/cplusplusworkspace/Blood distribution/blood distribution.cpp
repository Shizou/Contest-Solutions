#include<iostream>
#include<fstream>

using namespace std;

int b[8];
int p[8];
int cnt;
bool a;
int main(){
    //freopen("input.txt","r",stdin);
    for(int i = 0;i < 8;i++) cin >> b[i];
    for(int i = 0;i < 8;i++) cin >> p[i];

    //on
    while(b[0] != 0 && p[0] != 0){
        b[0]--;
        p[0]--;
        cnt++;
    }
    //op
    while( (b[0] != 0 || b[1] != 0) && p[1] != 0){
        if(b[1] > 0) b[1]--;
        else         b[0]--;
        p[1]--;
        cnt++;
    }
    //an
    while(  (b[2] != 0 || b[0] != 0) && p[2] != 0 ){
        if(b[2] > 0) b[2]--;
        else         b[0]--;
        p[2]--;
        cnt++;
    }
    //ap
    while(  (b[3] != 0 || b[2] != 0 || b[1] != 0 || b[0] != 0) && p[3] != 0 ){
        if(b[3] > 0)      b[3]--;
        else if(b[2] > 0) b[2]--;
        else if(b[1] > 0) b[1]--;
        else              b[0]--;
        p[3]--;
        cnt++;
    }

    //bn
    while(  (b[4] != 0 || b[0] != 0) && p[4] != 0 ){
        if(b[4] > 0) b[4]--;
        else         b[0]--;
        p[4]--;
        cnt++;
    }
    //bp
    while(  (b[5] != 0 || b[4] != 0 || b[1] != 0 || b[0] != 0) && p[5] != 0 ){
        if(b[5] > 0)      b[5]--;
        else if(b[4] > 0) b[4]--;
        else if(b[1] > 0) b[1]--;
        else              b[0]--;
        p[5]--;
        cnt++;
    }
    //abn
    while(  (b[6] != 0 || b[4] != 0 || b[2] != 0 || b[0] != 0) && p[6] != 0 ){
        if(b[6] > 0)      b[6]--;
        else if(b[4] > 0) b[4]--;
        else if(b[2] > 0) b[2]--;
        else              b[0]--;
        p[6]--;
        cnt++;
    }
    //abp
    while(  (b[7] != 0 || b[6] != 0 || b[5] != 0 || b[4] != 0 || b[3] != 0 || b[2] != 0 || b[1] != 0 || b[0] != 0) && p[7] != 0 ){
        if(b[7] > 0)      b[7]--;
        else if(b[6] > 0) b[6]--;
        else if(b[5] > 0) b[5]--;
        else if(b[4] > 0) b[4]--;
        else if(b[3] > 0) b[3]--;
        else if(b[2] > 0) b[2]--;
        else if(b[1] > 0) b[1]--;
        else              b[0]--;
        p[7]--;
        cnt++;
    }
    cout << cnt << endl;
    //fclose(stdin);
    return 0;
}
