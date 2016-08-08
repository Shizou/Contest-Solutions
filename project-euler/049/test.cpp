#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

bool is_prime(int x){
    if(x == 2)return true;
    if(x % 2 == 0)return false;
    for(int i = 3;i*i < x;i+=2){
        if(x%i == 0)return false;
    }
    return true;
}

bool same_digit(int x, int y, int z){
    stringstream ss;
    string sx, sy, sz;
    ss << x;
    ss >> sx;
    ss.clear();
    sort(all(sx));
    ss << y;
    ss >> sy;
    ss.clear();
    sort(all(sy));
    ss << z;
    ss >> sz;
    ss.clear();
    sort(all(sz));
    return sx == sy && sy == sz;
}

int main() {
    set<int>s;
    for(int i = 1000;i <= 9999;i++)s.insert(i);
    for(auto &it : s){
        if(is_prime(it) && is_prime(it+3330) && is_prime(it+6660) && same_digit(it, it+3330,it+6660)){
            if(s.count(it+3330) && s.count(it+6660)){
                cout << it << " " << it+3330 << " " << it+6660 << endl;
            }
        }
    }
}
