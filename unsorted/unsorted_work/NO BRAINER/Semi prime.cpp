#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    vector<int> primes;
    bool prime = true;

    primes.push_back(2);

    for(int i = 3;i < 1000;i++){
        prime = true;
        for(int j = 2; j <= sqrt(i);j++){
            if(i%j == 0){
                prime = false;
                break;
            }
        }
        if(prime)
            primes.push_back(i);
    }



    int input = 0;
    cin >> input;

        int cnt = 0;
        int a = 0, b = 0;

        for(int i = 0;i < primes.size();i++)
            for(int j = 0; j < primes.size();j++)
                if(primes.at(i) * primes.at(j) == input){
                    cnt++;


                    if(cnt < 1)
                    a = primes.at(i);
                    b = primes.at
                    cout << primes.at(i) << " * " << primes.at(j)  << "= " << input << endl;

                }


        if(cnt == 1)
            cout << "semiprime" << endl;
        else{
            cout << "not" << endl;
        }







    fclose(stdin);
    return 0;
}
