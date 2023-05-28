//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
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
   
    int doctorStrange(int V, int M, vector<vector<int>> & graph)
    {
        vector<int>adj[V];
        for(int i=0;i<M;i++){
            adj[graph[i][0]-1].push_back(graph[i][1]-1);
             adj[graph[i][1]-1].push_back(graph[i][0]-1);
            
        }
         vector<int>vis(V,0);
        int tin[V];
        int low[V];
        
        set<int>mark;
        
        for(int i=0;i<V;i++){
            dfs(i,-1,vis,tin,low,mark,adj);
        }
      
       
        
        // if(adj[0].size()>2){
        //   mark.push_back(0);
        // }
       
        if(mark.size()==0){
            return {0};
        }
      
        return mark.size();
         //Write your code here
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}
// } Driver Code Ends