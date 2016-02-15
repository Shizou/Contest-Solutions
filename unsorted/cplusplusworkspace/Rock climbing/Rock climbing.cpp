#include <iostream>

using namespace std;

int main(){
    int n, m , e, position = 0;
    cin >> n >> m >> e;
    int steps[n];
    int eTwo = 2*m;
    bool easy = true;


    for(int i = 0;i < n;i++){
        cin >> steps[i];
    }

    for(int i = 0;i < n;i++){
        if(position + m >= steps[i]){
            position = steps[i];
        }
        else if(e > 0 && position + eTwo >= steps[i]){
            e -= 1;
            position = steps[i];
        }
        else{
            easy = false;
            break;
        }
    }

    if(easy)
        cout << "Too easy!\n";
    else
        cout << "Unfair!";


    return 0;
}
