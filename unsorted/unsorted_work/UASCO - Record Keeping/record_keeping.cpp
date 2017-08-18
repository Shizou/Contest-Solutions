#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    freopen("file records.in.txt", "r" , stdin);
    freopen("file records.out.txt", "w", stdout);

    int size;cin >> size;
    int occurences = 0;
    int temp = 0;
    string input[size];

    getline(cin, input[0]);

        for(int i = 0;i < size;i++){
            getline(cin,input[i]);
            sort(input[i].begin(), input[i].end());
        }

    sort(input,input + size);

        for(int i = 0;i < size-1;i++){
            temp = 0;
            for(int j = i;j < size;j++){
                if(input[i] == input[j])
                    temp++;
            }
            if(temp > occurences)
                occurences = temp;

        }
        cout << occurences << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
