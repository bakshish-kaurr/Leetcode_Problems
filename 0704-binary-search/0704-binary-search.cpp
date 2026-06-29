class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == tar) {
                return m;
            }
            else if (nums[m] < tar) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};