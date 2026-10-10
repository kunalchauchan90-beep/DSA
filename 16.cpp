class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> ans;

        // Step 1: Store nums1 elements in set
        for (int i = 0; i < nums1.size(); i++) {
            st.insert(nums1[i]);
        }

        // Step 2: Check nums2 elements in set
        for (int i = 0; i < nums2.size(); i++) {
            if (st.find(nums2[i]) != st.end()) {
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }

        // Step 3: Return common unique elements
        return ans;
    }
};