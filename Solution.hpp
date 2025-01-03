#include <vector>
using namespace std;

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