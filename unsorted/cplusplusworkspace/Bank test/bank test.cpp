#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    double balance = 0;
    double interest = 0.03;
    double total = 0;


    cin >> balance;
    for(int years = 1;years <= 1;years++){
        for(int days = 1;days <= 30;days++){
            total += balance + balance*interest;
            printf("Balance on day %d : %.2f\n", days,total);
        }
            balance = total;
            balance -= 8.5;
            printf("End of monthly statement.\n");
    }
    return 0;
}
