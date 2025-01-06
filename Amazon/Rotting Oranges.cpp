class Solution {
public:
int bfs(vector<vector<int>> grid){
	int n=grid.size();
	int m=grid[0].size();
	int visited[n][m];
	//{{ROW,COL},TIME}
	queue<pair<pair<int,int>,int>> q;
	int cntfresh=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==2){
				visited[i][j]=2;
				q.push({{i,j},0});
			}
			else{
				visited[i][j]=0;
			}
			if(grid[i][j]==1)
			cntfresh++;
		}
	}
	
	int tm=0;
	int cnt=0;
	int delrow[]={0,-1,0,1};
	int delcol[]={-1,0,1,0};
	while(!q.empty()){
		int row=q.front().first.first;
		int col=q.front().first.second;
		int t=q.front().second;
		tm=max(tm,t);
		q.pop();
		for(int i=0;i<4;i++){
			int nrow=row+delrow[i];
			int ncol=col+delcol[i];
			if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
				q.push({{nrow,ncol},t+1});
				visited[nrow][ncol]=2;
				cnt++;
			}
		}
	}

	if(cnt!=cntfresh)
	return -1;
	return tm;
}
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
