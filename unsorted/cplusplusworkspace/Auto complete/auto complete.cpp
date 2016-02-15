#include<iostream>
#include<fstream>

using namespace std;

int main(){
    freopen("input.txt", "r",stdin);
    int size; cin >> size;
    int temp = 0;
    int p[size];
    string w[size];
    string tmps = "";
    int tmpi = 0;

    for(int i = 0;i < size;i++){
        cin >> p[i];
        cin >> w[i];
    }
    // bubble sort
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size-2;j++){
            if(w[i] > w[i+1]){
                tmps = w[i];
                tmpi = p[o]
                w[i] = w[i+1];
                w[i+1] = tmps;
                p[i] = p[i+1]
                p[i+1] = tmpi;
                temp++;
            }
        }
        if(temp == 0)
            break;
    }


    fclose(stdin);
    return 0;
}
