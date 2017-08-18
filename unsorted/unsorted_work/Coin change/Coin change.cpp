#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n,den;
struct combo{
    int s,d;
};
int main(){
    cin >> n >> den;
    int c[n];
    for(int i = 0;i < den;i++) cin >> c[i];
    queue< combo > q;
    set < int > set;
    q.push( (combo){0,0} );
    while(!q.empty()){
        int s = q.front().s;
        int d = q.front().d;
        q.pop();
        if(s > n)
            continue;
        if(s == n){
            cout << d << endl;
            break;
        }
        for(int i = 0;i < den;i++){
            if(set.find(s+c[i]) == set.end()){
                q.push( (combo){ (s+c[i]),d+1} );
                set.insert(s+c[i]);
            }
        }
    }
    return 0;
}
