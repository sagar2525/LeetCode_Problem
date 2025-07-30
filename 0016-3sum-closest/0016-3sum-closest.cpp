class Solution {
public:
void solve(vector<int>& nums, int target,int &ans){
    int n = nums.size();
    int temp1=0;
    int mini=INT_MAX;
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                temp = (nums[i]+nums[j]+nums[k]);
                temp1 = abs(temp-target);
                // mini = min(temp1,mini);
                if(temp1<mini){
                    mini = temp1;
                    ans = temp;
                }
            }
        }
    }
}
    int threeSumClosest(vector<int>& nums, int target) {
        int ans =0;
        solve(nums,target,ans);
        return ans;
    }
};