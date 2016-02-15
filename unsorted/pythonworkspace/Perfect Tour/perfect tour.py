N, M = map(int, raw_input().strip().split())
best = [-101 for i in range(0, 20000)]
for i in range(M):
    a = [input().strip().split()]