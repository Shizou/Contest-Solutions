N = int(input())
g = [input() for i in range(0, N)]
v = [[False for i in range(N)] for j in range(N)]
v2 = [[False for i in range(N)] for j in range(N)]
rgb = [0, 0, 0]
rg_b = [0, 0]
c = ''


def b(x, y):
    if x < 0 or y < 0 or x > N-1 or y > N-1:
        return
    if g[x][y] != 'B':
        return
    if v[x][y]:
        return
    v[x][y] = v2[x][y] = True
    b(x+1, y)
    b(x, y+1)
    b(x-1, y)
    b(x, y-1)


def r_or_g(x, y):
    if x < 0 or y < 0 or x > N-1 or y > N-1:
        return
    if g[x][y] != c:
        return
    if v[x][y]:
        return
    v[x][y] = True
    r_or_g(x+1, y)
    r_or_g(x, y+1)
    r_or_g(x-1, y)
    r_or_g(x, y-1)


def r_and_g(x, y):
    if x < 0 or y < 0 or x > N-1 or y > N-1:
        return
    if g[x][y] == 'B':
        return
    if v2[x][y]:
        return
    v2[x][y] = True
    r_and_g(x+1, y)
    r_and_g(x, y+1)
    r_and_g(x-1, y)
    r_and_g(x, y-1)

#main
for i in range(N):
    for j in range(N):
        if g[i][j] == 'B':
            if not v[i][j]:
                rgb[2] += 1
                rg_b[1] += 1
                b(i, j)
        elif g[i][j] == 'R':
            if not v[i][j]:
                rgb[0] += 1
                c = g[i][j]
                r_or_g(i, j)
            if not v2[i][j]:
                rg_b[0] += 1
                r_and_g(i, j)
        elif g[i][j] == 'G':
            if not v[i][j]:
                rgb[1] += 1
                c = g[i][j]
                r_or_g(i, j)
            if not v2[i][j]:
                rg_b[0] += 1
                r_and_g(i, j)

ans = rgb[0]+rgb[1]+rgb[2]
ans2 = rg_b[0]+rg_b[1]
print(ans, ans2)