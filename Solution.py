from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        splitCount = 0  # Counter to keep track of the number of valid splits
        n = len(nums)   # Get the length of the array

        # Initialize leftSum and rightSum to 0
        leftSum = rightSum = 0
        
        # Calculate the sum of the entire array and store it in rightSum
        # Initially, the right subarray is the whole array
        for index in range(n): rightSum += nums[index]

        # Loop through the array, considering each potential split point
        for index in range(n - 1):  # We go up to n-1 because both subarrays must be non-empty
            leftSum += nums[index]  # Add the current element to the left subarray sum
            rightSum -= nums[index]  # Subtract the current element from the right subarray sum
            
            # If the sum of the left subarray is greater than or equal to the sum of the right,
            # count this as a valid split
            splitCount += 1 if leftSum >= rightSum else 0

        return splitCount  # Return the total number of valid splits