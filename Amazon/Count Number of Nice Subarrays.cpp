class Solution {
public:
    int AtMostXOddNumber(vector<int> &nums,int k){
        int l=0,r=0;
        int sum=0,countOdd=0;
        while(r<nums.size()){
            sum+=(nums[r]%2);

            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            countOdd+=r-l+1;
            r++;
        }
        return countOdd;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtMostXOddNumber(nums,k)-AtMostXOddNumber(nums,k-1);
    }
};
