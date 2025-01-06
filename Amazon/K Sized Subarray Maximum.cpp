class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        if(k==1) return arr;
        int n=arr.size();
        int currMax=0;
        map<int,int> mpp;
        vector<int> result;
        int j=0;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            currMax=max(currMax,arr[i]);
            
            if(i-j+1==k){
                result.push_back(currMax);
                mpp[arr[j]]--;
                if(mpp[arr[j]]==0){
                    mpp.erase(arr[j]);
                    if(arr[j]==currMax && mpp.size()>=1)
                    currMax=(--mpp.end())->first;
                }
                j++;
            }
        }
        return result;
    }
};
