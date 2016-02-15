s = raw_input().strip()
best = '~'
for i in range(1, len(s)):
    for j in range(i+1, len(s)):
        s1 = s[0:i]
        s2 = s[i:j]
        s3 = s[j:]
        s1 = s1[::-1]
        s2 = s2[::-1]
        s3 = s3[::-1]
        b = s1+s2+s3
        if b < best:
            best = b
print(best)