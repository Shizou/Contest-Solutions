DP = {1:1}

def collatz_sequence(n):
    if(n in DP):
        return DP[n]
    else:
        if(n%2 == 0):
            DP[n] = 1+collatz_sequence(n/2)
        else:
            DP[n] = 1+collatz_sequence(3*n+1)
        return DP[n]

best = 0
it = 0
for i in range(1, 1000000):
    sequence = collatz_sequence(i)
    if(sequence > best):
        best = sequence
        it = i

print(it,best)
