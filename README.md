- ## Approach 1: Brute Force

    - ### Intuition
        The problem is asking for the number of valid ways to split an array `nums` into two non-empty subarrays such that the sum of the elements in the left subarray is greater than or equal to the sum of the elements in the right subarray.

        #### Key Insight:
        To solve this problem, we can consider every possible position where we can "split" the array into two subarrays. For each split, we calculate the sum of the left and right subarrays, and check if the left sum is greater than or equal to the right sum.

        We do this for each potential split from the beginning of the array until the second-to-last element, as both subarrays must be non-empty.

    - ### Approach
        1. **Iterate over possible split points**: 
        We loop through all possible split points from index `0` to `n-2`, where `n` is the length of the array. For each split point, we divide the array into two parts:
            - Left subarray: from the start of the array up to the current split point.
            - Right subarray: from the next element after the current split point to the end of the array.
        
        2. **Calculate sums**: 
        For each split point, calculate the sum of the elements in the left subarray and the right subarray.

        3. **Check condition**: 
        If the sum of the left subarray is greater than or equal to the sum of the right subarray, count it as a valid split.

        4. **Return result**: 
        Finally, return the total number of valid splits.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
            class Solution {
            public:
                int waysToSplitArray(vector<int>& nums) {
                    int splitCount = 0;  // Counter to store the number of valid splits
                    int n = nums.size(); // Get the size of the array

                    // Loop through the array and consider each potential split point
                    for(int index = 0; index < n-1; ++index) {
                        // Initialize pointers for the left and right subarrays
                        int leftPtr = index, rightPtr = index + 1;
                        
                        long long int leftSum = 0, rightSum = 0; // Initialize sums of the left and right subarrays

                        // Compute the sum of the left subarray (from 0 to index)
                        for(; leftPtr >= 0; --leftPtr) leftSum += nums[leftPtr];
                        
                        // Compute the sum of the right subarray (from index+1 to n-1)
                        for(; rightPtr < n; ++rightPtr) rightSum += nums[rightPtr];

                        // If the sum of the left subarray is greater than or equal to the right,
                        // count this as a valid split
                        splitCount += ((leftSum >= rightSum) ? 1 : 0);
                    }

                    return splitCount; // Return the total number of valid splits
                }
            };
            ```

    - ### Time Complexity
        - **Naive Approach**: For each split index, we are calculating the sum of the left subarray and the right subarray by iterating over the respective parts of the array.
        - **Time Complexity**: The solution involves two nested loops. The outer loop runs `n-1` times (since we iterate through all possible split points from index `0` to `n-2`). For each split point, the inner loops calculate the sum of the left and right subarrays, each taking $O(n)$ time in the worst case.

            Thus, the overall time complexity is **$O(n^2)$**, where $n$ is the number of elements in the array.

    - ### Space Complexity
        - **Space Complexity**: The algorithm only uses a few extra variables (such as `splitCount`, `leftSum`, and `rightSum`), and no additional data structures are used that scale with input size.
        
            Thus, the space complexity is **$O(1)$** (constant space).