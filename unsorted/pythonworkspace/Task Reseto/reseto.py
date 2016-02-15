def find_k():
    cnt = 0
    for x in range(2, n+1):
        if arr[x] != 0:
            for y in range(x, n+1, x):
                if arr[y] == 0:
                    continue
                cnt += 1
                arr[y] = 0
                if cnt == k:
                    return y

n, k = map(int, input().split())
arr = [i for i in range(0, n+2)]
print(find_k())
