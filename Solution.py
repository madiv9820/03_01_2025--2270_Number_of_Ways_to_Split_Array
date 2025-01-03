from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        splitCount = 0  # Counter to keep track of the number of valid splits
        n = len(nums)   # Get the length of the array

        # Loop through the array, considering each potential split point
        for index in range(n-1):
            leftSum = rightSum = 0  # Initialize sums for the left and right subarrays
            
            # Calculate the sum of the left subarray (from index to 0)
            for leftPtr in range(index, -1, -1): leftSum += nums[leftPtr]
            
            # Calculate the sum of the right subarray (from index+1 to n-1)
            for rightPtr in range(index + 1, n): rightSum += nums[rightPtr]
            
            # If the sum of the left subarray is greater than or equal to the sum of the right,
            # count this as a valid split
            splitCount += 1 if leftSum >= rightSum else 0

        return splitCount  # Return the total number of valid splits