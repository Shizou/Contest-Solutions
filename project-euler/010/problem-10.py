def isprime(n):
    i = 2
    while(i*i <= n):
        if(n % i == 0):
            return False
        else:
            i+=1
    return True

ans = 2
for i in range(3,2000000,2):
    if(isprime(i)):
        ans += i
print(ans)
