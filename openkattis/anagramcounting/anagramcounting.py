import sys
# sys.stdin = open('input.txt')

def fac(n):
    ret = 1
    for i in range(1, n+1):
        ret *= i
    return ret

# input
for line in sys.stdin:
    for var in line.split():
        ln = list(var)
        ln.sort()
        mp = {}
        for i in ln:
            if(i not in mp):
                mp[i] = 1
            else:
                mp[i] += 1

        num = fac(len(ln))
        dem = 1
        for key in mp:
            dem *= fac(mp[key])
        print(num//dem)
        mp.clear()