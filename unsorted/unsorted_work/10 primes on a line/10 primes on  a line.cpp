#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int size,count = 0;
    bool prime = true;
    cin >> size;


    if(size > 1){
        cout << "2 ";
        count +=1;
    }

   for(int i = 3;count != size;i+=2){

        for(int j = 2; j <= sqrt(i);j++){
            if(i % j == 0){
                prime = false;
                break;
            }

        }
        if(prime){
            cout << i << " ";
            count += 1;
        }
        if(count % 10 == 0)
            cout << endl;

        prime = true;

   }

    return 0;
}
