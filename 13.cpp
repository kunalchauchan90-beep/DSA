class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Step 2: Reset slow to the starting point
        slow = nums[0];

        // Step 3: Find the entrance of the cycle (duplicate)
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Step 4: Return the duplicate number
        return slow;
    }
};