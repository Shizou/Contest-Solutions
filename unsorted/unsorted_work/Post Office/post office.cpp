#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){

    double l = 0, h = 0, t = 0, w = 0;
    double area = 0;

    for(int i = 0;i < 5;i++){

        cin >> l >> h >> t >> w;
        area = 2*t + 3*l;

        // regular post card
        if( (l >= 3.5 && l <= 4.25) && (h >= 3.5 && h <= 6) && (t >= 0.007 && t <= 0.016)){
            printf("%.2f\n", ceil(w/0.0625)*0.20);
        }
        // large post card
        else if( (l >= 4.25 && l <= 6) && (h >= 6 && h <= 11.5) && (t >= 0.007 && t <= 0.016)){
            printf("%.2f\n", ceil(w/0.0625)*0.30);
        }
        // envelope
        else if( (l >= 3.5 && l <= 6.125) && (h >= 5 && h <= 11.5) && (t >= 0.016 && t <= 0.25)){
            printf("%.2f\n", ceil(w/0.0625)*0.47);
        }
        // large envelope
        else if( (l >= 6.125 && l <= 24) && (h >= 11 && h <= 18) && (t >= 0.25 && t <= 0.5)){
            printf("%.2f\n", ceil(w/0.0625)*0.56);
        }
        // package
        else if( area <= 84){
            printf("%f\n", area);
            printf("%.2f\n", ceil(w/0.50)*1.50);
        }
        // large package
        else if( area > 84 && area < 130){
            printf("%.2f\n", ceil(w/0.50)*1.75);
        }
        else{
            printf("UNMAILABLE\n");
        }

    }







    return 0;
}
