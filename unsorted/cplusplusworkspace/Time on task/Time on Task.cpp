#include <iostream>

using namespace std;

int main(){
    int timeGiven = 0, tasks = 0, completed = 0,temp = 0;
    cin >> timeGiven >> tasks;

    int time[tasks];


    for(int i = 0;i < tasks;i++){
        cin >> time[i];
    }

    //bubble sort
    for(int i = 0, exchanges = 0;i < tasks;i++){
        exchanges = 0;
        for(int j = 0;j < tasks ;j++){
            if(time[j] > time[j+1]){
                temp = time[j];
                time[j] = time[j+1];
                time[j+1] = temp;
                exchanges++;
            }
        }
        if(exchanges==0)
            break;
    }

    //check through subtraction of lowest values
    for(int i = 0;i < tasks;i++){
        if((timeGiven - time[i]) >= 0){
            timeGiven -= time[i];
            completed++;
        }else{
            break;
        }
    }

    cout << completed << endl;






}
