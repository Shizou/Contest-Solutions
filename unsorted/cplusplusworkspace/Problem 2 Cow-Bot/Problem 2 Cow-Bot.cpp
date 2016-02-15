#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>

using namespace std;

bool primeChecker(int a){
    if(a == 1 || a == 2)
        return true;
    if(a % 2 == 0)
        return false;

    for(int i = 3;i <= (int)sqrt(a);i+=2){
        if(a%i == 0)
            return false;
    }

    return true;
}
bool squareChecker(int a){
    if((int)sqrt(a)*(int)sqrt(a) == a)
        return true;
    else
        return false;
}
bool pallindromeChecker(int a){
    string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
    string reverse = "";

    for(int i = conversion.size()-1;i > -1;i--){
        reverse+= conversion.at(i);
    }


    if(conversion == reverse)
        return true;
    else
        return false;

}
bool checkForTwo(int a){
    string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
    if(conversion.at(0) == '2')
        return true;

    return false;
}
bool checkForSeven(int a){
    string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
    for(int i = 0;i < conversion.size();i++){
        if(conversion.at(i) == '7')
            return true;
    }
    return false;
}
bool checkForEven(int a){
    string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
    if(conversion.size()%2 == 0)
        return true;
    else
        return false;
}

string reverseString(string a){
    string b;
    for(int i = a.size()-1;i > -1;i--){
        b+= a.at(i);
    }
    return b;
}

int main(){
    int t,a,b;
    cin >> t;


        for(int i = 0;i < t;i++)
        {
            cin >> a >> b;

                for(int j = 0;j < b;j++){

                    if(primeChecker(a)){
                        a*=11;

                    }
                    else if(squareChecker(a)){

                        string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
                        conversion = reverseString(conversion.c_str());
                        int reverse = atoi(conversion.c_str());
                        a+= reverse;

                    }
                    else if(pallindromeChecker(a)){

                        string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
                        string four = "4";
                        conversion.append(four);
                        a = atoi(conversion.c_str());

                    }
                    else if(checkForTwo(a)){

                        string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
                        string appendFive = "5";
                        appendFive.append(conversion);
                        a = atoi(appendFive.c_str());

                    }
                    else if(checkForSeven(a)){

                        if(a == 7)
                            a = 0;
                        else{
                                string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
                                conversion.erase(conversion.size()-1, 1);
                                a = atoi(conversion.c_str());
                        }

                    }
                    else if(a%6 == 0 ){
                        if(a == 6)
                            a = 0;
                        else{
                                string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
                                conversion = conversion.substr(0,conversion.size());
                                conversion.erase(0, 1);
                                a = atoi(conversion.c_str());
                        }

                    }
                    else if(checkForEven(a)){
                        string conversion = static_cast<ostringstream*>( &(ostringstream() << a) )->str();
                        conversion =  conversion.substr(0,conversion.size()/2) + "1" + conversion.substr(conversion.size()/2, conversion.size()-1);
                        a = atoi(conversion.c_str());

                    }
                    else
                         a += 231;





                }

                cout << a << endl;


        }
}
