class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // Initialize the first missing number to 1.
        int patches = 0;    // Number of patches needed.
        int i = 0;          // Index to iterate through the input vector nums.
        
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // If nums[i] is less than or equal to the current missing number, 
                // extend the range by adding nums[i] to it.
                miss += nums[i];
                i++;
            } else {
                // If nums[i] is greater than the current missing number,
                // add the current missing number to the array and update the missing number.
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};
