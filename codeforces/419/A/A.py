
def pallindrome(a,b):
    # print(a,b)
    a_str = ''
    b_str = ''
    if a <= 9:
        a_str += "0"
    if b <= 9:
        b_str += "0"
    a_str += str(a)
    b_str += str(b)
    fwd = a_str+b_str
    # print(a_str+b_str, b_str+a_str)
    return fwd == fwd[::-1] 

if __name__ == '__main__':
    a,b = map(int, str(input()).split(':'))
    cnt = 0
    while not pallindrome(a,b):
       cnt += 1
       if b+1 <= 59:
           b = b+1
           if pallindrome(a,b):
               break
       else:
           b = 0
           a = (a+1)%24
           if pallindrome(a,b):
               break
    print(cnt)
