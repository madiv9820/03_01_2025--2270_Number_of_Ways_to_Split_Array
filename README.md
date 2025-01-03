# [2270. Number of Ways to Split Array](https://github.com/madiv9820/03_01_2025--2270_Number_of_Ways_to_Split_Array)

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
            ```python3[]
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

- ## Approach 2:- Prefix Sum

    - ### Intuition
        The problem asks us to count how many valid ways we can split an array `nums` into two non-empty subarrays such that the sum of the left subarray is greater than or equal to the sum of the right subarray.

        #### Key Insight:
        Instead of recalculating the sum of the left and right subarrays from scratch at each split point (which would be inefficient), we can:
        1. Compute the sum of the entire array initially (the total sum of the right subarray).
        2. As we move through the array and consider each split point, we update the sum of the left subarray by adding the current element, and we update the sum of the right subarray by subtracting the current element.
        3. This way, we avoid redundant recalculations and can efficiently check whether the sum of the left subarray is greater than or equal to the sum of the right subarray at each potential split.

    - ### Approach
        1. **Precompute the total sum of the array**: 
            - First, calculate the sum of all elements in the array. This is the sum of the right subarray before any split.

        2. **Iterate through possible split points**:
            - For each potential split point (from index `0` to `n-2`), consider the array as split into two parts:
                - Left subarray: from index `0` to `index`.
                - Right subarray: from index `index+1` to `n-1`.
        
        3. **Update left and right sums**:
            - As you move through the array, update the left subarray sum (`leftSum`) by adding the current element (`nums[index]`).
            - Update the right subarray sum (`rightSum`) by subtracting the current element (`nums[index]`).
        
        4. **Check the validity of each split**:
            - If at any split point, the sum of the left subarray is greater than or equal to the sum of the right subarray (`leftSum >= rightSum`), count this split as valid.
        
        5. **Return the count of valid splits**:
            - After processing all potential split points, return the total number of valid splits.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
            class Solution {
            public:
                int waysToSplitArray(vector<int>& nums) {
                    int splitCount = 0;  // Counter to store the number of valid splits
                    int n = nums.size(); // Get the size of the array
                    
                    // Initialize leftSum and rightSum to 0
                    long long int leftSum = 0, rightSum = 0;

                    // Calculate the sum of the entire array and store it in rightSum
                    // Initially, the right subarray is the whole array
                    for(int index = 0; index < n; ++index) rightSum += nums[index];

                    // Loop through the array and consider each potential split point
                    for(int index = 0; index < n - 1; ++index) {
                        // Add the current element to the left subarray sum
                        leftSum += nums[index];
                        
                        // Subtract the current element from the right subarray sum
                        rightSum -= nums[index];

                        // If the sum of the left subarray is greater than or equal to the right,
                        // count this as a valid split
                        splitCount += ((leftSum >= rightSum) ? 1 : 0);
                    }

                    // Return the total number of valid splits
                    return splitCount;
                }
            };
            ```

    - ### Time Complexity
        - The solution involves two main operations:
            1. A single pass to compute the sum of the entire array ($O(n)$).
            2. A second pass to compute the left and right sums and check the condition at each potential split point ($O(n)$).
        
            Therefore, the overall time complexity is **$O(n)$**, where $n$ is the number of elements in the array.

    - ### Space Complexity
        - The algorithm only uses a few variables (such as `leftSum`, `rightSum`, and `splitCount`), which do not grow with the size of the input.
    
            Therefore, the space complexity is **$O(1)$**, meaning it uses constant extra space.