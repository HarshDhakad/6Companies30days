class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sorting Width in Increasing Order & Height in Decreasing Order
        sort(envelopes.begin() , envelopes.end() , [](vector<int>& a , vector<int>& b)
        {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        // Extracting the Heights
        vector<int> second;
        for(auto& it : envelopes)
            second.push_back(it[1]);
  
        vector<int> lis;
        lis.push_back(second[0]);
        for(int i = 1 ; i < second.size() ; i++)
        {
            // greater than the last element in LIS
            if(lis.back() < second[i])
            {
                lis.push_back(second[i]);
            }
            else
            {
                // finding the first element in LIS that is greater than or equal the Current Height
                auto it = lower_bound(lis.begin() , lis.end() , second[i]);
                *it = second[i];
            }
        }
        return lis.size();
    }
};
