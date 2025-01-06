
class Solution {
public:
    bool isPresent(int i,int j,int n,int m){
        return ((i<n and i>=0 ) and (j<m and j>=0));
    }
    int getAvg(vector<vector<int>>&img,int i,int j,int n,int m){
        int sum = 0;
        int cnt = 0;
        for(int x = -1 ; x <=1 ;x++){
            for(int y=-1;y<=1;y++){
                if(isPresent(i+x,y+j,n,m)){
                    sum+=img[i+x][j+y];
                    cnt++;
                }
            }
        }
        return sum/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int avg = getAvg(img,i,j,n,m);
                ans[i][j] = avg;
            }
        }
        return ans;
    }
};
