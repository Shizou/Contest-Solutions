#!/bin/python3


def is_sorted(arr):
    for i in range(1, len(arr)):
        if arr[i] > arr[i-1]:
            continue
        else:
            return False
    return True

T = int(input())
for t in range(T):
    vals = list(map(int, input().split()))
    n = vals[0]
    arr = vals[1:]
    for i in range(1, n):
        compl = arr[:i] + arr[i+1:]
        is_sorted_comp1 = is_sorted(compl)
        if(is_sorted_comp1):
            print(i+1)
            break
