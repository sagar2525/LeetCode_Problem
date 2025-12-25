class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>map;

        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            map[val].push_back(i);
        }

        for(int i=0;i<nums.size();i++){
            int current = nums[i];
            int required = target - nums[i];
            if(map.find(required) != map.end()){
                if(required == current  && map[current].size() == 1){
                    continue;
                }
                if(required == current && map[current].size()>1){
                    return {map[current][0] , map[current][1]};
                }
                else{
                    return {i,map[required][0]};
                }
            }
        }
        return{-1,-1};

    }
};