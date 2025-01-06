class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //find median element
        sort(nums.begin(),nums.end());

        int x=nums[nums.size()/2];  //median element

        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+=abs(nums[i]-x);
        }
        return moves;
    }
};
