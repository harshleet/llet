//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
          if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        queue<pair<pair<int,int>,int>>pq;
        
        dist[source.first][source.second]=0;
        
        pq.push({{source.first,source.second},0});
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        
        while(!pq.empty()){
            auto it=pq.front();
            int r=it.first.first;
            int c=it.first.second;
            int dis=it.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newc>=0 && newc<m && newr>=0 && newr<n && grid[newr][newc]==1 && dis+1<dist[newr][newc]){
                    dist[newr][newc]=1+dis;
                    if(newr==destination.first && newc==destination.second){
                        return dis+1;
                    }
                    pq.push({{newr,newc},1+dis});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends