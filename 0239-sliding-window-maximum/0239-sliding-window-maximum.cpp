class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // first window ke chote element ko proccess kerna hai 
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        // ab baki bachi hui windows ko proccess kerna hai
        for(int i=k;i<nums.size();i++){
            // check kerna hai ki nums[i] bada hai kya queue ke element se 
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            // firse chote ko remove kerna hai
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;

    }
};