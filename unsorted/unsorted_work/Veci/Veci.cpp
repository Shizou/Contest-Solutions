#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdlib.h>
#include<sstream>
using namespace std;

int main(){
    int a; cin >> a;
    bool n = true;
    string aS = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
    string bS = aS;
    sort(aS.begin(), aS.end());
    for(int i = a+1;i <= 999999;i++){
        bS = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
        sort(bS.begin(),bS.end());
        if(bS.size() > aS.size()){
            break;
        }
        if(aS == bS){
            cout << i << endl;
            n = false;
            break;
        }
    }
    if(n)
        cout << "0" << endl;
}
