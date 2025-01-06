class Solution {
public:
typedef pair<int,int> P;
int dijkstra(int i,unordered_map<int,vector<pair<int,int>>> & adj,int dis,int n){
    vector<int> a(n,INT_MAX);
    priority_queue<P,vector<P>,greater<P>> pq;
    a[i] = 0;
    pq.push({0,i});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int w = it.first;
        int node = it.second;
        //if(w > a[node]) continue;
        
        
        for(auto & v:adj[node]){
            int nextNode = v.first;
            int cost = v.second;
            if(cost+w<a[nextNode] && cost+w<=dis){
                pq.push({cost+w,nextNode});
                a[nextNode] = w + cost;
            }
        }

        
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i]<=dis) cnt++;
    }
    return cnt;
}
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto & e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int res = -1;
        int count = INT_MAX;
        for(int i = 0;i<n;i++){
            int a = dijkstra(i,adj,dis,n);
            
            if(a<=count){ res = i; count = a;}
            
        }
        return res;
    }
};
