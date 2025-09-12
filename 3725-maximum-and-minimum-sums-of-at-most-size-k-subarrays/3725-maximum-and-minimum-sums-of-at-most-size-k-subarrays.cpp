class Solution {
public:
    long long getMinSum(const vector<int>& nums, int k) {
        long long minSum = 0LL;
        long long currSum = 0LL;
        deque<pair<long long, long long>> dq;         
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i >= k) {
                dq.front().second -= 1;
                currSum -= dq.front().first;
                if (dq.front().second == 0) {
                    dq.pop_front();
                }
            }        
            long long currLen = 1;
            currSum += nums[i];
            while (!dq.empty() && dq.back().first > nums[i]) {
                auto [prevVal, prevLen] = dq.back();
                dq.pop_back();
                currSum += (nums[i] - prevVal) * prevLen;
                currLen += prevLen;
            }
            dq.emplace_back(nums[i], currLen);
            minSum += currSum;
        }
        return minSum;
    }
    
    long long minMaxSubarraySum(const vector<int>& nums, int k) {
        long long minSum = getMinSum(nums, k);
        vector<int> negNums(nums.size());
        for (int i = 0; i < (int)nums.size(); i++) {
            negNums[i] = -nums[i];
        }
        long long maxSum = -getMinSum(negNums, k);
        return minSum + maxSum;
    }
};