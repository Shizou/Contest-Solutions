#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

    char grid[50][50];
	bool visited[50][50];
	int columbs = 0;
	int rows = 0;

int flood(int x, int y){

		if(x < 0|| y < 0  || x > rows-1  || y > columbs-1 ){
			return 0;
		}

		if(visited[x][y]){
			return 0;
		}
		if(grid[x][y] == '.'){
			visited[x][y] = true;
			return 0;
		}

			visited[x][y] = true;
			grid[x][y] = '.';


		return flood(x+1,y) + flood(x-1,y) + flood(x,y+1) + flood(x,y-1);


}


int main(){
    freopen("input.txt", "r", stdin);

   int shapes = 0;

    for(int i = 1;i <= 5 ;i++){
                cin >> columbs >> rows;
                string input[rows];
                getline(cin,input[0]);


				// input
				for(int x = 0;x < rows;x++)
					getline(cin,input[x]);

				for(int x = 0;x < rows;x++)
					for(int y = 0;y < columbs;y++)
					    grid[x][y] = input[x].at(y);

					// the magic
					for(int x = 0;x < rows;x++)
					{
						for(int y = 0;y < columbs;y++)
						{

							if(grid[x][y] == 'X'){
								shapes++;
								flood(x,y);
							}

						}
					}

					for(int x = 0;x < rows;x++)
                        for(int y = 0;y < columbs;y++)
                            grid[x][y] = ' ';


					printf("In rectangle #%d are %d shapes\n",1, shapes);

					shapes = 0;


		}

    fclose(stdin);



    return 0;
}
