class Solution {
public:
    int joseph(vector<int> &v,int start,int k){
        if(v.size()==1) return v[0];

        start=(start+k-1)%(v.size());
	    v.erase(v.begin()+start);
	    return joseph(v,start,k);
    }
    int findTheWinner(int n, int k) {
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i]=i;
        }
        int winner=joseph(vec,0,k);
        return winner+1;
    }
};
