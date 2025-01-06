class Solution {
public:
    bool isIncremovable(vector<int> &nums,int i,int j){
        int prev=-1;
        for(int low=0;low<nums.size();low++){
            if(low<i || low>j){
                if(nums[low]<=prev) return false;
                prev=nums[low];
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isIncremovable(nums,i,j)) count++;
            }
        }
        return count;
    }
};
