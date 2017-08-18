n = input().split()
n = [int(i) for i in n]
while not (n[4] > n[3] > n[2] > n[1] > n[0]):
    if n[0] > n[1]:
        n[0], n[1] = n[1], n[0]
        print(n[0], n[1], n[2], n[3], n[4])
    if n[1] > n[2]:
        n[1], n[2] = n[2], n[1]
        print(n[0], n[1], n[2], n[3], n[4])
    if n[2] > n[3]:
        n[2], n[3] = n[3], n[2]
        print(n[0], n[1], n[2], n[3], n[4])
    if n[3] > n[4]:
        n[3], n[4] = n[4], n[3]
        print(n[0], n[1], n[2], n[3], n[4])