//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int row,int col,vector<vector<int>>& grid,vector<pair<int,int>>&vec,vector<vector<int>>&vis,int prow,int pcol)
    {
         int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        vec.push_back({prow-row,pcol-col});
         int drow[]={-1,0,1,0};
       int dcol[]={0,-1,0,1};

       for(int i=0;i<4;i++){
           int nrow=row+drow[i];
           int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                   
                    dfs(nrow,ncol,grid,vec,vis,prow,pcol);
            }
       }
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vec,vis,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends