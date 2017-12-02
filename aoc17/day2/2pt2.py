ans = 0
try:
    nums = [int(i) for i in input().strip().split('\t')]
    while nums:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] > nums[j] and i != j  and nums[i] % nums[j] == 0:
                    ans += nums[i]//nums[j] 
        nums = [int(i) for i in input().strip().split('\t')]
except:
    print(ans)
