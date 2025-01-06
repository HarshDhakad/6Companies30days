class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size()<10) return result;
        unordered_map<string,int> mpp;
        for(int i=0;i<=s.size()-10;i++){
            string str=s.substr(i,10);
            mpp[str]++;
            if(mpp[str]==2) result.push_back(str);
        }
        return result;
    }
};
