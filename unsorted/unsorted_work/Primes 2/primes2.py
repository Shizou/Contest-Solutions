max_n = 1000005
v = [True]*max_n


def sieve_of_erathonese():
    v[0] = False
    v[1] = False
    for i in range(2, max_n):
        if v[i]:
            for j in range(i*i, max_n-1, i):
                v[j] = False


def palindrome(i):
    num = i
    rev = 0
    dig = 0
    while num > 0:
        dig = num % 10
        rev = rev * 10 + dig
        num /= 10
    return rev == i

#main
sieve_of_erathonese()
for t in range(5):
    s = int(input())
    e = int(input())
    cnt = 0
    for it in range(s, e):
        if v[it] and palindrome(it):
            cnt += 1
    print(cnt)