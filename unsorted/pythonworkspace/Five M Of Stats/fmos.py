import math
n = int(input())
arr = []
stf = [0, 0, 0, -1001, 1001]
for x in range(0, n):
    arr.append(float(input()))
    stf[0] += arr[x]
    stf[3] = max(stf[3], arr[x])
    stf[4] = min(stf[4], arr[x])

stf[0] /= n
arr.sort()
if n % 2 != 0:
    stf[1] = arr[int(n/2)]
else:
    stf[1] = (arr[int(n/2)-1] + arr[int(n/2)])/2

for x in range(0, n-1):
    if arr[x] == arr[x+1]:
        stf[2] = arr[x]
        break

for x in range(0, 5):
    print('%.2f' % stf[x])


