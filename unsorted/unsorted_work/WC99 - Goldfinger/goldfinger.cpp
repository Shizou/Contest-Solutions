#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

vector<int> primes;

void init(){
    primes.push_back(1);
    primes.push_back(2);

    bool prime = false;
    for(int i = 3;i < 16000;i+=2){
        prime = true;
        for(int j = 3;j*j <= i;j++){
            if(i%j == 0){
                prime = false;
                break;
            }
        }
        if(prime)
         primes.push_back(i);
    }

}
void calc(int i){
    int range = ceil(sqrt(i));

    for(int x = 0;x < range;x++)
        for(int y = 0; y < i && y < primes.size();y++)
            if(primes.at(x) + primes.at(y) == i)
                printf("%d %d\n", primes.at(x), primes.at(y));

}

int main(){
    //freopen("input.txt","r",stdin);
    init();
    int input = 0;

    while(true){
        scanf("%d",&input);
        if(input == -1)
            break;
        else
            calc(input);

        printf("\n");
    }



   // fclose(stdin);
    return 0;
}



