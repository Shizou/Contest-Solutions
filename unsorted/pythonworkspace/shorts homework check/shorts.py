inf = 1000000
SIZE = 10000
SIZE2D = 1000
memo = [inf for i in range(SIZE)]
memo2 = [inf for i in range(SIZE)]
memo2D = [[inf for i in range(SIZE2D)] for j in range(SIZE2D)]


def f(x):
    if x >= 6:
        if memo[x] != inf:
            return memo[x]
        else:
            memo[x] = 2*f(b(2))
            return memo[x]
    elif 2 <= x <= 5:
        if memo[x] != inf:
            return memo[x]
        else:
            memo[x] = f(x-1) + 3*b(x) + 2*b(x-2) - 4*b(x-3)
            return memo[x]
    elif x <= 1:
        if memo[x] != inf:
            return memo[x]
        else:
            memo[x] = 1
            return memo[x]


def b(x):
    if x >= 2:
        if memo2[x] != inf:
            return memo2[x]
        else:
            memo2[x] = 3 + 2*b(x-1)
            return memo2[x]
    elif x <= 1:
        return 1


xin = int(input())
print(f(xin))
#xin, yin = map(int, input().split())
#print(f2(xin, yin))
