#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int in = 0; cin >> in;
    vector<int>p; p.push_back(2);
    vector<set<int,int>> lookup;
    bool prime = true;

        // primes check
        for(int i = 3;i <= 1000;i+=2){
            prime = true;
            for(int j = 3;j <= sqrt(i);j+=2){
                if(i%j == 0){
                    prime = false;
                    break;
                }
            }
            if(prime)
                p.push_back(i);
        }

    int cnt = 0;

    for(int i = 0;i < p.size()-1;i++){
        for(int j = 0; j < p.size()-1;j++){
            if(p.at(i) + p.at(j) == in){
                if()
                cnt++;
            }

        }
    }
    if(cnt == 1)
        cout << "semiprime" << endl;
    else
        cout << "not" << endl;

    fclose(stdin);
    return 0;
}



