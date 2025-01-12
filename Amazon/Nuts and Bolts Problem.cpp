class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
       vector<char> symbols={'!','#','$','%','&','*','?','@','^'};
       
       unordered_map<char,int> rank;
       
       for(int i=0;i<symbols.size();i++){
           rank[symbols[i]]=i;
       }
       
       sort(bolts,bolts+n,[&](char a1,char a2){
           return rank[a1]<rank[a2];
       });
        sort(nuts,nuts+n,[&](char a1,char a2){
           return rank[a1]<rank[a2];
       });
       
    }
};
