class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        set<long long> st;

        // Example:
        // nums = [4, 10, 4]
        // indexDiff = 2, valueDiff = 0
        // Initially: st = {}

        for (int i = 0; i < nums.size(); i++) {

            // i = 0: nums[0] = 4
            // i = 1: nums[1] = 10
            // i = 2: nums[2] = 4

            // Step 1: Minimum allowed value find karo
            long long low = (long long)nums[i] - valueDiff;

            // i = 0: low = 4 - 0 = 4
            // i = 1: low = 10 - 0 = 10
            // i = 2: low = 4 - 0 = 4

            // Step 2: Set mein low ya usse bada pehla element dhoondo
            auto it = st.lower_bound(low);

            // i = 0: set empty hai, it = st.end()
            // i = 1: set {4} hai, 10 ya bada element nahi mila
            // i = 2: set {4, 10} hai, lower_bound(4) = 4

            // Step 3: Check karo ki value allowed range mein hai
            if (it != st.end() &&
                *it <= (long long)nums[i] + valueDiff) {

                // i = 2:
                // it != st.end() -> true, kyunki 4 mil gaya
                // *it <= nums[i] + valueDiff
                // 4 <= 4 + 0 -> true

                return true; // Dono conditions true, answer mil gaya
            }

            // Step 4: Current number ko set mein add karo
            st.insert(nums[i]);

            // i = 0: st = {4}
            // i = 1: st = {4, 10}
            // i = 2: execute nahi hoga, kyunki return true ho gaya

            // Step 5: Purana element remove karke window maintain karo
            if (i >= indexDiff) {
                st.erase(nums[i - indexDiff]);
            }

            // i = 0: 0 >= 2 -> false
            // i = 1: 1 >= 2 -> false
            // i = 2: ye line execute nahi hogi
        }

        return false; // Koi valid pair nahi mila
    }
};