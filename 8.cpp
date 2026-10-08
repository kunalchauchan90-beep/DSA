class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int x : st) {

            // Agar x-1 nahi mila,
            // to x sequence ka starting point hai
            if(st.find(x - 1) == st.end()) {

                int current = x;
                int length = 1;

                // Next consecutive number check karo
                while(st.find(current + 1) != st.end()) {

                    current++;
                    length++;
                }

                // Maximum length update karo
                longest = max(longest, length);
            }
        }

        return longest;
    }
};