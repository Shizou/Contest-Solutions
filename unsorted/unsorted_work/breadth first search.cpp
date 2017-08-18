#include <iostream>
#include <queue>
using namespace std;

struct state {
   int r, c, dist;
};

int row, col;
char G[101][101];

int sr, sc;
bool V[101][101] = {0};

int main() {
   cin >> row >> col;
   for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
       cin >> G[r][c];
       if (G[r][c] == 'S') { sr = r; sc = c; }
    }
   }
   queue< state > Q;
   Q.push( (state){sr, sc, 0} ); /* push the initial state! */
   while (!Q.empty()) {
      int r = Q.front().r;
      int c = Q.front().c;
      int d = Q.front().dist;
      Q.pop();
      /*check for base cases */
      if (r < 0 || r >= row || c < 0 || c >= col) /* out of bounds! */
         continue;
      if (G[r][c] == 'x') continue; /* obstacle! */
      if (V[r][c]) continue; /* already visited */
      V[r][c] = true; /* flag state as visited! */

      if (G[r][c] == 'F') {
         cout << "FOUND at: " << r << " " << c << endl;
         cout << "SHORTEST PATH IS " << d << endl;
         break;
      }
      Q.push((state){r-1, c, d+1});
      Q.push((state){r+1, c, d+1});
      Q.push((state){r, c-1, d+1});
      Q.push((state){r, c+1, d+1});
   }
   return 0;
}
