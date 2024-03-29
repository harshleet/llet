//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[1]=0;
        pq.push({1,0});
        
        vector<int>parent(n+1);
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.first;
            int dis=it.second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edge=it.first;
                int edge_w=it.second;
                
                if(dis+edge_w<dist[edge]){
                    dist[edge]=dis+edge_w;
                     pq.push({edge,dis+edge_w});
                     parent[edge]=node;
                }
            }
        }
        
        if(dist[n]==1e9){
            return {-1};
        }
        int node=n;
        vector<int>path;
        
        while(parent[node]!=node){
           path.push_back(node);
           node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends