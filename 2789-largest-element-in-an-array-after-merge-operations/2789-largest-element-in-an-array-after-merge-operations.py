class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        n = len(nums)
        curr_sum = nums[-1]
        merge_sum = curr_sum

        for i in range (n-2,-1,-1):
            if nums[i] <= curr_sum:
                curr_sum += nums[i]
            else:
                curr_sum = nums[i]
            
            merge_sum = max(merge_sum, curr_sum)
        
        return merge_sum
