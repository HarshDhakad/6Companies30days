class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        int n=nums.size();
        int i=1,j=n-1;


        while(j>=0){
            if(i<n){
                nums[i]=sorted[j];
            }
            else{
                i=0;
                nums[i]=sorted[j];
            }
            i+=2;
            j--;
        }

    }
};
