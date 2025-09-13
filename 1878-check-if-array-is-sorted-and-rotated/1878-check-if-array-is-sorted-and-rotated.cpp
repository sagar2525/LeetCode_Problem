class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int countBreaks = 0;

        for (int i = 0; i < n; i++) {
            // Compare current with next (next wraps around using %)
            if (nums[i] > nums[(i + 1) % n]) {
                countBreaks++;
            }
            // More than one break → not sorted-rotated
            if (countBreaks > 1) return false;
        }
        return true;
    }
};
