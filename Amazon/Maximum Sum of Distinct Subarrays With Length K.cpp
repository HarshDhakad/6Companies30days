class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum=0;
        long long sum=0;
        int n=nums.size(),j=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            while(st.count(nums[i])){
                sum-=nums[j];
                st.erase(nums[j]);
                j++;
            }

            st.insert(nums[i]);
            sum+=nums[i];

            if(i-j+1 > k){
                st.erase(nums[j]);
                sum-=nums[j];
                j++;
            }
            if(i-j+1==k){
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};
