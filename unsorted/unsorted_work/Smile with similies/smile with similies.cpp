#include <iostream>
#include <string>

using namespace std;

int main(){
    int adjSize, nounSize;
    cin >> adjSize >> nounSize;

    string adj[adjSize];
    string noun[nounSize];

        for(int i = 0;i < adjSize;i++){
            cin >> adj[i];
        }

        for(int i = 0;i < nounSize;i++){
            cin >> noun[i];
        }

        for(int i = 0;i < adjSize;i++){
            for(int j = 0;j < nounSize;j++){
                cout << adj[i] << " as " << noun[j] << endl;
            }
        }



    return 0;
}
