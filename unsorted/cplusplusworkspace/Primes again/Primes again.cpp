#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    unsigned long min, max;
    bool prime;
    scanf("%l %l",&min, &max);

    if(min < 3){
        if(min == 1){
            printf("1\n2\n");
            min+=2;
        }
        else{
            printf("2\n");
            min +=1;
        }

    }
    if(min%2 == 0)
        min+=1;


    for(int i = min;i <= max;i+=2){
        prime = true;
        for(int j = 3;j <= sqrt(i);j+=2){
            if(i%j == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            printf("%d\n", i);

        }

    }

    return 0;
}
