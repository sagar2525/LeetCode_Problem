class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
    
        // for(int i =0;i<nums.size();i++){
        //     int val = nums[i];
        //     m[val] = i;
        // }
        
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            int required = target- curr;
            if(m.find(required) !=m.end()){
                return {i,m[required]};
            }
            m[curr] = i;
        }
        return {-1,-1};
    }
};