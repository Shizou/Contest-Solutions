#include<iostream>
#include<set>
using namespace std;
set<int>a;
int main(){
    int b;
    for(int i = 0;i < 10;i++){
        cin >> b;
        a.insert(b%42);
    }
    cout << a.size() << endl;
}
