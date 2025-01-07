class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(hash[i]==1){
                hash[i]=-1;
                cnt++;
            }
        }
        if(cnt==0) return -1;
        for(int i=0;i<s.size();i++){
            if(hash[s[i]-'a']==-1) return i;
        }
        return -1;
    }
};
