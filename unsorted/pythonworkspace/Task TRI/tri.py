n = input().split()
n = [int(i) for i in n]
if n[0] == n[1] + n[2]:
    print(n[0], "=", n[1], '+', n[2], sep="")
elif n[0] == n[1] - n[2]:
    print(n[0], "=", n[1], '-', n[2], sep="")
elif n[0] == n[1] * n[2]:
    print(n[0], "=", n[1], '*', n[2], sep="")
elif n[0] == n[1] / n[2]:
    print(n[0], "=", n[1], '/', n[2], sep="")
elif n[2] == n[0] + n[1]:
    print(n[0], "+", n[1], '=', n[2], sep="")
elif n[2] == n[0] - n[1]:
    print(n[0], "-", n[1], '=', n[2], sep="")
elif n[2] == n[0] * n[1]:
    print(n[0], "*", n[1], '=', n[2], sep="")
elif n[2] == n[0] / n[1]:
    print(n[0], "/", n[1], '=', n[2], sep="")
