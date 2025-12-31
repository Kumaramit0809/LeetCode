class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # sort array
        n = len(nums)
        res = []
        for i in range (n):
            if i > 0 and nums[i] == nums[i - 1]: # check i >0 and
                continue
            left = i + 1
            right = n - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total == 0: 
                    res.append([nums[i], nums[left], nums[right]])

                    
                    while(left < right and nums[left] == nums[left+1]):
                        left += 1
                    while(left < right and nums[right] == nums[right-1]):
                        right -= 1
                
                    left += 1
                    right -= 1
                elif total < 0:
                    left += 1
                else: 
                    right -= 1

                
        return res
