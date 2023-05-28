//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <bits/stdc++.h>
class Solution {
  public:
  int timer=0;
     void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],set<int>&mark,vector<int>adj[]){
       vis[node]=1;
       tin[node]=low[node]=timer;
       timer++;
       int child=0;
       for(auto it:adj[node]){
           if(it==parent)continue;
           
           if(vis[it]==0){
               dfs(it,node,vis,tin,low,mark,adj);
               low[node]=min(low[node],low[it]);

               if(low[it]>=tin[node] && parent!=-1){
                  mark.insert(node);
               }
              child++; 
              
           }else{
               low[node]=min(low[node],tin[it]);
           }
           
           
       }
       
           if(child>1 && parent==-1){
               mark.insert(node);
           }
   }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>vis(V,0);
        int tin[V];
        int low[V];
        
        set<int>mark;
        
        for(int i=0;i<V;i++){
            dfs(i,-1,vis,tin,low,mark,adj);
        }
        int cnt=0;
       
        
        // if(adj[0].size()>2){
        //   mark.push_back(0);
        // }
       
        if(mark.size()==0){
            return {-1};
        }
        vector<int>ans(mark.begin(),mark.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends