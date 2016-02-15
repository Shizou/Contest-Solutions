#include <iostream>

using namespace std;

int main(){
    int x = 0, y = 0, currentX = 0,currentY = 0;
    int xSize = 0, ySize = 0;

    cin >> xSize >> ySize;

    while(true){
        cin >> x >> y;

        if(x == 0 && y == 0){
            break;
        }

        if(currentX + x >= 0 && currentX + x <= xSize){
            currentX += x;
        }
        else if( currentX + x <= 0){
            currentX = 0;
        }
        else if( currentX + x >= xSize){
            currentX = xSize;
        }

        if(currentY + y >= 0 && currentY + y <= ySize){
            currentY += y;
        }
        else if( currentY + y <=0){
            currentY = 0;
        }
        else if( currentY + y >= ySize){
            currentY = ySize;
        }

            cout << currentX << " " << currentY << endl;

    }



    return 0;
}
