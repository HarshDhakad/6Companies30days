class Solution {
public:
unordered_map<string,int> mpp;
int f(int i,int jump,int k,bool canJump){
    
    if(i>k+1) return 0;
    string key = to_string(i)+"-"+to_string(jump)+"-"+to_string(canJump);
    if(mpp.find(key)!=mpp.end()) return mpp[key];
    int ways = 0;
    if(i == k) ways+=1;
    if(canJump){
        ways+=f(i-1,jump,k,false);
    }
    ways+=f(i+pow(2,jump),jump+1,k,true);
    return mpp[key] = ways;
}
    int waysToReachStair(int k) {
        return f(1,0,k,true);
    }
};
