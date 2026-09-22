class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        k = len(nums)
        prefix = [0]*k
        suffix = [0]*k
        prefix[0]=1
        suffix[len(nums)-1] = 1;
        for i in range(1,len(nums),1):
            prefix[i] = prefix[i-1] * nums[i-1]
        for i in range(len(nums)-2,-1,-1):
            suffix[i] = suffix[i+1]*nums[i+1]
        res=[0]*k
        for i in range(len(nums)):
            res[i]=prefix[i]*suffix[i]
        return res
