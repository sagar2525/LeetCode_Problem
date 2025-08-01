class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>>&ans,int index){
    // base case 
    if(index==nums.size()-1){
        ans.push_back(nums);
        return;
    }
    //ek case
    for(int i=index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        solve(nums,ans,index+1);
        swap(nums[i],nums[index]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(nums,ans,0);
        set<vector<int>> st;
        for(auto e : ans){
            st.insert(e);
        }
        ans.clear();
        for(auto e:st){
            ans.push_back(e);
        }
        return ans;
    }
};