/// Time-> O(n) 
// Space-> O(n)
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // LIS (Longest Increasing Subsequence)
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                LIS[i] = LIS[i - 1] + 1;
            }
        }

        // LDS (Longest Decreasing Subsequence)
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                LDS[i] = LDS[i + 1] + 1;
            }
        }

        int len = 0;

        // Find the longest mountain
        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {
                len = max(len, LIS[i] + LDS[i] - 1);
            }
        }
        return len;
    }
};



// ## 2nd Approch 


