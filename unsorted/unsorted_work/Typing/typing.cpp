#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	int testcases;
	string input;
	bool alphabet[26] = {0};
	bool check = true;

	cin >> testcases;
	getline(cin,input);

    for(int i = 0;i < testcases;i++){
        getline(cin,input);

        fill(alphabet, alphabet + 25, false);
        check = true;

        for(int j = 0; j < input.length();j++){

            if(input.at(j) == 'a')
                alphabet[0] = true;
            else if(input.at(j) == 'b')
                alphabet[1] = true;
            else if(input.at(j) == 'c')
                alphabet[2] = true;
            else if(input.at(j) == 'd')
                alphabet[3] = true;
            else if(input.at(j) == 'e')
                alphabet[4] = true;
            else if(input.at(j) == 'f')
                alphabet[5] = true;
            else if(input.at(j) == 'g')
                alphabet[6] = true;
            else if(input.at(j) == 'h')
                alphabet[7] = true;
            else if(input.at(j) == 'i')
                alphabet[8] = true;
            else if(input.at(j) == 'j')
                alphabet[9] = true;
            else if(input.at(j) == 'k')
                alphabet[10] = true;
            else if(input.at(j) == 'l')
                alphabet[11] = true;
            else if(input.at(j) == 'm')
                alphabet[12] = true;
            else if(input.at(j) == 'n')
                alphabet[13] = true;
            else if(input.at(j) == 'o')
                alphabet[14] = true;
            else if(input.at(j) == 'p')
                alphabet[15] = true;
            else if(input.at(j) == 'q')
                alphabet[16] = true;
            else if(input.at(j) == 'r')
                alphabet[17] = true;
            else if(input.at(j) == 's')
                alphabet[18] = true;
            else if(input.at(j) == 't')
                alphabet[19] = true;
            else if(input.at(j) == 'u')
                alphabet[20] = true;
            else if(input.at(j) == 'v')
                alphabet[21] = true;
            else if(input.at(j) == 'w')
                alphabet[22] = true;
            else if(input.at(j) == 'x')
                alphabet[23] = true;
            else if(input.at(j) == 'y')
                alphabet[24] = true;
            else if(input.at(j) == 'z')
                alphabet[25] = true;

        }
        for(int j = 0;j < 26;j++){
            if(!alphabet[j]){
                check = false;
                break;
            }
        }
        if(check && input.size() <= 26){
            cout << "OK." << endl;
        }
        else
            cout << "Nope." << endl;
    }

    return 0;
}

