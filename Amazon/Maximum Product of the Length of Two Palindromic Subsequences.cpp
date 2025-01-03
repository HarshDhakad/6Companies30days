class Solution {
public:
//with memoization
    bool isPallindrome(string s){
        string rev=s;
        reverse(s.begin(),s.end());
        return s==rev;
    }

    unordered_map<string,int> mpp;

    int find(int index,string &s,string s1,string s2){
        if(index==s.size()){
            if(s1.size() && s2.size() && isPallindrome(s1) && isPallindrome(s2))
            return s1.size()*s2.size();
            return 0;
        }

        string key=to_string(index)+"#"+s1+"#"+s2;

        if(mpp.find(key)!=mpp.end()) return mpp[key];


        int a,b,c;
        // take that elemenet in s1
        a=find(index+1,s,s1+s[index],s2);

        //take that element in s2
        b=find(index+1,s,s1,s2+s[index]);

        // donot take that element
        c=find(index+1,s,s1,s2);

        return mpp[key]=max({a,b,c});
    }
    int maxProduct(string s) {
        return find(0,s,"","");
    }
};
