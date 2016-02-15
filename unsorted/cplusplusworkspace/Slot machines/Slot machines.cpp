#include <iostream>

using namespace std;

int main(){
    int coins = 0, turns = 0;
    int cashout1 = 35;
    int cashout2 = 100;
    int cashout3 = 10;

    int slot1 = 0;
    int slot2 = 0;
    int slot3 = 0;
    int i = 1;

    cin >> coins >> slot1 >> slot2 >> slot3;

    do{
         if(i == 1){
            coins--;
            slot1++;
            if(slot1 == cashout1){
                coins += 30;
                slot1 = 0;
            }
            i++;
        }
        else if(i == 2){
            coins--;
            slot2++;
            if(slot2 == cashout2){
                coins += 60;
                slot2 = 0;
            }
            i++;
        }
        else if(i == 3){
            coins--;
            slot3++;
            if(slot3 == cashout3){
                coins += 9;
                slot3 = 0;
            }
            i = 1;
        }
        turns++;
    }while(coins > 0);

    cout << "Martha plays " << turns << " times before going broke.\n";

}
