#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

string input[16];
char grid[16][30];
bool visited[16][30];

void newGrid(){

		for(int x = 0;x < 16;x++){
			for(int y = 0;y < 30;y++){

				int count = 0;

				if(grid[x][y] == 'X'){
					continue;
				}
				else if(grid[x][y] == '.'){

					// Checks for bomb in the normal four directions
					if(x-1 >= 0){//up
						if(grid[x-1][y] == 'X')
							count++;
					}
					if(x+1 < 16){//down
						if(grid[x+1][y] == 'X')
							count++;
					}
					if(y-1 >= 0){//left
						if(grid[x][y-1] == 'X')
							count++;
					}
					if(y+1 < 30){//right
						if(grid[x][y+1] == 'X')
							count++;
					}

					// Checks for bomb in four diagnol dirrections
					if(x-1 >= 0 && y-1 >= 0){//up left
						if(grid[x-1][y-1] == 'X')
							count++;
					}
					if(x+1 < 16 && y+1 < 30){//down right
						if(grid[x+1][y+1] == 'X')
							count++;
					}
					if(x-1 >= 0 && y+1 < 30){//up right
						if(grid[x-1][y+1] == 'X')
							count++;
					}
					if(x+1 < 16 && y-1 >= 0){//down left
						if(grid[x+1][y-1] == 'X')
							count++;
					}
					//assigns number to grid point
					if(count > 0)
						grid[x][y] = (char) ('0' + (char)count);


				}

		}

	}



}

int flood(int x, int y){

		if(x  < 0|| x > 15 || y < 0 || y > 29 ){
			return 0;
		}
		else if(visited[x][y]){
			return 0;
		}
		else if(grid[x][y] == 'x'){

			visited[x][y] = true;
			return 0;
		}
		else if(grid[x][y] != '.'){

			visited[x][y] = true;
			return 1;
		}
		else
			visited[x][y] = true;


		return flood(x+1,y) + flood(x-1,y) + flood(x,y+1) + flood(x,y-1) +
			   flood(x+1,y+1) + flood(x-1,y-1) + flood(x-1,y+1) + flood(x+1,y-1) + 1;


	}

int main(){
    //freopen("input.txt", "r", stdin);
        // input
        for(int x = 0;x < 16;x++){
			getline(cin,input[x]);
		}
		for(int x = 0;x < 16;x++){
			for(int y = 0; y < 30;y++){
				grid[x][y] = input[x].at(y);
			}

		}
        newGrid();

        for(int i = 0;i < 5;i++){
			int x = 0;
			int y = 0 ;
            cin >> x >> y;

			if(grid[x-1][y-1] == 'X'){
				cout << "MINE - YOU LOSE" << endl;
			}
			else if(grid[x-1][y-1] != '.'){
				printf("NO MINE - %c SURROUNDING IT\n", grid[x-1][y-1]);
			}
			else{
				printf("NO MINE - %d SQUARES REVEALED\n", flood(x-1,y-1));

				for(int r = 0;r < 16;r++){
					for(int c = 0; c < 30;c++){
						visited[r][c] = false;
					}
				}

			}
		}
   // fclose(stdin);
    return 0;
}
