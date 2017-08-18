#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> hotelsPosition;
int minValue = 0;
int maxValue = 0;
int ways = 0;




void optionsCalc(int position, int i){
    if(position == 7000){
       ways +=1;
    }
    else{
        for(int x = i;x <= hotelsPosition.size()-1;x++){
            if(hotelsPosition.at(x) - position >= minValue && hotelsPosition.at(x) - position <= maxValue){
                optionsCalc(hotelsPosition.at(x), x);
            }

        }

        return;
    }
}
void addDefault(){
        // default hotel positions
    hotelsPosition.push_back(0);
    hotelsPosition.push_back(990);
    hotelsPosition.push_back(1010);
    hotelsPosition.push_back(1970);
    hotelsPosition.push_back(2030);
    hotelsPosition.push_back(2940);
    hotelsPosition.push_back(3060);
    hotelsPosition.push_back(3930);
    hotelsPosition.push_back(4060);
    hotelsPosition.push_back(4970);
    hotelsPosition.push_back(5030);
    hotelsPosition.push_back(5990);
    hotelsPosition.push_back(6010);
    hotelsPosition.push_back(7000);

}

int main(){
    freopen("input.txt", "r", stdin);

        int hotels = 0;
        int temp = 0;

        addDefault();
        cin >> minValue >> maxValue >> hotels;

            //input
            for(int i = 0;i < hotels;i++){
                cin >> temp;
                hotelsPosition.push_back(temp);
            }
            sort(hotelsPosition.begin(), hotelsPosition.end());



            optionsCalc(0,0);

            cout << ways << endl;


    fclose(stdin);
    return 0;
}
