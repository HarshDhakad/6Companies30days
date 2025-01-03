class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0,cow=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) bull++;
            else mpp[secret[i]]++;
        }

        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i]){
                if(mpp[guess[i]]>0) {
                    mpp[guess[i]]--;
                    cow++;
                }
            }
        }
        return to_string(bull)+'A'+to_string(cow)+'B';
    }
};
