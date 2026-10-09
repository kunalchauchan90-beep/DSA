class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
        // Initially vector aur map empty hain
    }

    bool insert(int val) {
        // Agar value already present hai
        if(mp.find(val) != mp.end()) {
            return false;
        }

        // Value ko vector ke end mein add karo
        nums.push_back(val);

        // Value ka index map mein store karo
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        // Agar value present nahi hai
        if(mp.find(val) == mp.end()) {
            return false;
        }

        // Delete hone wali value ka index
        int index = mp[val];

        // Vector ka last element
        int last = nums.back();

        // Last element ko delete hone wali value ki jagah rakho
        nums[index] = last;

        // Map mein last element ka index update karo
        mp[last] = index;

        // Vector se last element remove karo
        nums.pop_back();

        // Deleted value ko map se remove karo
        mp.erase(val);

        return true;
    }

    int getRandom() {
        // Random valid index choose karo
        int index = rand() % nums.size();

        return nums[index];
    }
};