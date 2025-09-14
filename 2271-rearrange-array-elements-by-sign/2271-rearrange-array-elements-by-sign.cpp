class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }

        for(int i=0;i<v1.size();i++){
            arr.push_back(v2[i]);
            arr.push_back(v1[i]);
            
        }

        for(int i=0;i<nums.size();i++){
            nums[i] = arr[i];
        }
        return nums;
    }
};