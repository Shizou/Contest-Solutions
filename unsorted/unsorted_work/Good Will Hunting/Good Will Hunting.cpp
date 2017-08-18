#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
    double input, scientificNotation,power;
    int position;
    int superscript,equality;
    string conversion;

        for(;;){

            scientificNotation = 0;
            superscript = 0;
            equality = 0;
            power = 1;

            conversion = "";

            cin >> input;
            conversion = static_cast<ostringstream*>( &(ostringstream() << input) )->str();

            if(input == 0)
                break;
            if(conversion.at(0) == '-')
                conversion.erase(0,1);

            if(input < 1 && input > 0)
            {

                for(int i = 2; i < conversion.size()-1;i++){
                    equality+= 1;
                    superscript-=1;
                    if(conversion.at(i) != '0')
                        break;
                }

                for(int i = 0;i < equality;i++)
                    power *=10;
            }
            else{
                for(int i = conversion.find('.')-1;i > 0;i--){
                    equality+= 1;
                    superscript+=1;

                }

                for(int i = 0;i < equality;i++)
                    power /=10;
            }




            scientificNotation = input*power;

            printf("%.3f X 10^%d\n",scientificNotation,superscript);

        }
}

