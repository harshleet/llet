//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      bool check(int src,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){
          vis[src]=1;
          pathvis[src]=1;
          
          for(auto it:adj[src]){
              if(!vis[it]){
                  if(check(it,adj,vis,pathvis)==true){
                      return true;
                  }
              }    
              else if(vis[it]==1 && pathvis[it]==1){
                  return true;
              }
          }
         
          pathvis[src]=0;
          return false;
      }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code her
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i])
            {
                if(check(i,adj,vis,pathvis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends