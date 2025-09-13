class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int countBreaks = 0;

        // check breaks inside array
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                countBreaks++;
            }
            if (countBreaks > 1) return false;
        }

        // check last element with first (wrap around)
        if (nums[n - 1] > nums[0]) {
            countBreaks++;
        }

        return countBreaks <= 1;
    }
};
