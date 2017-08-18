#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int orig = 0; cin >> orig ;
    int price = orig/2;

    for(int i = 1;;i++){
        if(i%2!=0){
            orig = (orig + price )/2;
        }
        else{
            price = (orig + price )/2;
        }

        if(orig == price)
            break;
    }
    cout << price;

   // fclose(stdin);
    return 0;
}
