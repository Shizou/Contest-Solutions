def sieve(N,K):
    v = [True for i in range(0,N+2)]
    cnt = 0
    for i in range(2,N+1):
       if(v[i]):
          for j in range(i,N+1,i):
              if(v[j]):
                 cnt+=1
              v[j] = False
              if(cnt == K):
                 return j

N,K = map(int,input().split())
print(sieve(N,K))