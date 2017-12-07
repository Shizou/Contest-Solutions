ans = 0
try:
    nums = [int(i) for i in input().strip().split('\t')]
    while nums:
        big = nums[0]
        small = nums[0]
        for i in nums:
            big = max(i, big)
            small =  min(i, small)
        ans += big-small
        nums = [int(i) for i in input().strip().split('\t')]
except:
    print(ans)
