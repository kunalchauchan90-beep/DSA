class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> mp;
        int count = 0;

        // Step 1: Store all pair sums of nums1 and nums2
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                mp[sum]++;
            }
        }

        // Step 2: Find opposite pair sums in nums3 and nums4
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int sum = nums3[i] + nums4[j];
                int need = -sum;

                if (mp.find(need) != mp.end()) {
                    count += mp[need];
                }
            }
        }

        return count;
    }
};