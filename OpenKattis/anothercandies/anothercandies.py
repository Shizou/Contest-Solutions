T = int(input())
for t in range(T):
   g = input()
   N = int(input())
   C = 0
   for i in range(N):
       c = int(input())
       C += c
   if(C % N == 0):
      print('YES')
   else:
    print('NO')