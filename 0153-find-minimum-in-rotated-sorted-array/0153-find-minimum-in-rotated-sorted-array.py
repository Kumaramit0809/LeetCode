class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        return nums[0]
        # left = 0
        # right = n-1


        # while left <= right:
        #     mid = (left+ right) // 2
        #     if(nums[mid] )