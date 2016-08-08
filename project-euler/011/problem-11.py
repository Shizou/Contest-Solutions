file = open("input.txt")
grid = []
for x in file:
   grid.append(x.strip().split(" "))
for i in range(20):
    for j in range(20):
        grid[i][j] = int(grid[i][j])

best = 0
for i in range(20):
    for j in range(20):
        if(i+3 < 20):
           best = max(best,grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j])
        if(i-3 >= 0):
           best = max(best,grid[i][j]*grid[i-1][j]*grid[i-2][j]*grid[i-3][j])
        if(j+3 < 20):
           best = max(best,grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3])
        if(j-3 >= 0):
           best = max(best,grid[i][j]*grid[i][j-1]*grid[i][j-2]*grid[i][j-3])
        if(i+3 < 20 and j+3 < 20):
           best = max(best,grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3])
        if(i-3 >= 0 and j-3 >= 0):
           best = max(best,grid[i][j]*grid[i-1][j-1]*grid[i-2][j-2]*grid[i-3][j-3])
        if(i+3 < 20 and j-3 >= 0):
           best = max(best,grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3])
        if(i-3 >= 0 and j+3 < 20):
           best = max(best,grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3])
        
for i in range(20):
    print(grid[i])
print(best)
