#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;


int main(){
    int distance= 0, occurences = 0, occurences2 = 0, value = 0;
    string reading = "", reading2 = "" ,digit = "",digit2 = "", conversion = "";


    for(int i = 0;i < 5;i++){
        reading2 = "";
		distance = 0;occurences = 0;occurences2 = 0;

        //input
        cin >> reading;
        cin >> digit;
        cin >> digit2;

            //check occucerences
            for(int j = 0; j < reading.size();j++){
                if(reading.at(j) == digit.at(0))
                    occurences++;
            }

            value = atoi(reading.c_str());

            // calculation
            for(int j = value; j < 1000001;j++){
                conversion = static_cast<ostringstream*>( &(ostringstream() << j) )->str();

                    if(j < 10)          reading2 = "00000" + conversion;
                    else if(j < 100)    reading2 = "0000" + conversion;
                    else if(j < 1000)   reading2 = "000" + conversion;
                    else if(j < 10000)  reading2 = "00" + conversion;
                    else if(j < 100000) reading2 = "0" + conversion;
                    else                reading2 = conversion;

                // check occurences
                for(int k = 0; k < reading2.size();k++){
                    if(reading2.at(k) == digit2.at(0))
                        occurences2++;
                }


                if(occurences == occurences2) break;
                else                          occurences2 = 0;

                if(j == 1000000)              j = 0;


                distance++;


            }
            cout << reading2 << " " << distance << endl;

    }
    return 0;
}
