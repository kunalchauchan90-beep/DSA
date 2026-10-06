class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>freq;

        for(int x:nums){
            freq[x]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it:freq){
            int number=it.first;
            int count=it.second;

            bucket[count].push_back(number);
        }
        vector<int>ans;
        for(int i=bucket.size()-1;i>=0;i--){
            for(int x:bucket[i]){
                ans.push_back(x);

                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};