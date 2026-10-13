class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            //original no nikalo

            int x=abs(nums[i]);

            //corresponding se map kro
            int idx=x-1;

            // no phle se - hai to  ans m add kro

            if(nums[idx]<0){
                ans.push_back(x);
            } else{
                // phle baar mila h to -mark krdo
                nums[idx]=-nums[idx];
            }


        }
        return ans;
        
    }
};