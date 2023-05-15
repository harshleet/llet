//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
       int n= board.size();
          int m =board[0].size();
       vis[row][col]=1;
       int drow[]={-1,1,0,0};
       int dcol[]={0,0,1,-1};

       for(int i=0;i<4;i++){
           int nrow=row+drow[i];
           int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                   
                    dfs(nrow,ncol,board,vis);
                }
       }
   }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
       
          vector<vector<int>>vis(n,(vector<int>(m,0)));
          for(int i =0;i<m;i++){
                if(board[0][i]=='O'){
                    vis[0][i]=1;
                    dfs(0,i,board,vis);
                }
          }
          for(int i =0;i<m;i++){
                if(board[n-1][i]=='O'){
                     vis[n-1][i]=1;
                    dfs(n-1,i,board,vis);
                }
          }
          for(int i =0;i<n;i++){
                if(board[i][0]=='O'){
                     vis[i][0]=1;
                    dfs(i,0,board,vis);
                }
          }
           for(int i =0;i<n;i++){
                if(board[i][m-1]=='O'){
                     vis[i][m-1]=1;
                    dfs(i,m-1,board,vis);
                }
          }
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(vis[i][j]==0 && board[i][j]=='O'){
                      board[i][j]='X';
                  }
              }
          }
          return board;// code here
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends