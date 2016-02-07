#include<bits/stdc++.h>
using namespace std;

char grid[250][250];

int POW(int b, int p)
{
    int ret = 1;
    for(int i = 1;i <= p;i++)
    {
        ret *= b;
    }
    return ret;
}

void print_grid(int n)
{
   n = POW(3,n);
   for(int i = 0;i < n;i++)
   {
      for(int j = 0;j < n;j++)
      {
          cout << grid[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

void rec(int r, int c, int n)
{
    if(n >= 1)
    {
        int pivot = POW(3, n-1);
        for(int i = 0;i < pivot;i++)
        {
            for(int j = 0;j < pivot;j++)
            {
                grid[r+i][c+j] = ' ';
            }
        }
        // recursive parts

        // left 3 squares
        rec(r-2*pivot/3, c-2*pivot/3, n-1);
        rec(r+pivot/3, c-2*pivot/3, n-1);
        rec(r+pivot+pivot/3, c-2*pivot/3, n-1);

        // middle 2 squares
        rec(r-2*pivot/3, c+pivot/3, n-1);
        rec(r+pivot+pivot/3, c+pivot/3, n-1);

        // right 3 squares
        rec(r-2*pivot/3, c+pivot+pivot/3, n-1);
        rec(r+pivot/3, c+pivot+pivot/3, n-1);
        rec(r+pivot+pivot/3, c+pivot+pivot/3, n-1);
    }
}

int main()
{
  freopen("input.txt","r",stdin);
  int D; cin >> D;
  for(int d = 0;d < D;d++)
  {
     int n,b,t,l,r;
     cin >> n >> b >> t >> l >> r;
     b--;
     t--;
     l--;
     memset(grid, '*', sizeof(grid));
     rec(POW(3,n-1),POW(3,n-1), n);
     // print_grid(n);
     for(int i = t;i >= b;i--)
     {
         for(int j = l;j < r;j++)
         {
             cout << grid[i][j] << " ";
         }
         cout << endl;
     }
     cout << endl;
     //print_grid(n);
  }
  return 0;
}
