class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int candidate1 = 0;
        int candidate2 = 0;

        int count1 = 0;
        int count2 = 0;

        // First pass:
        // Possible majority candidates find karo
        for(int x : nums) {

            // Agar x candidate1 ke equal hai
            if(x == candidate1) {
                count1++;
            }

            // Agar x candidate2 ke equal hai
            else if(x == candidate2) {
                count2++;
            }

            // Agar candidate1 ka count zero hai
            // to x ko candidate1 bana do
            else if(count1 == 0) {
                candidate1 = x;
                count1 = 1;
            }

            // Agar candidate2 ka count zero hai
            // to x ko candidate2 bana do
            else if(count2 == 0) {
                candidate2 = x;
                count2 = 1;
            }

            // Dono candidates se different hai
            // to dono ko ek-ek cancel karo
            else {
                count1--;
                count2--;
            }
        }

        // Second pass:
        // Candidates ki actual frequency count karo
        count1 = 0;
        count2 = 0;

        for(int x : nums) {

            if(x == candidate1) {
                count1++;
            }

            else if(x == candidate2) {
                count2++;
            }
        }

        vector<int> ans;

        // Actual condition check karo
        if(count1 > nums.size() / 3) {
            ans.push_back(candidate1);
        }

        if(count2 > nums.size() / 3) {
            ans.push_back(candidate2);
        }

        return ans;
    }
};