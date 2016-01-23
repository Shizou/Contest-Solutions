lst = input().split()
H = int(lst[0])+1
N = 2**(H)-1
S = ''
if(len(lst) > 1):
   S = str(lst[1])

n = 0
for i in range(len(S)):
    if(S[i] == 'L' and 2*n+1 < N):
       n = 2*n+1
    elif(2*n+2 < N):
       n = 2*n+2
print(N-n)