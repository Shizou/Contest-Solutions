#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

    int tiles = 0;
    int totalRooms = 0;
    int rows = 0;
    int columbs = 0;

    char grid[25][25];
    bool  visited[25][25];
    vector<int> roomsSize;

int sizeCalc(int x, int y){

		if(x < 0 || y < 0 || x > rows-1 || y > columbs-1){
			return 0;
		}
		if(visited[x][y]){
			return 0;
		}
		if(grid[x][y] == 'I'){
			visited[x][y] = true;
			return 0;
		}


		visited[x][y] = true;

		return sizeCalc(x+1,y) + sizeCalc(x-1,y) + sizeCalc(x, y+1) + sizeCalc(x,y-1) + 1;

}


int main(){
    //freopen("input.txt", "r", stdin);
        cin >> tiles >> rows >> columbs;

        string input[rows];
        string test;

        getline(cin,test);
          // input
		for(int x = 0;x < rows;x++){
			getline(cin,input[x]);

		}

        for(int x = 0;x < rows;x++)
			for(int y = 0;y < columbs;y++)
			   grid[x][y] = input[x].at(y);


            // the magic
			for(int x = 0;x < rows;x++){
				for(int y = 0;y < columbs;y++){

					if(grid[x][y] == '.')
						if(!visited[x][y]){
							totalRooms++;
							roomsSize.push_back(sizeCalc(x,y));
						}

				}
			}

        sort(roomsSize.begin(), roomsSize.end());


    int completeRooms = 0;

    for(int i = roomsSize.size()-1;i >= 0;i--){
			if(tiles-roomsSize.at(i) >= 0){
				completeRooms++;
				tiles -= roomsSize.at(i);
			}
			else
				break;
    }

        if(completeRooms != 1)
                printf("%d rooms, %d square metre(s) left over", completeRooms, tiles);
        else
                printf("%d room, %d square metre(s) left over", completeRooms, tiles);

    //fclose(stdin);
    return 0;
}




