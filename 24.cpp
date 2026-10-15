class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;

        mp[0]=-1;

        int sum=0;
        int maxi=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
            }else{
                sum--;
            }

            if(mp.find(sum)!=mp.end()){
                int lenght=i-mp[sum];

                maxi=max(maxi,lenght);
            }else{
                mp[sum]=i;
            }
        }
    
        return maxi;
    }
};