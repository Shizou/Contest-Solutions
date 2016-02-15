#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    vector<int> a;
    int t = 0;
    for(int i = 0;i < 3;i++){
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(),a.end());

    int diff = a.at(1) - a.at(0);

    if(diff > a.at(2)- a.at(1)){
        diff = a.at(2)-a.at(1);
        cout << a.at(0) + diff;
        return 0;
    }

    for(int i = 0;i < a.size()-1;i++){
        if(a.at(i+1)- a.at(i) != diff){
            cout << a.at(i) + diff << endl;
            break;
        }
        if(i == a.size()-2){
            cout << a.at(i+1) + diff << endl;\
            break;
        }
    }

    //fclose(stdin);
    return 0;
}
