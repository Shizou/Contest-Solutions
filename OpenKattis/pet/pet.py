A = 0
B = 0
for i in range(1,6):
    b = map(int,input().split())
    cnt = 0
    for j in b:
        cnt += j
    if(cnt > B):
       A = i
       B = cnt
print(A,B)