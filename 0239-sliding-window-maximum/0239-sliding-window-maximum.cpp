class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<k;i++){
            // chote element ko remove kero 
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        // proccess remaining windows
        for(int i=k;i<nums.size();i++){
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            // ab firse chote elemnt ko remover kerna hai 
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);


            // current elemnt ko store kerna hai 
            ans.push_back(nums[dq.front()]);

        }
        return ans;
    }
};