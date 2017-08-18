#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int n = 1;
    cin >> n;
    int sl = 5,dif = 2;
    if(n == 1)
        cout << "9" << endl;
    else if(n == 2)
        cout << "25" << endl;

    else{
        for(int i = 3;i <= n;i++){
            dif*=2;
            sl += dif;
        }
        cout << sl*sl << endl;
    }

   //fclose(stdin);
    return 0;
}
