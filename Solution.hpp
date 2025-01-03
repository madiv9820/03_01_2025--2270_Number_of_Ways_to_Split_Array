#include <vector>
using namespace std;

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