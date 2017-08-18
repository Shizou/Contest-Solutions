def sn(n):
    dig_sum = 0
    while n != 0:
        dig_sum += n % 10
        n /= 10
    return dig_sum % 2 == 0


def sp(n):
    last = n % 10
    n /= 10
    while n != 0:
        if n % 10 >= last:
            return False
        else:
            last = n % 10
            n /= 10
    return True


def aw(n):
    for i in range(2, n, 1):
        if n % (i*i) == 0:
            return False
    return True


# main
for j in range(5):
    a, b = map(int, raw_input().strip().split())
    cnt = 0
    while a <= b:
        if sn(a) and sp(a) and aw(a):
            cnt += 1
        a += 1
    print(cnt)