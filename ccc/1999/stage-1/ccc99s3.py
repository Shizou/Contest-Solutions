import sys
sys.stdin = open("input.txt")

def print_grid(grid):
    print(len(grid))
    for i in grid:
        for j in i:
            print(j,'' ,end='')
        print()
    print()


def rec(grid, r, c, n):
    if(n >= 1):
        pivot = int(3**(n-1))
        # clearing out the middle of the square
        for i in range(pivot):
            for j in range(pivot):
                grid[r+i][c+j] = ' '
        # recursive parts

        # left 3 squares
        rec(grid, r-2*pivot//3, c-2*pivot//3, n-1)
        rec(grid, r+pivot//3, c-2*pivot//3, n-1)
        rec(grid, r+pivot+pivot//3, c-2*pivot//3, n-1)

        # middle 2 squares
        rec(grid, r-2*pivot//3, c+pivot//3, n-1)
        rec(grid, r+pivot+pivot//3, c+pivot//3, n-1)

        # right 3 squares
        rec(grid, r-2*pivot//3, c+pivot+pivot//3, n-1)
        rec(grid, r+pivot//3, c+pivot+pivot//3, n-1)
        rec(grid, r+pivot+pivot//3, c+pivot+pivot//3, n-1)



D = int(input())
for d in range(D):
    n = int(input())
    b = int(input())-2
    t = int(input())-1
    l = int(input())-1
    r = int(input())
    grid = [['*' for j in range(int(3**n))] for i in range(int(3**n))]
    rec(grid, int(3**(n-1)), int(3**(n-1)), n)
    #print_grid(grid)
    for i in range(t, b,-1):
        for j in range(l, r):
            print(grid[i][j],'', end='')
        print()
    print()
