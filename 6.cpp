class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

         vector<int> ans(nums.size(), 1);
         int left = 1;

        // Left se right ja rahe hain
        for(int i = 0; i < nums.size(); i++) {

            // Current number ko include kiye bina
            // left side ka product ans mein store karo
            ans[i] = left;

            // Ab current number ko left product mein add karo
            left *= nums[i];
        }

        // Right side ka product
        int right = 1;

        // Right se left ja rahe hain
        for(int i = nums.size() - 1; i >= 0; i--) {

            // Current number ko include kiye bina
            // right side ka product ans mein multiply karo
            ans[i] *= right;

            // Ab current number ko right product mein add karo
            right *= nums[i];
        }
        return ans;
    }

};