#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int testcases, teams;
    int undefeated, oneLoss, eliminated;
    cin >> testcases ;

    for(int i = 0;i < testcases;i++){
        cin >> teams;
        undefeated = teams;
        oneLoss = 0;
        eliminated = 0;

        for(int j = 0;;j++){


            printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", j , undefeated, oneLoss, eliminated);
            break;
        }

    }

}
