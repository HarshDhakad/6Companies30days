class Solution {
public:
    string solve(int n){
        if(n<=26) {char ch=('A'+(n-1)) ; return string(1,ch);}
        n--;
        int rem=n%26;
        return solve(n/26)+string(1,'A'+rem);
    }
    string convertToTitle(int columnNumber){
        return solve(columnNumber);
    }
};
